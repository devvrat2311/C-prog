#include<stdio.h>
#include<time.h>
#define MAXLINE 1000

/*A program which tests the user's typing skills, by having them copy a 60 word paragraph.*/
void timer(void);
void gorillatype(char content[], int size);


int main() {
  char s[MAXLINE];
  char d[MAXLINE] = "for the once known amethyst metal charizard transformers who never thought football manchester united";
  int i = 0;
  // while((s[i] = getchar()) != EOF){
  //   putchar(s[i++]);
  // }
  while(d[i] != '\0'){
    putchar(d[i++]);
  }

  // printf("%s", d);
  gorillatype(d, MAXLINE);
  return 0;
}

void timer() {
  time_t t1 = clock();
  float x = t1;
  printf("\n%3.3f", x);
}

void gorillatype(char content[], int size) {
  char state;
  int i = 0;
  while(content[i] != '\0'){
    putchar(content[i++]);
  }

  printf("%d", i + 1);

  int c;
  int entry[MAXLINE];
  i = 0; 
  while((c = getchar()) != EOF){
    entry[i++] = c;
  }

  i = 0;
  while(entry[i] != '\0'){
    putchar(entry[i++]);
  }
}