#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main() {
    printf("PID: %d, UID: %d, GID: %d, EGID: %d\n", getpid(), getuid(), getgid(), getegid());
    return 0;
}
