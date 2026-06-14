#include <stdio.h>

#define INF 9999
#define MAX 10

int main() {
    int n, cost[MAX][MAX];
    int visited[MAX] = {0};
    int minCost = 0;
    int edges = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            // Replace 0 (except diagonal) with INF
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;    // Start from vertex 1
    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        int min = INF;
        int u = -1, v = -1;

        // Find the minimum edge connecting visited and unvisited vertices
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d --> %d : Cost = %d\n", u + 1, v + 1, min);

        minCost += min;
        visited[v] = 1;
        edges++;
    }

    printf("\nMinimum Cost of Spanning Tree = %d\n", minCost);

    return 0;
}