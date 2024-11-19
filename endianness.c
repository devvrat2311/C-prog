#include <stdio.h>

union word {
  int i;
  char bytes[sizeof(int)];
};

int main() {
  union word x;
  x.i = 0x23110012;

  printf(" Value of x.i: %x\n", x.i);
  printf("Addess of x.i: %p\n", &x.i);
  for(int i = 0; i < sizeof(typeof(x.i)); ++i) {
    printf("\naddress of  x.bytes[%d] - %p\n", i, &x.bytes[i]);
    printf("  value of  x.bytes[%d] = %02x\n", i, x.bytes[i]);
  }

  return 0;
}
