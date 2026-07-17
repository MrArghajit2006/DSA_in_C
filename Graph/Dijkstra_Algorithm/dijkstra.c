#include<stdio.h>
#include<limits.h>
#define MAX 100
int source,d[100],visit[100],pi[100], total_Cost = 0;
int g[MAX][MAX];
int n;
void solution(int s)
{
    int i,t;
    for (int i = 1; i <= n; i++)
    {
        printf("%c\t", pi[i]+64);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d\t", d[i]);
    }
    printf("\nShortest Paths:\n");
    for(i=1;i<=n;i++)
    {
        if(i==s)
            continue;

        printf("%c : ",i+64);

        t=i;

        while(t!=-1)
        {
            printf("%c",t+64);

            if(pi[t]!=-1)
                printf(" <- ");
                

            t=pi[t];
        }
        printf("\n");
    }
}
void create_graph()
{
    int i,j;
    FILE *fp=fopen("inputt.txt","r");
    if(fp==NULL)
    {
        printf("Error opening file!");
        return;
    }
    fscanf(fp,"%d",&n);
    printf("%d\n",n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            fscanf(fp,"%d",&g[i][j]);
        }
    }
    fclose(fp);
}
void show_graph()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d\t",g[i][j]);
        }
        printf("\n");
    }
}
int extract_min()
{
    int min=INT_MAX;
    int pos=-1,i;
    for(i=1;i<=n;i++)
    {
        if(visit[i]==0)
        {
            if(d[i]<min)
            {
                min=d[i];
                pos=i;
            }
        }
    }
    if(pos!=-1)
        visit[pos]=1;

    return pos;
}
void ini_single_s(int s)
{
    int i;
    for(i=1;i<=n;i++)
    {
        d[i]=INT_MAX;
        pi[i]=-1;
        visit[i]=0;
    }
    d[s]=0;
}
void relax(int u,int v)
{
    if(d[u]!=INT_MAX && d[v]>d[u]+g[u][v])
    {
        d[v]=d[u]+g[u][v];
        pi[v]=u;
    }
}
void dijkstra(int s)
{
    int i,v,u;
    ini_single_s(s);
    for(i=1;i<=n;i++)
    {
        u=extract_min();

        if(u==-1)
            break;

        for(v=1;v<=n;v++)
        {
            if(visit[v]==0 && g[u][v]!=0)
            {
                relax(u,v);
            }
        }
    }
}
int main()
{
    create_graph();
    printf("\nAdjacency Matrix:\n");
    show_graph();
    dijkstra(1);
    printf("\nShortest Distances:\n");
    for(int i=1;i<=n;i++)
    {
        printf("%c = %d\n",i+64,d[i]);
    }
    solution(1);
    return 0;
}
