#include <stdio.h>
#include <stdlib.h>

void main(){
    int a[10], i, n, mid, max, min=0;
    printf("Enter limit: ");
    scanf("%d", &n);
    max = n;

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    printf("Enter elemetn to be searched: ");
    scanf("%d", &n);
    mid = (min + max)/2;

    while (a[mid] != n)
    {
        if(max == min){
            printf("Element not found");
            exit(0);
        }
        if(a[mid] > n){
            max = mid-1;
        }
        else
        {
            min = mid+1;
        }
        mid = (max + min)/2;
    }
    printf("Elemnt found at %d", mid);

}