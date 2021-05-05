% % cu
#include <stdio.h>
#include <stdlib.h>

        __global__ void
        oddEven(int *a, int n)
{
    int i = threadIdx.x;
    if ((i % 2 == 1) && i < n - 1)
    {
        if (a[i] > a[i + 1])
        {
            int temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
        }
    }
}

__global__ void evenOdd(int *a, int n)
{
    int i = threadIdx.x;
    if ((i % 2 == 0) && i < n - 1)
    {
        if (a[i] > a[i + 1])
        {
            int temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
        }
    }
}

void hostfunc(int *a, int *b, int n)
{
    int size = n * sizeof(int);
    int *d_a, *d_b;
    cudaMalloc((void **)&d_a, size);
    cudaMalloc((void **)&d_b, size);
    cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);

    for (int i = 0; i <= n / 2; i++)
    {
        oddEven<<<1, n>>>(d_a, n);
        evenOdd<<<1, n>>>(d_a, n);
    }

    cudaMemcpy(b, d_a, size, cudaMemcpyDeviceToHost);
    cudaFree(d_a);
    cudaFree(d_b);
}

int main()
{
    int *d_a;
    int n = 10;
    int a[n] = {14, 55, -14, 0, 88, 2, 71, -12, 22, 68};
    int b[n];

    hostfunc(a, b, n);
    printf("Sorted Array : \n");
    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);
    return 0;
}