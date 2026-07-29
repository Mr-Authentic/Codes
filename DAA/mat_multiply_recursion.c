#include <stdio.h>
#include <stdlib.h>
void multiply(int **a,int **b,int **c,int i,int j,int k,int m1,int n1,int n2)
{
    if(i<m1)
    {
        if(j<n2)
        {
            if(k<n1)
            {
                c[i][j]+=a[i][k]*b[k][j];
                multiply(a,b,c,i,j,k+1,m1,n1,n2);
            } 
            else 
                multiply(a,b,c,i,j+1,0,m1,n1,n2);
        } 
        else 
            multiply(a,b,c,i+1,0,0,m1,n1,n2);
    }
}
int main()
{
    int m1,n1,m2,n2;
    scanf("%d%d",&m1,&n1);
    scanf("%d%d",&m2,&n2);
    if(n1!=m2)
    {
        printf("Not possible");
        return 0;
    }
    int **a=(int**)malloc(m1*sizeof(int*));
    int **b=(int**)malloc(m2*sizeof(int*));
    int **c=(int**)malloc(m1*sizeof(int*));
    for(int i=0;i<m1;i++)   
    {
        a[i]=(int*)malloc(n1*sizeof(int));
        c[i]=(int*)malloc(n2*sizeof(int));
        for(int j=0;j<n2;j++) 
            c[i][j]=0;
    }
    for(int i=0;i<m2;i++) 
        b[i]=(int*)malloc(n2*sizeof(int));
    for(int i=0;i<m1;i++)
        for(int j=0;j<n1;j++) 
            scanf("%d",&a[i][j]);
    for(int i=0;i<m2;i++)
        for(int j=0;j<n2;j++) 
            scanf("%d",&b[i][j]);
    multiply(a,b,c,0,0,0,m1,n1,n2);
    for(int i=0;i<m1;i++)
    {
        for(int j=0;j<n2;j++) 
            printf("%d ",c[i][j]);
        printf("\n");
    }
    return 0;
}
