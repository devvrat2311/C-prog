//todo:- 
//  1. A program which reverses the words of a sentence.

#include <stdio.h>
#include "./include/gorilla.h"

#define MAXLINE 1000
#define TABSPACE 4

/* current program, detab program, from c book end of chapter one
One tab is 8 spaces, at least in my terminal settings*/
void detab(char *s, int len,  int maxlen);
void entab(char *s, int len,  int maxlen);

int main() {
  int len;
  char line[MAXLINE];

  while((len = getlineCustom(line, MAXLINE)) > 0) {
    //printf("%s", line);
    detab(line, len, MAXLINE);
  }

  
  return 0;
}

/*
  This function replaces a tab character with the appropriate number of
  spaces to the next tab step in the line.
*/
void detab(char *s, int len, int maxlen) {
  int i, j = 0;
  for(i = 0; i < len; ++i) {
    if(s[i] == '\t') {
      int k = 8 - j;
      while(k--) {
        putchar('_');
      }
      j = 0;
    }
    else {
      j++;
      j %= 8;
      putchar(s[i]);
    }
  }
}

void entab(char s[], int len, int maxlen) {
  for(int i = 0; i < len; ++i) {
    putchar(s[i]);
  }
  return;
}

