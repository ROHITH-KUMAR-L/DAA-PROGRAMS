#include <stdio.h>
#define MAX 100
int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int val) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    rear++;
    queue[rear] = val;
}
int dequeue() {
    if (front == -1 || front > rear) return -1;
    int val = queue[front];
    front++;
    return val;
}
void bfs(int start, int n) {
    visited[start] = 1;
    enqueue(start);
    printf("BFS traversal starting from node %d:\n", start);
    while (front <= rear && front != -1) {
        int curr = dequeue();
        if (curr == -1) break;
        printf("%d ", curr);
        for (int i = 0; i < n; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1) return 1;
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &adj[i][j]) != 1) return 1;
        }
        visited[i] = 0;
    }
    int start;
    printf("Enter starting vertex (0 to %d): ", n - 1);
    if (scanf("%d", &start) != 1) return 1;
    bfs(start, n);
    return 0;
}
