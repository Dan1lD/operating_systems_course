#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "string.h"

int main() {
    char str[1024];

    printf(">>>");
    fgets(str, 1024, stdin);
    printf("%s",str);

    while (strcmp(str, "exit") != 0) {
        char *argc[32];
        for (int i = 0; i < 32; i++)
            argc[i] = NULL;
        char *ch = strtok(str, " \n");

        for (int i = 0; ch != NULL; i++) {
            argc[i] = malloc(strlen(ch));
            strcpy(argc[i], ch);
            ch = strtok(NULL, " \n");
        }
        for (int i = 0; i < 32; i++)
            printf("%s ",argc[i]);
        execve(argc[0],argc,NULL);

        printf("\n>>>");
        fgets(str, 1024, stdin);
    }

    return 0;
}