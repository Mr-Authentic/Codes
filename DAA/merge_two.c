#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i=0,j=0,k=0;
    int *a,*b,*c;

    scanf("%d",&n);
    a=malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    scanf("%d",&m);
    b=malloc(m*sizeof(int));
    for(i=0;i<m;i++)
        scanf("%d",&b[i]);

    c=malloc((n+m)*sizeof(int));

    i=j=0;
    while(i<n && j<m)
        if(a[i]<b[j])
            c[k++]=a[i++];
        else
            c[k++]=b[j++];

    while(i<n)
        c[k++]=a[i++];

    while(j<m)
        c[k++]=b[j++];

    return 0;
}
