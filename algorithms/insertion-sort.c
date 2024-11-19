#include <stdio.h>

void print_array(int* array, int size) {
  for(int i = 0; i < size; ++i) {
    printf("%d ", array[i]);
  }
}

int main() {

  int n;
  scanf("%d", &n);
  int array[n];
  for(int i = 0; i < n; ++i) {
    scanf("%d"  , &array[i]);
  }

  //insertion sort, j starts from the second index till the end of the array
  for(int j = 1; j < n; ++j) {
    int key = array[j];
    int i = j - 1;
    while(array[i] >= 0 && array[i] > key) {
      array[i + 1] = array[i];
      i--;
    }
    array[i + 1] = key;
  }

  print_array(array, n);
  return 0;
}
