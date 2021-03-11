#include <stdio.h>
#include <math.h>
#include "mpi.h"

int main(int argc, char *argv[]) {
  int rank,size,x= 5;
  int arr[9] = {18,523}
  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  double  y = pow(x,rank);
  printf("rank :  %d -> pow(%d,%d) = %.0f\n",rank,x,rank,y);

  MPI_Finalize();
  return 0;
}
