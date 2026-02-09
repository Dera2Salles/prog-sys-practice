#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUF_SIZE 20
#define WORD_SIZE 64

int main(int argc, char *argv[]) {

  int fd = open("out/toto.txt", O_RDONLY);

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
      if (caracter == ' ' || caracter == '\n' || caracter == '\t' ||
          caracter == '.' || caracter == ',') {
        if (wpos > 0) {
          word[wpos] = '\0';
          printf("Mot trouvé avec espace: %s\n", word);
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
