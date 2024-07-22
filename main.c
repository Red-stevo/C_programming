#include <stdio.h>
#include <stdbool.h>

int main(void){
   int i, sum = 0;
   puts(__TIME__);
   while (true){
      scanf("%d", &i);
      if(i == 0){
         printf("Sum : %d\n", sum);
         puts(__TIME__);
         return sum;
      }
      sum = sum + i;
   }
}
