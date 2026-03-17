#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "search.h"

#define BUF_SIZE 20
#define WORD_SIZE 64
#define INITIAL_TABLE_SIZE 100

typedef struct {
  char *word;
  int occurence;
} WordCount;

void clean_word(char *word) {
  int j = 0;
  for (int i = 0; word[i]; i++) {
    if (isalnum((unsigned char)word[i])) {
      word[j++] = tolower((unsigned char)word[i]);
    }
  }
  word[j] = '\0';
}

char *find_word(int fd, off_t *cursor) {
  char *word = malloc(WORD_SIZE);
  if (!word) {
    perror("malloc");
    exit(1);
  }

  int wpos = 0;
  int capacity = WORD_SIZE;
  char c;
  ssize_t byte_read;

  while ((byte_read = read(fd, &c, 1)) > 0) {
    if (isEndOfSentence(c)) {
      if (wpos > 0) {
        word[wpos] = '\0';
        clean_word(word);
        if (strlen(word) == 0) {
          wpos = 0;
          continue;
        }
        if (cursor)
          *cursor = lseek(fd, 0, SEEK_CUR);
        return word;
      }
    } else {
      if (wpos >= capacity - 1) {
        capacity *= 2;
        char *tmp = realloc(word, capacity);
        if (!tmp) {
          free(word);
          perror("realloc");
          exit(1);
        }
        word = tmp;
      }
      word[wpos++] = c;
    }
  }

  if (wpos > 0) {
    word[wpos] = '\0';
    clean_word(word);
    if (strlen(word) == 0) {
      free(word);
      return NULL;
    }
    if (cursor)
      *cursor = lseek(fd, 0, SEEK_CUR);
    return word;
  }

  free(word);
  return NULL;
}

int find_or_add_word(WordCount **word_counts, int *size, int *capacity,
                     char *word) {
  for (int i = 0; i < *size; i++) {
    if (strcmp((*word_counts)[i].word, word) == 0) {
      return i; 
    }
  }

  if (*size >= *capacity) {
    *capacity *= 2;
    *word_counts = realloc(*word_counts, (*capacity) * sizeof(WordCount));
    if (!*word_counts) {
      perror("realloc");
      exit(1);
    }
  }

  (*word_counts)[*size].word = strdup(word);
  (*word_counts)[*size].occurence = 0;
  (*size)++;

  return *size - 1;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr,
            "Usage: %s [-o <output>] <filename>\n"
            "Options:\n"
            "  -o <output>   écrire le résultat dans un fichier\n"
            "Example:\n"
            "  %s out/toto.txt\n"
            "  %s -o result.txt out/toto.txt\n",
            argv[0], argv[0], argv[0]);
    return 1;
  }

  char *filename = NULL;
  char *output_file = NULL;

  int i = 1;
  while (i < argc) {
    if (strcmp(argv[i], "-o") == 0) {
      if (i + 1 >= argc) {
        fprintf(stderr, "Erreur : -o nécessite un nom de fichier\n");
        return 1;
      }
      output_file = argv[i + 1];
      i += 2;
    } else if (filename == NULL) {
      filename = argv[i];
      i++;
    } else {
      i++;
    }
  }

  if (filename == NULL) {
    fprintf(stderr, "Erreur : fichier manquant\n");
    return 1;
  }

  int fd_in = open(filename, O_RDONLY);
  if (fd_in == -1) {
    perror("open input");
    return 1;
  }

  int table_capacity = INITIAL_TABLE_SIZE;
  int table_size = 0;
  WordCount *word_counts = malloc(table_capacity * sizeof(WordCount));
  if (!word_counts) {
    perror("malloc");
    close(fd_in);
    return 1;
  }

  char *word;
  off_t cursor = lseek(fd_in, 0, SEEK_CUR);

  while ((word = find_word(fd_in, &cursor)) != NULL) {
    int index =
        find_or_add_word(&word_counts, &table_size, &table_capacity, word);
    word_counts[index].occurence++;
    free(word);
  }

  if (table_size == 0) {
    printf("Aucun mot trouvé dans le fichier.\n");
    free(word_counts);
    close(fd_in);
    return 0;
  }

  int max_index = 0;
  for (int i = 1; i < table_size; i++) {
    if (word_counts[i].occurence > word_counts[max_index].occurence) {
      max_index = i;
    }
  }

  char result_buf[256];
  snprintf(result_buf, sizeof(result_buf),
           "Le mot le plus fréquent : '%s' avec %d occurrence(s) dans le "
           "fichier %s\n",
           word_counts[max_index].word, word_counts[max_index].occurence,
           filename);

  if (output_file != NULL) {
    int fd_out = open(output_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd_out == -1) {
      perror("open output");
    } else {
      write(fd_out, result_buf, strlen(result_buf));
      close(fd_out);
    }
  } else {
    printf("%s", result_buf);
  }

  for (int i = 0; i < table_size; i++) {
    free(word_counts[i].word);
  }
  free(word_counts);
  close(fd_in);

  return 0;
}
