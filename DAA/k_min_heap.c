#include <stdio.h>

void heapifyKaryMin(int a[], int n, int i, int k) 
{
    int smallest = i;
    for (int j = 1; j <= k; j++) 
    {
        int child = k * i + j;
        if (child < n && a[child] < a[smallest])
            smallest = child;
    }
    if (smallest != i) 
    {
        int t = a[i];
        a[i] = a[smallest];
        a[smallest] = t;
        heapifyKaryMin(a, n, smallest, k);
    }
}

void buildKaryMinHeap(int a[], int n, int k) 
{
    for (int i = (n - 1) / k; i >= 0; i--)
        heapifyKaryMin(a, n, i, k);
}

int main() 
{
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) 
        scanf("%d", &a[i]);
    buildKaryMinHeap(a, n, k);
    for (int i = 0; i < n; i++) 
        printf("%d ", a[i]);
    return 0;
}
