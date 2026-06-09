#include <stdio.h>
int main() {
    int n;
    printf("Enter N for NxN matrices: ");
    if (scanf("%d", &n) != 1) return 1;
    int a[n][n], b[n][n], c[n][n];
    printf("Enter matrix A elements:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (scanf("%d", &a[i][j]) != 1) return 1;
    printf("Enter matrix B elements:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (scanf("%d", &b[i][j]) != 1) return 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("Resultant Matrix C:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
