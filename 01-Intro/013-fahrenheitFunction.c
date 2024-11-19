#include<stdio.h>

void fahrToCels(float lower, float upper, float step);

int main() {
  fahrToCels(0.0, 10.0, 0.5 );


  return 0;//program successfully executed
}

void fahrToCels(float lower, float upper, float step) {
  float fahr, celsius;

  printf("%s  |  %s\n", "Fahr", "Celsius");
  for(fahr = lower; fahr <= upper; fahr += step) {

    celsius = (5.0/9.0) * (fahr - 32.0);

    printf("%4.1f  | %7.1f\n", fahr, celsius);
  }

  return;
}