#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,k;
    int **a;

    scanf("%d",&n);
    a=malloc((n+1)*sizeof(int*));

    for(i=1;i<=n;i++)
    {
        a[i]=malloc((n+1)*sizeof(int));
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }

    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                a[i][j]=a[i][j]||(a[i][k]&&a[k][j]);

    return 0;
}
