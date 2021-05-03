#include <stdio.h>
#include "mpi.h"

int main(int argc, char *argv[]) {
  int rank,size,fact=1,factsum, i;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  for(i = 1; i <= rank; i++ , fact*=i);

  // MPI_Reduce(&fact, &factsum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
  // !rank && printf("Sum of fact :  %d\n",factsum );

  MPI_Scan(&fact, &factsum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD); //automatically stores everything in the last process
  rank == size-1 && printf("Sum of fact :  %d\n",factsum );

  MPI_Finalize();
  return 0;
}

// To run
/*
mpicc q.c -o q
mpirun -np [arg] ./1

*/
