/*Write a program to determine the ranges of char, short, int and long
variables , both signed and unsigned, by printing appropriate values
from the standard headers and by direct computation. Harder if you compute
them: determine the ranges of various floating point types.*/

#include <limits.h>
#include <stdio.h>
#include <stdint.h>

int main() {
  //short integer
  int no_of_bits = 0;
  short s = 0;
  short max_short = 0;
  short min_short = 0;
  for(int i = 0; i < sizeof(short)*CHAR_BIT; ++i) {
    s += 1 << (i);
    max_short = (s > max_short? s : max_short);
    no_of_bits++;
  }
  s = max_short;
  for(int i = 0; i < sizeof(short)*CHAR_BIT; ++i) {
    s -= 1 << (i);
    min_short = (s < min_short ? s : min_short);
  }
  max_short = SHRT_MAX;
  printf("\nmax value of short integer:\nbin value: %hb\nint value: %hd\n", max_short, max_short);
  printf("\nmin value of short integer:\nbin value: %hb\nint value: %hd\n", min_short, min_short);
  printf("No of bits are: %d\n", no_of_bits);
  //signed integer
  no_of_bits = 0;
  int x = 0;
  int max_integer = 0;
  int min_integer = 0;
  for(int i = 0; i < sizeof(int)*CHAR_BIT; ++i) {
    x += 1 << (i);
    max_integer = (x > max_integer ? x : max_integer);
    no_of_bits++;
  }
  x = max_integer;
  for(int i = 0; i < sizeof(int)*CHAR_BIT; ++i) {
    x -= 1 << (i);
    min_integer = (x < min_integer ? x : min_integer);
    no_of_bits++;
  }
  printf("\nmax value of signed integer:\nbin value: %b\nint value: %d\n", max_integer, max_integer);
  printf("\nmin value of signed integer:\nbin value: %b\nint value: %d\n", min_integer, min_integer);
  printf("No of bits are: %d\n", no_of_bits);

  //unsigned integer
  no_of_bits = 0;
  unsigned y = 0;
  unsigned max_unsigned = 0;
  unsigned min_unsigned = 0;
  for(int i = 0; i < sizeof(unsigned)*CHAR_BIT; ++i) {
    y += 1U << i;
    max_unsigned = (y > max_unsigned ? y : max_unsigned);
  }
  for(int i = 0; i < sizeof(unsigned)*CHAR_BIT; ++i) {
    y -= 1U << i;
    min_unsigned = (y < min_unsigned ? y : min_unsigned);
    no_of_bits++;
  }
  printf("\nmax value of the unsigned integer:\nbin value: %b\nint value: %u\n", max_unsigned, max_unsigned);
  printf("\nmin value of the unsigned integer:\nbin value: %b\nint value: %u\n", min_unsigned, min_unsigned);
  printf("No of bits are: %d\n", no_of_bits);

  //signed long integer
  no_of_bits = 0;
  long a = 0;
  long max_long = 0;
  long min_long = 0;
  for(int i = 0; i < sizeof(long)*CHAR_BIT; ++i) {
    a += 1L << i;
    max_long = (a > max_long ? a : max_long);
  }
  for(int j = 0; j < sizeof(long)*CHAR_BIT; ++j) {
    a -= 1L << j;
    min_long = (a < min_long ? a : min_long);
    no_of_bits++;
  }
  printf("\nmax possible value of the signed long integer:\nbin value: %lb\nint value: %ld\n", max_long, max_long);
  printf("\nmin possible value of the signed long integer:\nbin value: %lb\nint value: %ld\n", min_long, min_long);
  printf("\nNo of bits are: %d\n", no_of_bits);

  //unsigned long
  unsigned long z = 0;
  unsigned long max_unsigned_long = 0;
  unsigned long min_unsigned_long = 0;
  no_of_bits = 0;
  for(int i = 0; i < sizeof(long)*CHAR_BIT; ++i) {
    z += 1UL << i;
    max_unsigned_long = ( z > max_unsigned_long ? z : max_unsigned_long);
    no_of_bits++;
  }
  for(int i = 0; i < sizeof(long)*CHAR_BIT; ++i) {
    z -= 1UL << i;
    min_unsigned_long = ( z < min_unsigned_long ? z : min_unsigned_long);
    no_of_bits++;
  }
  printf("\nMaximum value of the unsigned long integer:\nbin value: %lb\nint value: %lu\n", max_unsigned_long, max_unsigned_long);
  printf("\nMinimum value of the unsigned long integer:\nbin value: %lb\nint value: %lu\n", min_unsigned_long, min_unsigned_long);
  printf("No of bits are: %d\n", no_of_bits);

  //characters
  no_of_bits = 0;
  int c = 0;
  int max_char= 0;
  int min_char= 0;
  for(int i = 0; i < sizeof(char)*CHAR_BIT; ++i) {
    c += 1 << (i);
    max_char = (c > max_char ? c : max_char);
    no_of_bits++;
  }
  c = max_char;
  for(int i = 0; i < sizeof(char)*CHAR_BIT; ++i) {
    c -= 1 << (i);
    min_char= (c < min_char? c : min_char);
    no_of_bits++;
  }
  printf("\nmax value of char:\nbin value: %b\nint value: %d\n", max_char, max_char);
  printf("\nmin value of char:\nbin value: %b\nint value: %d\n", min_char, min_char);
  printf("No of bits are: %d\n", no_of_bits);

  return 0;
}
