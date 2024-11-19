#include <stdio.h>
#include "../include/gorilla.h"

//remove comments from a program, we will try a different approach
#define MAXLINE 5000
#define FALSE 0
#define MAYBE 2
#define TRUE 1

//global variables
char c;
char line[MAXLINE];
int len;
int isMultComment = FALSE; //if we are in multComment i.e. /* - - - */
int isInlineComment = FALSE;
int multiLineFlag = FALSE;
 
//functions
void firstway();
void secondway();

int main() {

  secondway();

}

void secondway() {
  while((len = getlineCustom(line, MAXLINE))) {
    for(int i = 0; i < len; ++i) {
      if(line[i] == '/' && line[i+1] == '/'){
        // isInlineComment = TRUE;
        break;
      }
      else if(line[i] == '/' && line[i+1] == '*') {
        multiLineFlag = TRUE;
      }
      else if(multiLineFlag == TRUE && line[i-1] == '*' && line[i] == '/') {
        multiLineFlag = FALSE;
      }
      else {
        if(multiLineFlag == FALSE)
          putchar(line[i]);
      }
    }
  }
}

void firstway() {
  while((c = getchar()) != EOF) {
    if(c == '/') {
      isMultComment = MAYBE;
      isInlineComment = MAYBE;
    }
    if(isInlineComment == MAYBE && c == '/') {
      isInlineComment = TRUE;
      while((c = getchar()) != '\n');
      isInlineComment = FALSE;
    }
    if(isMultComment == MAYBE && c == '*') {
      isMultComment = TRUE;
      
    }
    putchar(c);
  }
}


