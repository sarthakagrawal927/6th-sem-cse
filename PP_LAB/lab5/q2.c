% % cu
#include <stdio.h>
#include <stdlib.h>

        __global__ void
        selsort(int *a, int *b, int n)
{
    int i = threadIdx.x + blockDim.x * blockIdx.x;
    int pos = 0;
    if (i < n)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] > a[j] || (a[i] == a[j] && i > j))
                pos++;
        }
        b[pos] = a[i];
    }
}
void hostfunc(int *a, int *b, int n)
{
    int size = n * sizeof(int);
    int *d_a, *d_b;
    cudaMalloc((void **)&d_a, size);
    cudaMalloc((void **)&d_b, size);
    cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);
    selsort<<<ceil(n / 256.0), 256>>>(d_a, d_b, n);
    cudaMemcpy(b, d_b, size, cudaMemcpyDeviceToHost);
    cudaFree(d_a);
    cudaFree(d_b);
}
int main()
{
    int n = 10;
    int a[10] = {5, 3, 6, 1, 7, 9, 2, 10, 4, 8};
    int b[10];
    hostfunc(a, b, n);
    printf("Sorted array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
}