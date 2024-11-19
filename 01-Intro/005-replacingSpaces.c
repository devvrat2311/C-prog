#include<stdio.h>

int main() {
  int spaces = 0;

  int c;
  while((c = getchar()) != EOF){
    if(c == ' '){
      ++spaces;
    }
    else{
      spaces = 0;
    }
    if(spaces > 1){
      continue;
    }
    else{
      putchar(c);
    }
  }

  return 0;
}
