#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid();
    pid_t ppid = getppid();

    printf("Current Process ID: %d\n", pid);
    printf("Parent Process ID: %d\n", ppid);

    return 0;
}
