
#include <stdio.h>
#include "../include/gorilla.h" //change this line when copying into main

#define MAXLINE 1000
#define TABSIZE 8
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void function(char line[], int len);//entabs a line

int main() {
  int len;
  char line[MAXLINE];
  while((len = getlineCustom(line, MAXLINE)) > 0) {
    // printf("%s", line);
    //take this 'line', put it into a function
    function(line, len);
    //replace spaces to next tab by tab to next tab
    //replace line by newLine(in the function)

    //printf("%s", line);
  }
  return 0;
}

void function(char line[], int len) {
  char newLine[MAXLINE];
  int j = 0;
  int tabtracker = 0, count = 0;
  for(int i = 0; line[i] != '\0'; ++i) {
  //we just have to use appropriate tabs and spaces to achieve the same thing, 
  //first order of business, count how much effective 'white space' we are dealing w
    if(line[i] == ' ') {
      count++;

      tabtracker++;
      tabtracker %= 8;
    }
    else if (line[i] == '\t') {
      count+= TABSIZE - tabtracker;
      tabtracker = 0;
    }
    else {
      tabtracker++;
      tabtracker %= 8;
    }
  }
  int ntabs = count/8;
  int nspaces = count % 8;

  for(j = 0; j < ntabs; ++j) {
    newLine[j] = '\t';
  }
  for(j = ntabs; j < (ntabs + nspaces); ++j) {
    newLine[j] = ' ';
  }
  newLine[j++] = '\n';
  newLine[j] = '\0';

  printf("\nlength of oldLine was: %d\n", len-1);//len - 1 is the length after ignoring the last newline character
  printf("\nlength of newLine is: %d\n", j-1);//same reason as above

  // printf("\ntabs: %d\nspaces: %d\n",ntabs, nspaces);

  for(j = 0; newLine[j] != '\0'; ++j) {

    if(newLine[j] == '\t')
    printf(ANSI_COLOR_YELLOW" tab " ANSI_COLOR_YELLOW);
    else if(newLine[j] == ' ')
      printf(ANSI_COLOR_CYAN" space "ANSI_COLOR_CYAN);
    else 
      putchar(newLine[j]);
    
  }
}
