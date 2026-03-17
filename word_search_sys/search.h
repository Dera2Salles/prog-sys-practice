#ifndef SEARCH_H
#define SEARCH_H

int isEndOfSentence(char c);

int process_search_word(char *search, int *word_count, int fd, int fd_out);

int process_search_word_occur(char *search, int *word_count, int fd,
                              int fd_out);

#endif
