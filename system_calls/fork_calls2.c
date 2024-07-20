#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void forkInstance(){
  int  y = 3;
  if(fork() == 0)
    printf("child => Y is %d\n", ++y);
  else
    printf("parent => Y is %d\n", --y);
}


int main(){
  forkInstance();
  return 0;
}
