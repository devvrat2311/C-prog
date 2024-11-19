#include<stdio.h>

#define MAXLINE 1000

int max;
char longest[MAXLINE];
char line[MAXLINE];

int getlineCustom(void);
void copy(void);

int main() {
  int len;
  extern int max;
  extern char line[], longest[];

  max = 0;
  while((len = getlineCustom()) > 0) {
    if(len > max){
      max = len;
      copy();
    }
  }

  if(max > 0) {
    printf("%s", longest);
  }

  return 0;
}

/*GetlineCustom specialized version*/
int getlineCustom(void) {
  int c, i;
  extern char line[];

  for(i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;

  if(c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i; //here i returns the exact length of the line in chars not words
}

void copy(void) {
  int i;
  extern char line[], longest[];

  i = 0;
  while((longest[i] = line[i]) != '\0')
    ++i;
}

