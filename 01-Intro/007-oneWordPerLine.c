#include<stdio.h>
#define IN 1
#define OUT 0

int main() {
  int c, nw, state;

  state = OUT;
  nw = 0;
  while((c = getchar()) != EOF) {
    if(c == ' ' || c == '\n' || c == '\t'){ //for when c is whitespace
      state = OUT;
    }
    else if(state == OUT) { //for when c is not whitespace
      state = IN;
      ++nw;
      printf("\n%d: ", nw);
    }
    putchar(c);
  }

  printf("\nThere were a total of %d words typed", nw);

  return 0;
}
