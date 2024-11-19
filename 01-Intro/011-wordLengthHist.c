#include<stdio.h>

#define IN 1
#define OUT 0

/*Count the no. of words of various lengths(this program is really close to my heart. Had a lot of fun writing this.)*/

void arrayToHistogramHorizontal(int [], int);
void arrayToHistogramVertical(int [], int);

int main() {

  int c, state, ncw; 
  int countArray[20];
  for(int i = 0; i < 20; i++) { //initializes the countArray array
    countArray[i] = 0;
  }

  //initializes the variables, 
  state = OUT;//begin state is outside of a word
  ncw = 0;//no. of chars in current word

  while((c = getchar()) != EOF) {
    if(c == ' ' || c == '\n' || c == '\t') { //we have exited a word
      state = OUT;
      countArray[ncw - 1]++;//i am very suspicious that this will cause out of bounds error
      ncw = 0;
    }
    else if(state == OUT) { //we have entered a word
      state = IN;
      ++ncw;
    }
    else if(state == IN) { //we are in the word
      ++ncw;
    }
  }

  printf("\n\n");

  printf("\n%30s", "Number of chars in word: ");
  for(int i = 0; i < 20; i++) {
    printf(" %2d", i + 1);
  }

  printf("\n");

  printf("\n%30s", "Number of such words: ");
  for(int i = 0; i < 20; i++) {
    printf(" %2d", countArray[i]);
  }

  printf("\n\n");

  arrayToHistogramHorizontal(countArray, 20);

  printf("\n\n");

  arrayToHistogramVertical(countArray, 20);

  printf("\n\n");
}

void arrayToHistogramHorizontal(int a[], int size) {
  for(int i = 0; i < size; ++i) {
    printf("%2d: ", i + 1);
    for(int j = 0; j < a[i]; ++j) {
      printf("");
    }
    printf("\n");
  }
}

void arrayToHistogramVertical(int A[], int size) {
  int max = 0;
  for(int i = 0; i < size; ++i) {
    if(A[i] >= A[max])
      max = i;
  }
  printf("most frequent word size %d, with %d counts \n", max + 1, A[max]);
  for(int i = A[max]; i >= 0; --i) {
    for(int j = 0; j < size; j++) {
      if(i == 0)
        printf("---");
      else if(A[j] >= i)
        printf("_  ");
      else
        printf("   ");
    }
    printf("\n");
  }
}
