#include <stdio.h>
void SWAP(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void BUBBLE_SORT(int array[], int size){
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j]>array[j+1])
            {
                SWAP(&array[j], &array[j+1]);
            }
            
        }
        
    }
    
}
int main(){
    int array[500],  limit;
    printf("Enter Array Limmit\n");
    scanf("%d", &limit);
    for (int i = 0; i < limit; i++)
    {
        printf("INDEX[%d]\n", i);
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < limit; i++)
    {
        printf("%d\t", array[i]);
        
    }
    BUBBLE_SORT(array, limit);
    printf("\nAfter Applying Bubble Sort\n");
    for (int i = 0; i < limit; i++)
    {
        printf("%d\t", array[i]);
        
    }
    return 0;
}
