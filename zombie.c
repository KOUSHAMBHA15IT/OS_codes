#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    if (fork() == 0)
        printf("Child process\n");
    else {
        sleep(3);
        wait(NULL);
        printf("Parent process\n");
    }
    return 0;
}
