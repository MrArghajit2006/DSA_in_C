#include <stdio.h>
int array[500];
void SWAP(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void MAX_HEAPIFY(int i, int size){
    int LEFT = 2*i, RIGHT = 2*i+1, LARGEST = i;
    if (LEFT<=size && array[LEFT]>array[LARGEST])
    {
        LARGEST = LEFT;
    }
    if (RIGHT<=size && array[RIGHT]>array[LARGEST])
    {
        LARGEST = RIGHT;
    }
    if (LARGEST != i)
    {
        SWAP(&array[i],&array[LARGEST]);
        MAX_HEAPIFY(LARGEST, size);
    }
}
void BUILD_MAX_HEAP(int size){
    for (int i = (size/2); i >= 1; i--)
    {
        MAX_HEAPIFY(i, size);
    }
}
void HEAP_SORT(int size){
    BUILD_MAX_HEAP(size);
    for (int i = size; i >= 2; i--)
    {
        SWAP(&array[1], &array[i]);
        MAX_HEAPIFY(1, i-1);
    }
}
int main(){
    int size;
    printf("Enter Array Size:: \n");
    scanf("%d", &size);
    for (int i = 1; i <= size; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Entered Array\n");
    for (int i = 1; i <= size; i++)
    {
        printf("%d\t", array[i]);
    }
    HEAP_SORT(size);
    printf("\nAfter Sorting\n");
    for (int i = 1; i <= size; i++)
    {
        printf("%d\t", array[i]);
    }
    return 0;
}
