#include<stdio.h>
#include "../include/gorilla.h"
#define MAXLINE 1000

/*A program to print all input lines 
longer than 80 characters*/

int main() {
  int len; 
  char line[MAXLINE];
  while((len = getlineCustom(line, MAXLINE)) > 0){
    if(len > 80) {
      printf("%s", line);
    }
  }
}
