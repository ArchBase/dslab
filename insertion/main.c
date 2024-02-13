#include <stdio.h>
#include <stdlib.h>

void main(){
    int a[] = {57, 55, 6, 7, 77}, i, n=5, j, current;

    // Sort
    for (i = 1; i < n; i++)
    {        
        current = a[i];
        for(j=i-1; j>=0 && a[j]>current; j--){
            a[j+1] = a[j];
        }
        a[j+1] = current;
    }
    printf("Sorted array:\n");
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    


}
