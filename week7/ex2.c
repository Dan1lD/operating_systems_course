#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    int *array = (int*) malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        array[i] = i;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}