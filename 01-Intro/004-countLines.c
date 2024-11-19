#include<stdio.h>

/*Line counting in C*/

int main() {
  int c, nl;

  nl = 0;
  while( (c = getchar()) != EOF ) {
    if(c == '\n')
      ++nl;
  }
  printf("There are %d lines", nl);
  return 0;
}