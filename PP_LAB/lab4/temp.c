#include <stdio.h>
#include "mpi.h"

int int main(int argc, char const *argv[]) {
  int rank,size;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_Size(MPI_COMM_WORLD, &size);
  MPI_Finalize();

  //Reduction
  MPI_Reduce( SendAddress, RecvAddress, Count, Datatype, Op, Root, Comm);
  // reduces the partial values stored in SendAddress of each process into a final result and stores
  // it in RecvAddress of the Root process. Reduction op specified by the Op field.
  // Some reduction op are : MPI_SUM, MPI_MAX, MPI_MIN, MPI_PROD

  MPI_Scan(SendAddress, RecvAddress, Count, Datatype, Op, Comm);
  // combines partial values into N final results which it stores in RecvAddress of N processes

  MPI_Barrier(Comm); // synchronizes all processes in communicator Comm
                    // They wait all N processes execute their respective MPI_Barrier

  

  return 0;
}

// To run
/*
mpicc q.c -o q
mpirun -np [arg] ./1

*/
