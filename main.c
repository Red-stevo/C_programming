#include <stdio.h>
#include <stdbool.h>

int main(void)
{
   int i, sum = 0;
   while (true){
      scanf("%d", &i);
      if(i == 0){
         printf("Sum : %d", sum);
         return sum;
      }
      sum = sum + i;
   }
}