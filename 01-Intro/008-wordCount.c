#include<stdio.h>

#define IN 1
#define OUT 0

/*Word counting*/

int main() {
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while((c = getchar()) != EOF) {
    ++nc;//updates the no of chars
    if(c == '\n')
      ++nl;//updates the no of lines
    if( c == ' ' || c == '\n' || c == '\t' )//whenever a whitespace is encountered, we jump OUT of the word
      state = OUT;
    else if(state == OUT){//When we are already in whitespace universe, anything other than a whitespace means that we are inside a word
      state = IN;
      ++nw;//increments the word count at the first char of the word and doesn't do anything special after that, until a whitespace is encountered, 
           //at which point it changes state to OUT
    }
  }

  printf("No of lines: %d\nNo of words: %d\nNo of chars: %d\n", nl, nw, nc);

  return 0;
}
