#include <stdio.h>
int TEMP[500];
void MERGE(int arr[], int beg, int end, int mid){
    int i = beg, j = mid + 1, index = 0;
    while ((i<=mid) && (j<=end))
    {
       if (arr[i]<arr[j])
       {
        TEMP[index] = arr[i];
        i = i+1;
       }
       else{
        TEMP[index] = arr[j];
        j = j + 1;
       }
       index = index + 1;
    }
    if (i>mid)
    {
        while (j<=end)
        {
            TEMP[index] = arr[j];
            index = index + 1;
            j = j + 1;
        }
    }else{
        while (i<=mid)
        {
            TEMP[index] = arr[i];
            index = index + 1;
            i = i + 1;
        }
    }
    int k = 0, x = beg;
    while (k < index) {
    arr[x] = TEMP[k];
    k++;
    x++;
}

}
void MERGE_SORT(int arr[], int beg, int end){
    if (beg<end)
    {
        int mid = (beg + end)/2;
        MERGE_SORT(arr, beg, mid);
        MERGE_SORT(arr, mid+1, end);
        MERGE(arr, beg, end, mid);
    }
}
int main(){
    int array[500], start = 1, limit;
    printf("Enter Array Limmit\n");
    scanf("%d", &limit);
    for (int i = start; i <= limit; i++)
    {
        printf("INDEX[%d]\n", i);
        scanf("%d", &array[i]);
    }
    for (int i = start; i <= limit; i++)
    {
        printf("%d\t", array[i]);
        
    }
    MERGE_SORT(array, start, limit);
    printf("\nAfter Applying Merge Sort\n");
    for (int i = start; i <= limit; i++)
    {
        printf("%d\t", array[i]);
        
    }
    return 0;
}
