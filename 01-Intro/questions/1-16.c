#include<stdio.h>
#include "../include/gorilla.h"
#define MAXLINE 10

int main() {
  int len, max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  int currentLen = 0;
  while((len = getlineCustom(line, MAXLINE)) > 0) {
    if(len > max){
      max = len;
      currentLen = len;
      // printf("the length of this line is %d", len);
      copy(longest, line);
    }
  }
  
  if(max > 0) {
    printf("\nlongest line->%slength-> %d\n", longest, currentLen);
  }

}
