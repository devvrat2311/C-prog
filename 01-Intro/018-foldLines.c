#include <stdio.h>
#include "../include/gorilla.h"

//the long lines folding program. . .beep boop
#define MAXLINE 5000

void showThresh(int);

int main() {
  char line[MAXLINE];
  int len;
  int lenThreshold = 50;
  
  
  putchar('\n');
  while((len = getlineCustom(line, MAXLINE)) > 0) {

    showThresh(lenThreshold);

    int lineLength = 0;
    int wordLength = 0;


    for(int i = 0 ; i < len; ++i) {
      
      if(line[i] == ' ') {
        wordLength = 0;
      } else {
        wordLength++;
      }

      putchar(line[i]);
      lineLength++;
    
    //check if word has ended
      if(lineLength >= (lenThreshold - 5) && wordLength > 0 && (line[i+1] == ' ' || line[i+1] == '\n' || line[i] == '\0')){
        putchar('\n');
        wordLength = 0;
        lineLength = 0;
      }
    }
  }
}

/*

[may 1] this does work right now, but only strictly, it doesnt consider
word endings and shifting to new line only on white spaces just yet

[may 2] now this gets to newline only after a word has been ended, albeit
after the threshold

*/


void showThresh(int lenThreshold) {
  for(int i = 0; i < lenThreshold; ++i) {
    if(i == lenThreshold - 1)
      putchar('|');
    else 
      putchar(' ');
  }
  putchar('\n');
  
}
