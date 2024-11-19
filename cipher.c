#include <asm-generic/errno.h>
#include<stdio.h>
#include<ctype.h>

//this is an inline comment
//who let the fuckng dogs outttt
char shiftChar(char c, int shift, int isEncrypt);
void encrypt(char* str, int shift, int isEncrypt);
void decrypt(char*, int);

int main() {
  char str[100];
  int shift;
  
  printf("Enter a string: ");
  fgets(str, 100, stdin);

  printf("Enter a shift value (1-25): ");
  scanf("%d", &shift);

  printf("Encrypting . . .\n");
  encrypt(str, shift, 1);
  printf("Encrypted string: %s\n", str);

  printf("Decrypting...\n");
  decrypt(str, shift);
  printf("Decrypting string: %s\n", str);

  return 0;
}

char shiftChar(char c, int shift, int isEncrypt) {
  // if(!isalpha(c)) {
  //   return c;
  // }
  int offset = isEncrypt ? shift : -shift;
  c = toupper(c);
  c = c - 'A' + offset;
  c = (c + 26) % 26;
  c = tolower(islower(c) ? c : 'A' + c);

  return c;
}

void encrypt(char* str, int shift, int isEncrypt) {
  for(int i = 0; str[i] != '\0'; i++) {
    str[i] = shiftChar(str[i], shift, isEncrypt);
  }
}

void decrypt(char* str, int shift) {
  encrypt(str, shift, 0);
}
