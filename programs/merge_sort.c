#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void run_analysis() {
    int sizes[] = {10, 100, 1000, 10000, 20000, 30000, 40000, 50000, 60000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    printf("\n--- Time Complexity Analysis (Merge Sort) ---\n");
    printf("%-12s | %-20s\n", "Array Size (N)", "Time Taken (seconds)");
    printf("---------------------------------------------\n");
    
    srand(time(NULL));
    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];
        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            arr[i] = rand();
        }
        
        clock_t start = clock();
        merge_sort(arr, 0, n - 1);
        clock_t end = clock();
        
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%-12d | %-20.6f\n", n, time_taken);
        
        free(arr);
    }
}

int main() {
    int n;
    printf("Enter number of elements for manual sort (0 to skip to analysis): ");
    if (scanf("%d", &n) != 1) return 1;
    
    if (n > 0) {
        int *arr = (int *)malloc(n * sizeof(int));
        printf("Enter %d elements:\n", n);
        for (int i = 0; i < n; i++) {
            if (scanf("%d", &arr[i]) != 1) {
                free(arr);
                return 1;
            }
        }
        merge_sort(arr, 0, n - 1);
        printf("Sorted array:\n");
        for (int i = 0; i < n; i++) printf("%d ", arr[i]);
        printf("\n");
        free(arr);
    }
    
    run_analysis();
    return 0;
}
