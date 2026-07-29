#include <stdio.h>
#include <stdlib.h>

int **a,*v,n;

void dfs(int i)
{
    int j;
    printf("%d ",i);
    v[i]=1;
    for(j=1;j<=n;j++)
        if(a[i][j] && !v[j])
            dfs(j);
}

int main()
{
    int i,j;
    scanf("%d",&n);

    a=malloc((n+1)*sizeof(int*));
    v=calloc(n+1,sizeof(int));

    for(i=1;i<=n;i++)
    {
        a[i]=malloc((n+1)*sizeof(int));
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }

    dfs(1);
    return 0;
}
