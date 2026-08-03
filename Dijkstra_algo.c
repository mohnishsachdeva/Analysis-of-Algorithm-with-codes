#include<stdio.h>
#include<conio.h>
#define infinity 999

void dij(int n,int v,int cost[10][10],int dist[100])
{
    int i,u,count,w,flag[10],min;

    for(i=1;i<=n;i++){
        flag[i]=0,dist[i]=cost[v][i];
    }
    for(i=1;i<=n;i++){
        printf("%d\t",flag[i]);
        
    }
    printf("\n");
    for(i=1;i<=n;i++){
        printf("%d\t",dist[i]);
        
    }
    count=2;
    while(count<=n)
    {printf(" count %d\t",count);
    printf("\n");
        min=99;
        for(w=1;w<=n;w++){
            if(dist[w]<min && !flag[w]){
                min=dist[w],u=w;
            }
        }
        printf("%d min\t",min);
        printf("\n");
        flag[u]=1;
        count++;
        for(w=1;w<=n;w++){
            if((dist[u]+cost[u][w]<dist[w]) && !flag[w])
            {
                dist[w]=dist[u]+cost[u][w];
            }
            printf(" w %d\t",w);
            printf("\n");

        }
    }
}
int main()
{
int n,cost[10][10],v,i,j,dist[10];


printf("\n Enter the number of nodes:");
scanf("%d",&n);
printf("\n Enter the cost matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
scanf("%d",&cost[i][j]);
if(cost[i][j]==0)
cost[i][j]=infinity;
}
printf("\n Enter the source matrix:");
scanf("%d",&v);
dij(n,v,cost,dist);
printf("\n Shortest path:\n");
for(i=1;i<=n;i++)
if(i!=v)
printf("%d->%d,cost=%d\n",v,i,dist[i]);
getch();
}