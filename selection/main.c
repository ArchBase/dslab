#include <stdio.h>

void main() {
    int a[] = {3, 57, 55, 6, 7, 77, 0, 999};
    int n = sizeof(a)/sizeof(a[0]);
    printf("%d", n);
    int i, j, min, temp, loc;

    // Sort
    for(i=0; i<n; i++){
        min = a[i];
        loc = i;
        for(j=i+1; j<n; j++){
            if(a[j] < min){
                loc = j;
                min = a[j];
            }
        }
        a[loc] = a[i];
        a[i] = min;
    }

    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    


}
