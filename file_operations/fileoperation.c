#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *bree;


int main(int argv, char *args[]){

  if(argv == 1){
    printf("Please Provide args.");
    return 0;
  }

  //open a file for write.
  bree = fopen("bob.txt", "a");

  fprintf(bree, strcat(args[1], "\n"));

  fclose(bree);

  bree = fopen("bob.txt", "r");

  int length = strlen(args[1]);

  char *brad = (char *)malloc(sizeof(char)*length);
 // char brad[length + 1];

 fgets(brad, length, bree);

  printf("%s", brad);

  return 0;
}

