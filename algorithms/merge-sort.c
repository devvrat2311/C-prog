#include <stdio.h>
#include <limits.h>

void print_array(int* array, int size) {
  for(int i = 0; i < size; ++i) {
    printf("%d ", array[i]);
  }
}

void merge(int* array, int start, int middle, int end) {
  int left_size = middle - start + 1;
  int right_size = end - middle;

  int left_array[left_size + 1];
  for(int i = 0; i < left_size; ++i) {
    left_array[i] = array[start + i];
  }
  left_array[left_size] = INT_MAX;

  int right_array[right_size + 1];
  for(int j = 0; j < right_size; ++j) {
    right_array[j] = array[middle + 1 + j];
  }
  right_array[right_size] = INT_MAX;

  //And thus the merge starts
  int i = 0;
  int j = 0;
  for(int k = start; k < end + 1; ++k) {
    if(left_array[i] <= right_array[j]) {
      array[k] = left_array[i];
      i++;
    }
    else {
      array[k] = right_array[j];
      j++;
    }
  }
}

void merge_sort(int *array, int start_index, int end_index) {
  if(start_index < end_index) {
    int middle_index = (start_index + end_index) / 2;
    merge_sort(array, start_index, middle_index);
    merge_sort(array, middle_index + 1, end_index);
    merge(array, start_index, middle_index, end_index);
  }
}

int main() {
  int n = 10000;
  int array[n];
  for(int i = 0; i < n; ++i) {
    array[i] = n - i;
  }
  print_array(array, n);
  printf("\n");
  merge_sort(array, 0, n - 1);
  print_array(array, n);
}
