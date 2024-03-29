#include <stdio.h>

long int factorial(int n);

int main() {
    int n;
    scanf("%d", &n);
    printf("Factorial of %d = %ld", n, factorial(n));
    
    return 0;
}

long int factorial(int n) {
    if (n >= 1)
        return n * factorial(n - 1);
    else
        return 1;
}
