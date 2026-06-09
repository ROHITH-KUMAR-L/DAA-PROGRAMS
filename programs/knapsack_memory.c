#include <stdio.h>
#define MAX_ITEMS 100
#define MAX_CAP 1000
int w[MAX_ITEMS];
int v[MAX_ITEMS];
int F[MAX_ITEMS][MAX_CAP];
int max(int a, int b) {
    return (a > b) ? a : b;
}
int mf_knapsack(int i, int j) {
    if (i == 0 || j == 0) return 0;
    if (F[i][j] < 0) {
        if (j < w[i]) {
            F[i][j] = mf_knapsack(i - 1, j);
        } else {
            F[i][j] = max(mf_knapsack(i - 1, j), v[i] + mf_knapsack(i - 1, j - w[i]));
        }
    }
    return F[i][j];
}
int main() {
    int n, W;
    printf("Enter number of items: ");
    if (scanf("%d", &n) != 1) return 1;
    printf("Enter weights of the items:\n");
    for (int i = 1; i <= n; i++) {
        if (scanf("%d", &w[i]) != 1) return 1;
    }
    printf("Enter values of the items:\n");
    for (int i = 1; i <= n; i++) {
        if (scanf("%d", &v[i]) != 1) return 1;
    }
    printf("Enter capacity of knapsack: ");
    if (scanf("%d", &W) != 1) return 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            F[i][j] = -1;
        }
    }
    int max_val = mf_knapsack(n, W);
    printf("Maximum value in knapsack: %d\n", max_val);
    return 0;
}
