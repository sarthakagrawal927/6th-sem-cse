#include <stdio.h>
#include <math.h>
#include "mpi.h"

int main(int argc, char *argv[]) {
  int rank,size,x= 5;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if(rank % 2) printf("rank : %d World  \n",rank);
  else   printf("rank : %d Hello \n",rank);

  MPI_Finalize();
  return 0;
}
