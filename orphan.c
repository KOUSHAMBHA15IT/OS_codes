#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) { // Parent process
        printf("Parent process exiting...\n");
    } else if (pid == 0) { // Child process
        sleep(5); // Delay to keep child running after parent exits
        printf("Child process, now orphan, adopted by init.\n");
    } else {
        perror("Fork failed");
    }

    return 0;
}
