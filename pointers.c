#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char name[30];
  char id[20];
  int marks[5];
  char grade;
}Student;


int main(int argc, char *argv[]){
  
  printf("%d", argc);
  
  for(int i= 0 ; i < argc ; i++){
    printf("%s", argv[i]);
  }
  return 0;
}
