#include <stdio.h>

int main() {
    int i, j;

    for (i = 1; i <= 4; i++) {
        // Print leading spaces
        for (j = 1; j < (5 - i); j++) {
            printf(" ");
        }

        // Print increasing sequence
        for (j = i; j<i+i; j++) {
            printf("%d", j);
        }

        // Print decreasing sequence
        for (j = 2*i - 2; j >= i; j--) {
            printf("%d", j);
        }

        printf("\n");
    }

    return 0;
}
