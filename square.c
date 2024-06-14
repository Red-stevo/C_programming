#include <stdio.h>

int main(){
  int number,i=1,j;

  printf("enter a number : ");
  scanf("%d", &number);

  while(i*i < number){
    j=1;
    while(j<i){
      if((i*i + j*j) == number){
          printf("Found the sum of the squares of %d and %d !\n", i, j);
          return 0;
      }
      ++j;
    }
    ++i;
  }

  printf("No sum found!!");
  return 0;
}
