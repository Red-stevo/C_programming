#include <stdio.h>

int main(){

  //bitwise AND.
  unsigned char a = 17;
  unsigned char b = 10;

  printf("Bitwise NOT for 17 -> ::= int %d\n", ~a);
  printf("Bitwise AND for 17 and 10 -> :: int %d\n", a & b);
  printf("Bitwise OR for 17 and 10 -> ::= int %d\n", a | b);
  printf("Bitsie XOR for 17 and 10 -> ::= int %d\n", a ^ b);
  printf("right shift for 17 int %d\n", a >> 3);
  printf("left shift for 17 int %d\n", a << 3);
  
  return 0;
}
