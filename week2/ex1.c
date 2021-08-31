#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a;
    float b;
    double c;

    a = INT_MAX;
    b = FLT_MAX;
    c = DBL_MAX;

    printf("Integer: (size: %lu, max_value: %d)\n", sizeof(a), a);
    printf("Float: (size: %lu, max_value: %f)\n", sizeof(b), b);
    printf("Double: (size: %lu, max_value: %f)\n", sizeof(c), c);

    return 0;
}
