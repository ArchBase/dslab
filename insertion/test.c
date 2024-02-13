#include <stdio.h>

void main() {
    int a[] = {57, 55, 6, 7, 77};
    int n = 5;
    int i, j, current;

    // Sort using insertion sort
    for (i = 1; i < n; i++) {
        current = a[i];
        for (j = i - 1; j >= 0 && a[j] > current; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = current;
    }

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
