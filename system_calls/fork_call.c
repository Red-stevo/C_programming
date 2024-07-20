#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

  fork();
  fork();
  printf("This is fork() system call\n");

  return 0;
}
