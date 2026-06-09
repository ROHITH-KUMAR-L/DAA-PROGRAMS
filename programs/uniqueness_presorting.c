#include <stdio.h>
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pi = i + 1;
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
int check_unique_presorted(int arr[], int n) {
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) return 0;
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
    if (check_unique_presorted(arr, n)) printf("All elements are unique.\n");
    else printf("Elements are not unique.\n");
    return 0;
}
