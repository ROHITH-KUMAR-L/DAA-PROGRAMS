#include <stdio.h>
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
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
    printf("Enter element to search (linear search): ");
    if (scanf("%d", &key) != 1) return 1;
    int pos = linear_search(arr, n, key);
    if (pos != -1) printf("Element found at index: %d\n", pos);
    else printf("Element not found\n");
    bubble_sort(arr, n);
    printf("Sorted array (Bubble Sort):\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
