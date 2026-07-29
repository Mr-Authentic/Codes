#include <stdio.h>

void heapifyKary(int a[], int n, int i, int k) 
{
    int largest = i;
    for (int j = 1; j <= k; j++) 
    {
        int child = k * i + j;
        if (child < n && a[child] > a[largest])
            largest = child;
    }
    if (largest != i) 
    {
        int t = a[i];
        a[i] = a[largest];
        a[largest] = t;
        heapifyKary(a, n, largest, k);
    }
}

void buildKaryMaxHeap(int a[], int n, int k) 
{
    for (int i = (n - 1) / k; i >= 0; i--)
        heapifyKary(a, n, i, k);
}

int main() 
{
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) 
        scanf("%d", &a[i]);
    buildKaryMaxHeap(a, n, k);
    for (int i = 0; i < n; i++) 
        printf("%d ", a[i]);
    return 0;
}
