#include<stdio.h>
#define MAXLINE 1000

int getlineCustom(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while((len = getlineCustom(line, MAXLINE)) > 0){
    printf("the length of this line was: %d\n", len);
    if(len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if(max > 0)
    printf("%s", longest);

  return 0;
}

int getlineCustom(char s[], int lim) {
  int c, i;

//following for loop takes input of chars until, either maxline length is reached, EOF is declared by the user or newline char is encountered
  for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) { 
    s[i] = c;                                                           
  }
//if the last char entered was a newline then it is added at the end of the current Line
  if(c == '\n'){ 
    s[i] = c;
    ++i;
  }

//the current, and the last index of the line is set to the null character or the zero character so that 'C' can recognize that this is where the string ends
  s[i] = '\0'; 
  
  return i;

}

void copy(char to[], char from[]) {
  int i = 0;

  while((to[i] = from[i]) != '\0')
    ++i;

  return;
}