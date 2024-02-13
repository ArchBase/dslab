#include <stdio.h>

int sort_and_partition(int arr[], int low, int high){
    int pivot, i, j, temp;
    pivot = arr[high];
    i = low - 1;
    for(j=low; j<=high; j++){
        if(arr[j]<pivot){
            i++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;            
        }
    }
    i++;
    temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}

void quick_sort(int arr[], int low, int high){
    //printf("Sorting");
    int partition_index;
    if(low < high){
        partition_index = sort_and_partition(arr, low, high);
        quick_sort(arr, low, partition_index-1);
        quick_sort(arr, partition_index+1, high);
    }
}

void main(){
    int arr[10] = {2, 4, 3, 10, 36, 9, 2, 1, 4, 5}, i;
    quick_sort(arr, 0, 9);

    printf("Sorted array: \n");
    for(i=0; i<10; i++){
        printf(" %d", arr[i]);
    }
}

