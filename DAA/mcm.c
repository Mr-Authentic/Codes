#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n,i,j,k,l;
    int *p;
    int **m;

    scanf("%d",&n);

    p=malloc((n+1)*sizeof(int));
    for(i=0;i<=n;i++)
        scanf("%d",&p[i]);

    m=malloc((n+1)*sizeof(int*));
    for(i=0;i<=n;i++)
        m[i]=malloc((n+1)*sizeof(int));

    for(i=1;i<=n;i++)
        m[i][i]=0;

    for(l=2;l<=n;l++)
        for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1;
            m[i][j]=INT_MAX;
            for(k=i;k<j;k++)
            {
                int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                    m[i][j]=q;
            }
        }

    printf("%d",m[1][n]);

    for(i=0;i<=n;i++)
        free(m[i]);
    free(m);
    free(p);

    return 0;
}
