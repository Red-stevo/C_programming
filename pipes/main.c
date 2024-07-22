#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void question9();
void question10();
int main(void){
   //question10();
   question9();

}


void question9(){
   char filename[100];
   int num, count = 0;
   double sum = 0.0;

   printf("Enter the filename: ");
   scanf("%s", filename);

   FILE *fptr = fopen(filename, "r");

   if (fptr == NULL) {
      perror("Cannot open file \n");
      exit(1);
   }

   while (fscanf(fptr, "%d", &num) != EOF) {
      sum += num;
      count++;
   }

   fclose(fptr);

   if (count == 0)
      perror("No numbers found in the file.\n");
   else {
      printf("sum %lf\n", sum);
      printf("count %d",count);
      printf("Average: %.2f\n", sum / count);
   }
}



void question10()
{
   FILE *fptr;
   char filename[100];
   long file_size;
   char *buffer;

   printf("Enter the filename: ");
   scanf("%s", filename);

   fptr = fopen(filename, "r");

   if (fptr == NULL) {
      perror("Cannot open file \n");
      exit(1);
   }

   fseek(fptr, 0, SEEK_END);
   file_size = ftell(fptr);
   fseek(fptr, 0, SEEK_SET);

   buffer = (char*)malloc(file_size + 1);
   fread(buffer, 1, file_size, fptr);
   buffer[file_size] = '\0';

   fclose(fptr);

   printf("Reversed content:\n");
   for (long i = file_size - 1; i >= 0; i--) {
      printf("%c", buffer[i]);
   }
   printf("\n");

   free(buffer);
}




