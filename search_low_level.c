#include <fcntl.h>
#include <stdio.h>
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
            "Usage: %s <fichier> <mot_a_chercher>\n"
            "Example:\n"
            "  %s out/toto.txt toto\n",
            argv[0], argv[0]);
    return 1;
  }

  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  char buffer[BUF_SIZE];
  char word[WORD_SIZE];
  char word_found[WORD_SIZE];
  int wpos = 0;
  ssize_t byte_read;
  int word_count = 0;

  while ((byte_read = read(fd, buffer, BUF_SIZE)) > 0) {
    for (int i = 0; i < byte_read; i++) {
      char c = buffer[i];

      if (isEndOfSentence(c)) {
        if (wpos > 0) {
          word[wpos] = '\0';

          if (strcmp(argv[2], word) == 0) {
            word_count++;
            strcpy(word_found, word);
          }

          wpos = 0;
        }
      } else {
        if (wpos < WORD_SIZE - 1) {
          word[wpos++] = c;
        }
      }
    }
  }

  if (wpos > 0) {
    word[wpos] = '\0';
    if (strcmp(argv[2], word) == 0) {
      word_count++;
      strcpy(word_found, word);
    }
  }

  if (word_count > 0)
    printf("Mot trouvé : %s, nombres : %d\n", word_found, word_count);
  else
    printf("Mot '%s' non trouvé\n", argv[2]);

  close(fd);
  return 0;
}
