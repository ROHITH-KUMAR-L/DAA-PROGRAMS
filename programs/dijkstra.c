#include <stdio.h>
#define MAX 100
#define INF 99999
void dijkstra(int cost[MAX][MAX], int n, int src) {
    int dist[MAX], visited[MAX];
    for (int i = 0; i < n; i++) {
        dist[i] = cost[src][i];
        visited[i] = 0;
    }

    dist[src] = 0;

    visited[src] = 1;
    for (int count = 0; count < n - 1; count++) {
        int min_dist = INF, u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min_dist) {
                min_dist = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = 1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && cost[u][v] != INF && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("To node %d: ", i);
        if (dist[i] == INF) printf("INF\n");
        else printf("%d\n", dist[i]);
    }
}
int main() {
    int n, cost[MAX][MAX];
    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1) return 1;
    printf("Enter cost adjacency matrix (use 99999 for infinity):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &cost[i][j]) != 1) return 1;
        }
    }
    int src;
    printf("Enter source vertex (0 to %d): ", n - 1);
    if (scanf("%d", &src) != 1) return 1;
    dijkstra(cost, n, src);
    return 0;
}
