#include <stdio.h>
#include "mpi.h"  //message passing interface
                  //It is a set of parallel APIs

int int main(int argc, char *argv[]) {
  int rank,size;

  MPI_Init(&argc, &argv); // Initializes the MPI execution env.
                          //This func must be called (only once) in every MPI prog/func

  MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Returns rank of all MPI processes
                                        // Each process will be assigned a whole number

  MPI_Comm_size(MPI_COMM_WORLD, &size); // Returns total # MPI processes to var size


  MPI_Finalize(); // terminates the MPI environment
  return 0;
}

// To run
/*
mpicc q.c -o q
mpirun -np [arg] ./1

*/
