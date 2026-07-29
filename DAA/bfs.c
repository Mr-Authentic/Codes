#include <stdio.h>
#include <stdlib.h>

int **a,*v,*q,n,f=0,r=-1;

int main()
{
    int i,j,u;
    scanf("%d",&n);

    a=malloc((n+1)*sizeof(int*));
    v=calloc(n+1,sizeof(int));
    q=malloc((n+1)*sizeof(int));

    for(i=1;i<=n;i++)
    {
        a[i]=malloc((n+1)*sizeof(int));
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }

    v[1]=1;
    q[++r]=1;
    printf("1 ");

    while(f<=r)
    {
        u=q[f++];
        for(i=1;i<=n;i++)
            if(a[u][i] && !v[i])
            {
                printf("%d ",i);
                v[i]=1;
                q[++r]=i;
            }
    }
    return 0;
}
