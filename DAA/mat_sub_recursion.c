#include <stdio.h>
#include <stdlib.h>
void sub(int **a,int **b,int **c,int i,int j,int m,int n){
    if(i<m)
    {
        if(j<n)
        {
            c[i][j]=a[i][j]-b[i][j];
            sub(a,b,c,i,j+1,m,n);
        } else sub(a,b,c,i+1,0,m,n);
    }
}
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
    sub(a,b,c,0,0,m,n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) 
            printf("%d ",c[i][j]);
        printf("\n");
    }
    return 0;
}
