#include <stdio.h>
void dec_to_bin(int n) {
    if (n == 0) return;
    dec_to_bin(n / 2);
    printf("%d", n % 2);
}
int main() {
    int n;
    printf("Enter a positive integer: ");
    if (scanf("%d", &n) != 1) return 1;
    if (n == 0) printf("Binary representation: 0\n");
    else {
        printf("Binary representation: ");
        dec_to_bin(n);
        printf("\n");
    }
    return 0;
}
