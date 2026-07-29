#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Enter the size of array:");
    int n;
    scanf("%d",&n);  
    int *arr=(int *)malloc(n * sizeof(int));
    printf("Enter the values of elements: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

    }
    for(int i =0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
                int x=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=x;
            }
        }
    }
    printf("Sorted Array: ");
    for(int i=0;i<n;i++)
    {
        printf("  %d",arr[i]);
    }
    return 0;
}