#include <stdio.h>
#define MAX 100
int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
void push(int val) {
    stack[++top] = val;
}
int pop() {
    return stack[top--];
}
void dfs(int v, int n) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
    push(v);
}
void topological_sort(int n) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n);
        }
    }
    printf("Topological order:\n");
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1) return 1;
    printf("Enter adjacency matrix (DAG):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &adj[i][j]) != 1) return 1;
        }
    }
    topological_sort(n);
    return 0;
}
