#include "../include/gorilla.h"
#define MAXLINE 1000

/*reverse engineering strings chars and words*/
void reverseDaString(char *s,int len, int maxlen);

int main() {
  int len;
  char s[MAXLINE];
  while((len = getlineCustom(s, MAXLINE)) > 0){
    reverseDaString(s, len, MAXLINE);
    printf("%s", s);
  }

  return 0;
}

void reverseDaString(char *s,int len, int maxlen) {
  char rev[MAXLINE];
  int i;
  for(i = 0; s[i] != '\0'; ++i) {
    // putchar(s[len - i - 1]);
    rev[i] = s[len - i - 1];
  }
  // putchar(s[len - 1]);
  rev[i++] = s[len - 1];

  rev[i] = '\0';

  copy(s, rev);

  return ;
}



