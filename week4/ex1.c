#include <stdio.h>
#include "unistd.h"

int main() {
    int n = 10;
    int pid = fork();

    if (pid == 0)
        printf("Hello from child [%d - %d]\n", getpid(), n);
    else if (pid >0)
        printf("Hello from parent [%d - %d]\n", getpid(), n);
    else return -1;

    return 0;
}