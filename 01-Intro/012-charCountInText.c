#include<stdio.h>
#include<ctype.h>

void charFrequencyHist(int [], int);
void arrayToHistogramVertical(int A[], int size);

int main() {
  int c;

  int charFrequencyArray[26];
  for(int i = 0; i < 26; ++i)
    charFrequencyArray[i] = 0;

  while((c = getchar()) != EOF) {
    c = tolower(c);
    //printf(" %d ", c-'a');
    charFrequencyArray[(c-'a')]++;
    //putchar(c);
  }

  charFrequencyHist(charFrequencyArray, 26);
  printf("\n");
  arrayToHistogramVertical(charFrequencyArray, 26);

  return 0;
}

void charFrequencyHist(int charFrequencyArray[], int size) {
  printf("\nHello World\n");
  for(int i = 0; i < size; ++i) {
    printf("%d ", charFrequencyArray[i]);
  }
  printf("\n");
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
        printf("  ");
      else
        printf("   ");
    }
    printf("\n");
  }

  for(int i = 0; i < 26; i++) {
    putchar(' ');
    putchar(' ');
    putchar('a' + i);
  }
  
}
