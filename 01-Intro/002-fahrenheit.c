#include<stdio.h>

/*
Print Fahrenheit-Celsius Table 
For fahr = 0, 20, ... , 300
*/

int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("%s - %s\n", "Fahr", "Celsius");
  while(fahr <= upper) {
    celsius = (5.0/9.0) * (fahr - 32.0);
    printf("%4.0f   %7.1f\n", fahr, celsius);
    // printf("%d\t%d\n", fahr, celsius);
    fahr += step;
  }
}