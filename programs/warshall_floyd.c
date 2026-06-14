#include <stdio.h>

#define MAX 100
#define INF 99999

int min(int a, int b) {
    return (a < b) ? a : b;
}

void warshall(int r[MAX][MAX], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                r[i][j] = r[i][j] || (r[i][k] && r[k][j]);
            }
        }
    }
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
    int choice, n;
    int a[MAX][MAX];

    printf("Menu:\n1. Warshall's Algorithm (Transitive Closure)\n2. Floyd's Algorithm (All-Pairs Shortest Path)\nEnter your choice: ");
    if (scanf("%d", &choice) != 1) return 1;

    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1) return 1;

    if (choice == 1) {
        printf("Enter adjacency matrix (0 or 1):\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (scanf("%d", &a[i][j]) != 1) return 1;
            }
        }
        warshall(a, n);
        printf("Transitive closure matrix:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    } else if (choice == 2) {
        printf("Enter cost adjacency matrix (use %d for infinity):\n", INF);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (scanf("%d", &a[i][j]) != 1) return 1;
            }
        }
        floyd(a, n);
        printf("All-pairs shortest path distances:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == INF) printf("INF ");
                else printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
