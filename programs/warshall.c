#include <stdio.h>
#define MAX 100
void warshall(int r[MAX][MAX], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                r[i][j] = r[i][j] || (r[i][k] && r[k][j]);
            }
        }
    }
}
int main() {
    int n;
    int r[MAX][MAX];
    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1) return 1;
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &r[i][j]) != 1) return 1;
        }
    }
    warshall(r, n);
    printf("Transitive closure matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", r[i][j]);
        }
        printf("\n");
    }
    return 0;
}
