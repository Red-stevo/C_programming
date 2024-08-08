#include <stdio.h>
#include <unistd.h>


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





int main(void){




    return 0;
}
