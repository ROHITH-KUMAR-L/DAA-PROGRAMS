#include <stdio.h>
#define MAX 100
#define INF 99999
void prims(int cost[MAX][MAX], int n) {
    int parent[MAX], key[MAX], visited[MAX];
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        visited[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < n - 1; count++) {
        int min_key = INF, u = -1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && key[v] < min_key) {
                min_key = key[v];
                u = v;
            }
        }
        if (u == -1) break;
        visited[u] = 1;
        for (int v = 0; v < n; v++) {
            if (cost[u][v] && !visited[v] && cost[u][v] < key[v]) {
                parent[v] = u;
                key[v] = cost[u][v];
            }
        }
    }
    int total_cost = 0;
    printf("Edges in Minimum Spanning Tree:\n");
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1 && cost[i][parent[i]] != INF) {
            printf("%d - %d: %d\n", parent[i], i, cost[i][parent[i]]);
            total_cost += cost[i][parent[i]];
        }
    }
    printf("Total Cost of MST: %d\n", total_cost);
}
int main() {
    int n, cost[MAX][MAX];
    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1) return 1;
    printf("Enter adjacency cost matrix (use 99999 for infinity or 0 for self/no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &cost[i][j]) != 1) return 1;
        }
    }
    prims(cost, n);
    return 0;
}
