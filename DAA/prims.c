#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,u,v,min;
    int **a,*vis;

    scanf("%d",&n);

    a=malloc((n+1)*sizeof(int*));
    vis=calloc(n+1,sizeof(int));

    for(i=1;i<=n;i++)
    {
        a[i]=malloc((n+1)*sizeof(int));
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }

    vis[1]=1;

    for(i=1;i<n;i++)
    {
        min=999;
        for(u=1;u<=n;u++)
            if(vis[u])
                for(v=1;v<=n;v++)
                    if(!vis[v] && a[u][v] && a[u][v]<min)
                        min=a[u][v];
        for(u=1;u<=n;u++)
            if(vis[u])
                for(v=1;v<=n;v++)
                    if(!vis[v] && a[u][v]==min)
                        vis[v]=1;
    }
    return 0;
}
