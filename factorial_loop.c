#include <stdio.h>

int main() {
    int n, i;
    long int factorial = 1;

    scanf("%d", &n);

    if (n < 0)
        printf("Factorial of a negative number doesn't exist.");
    else {
        for (i = 1; i <= n; ++i) {
            factorial *= i;             
        }
        printf("Factorial of %d = %ld", n, factorial);
    }

    return 0;
}
