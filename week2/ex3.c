#include <stdio.h>

void def(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }

        for (int j = 0; j < 2 * i - 1; j++) {
            printf("*");
        }

        printf("\n");
    }
}

void symmetric(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j ++) {
            printf("*");
        }

        printf("\n");
    }

    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j ++) {
            printf("*");
        }

        printf("\n");
    }
}

void square(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("*");
        }

        printf("\n");
    }
}

void triangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }

        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    int n;

    sscanf(argv[1], "%d", &n);

    if (argc > 2) {
        char b;
        char c;

        sscanf(argv[2], "%c%c", &b, &c);

        if (b == 's' && c == 'y') {
            symmetric(n);
        } else if (b == 's' && c == 'q') {
            square(n);
        } else if (b == 't' && c == 'r') {
            triangle(n);
        } else {
            def(n);
        }
    } else {
        def(n);
    }

    return 0;
}