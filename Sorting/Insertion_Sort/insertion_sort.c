#include <stdio.h>
int array[500];
void SWAP(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void INSERTION_SORT(int end){
    int i;
    for (int j = 2; j <= end; j++)
    {
        int key = array[j];
        i = j - 1;
        while (i>=1 && array[i] > key){
            array[i+1] = array[i];
            i = i - 1;
        }
        array[i+1] = key;
    }
}
int main(){
    int limit, end;
    printf("Enter Array Limmit\n");
    scanf("%d", &limit);
    for (int i = 1; i <= limit; i++)
    {
        printf("INDEX[%d]\n", i);
        scanf("%d", &array[i]);
    }
    for (int i = 1; i <= limit; i++)
    {
        printf("%d\t", array[i]);
        
    }
    
    INSERTION_SORT(limit);
    printf("\nAfter Applying insertion Sort\n");
    for (int i = 1; i <= limit; i++)
    {
        printf("%d\t", array[i]);
        
    }
    return 0;
}
