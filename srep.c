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

  if (argc < 4) {
    fprintf(
        stderr,
        "Usage: %s <fichier> <mot_a_chercher> <mot_de_remplacement>\n"
        "Example:\n"
        "  %s out/toto.txt toto niov\n\n"
        "  Attention: remplacement par écrasement (même taille recommandée)\n",
        argv[0], argv[0]);
    return 1;
  }

  int fd = open(argv[1], O_RDWR);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  char buffer[BUF_SIZE];
  char word[WORD_SIZE];
  int wpos = 0;
  ssize_t byte_read;

  while ((byte_read = read(fd, buffer, BUF_SIZE)) > 0) {
    for (int i = 0; i < byte_read; i++) {
      char caracter = buffer[i];

      if (isEndOfSentence(caracter)) {
        if (wpos > 0) {
          word[wpos] = '\0';

          if (strcmp(argv[2], word) == 0) {
            lseek(fd, -(byte_read - i + wpos), SEEK_CUR);

            write(fd, argv[3], strlen(argv[3]));
          }

          wpos = 0;
        }
      } else {
        if (wpos < WORD_SIZE - 1) {
          word[wpos++] = caracter;
        }
      }
    }
  }

  close(fd);
  return 0;
}
