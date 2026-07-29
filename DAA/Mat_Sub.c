#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int **a=(int**)malloc(m*sizeof(int*));
    int **b=(int**)malloc(m*sizeof(int*));
    int **c=(int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++)
    {
        a[i]=(int*)malloc(n*sizeof(int));
        b[i]=(int*)malloc(n*sizeof(int));
        c[i]=(int*)malloc(n*sizeof(int));
    }
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++) 
            scanf("%d",&a[i][j]);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++) 
            scanf("%d",&b[i][j]);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j]=a[i][j]-b[i][j];
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
