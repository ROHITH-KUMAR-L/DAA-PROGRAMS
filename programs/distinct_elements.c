#include <stdio.h>
int is_distinct(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) return 0;
        }
    }
    return 1;
}
int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 1;
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) return 1;
    }
    if (is_distinct(arr, n)) printf("All elements in the array are distinct/unique.\n");
    else printf("Elements in the array are not distinct (duplicates found).\n");
    return 0;
}
