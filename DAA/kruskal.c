#include <stdio.h>
#include <stdlib.h>

int *p;

int find(int i)
{
    while(p[i])
        i=p[i];
    return i;
}

int main()
{
    int n,i,j,u,v,min;
    int **a;

    scanf("%d",&n);

    a=malloc((n+1)*sizeof(int*));
    p=calloc(n+1,sizeof(int));

    for(i=1;i<=n;i++)
    {
        a[i]=malloc((n+1)*sizeof(int));
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }

    for(i=1;i<n;i++)
    {
        min=999;
        for(u=1;u<=n;u++)
            for(v=1;v<=n;v++)
                if(a[u][v]<min)
                {
                    min=a[u][v];
                    i=u;
                    j=v;
                }

        u=find(i);
        v=find(j);

        if(u!=v)
            p[v]=u;

        a[i][j]=a[j][i]=999;
    }
    return 0;
}
