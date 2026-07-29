#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,p,i=0,j=0,k=0,l=0;
    int *a,*b,*c,*d;

    scanf("%d",&n);
    a=malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    scanf("%d",&m);
    b=malloc(m*sizeof(int));
    for(i=0;i<m;i++)
        scanf("%d",&b[i]);

    scanf("%d",&p);
    c=malloc(p*sizeof(int));
    for(i=0;i<p;i++)
        scanf("%d",&c[i]);

    d=malloc((n+m+p)*sizeof(int));

    i=j=k=0;
    while(i<n || j<m || k<p)
    {
        int x=999,y=999,z=999;
        if(i<n) x=a[i];
        if(j<m) y=b[j];
        if(k<p) z=c[k];

        if(x<=y && x<=z) d[l++]=a[i++];
        else if(y<=x && y<=z) d[l++]=b[j++];
        else d[l++]=c[k++];
    }
    return 0;
}
