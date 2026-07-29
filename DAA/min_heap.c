#include <stdio.h>

void heapifyMin(int a[], int n, int i) 
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] < a[smallest])
        smallest = l;
    if (r < n && a[r] < a[smallest])
        smallest = r;

    if (smallest != i) 
    {
        int t = a[i];
        a[i] = a[smallest];
        a[smallest] = t;
        heapifyMin(a, n, smallest);
    }
}

void buildMinHeap(int a[], int n) 
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMin(a, n, i);
}

int main() 
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    buildMinHeap(a, n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}
