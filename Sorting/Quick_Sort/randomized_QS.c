#include <stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int array[], int start, int end){
    int pivot = array[end];
    int j = start - 1;
    for (int i = start; i < end; i++)
    {
        if (array[i] < pivot)
        {
            j = j + 1;
            swap(&array[j], &array[i]);
        }
    }
    swap(&array[j + 1], &array[end]);
    return j + 1;
}
int RANDOMIZED_PARTITION(int array[], int start, int end){
    int pivot_index = (rand() % (end - start + 1)) + start;
    swap(&array[pivot_index], &array[end]);
    return partition(array, start, end);
}
void Randomized_quick(int array[], int start, int end){
    if (start<end)
    {
        int mid = RANDOMIZED_PARTITION(array,start,end);
        Randomized_quick(array, start, mid-1);
        Randomized_quick(array, mid+1, end);
    }
}
int main(){
    srand(time(0));
    int array[500],  limit;
    printf("Enter Array Limmit\n");
    scanf("%d", &limit);
    for (int i = 1; i <= limit; i++)
    {
        printf("INDEX[%d]\n", i);
        scanf("%d", &array[i]);
    }
    printf("\nEntered Array:: \n");
    for (int i = 1; i <= limit; i++)
    {
        printf("%d\t", array[i]);
        
    }
    Randomized_quick(array, 1, limit);
    printf("\nSorted Array:: \n");
    for (int i = 1; i <= limit; i++)
    {
        printf("%d\t", array[i]);
    }
    
    return 0;
}
