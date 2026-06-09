#include <stdio.h>
int rec_linear_search(int arr[], int n, int key) {
    if (n == 0) return -1;
    if (arr[n - 1] == key) return n - 1;
    return rec_linear_search(arr, n - 1, key);
}
int main() {
    int n, key;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 1;
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) return 1;
    }
    printf("Enter element to search: ");
    if (scanf("%d", &key) != 1) return 1;
    int index = rec_linear_search(arr, n, key);
    if (index != -1) printf("Element found at index: %d\n", index);
    else printf("Element not found\n");
    return 0;
}
