#include <stdio.h>
#include "mpi.h"

 int main(int argc, char const *argv[]) {
  int rank,size;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_Size(MPI_COMM_WORLD, &size);

  MPI_Status status;
  // Collective Communication
  MPI_Bcast(Address , Count, Datatype,Root, Comm)
  // the process ranked root send the same message (address,count ,datatype) to all
  // processes in communicator Comm

  MPI_Scatter(SendBuff , Sendcount, SendDatatype, RecvBuff, Recvcount, RecvDatatype,Root,Comm);
  // Root process sends out a personalized message which are in rank order to send buffer
  //to all N processes
  MPI_Gather(SendBuff , Sendcount, SendDatatype, RecvBuff, Recvcount, RecvDatatype,Root,Comm);
  // Root process recieves a personalized message from all

  MPI_Alltoall(); // Equivalent to N gathers
  
  MPI_Finalize();
  return 0;
}

// To run
/*
mpicc q.c -o q
mpirun -np [arg] ./q
*/
