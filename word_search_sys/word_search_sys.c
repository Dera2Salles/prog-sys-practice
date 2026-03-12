#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUF_SIZE 20
#define WORD_SIZE 64

int isEndOfSentence(char c) {
  return (c == ' ' || c == '\n' || c == '\t' || c == '.' || c == ',');
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr,
            "Usage: %s [-o <output>] <fichier> <mot_a_chercher>\n"
            "Options:\n"
            "  -o <output>   écrire le résultat dans un fichier\n"
            "Example:\n"
            "  %s out/toto.txt toto\n"
            "  %s -o result.txt out/toto.txt toto\n",
            argv[0], argv[0], argv[0]);
    return 1;
  }

  char *filename = NULL;
  char *search = NULL;
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
    } else if (search == NULL) {
      search = argv[i];
      i++;
    } else {
      i++;
    }
  }

  if (filename == NULL || search == NULL) {
    fprintf(stderr, "Erreur : fichier ou mot manquant\n");
    return 1;
  }

  int fd = open(filename, O_RDONLY);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  int fd_out = -1;
  if (output_file != NULL) {
    fd_out = open(output_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd_out == -1) {
      perror("open output");
      close(fd);
      return 1;
    }
  }

  char buffer[BUF_SIZE];
  char *word = malloc(1);
  if (!word) {
    perror("malloc");
    close(fd);
    if (fd_out != -1)
      close(fd_out);
    return -1;
  }

  int word_cap = 4;
  int wpos = 0;
  ssize_t byte_read;
  int word_count = 0;

  while ((byte_read = read(fd, buffer, BUF_SIZE)) > 0) {
    for (int i = 0; i < byte_read; i++) {
      char caracter = buffer[i];
      if (isEndOfSentence(caracter)) {
        if (wpos > 0) {
          word[wpos] = '\0';
          if (strcmp(word, search) == 0)
            word_count++;
          wpos = 0;
        }
      } else {
        if (wpos + 1 >= word_cap) {
          word_cap *= 2;
          char *tmp = realloc(word, word_cap);
          if (!tmp) {
            perror("realloc");
            break;
          }
          word = tmp;
        }
        if (wpos < WORD_SIZE - 1)
          word[wpos++] = caracter;
      }
    }
  }

  if (wpos > 0) {
    word[wpos] = '\0';
    if (strcmp(word, search) == 0)
      word_count++;
  }

  char line_buf[256];
  snprintf(line_buf, sizeof(line_buf), "Mot : %s , occurence : %d\n", search,
           word_count);
  printf("%s", line_buf);
  if (fd_out != -1)
    write(fd_out, line_buf, strlen(line_buf));

  free(word);
  close(fd);
  if (fd_out != -1)
    close(fd_out);
  return 0;
}
