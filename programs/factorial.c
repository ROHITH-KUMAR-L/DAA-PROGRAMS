#include <stdio.h>
long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
int main() {
    int n;
    printf("Enter a positive integer: ");
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) printf("Factorial is not defined for negative numbers.\n");
    else printf("Factorial of %d is %lld\n", n, factorial(n));
    return 0;
}
