#include <stdio.h>
int n;
int W[100][100];
int d[100][100];
int parent[100][100];

void CREATE_GRAPH()
{
    int i, j;

    FILE *fp = fopen("inputt.txt", "r");

    if(fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fscanf(fp, "%d", &n);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            fscanf(fp, "%d", &W[i][j]);
        }
    }

    fclose(fp);
}

void SHOW_GRAPH()
{
    int i, j;

    printf("\nWeight Matrix:\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            printf("%d\t", W[i][j]);
        }
        printf("\n");
    }
}
void floyd_warshall()
{
    int i, j, k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = W[i][j];
            if (i == j || W[i][j] == 9999)
            {
                parent[i][j] = -1;
            }else{
                parent[i][j] = i;
            }
            
        }
    }
    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(d[i][k] != 9999 &&
                   d[k][j] != 9999 &&
                   d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }
}
void SOLUTION(){
    int t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                printf("\n%d-->%d: ", i, j);
                t = j;
                while (t != i)
                {
                    printf("%d ", t);
                    if (parent[i][t] != i)
                    {
                        printf("<- ");
                    }
                    t = parent[i][t];
                    
                }
                printf("<- %d", i);
            }
            printf("\n");
            
        }
        printf("\n");
        
    }
    
}
int main()
{
    CREATE_GRAPH();

    SHOW_GRAPH();

    floyd_warshall();

    SOLUTION();

    return 0;
}
