#include <stdio.h>
#define MAX 6
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int start, int end){
    int pivot = arr[end];
    int i = start-1;
    for (int j = start; j <= end-1; j++)
    {
        if (pivot >= arr[j])
        {
            i = i+1;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1], &arr[end]);
    return i+1;
}
void quick_sort(int arr[], int start, int end){
    if (start<end)
    {
        int mid = partition(arr, start, end);
        quick_sort(arr, start, mid-1);
        quick_sort(arr, mid+1, end);
    }
}
int main(){
    int array[] = {10,30,40,50,70,90,80};
    quick_sort(array, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", array[i]);
    }
    

    return 0;
}
