#include <stdio.h>
int rec_binary_search(int arr[], int low, int high, int key) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == key) return mid;
    if (arr[mid] > key) return rec_binary_search(arr, low, mid - 1, key);
    return rec_binary_search(arr, mid + 1, high, key);
}
int main() {
    int n, key;
    printf("Enter number of elements (sorted): ");
    if (scanf("%d", &n) != 1) return 1;
    int arr[n];
    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) return 1;
    }
    printf("Enter element to search: ");
    if (scanf("%d", &key) != 1) return 1;
    int index = rec_binary_search(arr, 0, n - 1, key);
    if (index != -1) printf("Element found at index: %d\n", index);
    else printf("Element not found\n");
    return 0;
}
