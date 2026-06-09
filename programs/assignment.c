#include <stdio.h>
#define MAX 10
#define INF 99999
int cost_matrix[MAX][MAX];
int assigned[MAX];
int n;
int min_cost = INF;
void assign_jobs(int worker, int current_cost) {
    if (worker == n) {
        if (current_cost < min_cost) {
            min_cost = current_cost;
        }
        return;
    }
    if (current_cost >= min_cost) return;
    for (int job = 0; job < n; job++) {
        if (!assigned[job]) {
            assigned[job] = 1;
            assign_jobs(worker + 1, current_cost + cost_matrix[worker][job]);
            assigned[job] = 0;
        }
    }
}
int main() {
    printf("Enter number of workers/jobs (N): ");
    if (scanf("%d", &n) != 1) return 1;
    printf("Enter cost matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &cost_matrix[i][j]) != 1) return 1;
        }
        assigned[i] = 0;
    }
    assign_jobs(0, 0);
    printf("Minimum cost for assignment is: %d\n", min_cost);
    return 0;
}
