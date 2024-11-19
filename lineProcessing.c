#include <stdio.h>
#include "./include/gorilla.h"

//the long lines folding program. . .beep boop
#define MAXLINE 1000

int main() {
  char line[MAXLINE];
  int len;
  while((len = getlineCustom(line, MAXLINE)) > 0) {
    for(int i = 0; i < len; ++i) {
    //where the line will be processed

    }

    printf("%s", line);
  }
}