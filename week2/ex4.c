#include <stdio.h>

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main() {
    printf("Write two integers: ");

    int a;
    int b;

    scanf("%d", &a);
    scanf("%d", &b);

    swap(&a, &b);

    printf("%d %d\n", a, b);

    return 0;
}