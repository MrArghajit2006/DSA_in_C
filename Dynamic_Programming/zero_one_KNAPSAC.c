#include <stdio.h>
#include<stdlib.h>
int profit[100], weight[100], no_of_object,selected[100];;
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
void zero_one_Enapsac(int capacity){
    FILE*fp;
    fp = fopen("input_zero_one.txt", "r");
    if (fp == NULL)
    {
        printf("FILE NOT FOUND\n");
        exit(0);
    }
    fscanf(fp, "%d", &no_of_object);
    for (int i = 1; i <= no_of_object; i++)
    {
        fscanf(fp, "%d", &profit[i]);
    }
    for (int i = 1; i <= no_of_object; i++)
    {
        fscanf(fp, "%d", &weight[i]);
    }
    printf("Profit Array\n");
    for (int i = 1; i <= no_of_object; i++)
    {
        printf("%d\t", profit[i]);
    }
    printf("\nWeight Array\n");
    for (int i = 1; i <= no_of_object; i++)
    {
        printf("%d\t", weight[i]);
    }
    int DP_TABLE[no_of_object + 1][capacity+ 1];
    for (int i = 0; i <= no_of_object; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
            {
               
                DP_TABLE[i][w] = 0;
            }
            else if (weight[i] <= w)
            {
                DP_TABLE[i][w] = max(profit[i] + DP_TABLE[i - 1][w - weight[i]], DP_TABLE[i - 1][w]);
            }
            else
            {
                DP_TABLE[i][w] = DP_TABLE[i - 1][w];
            }
        }
    }
    printf("\nMaximum Profit = %d\n", DP_TABLE[no_of_object][capacity]);
    int w = capacity;
    for (int i = no_of_object; i > 0 && w > 0; i--)
    {
        if (DP_TABLE[i][w] != DP_TABLE[i - 1][w])
        {
            selected[i] = 1;  
            w = w - weight[i];
        }
    }
    printf("\n--- Items Selected ---\n");
    printf("Item#\tProfit\tWeight\tParts Taken\n");
    int total_parts = 0;
    for (int i = 1; i <= no_of_object; i++)
    {
        printf("%d\t%d\t%d\t%d\n", i, profit[i], weight[i], selected[i]);
        total_parts += selected[i];
    }
    printf("\nTotal items selected: %d\n", total_parts);
    printf("Total weight used: %d / %d\n", capacity - w, capacity);
    
}
int main()
{
    zero_one_Enapsac(5);
    return 0;
}