#include<stdio.h>

void anotherMain() {
  double nc;
  for(nc = 0; getchar() != EOF; ++nc)
    ;
  printf("There are %.0f characters\n", nc);
}

int main() {
  // long nc;

  // nc = 0;
  // while(getchar() != EOF) {
  //   ++nc;
  // }

  // printf("%ld\n", nc);

  anotherMain();
}
