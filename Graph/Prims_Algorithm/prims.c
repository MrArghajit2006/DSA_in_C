#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int source, cost = 0;
int n, A[100][100], P[100], d[100], visit[100], result[100];
void show_MST(){
    for (int i = 1; i <= n; i++)
    {
        printf("\n%c\t", P[i] + 64);
    }
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        if (i != source)
        {
            printf("%c--> %c\n", P[i] + 64, i + 64);
            cost = cost + A[P[i]][i];
        }
    }
    printf("Cost of spanning tree--> %d\n", cost);
}
void create_graph(){
    FILE *fp;
    fp = fopen("MSTgraph.txt", "r");
    if (fp == NULL)
    {
        printf("Invalid File\n");
        exit(0);
    }
    fscanf(fp, "%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            fscanf(fp, "%d", &A[i][j]);
        }
    }
}
void show_graph(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d\t", A[i][j]);

        }
        printf("\n");
    }
}
int extract_min(){
    int min = INT_MAX;
    int pos = -1;
    for (int i = 1; i <= n ; i++)
    {
        if (visit[i] == 0)
        {
            if (d[i]<min)
            {
                min = d[i];
                pos = i;
            }
        }
    }
    visit[pos] = 1;
    return pos;
}
void prims(int r){
    for (int i = 1; i <= n; i++)
    {
        d[i] = INT_MAX;
        P[i] = -1;
        visit[i] = 0;
    }
    d[r] = 0;
    for (int i = 1; i <= n; i++)
    {
        int u = extract_min();
        for (int v = 1; v <= n; v++)
        {
            if (visit[v] == 0 && A[u][v] != 0)
            {
                if (A[u][v] < d[v])
                {
                    P[v] = u;
                    d[v] = A[u][v];
                }
            }
        }
    }
}
int main(){
    create_graph();
    show_graph();
    source = 2;
    prims(source);
    show_MST();
    return 0;
}
