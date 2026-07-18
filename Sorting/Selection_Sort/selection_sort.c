#include <stdio.h>
int array[100];
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void SELECTION_SORT(int end){
    for (int i = 1; i <= end-1; i++)
    {
        int min = array[i];
        for (int j = i+1; j <= end; j++)
        {
            if (array[j]< min)
            {
                min = array[j];
            }
            
        }
        if (array[i] != min)
        {
            swap(&array[i], &min);
        }
    }
}
int main(){
    int limit;
    printf("Enter Array limit:: \n");
    scanf("%d", &limit);
    for (int i = 1; i <= limit; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Entered Array\n");
    for (int i = 1; i <= limit; i++)
    {
        printf("%d\t", array[i]);
    }
    SELECTION_SORT(limit);
    printf("\nAfter Sorting\n");
    for (int i = 1; i <= limit; i++)
    {
        printf("%d\t", array[i]);
    }
    return 0;
}
