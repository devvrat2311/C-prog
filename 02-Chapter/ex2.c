#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int size_of_string(char *string) {
  int size = 0;
  for (int i = 0; string[i] != '\0'; ++i) {
    size++;
  }
  return size;
}

int htoi(char *string) {
  int size = size_of_string(string);
  int decimal = 0;
  // if(string)
  // check for prefixes like 0 or 0x
  int prefix = 0;
  if (string[0] == '0' && (string[1] == 'x' || string[1] == 'X')) {
    printf("prefix found\n");
    prefix = 2;
  }

  for (int i = 0; i < size - prefix; ++i) {
    if (isdigit(string[size - 1 - i])) {
      decimal += pow(16, i) * (string[size - 1 - i] - '0');
    } else if ((string[size - 1 - i] >= 'a' && string[size - 1 - i] <= 'f')) {
      decimal += pow(16, i) * (10 + (string[size - 1 - i] - 'a'));
    } else if ((string[size - 1 - i] >= 'A' && string[size - 1 - i] <= 'F')) {
      decimal += pow(16, i) * (10 + (string[size - 1 - i] - 'A'));
    } else {
      return INT_MIN;
    }
  }
  return decimal;
}

int routine() {
  char *string = (char *)malloc(100 * sizeof(char));
  if (string == NULL) {
    printf("memory allocation failed\n");
    return 1;
  }
  scanf("%s", string);
  int decimal = htoi(string);
  if (decimal > INT_MIN) {
    printf("the decimal value is: %d", decimal);
    free(string);
    return 0;
  } else {
    printf("string literal not acceptable, try again");
    free(string);
    return 1;
  }
}

int main() {

  routine();

  return 0;
}
