#include <stdio.h>
#define INF 99999
#define MAX 20
int adj[MAX][MAX];
int visited[MAX];
int n;
int best_cost = INF;
void tsp(int curr_pos, int count, int cost, int start) {
    if (count == n && adj[curr_pos][start] != INF) {
        if (cost + adj[curr_pos][start] < best_cost) {
            best_cost = cost + adj[curr_pos][start];
        }
        return;
    }
    if (cost >= best_cost) return;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && adj[curr_pos][i] != INF) {
            visited[i] = 1;
            tsp(i, count + 1, cost + adj[curr_pos][i], start);
            visited[i] = 0;
        }
    }
}
int main() {
    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1) return 1;
    printf("Enter adjacency matrix (use 99999 for infinity):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &adj[i][j]) != 1) return 1;
        }
        visited[i] = 0;
    }
    visited[0] = 1;
    tsp(0, 1, 0, 0);
    if (best_cost == INF) printf("No tour exists.\n");
    else printf("Minimum TSP Cost: %d\n", best_cost);
    return 0;
}
