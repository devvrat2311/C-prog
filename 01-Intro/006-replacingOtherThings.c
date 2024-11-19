#include<stdio.h>

int main() {
  double tabs, backs, bslash;
  int c;
  while((c = getchar()) != EOF){
    if(c == '\t'){
      putchar('\\');
      putchar('t');
    }
    else if(c == '\b'){
      putchar('\\');
      putchar('b');
    }
    else if(c == '\\'){
      putchar('\\');
      putchar('\\');
    }
    else{
      putchar(c);
    }
  }

  return 0;
}
