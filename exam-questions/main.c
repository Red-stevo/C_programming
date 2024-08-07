#include <stdio.h>
#include <unistd.h>


int main(void)
{

    fork();
    fork();
    if(fork() == 0){
        printf("process id : %d \n", getpid());

        printf("Parent id %d \n",getppid());

        printf("Hello From The Child Process.\n");
    }
    else{
        sleep(5);
        printf("process id : %d \n", getpid());
        printf("\tHello, World!\n");

    }
    return 0;
}
