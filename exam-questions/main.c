#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void working_with_fork(){

    fork();
    int return_value = fork();

    if (return_value == 0){
        printf("Child process is : %d\n", getpid());
        printf("return value : %d\n", return_value);
    }else{
        printf("Parent process id %d\n", getpid());
        printf("return value : %d\n", return_value);
    }

    fork();
    fork();
    if(fork() == 0){
        printf("process id : %d \n", getpid());

        printf("Parent id %d \n",getppid());

        printf("Hello From The Child Process.\n");
    }else{
        sleep(5);
        printf("process id : %d \n", getpid());
        printf("\tHello, World!\n");
    }
}

struct Student{
    char name[100];
    char grade;
};



int main(void){

    struct Student *bree = (struct Student*) malloc(sizeof(struct Student));

    /*
    printf("Enter you name : ");
    fgets(bree->name, sizeof(bree->name), stdin);

    printf("ENTER YOUR GRADE\nGRADE : ");
    scanf(" %c",&bree->grade);


    printf("name : %s and grade %c ", bree->name, bree -> grade);
    */


    bree = (struct Student*) realloc(bree, (5 * sizeof(struct Student)));
    const struct Student *bree2 = bree;

    for (int i = 0; i < 5; i++){
        bree += i;
        printf("\nEnter you name : ");
        fgets(bree->name, sizeof(bree->name), stdin);
        bree->name[strcspn(bree->name, "\n")] = '\0';

        printf("\nENTER YOUR GRADE\nGRADE : ");
        scanf(" %c",&bree->grade);
    }

    for (int i = 0; i < 5; i++){
        bree2 +=i;
        printf("name : %s and grade %c \n", bree->name, bree -> grade);

    }
    return 0;
}
