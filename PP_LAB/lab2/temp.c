#include <stdio.h>
#include "mpi.h"

 int main(int argc, char const *argv[]) {
  int rank,size;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_Size(MPI_COMM_WORLD, &size);

  MPI_Status status;

  //Sending message in
  // First 3 parameters constitute message buffer, next 3 parameters specify message envelope
  // Msg - any address in sender's addr space
  // Count - number of data elements to be sent
  // Datatype - message Datatype ( MPI_INT, MPI_FLOAT etc)
  // Destintation - rank of process to which message sent
  // Tag - int by programmer to label diff types of message
  // Communicator - Process group (default is MPI_COMM_WORLD)

  MPI_Send(&Msg, Count, Datatype, Destination, Tag, Comm); //blocks until the message is buffered
  MPI_Ssend(&Msg, Count, Datatype, Destination, Tag, Comm); //requires to send a block until recieved
  MPI_Bsend(&Msg, Count, Datatype, Destination, Tag, Comm); // assumes availability of certain amount of buffer space

  //Buffer allocation and deallocation
  MPI_Buffer_attach(buffer,size);
  MPI_Buffer_detach(*buffer, *size);

  //Recieving
  MPI_Recv(&msg, Count, Datatype, Source, Tag, Comm, &status);
    // Msg - any address in sender's addr space
    // Status - Sender's Rank, Sender's Tag and number of items received

  MPI_Wtime(); // returns elapsed walll clock on clocking processor

  MPI_Finalize();
  return 0;
}

// To run
/*
mpicc q.c -o q
mpirun -np [arg] ./q
*/
