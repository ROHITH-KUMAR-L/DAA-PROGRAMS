#include <stdio.h>
#define MAX 100
int s[MAX];
int x[MAX];
int d;
int has_solution = 0;
void sum_of_subsets(int s_so_far, int k, int r) {
    x[k] = 1;
    if (s_so_far + s[k] == d) {
        has_solution = 1;
        printf("Solution: { ");
        for (int i = 0; i <= k; i++) {
            if (x[i] == 1) printf("%d ", s[i]);
        }
        printf("}\n");
    } else if (s_so_far + s[k] + s[k + 1] <= d) {
        sum_of_subsets(s_so_far + s[k], k + 1, r - s[k]);
    }
    if ((s_so_far + r - s[k] >= d) && (s_so_far + s[k + 1] <= d)) {
        x[k] = 0;
        sum_of_subsets(s_so_far, k + 1, r - s[k]);
    }
}
int main() {
    int n, sum = 0;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 1;
    printf("Enter elements in ascending order:\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &s[i]) != 1) return 1;
        sum += s[i];
    }
    printf("Enter target sum: ");
    if (scanf("%d", &d) != 1) return 1;
    if (sum < d || s[0] > d) {
        printf("No subset exists.\n");
        return 0;
    }
    sum_of_subsets(0, 0, sum);
    if (!has_solution) printf("No subset exists.\n");
    return 0;
}
