% % cu
#define N 10
#include <stdio.h>
#include <stdlib.h>

		__global__ void
		add(int *a, int *b, int *c)
{
	int i = threadIdx.x + blockDim.x * blockIdx.x;
	c[i] = a[i] + b[i];
}

void hostfunc(int *a, int *b, int *c)
{
	int *d_a, *d_b, *d_c;
	int size = N * sizeof(int);

	cudaMalloc((void **)&d_a, size);
	cudaMalloc((void **)&d_b, size);
	cudaMalloc((void **)&d_c, size);

	cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, b, size, cudaMemcpyHostToDevice);

	add<<<N, 1>>>(d_a, d_b, d_c);

	cudaMemcpy(c, d_c, size, cudaMemcpyDeviceToHost);
	cudaFree(d_a);
	cudaFree(d_b);
	cudaFree(d_c);
}

int main(void)
{
	int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int b[N] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int c[N];
	hostfunc(a, b, c);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", c[i]);
	}
	return 0;
}
