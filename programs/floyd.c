#include <stdio.h>
#define MAX 100
#define INF 99999
int min(int a, int b) {
    return (a < b) ? a : b;
}
void floyd(int d[MAX][MAX], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
int main() {
    int n;
    int d[MAX][MAX];
    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1) return 1;
    printf("Enter cost adjacency matrix (use 99999 for infinity):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &d[i][j]) != 1) return 1;
        }
    }
    floyd(d, n);
    printf("All-pairs shortest path distances:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] == INF) printf("INF ");
            else printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    return 0;
}
