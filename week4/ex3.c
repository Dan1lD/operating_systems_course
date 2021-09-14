#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main() {
    char str[1024];
    printf(">>>");
    fgets(str, 1024, stdin);

    while (strcmp(str,"exit") != 0) {
        system(str);
        printf(">>>");
        fgets(str,1024,stdin);
    }

    return 0;
}