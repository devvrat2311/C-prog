#include<stdio.h>

int main() {
  int c;

//while((c = getchar()) != -1) { //static_cast<int>(EOF) == -1
  while((c = getchar()) != EOF) {
    putchar(c);
  }
}