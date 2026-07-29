#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,u,min;
    int **a,*d,*vis;

    scanf("%d",&n);

    a=malloc((n+1)*sizeof(int*));
    d=malloc((n+1)*sizeof(int));
    vis=calloc(n+1,sizeof(int));

    for(i=1;i<=n;i++)
    {
        a[i]=malloc((n+1)*sizeof(int));
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }

    for(i=1;i<=n;i++)
        d[i]=a[1][i];

    vis[1]=1;

    for(i=1;i<n;i++)
    {
        min=999;
        for(j=1;j<=n;j++)
            if(!vis[j] && d[j]<min)
            {
                min=d[j];
                u=j;
            }

        vis[u]=1;

        for(j=1;j<=n;j++)
            if(!vis[j] && d[u]+a[u][j]<d[j])
                d[j]=d[u]+a[u][j];
    }
    return 0;
}
