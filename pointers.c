#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
  char name[30];
  char id[20];
  int marks[5];
  char grade;
}Student;


int main(int argc, char *argv[]){
  char choice;


  while(true){
    printf("\tWhat would you like to do?\n");
    printf("1. Add student details.\n");
    printf("2. View a Student's details.\n");
    printf("3. View Students Details.\n");
    printf("4. Delete a Student's Details.\n");
    printf("5. Exit.\n");

    printf("Choice : ");
    scanf(" %c", &choice);
    switch(choice){
      case '1':
        //add students.
        break;
      case '2':
        //view one student's details.
        break;
      case '3':
        //view all student's details.
        break;
      case '4':
        //delete a students details.
        break;
      case '5':
        exit(0);
      default:
        printf("Invalid Choice try Again.\n");
    }
  }


  return 0;
}
