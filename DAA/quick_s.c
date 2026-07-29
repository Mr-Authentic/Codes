#include <stdio.h>
void swap(int *a,int *b)
{
    int t=*a;*a=*b;*b=t;
}
int partition(int a[],int l,int h)
{
    int p=a[h],i=l-1;
    for(int j=l;j<h;j++)
    {
        if(a[j]<p)
        {
            i++;swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[h]);
    return i+1;
}
void quicksort(int a[],int l,int h)
{
    if(l<h)
    {
        int pi=partition(a,l,h);
        quicksort(a,l,pi-1);
        quicksort(a,pi+1,h);
    }
}
int main()
{
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
