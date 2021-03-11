#include "mpi.h"

#include<stdio.h>

int main(int argc, char * argv[]) {
  int size, rank;
  MPI_Status status;
  MPI_Init( & argc, & argv);
  MPI_Comm_size(MPI_COMM_WORLD, & size);
  MPI_Comm_rank(MPI_COMM_WORLD, & rank);
  if (rank == 0) {
    int number;
    // fflush(stdin);
    // printf("%d. Enter a number : ", rank);
    fflush(stdin);
    scanf("%d", & number);
    number += 1;
    MPI_Send( & number, sizeof(int), MPI_INT, rank + 1, rank, MPI_COMM_WORLD);
    printf("\nNumber sent by process %d is %d.\n", rank, number);
    MPI_Recv( & number, sizeof(int), MPI_INT, size - 1, size - 1, MPI_COMM_WORLD, & status);
    printf("Number received by process %d is %d.\n", rank, number);
  } else {
    int number;
    MPI_Recv( & number, sizeof(int), MPI_INT, rank - 1, rank - 1, MPI_COMM_WORLD, & status);
    printf("Number received by process %d is %d.\n", rank, number);
    number += 1;
    MPI_Send( & number, sizeof(int), MPI_INT, (rank + 1) % size, rank, MPI_COMM_WORLD);
    printf("Number sent by process %d is %d.\n", rank, number);
  }

  MPI_Finalize();
  return 0;
}
