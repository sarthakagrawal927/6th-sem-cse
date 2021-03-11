#include "mpi.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char * argv[]) {

  int rank, size;
  MPI_Init( & argc, & argv);
  MPI_Comm_rank(MPI_COMM_WORLD, & rank);
  MPI_Comm_size(MPI_COMM_WORLD, & size);
  MPI_Status status;

  if (rank == 0) {
    char x[50];
    int sz;
    printf("Enter the string:");
    scanf("%s", x);
    sz = strlen(x);
    fprintf(stdout, "i have send %s from process 0\n", x);
    MPI_Ssend( & x, sz, MPI_CHAR, 1, 1, MPI_COMM_WORLD);
    MPI_Recv( & x, sz, MPI_CHAR, 1, 1, MPI_COMM_WORLD, & status);
    fprintf(stdout, "i have recieved %s from process 1\n", x);
    fflush(stdout);
  } else {
    char x[50];
    MPI_Recv( & x, 50, MPI_CHAR, 0, 1, MPI_COMM_WORLD, & status);
    fprintf(stdout, "i have recieved %s in process 1\n", x);

    for (int i = 0; i < strlen(x); i++) {
      if (islower(x[i]))
        x[i] = toupper(x[i]);
      else if (isupper(x[i]))
        x[i] = tolower(x[i]);
    }
    MPI_Ssend( & x,  strlen(x), MPI_CHAR, 0, 1, MPI_COMM_WORLD);
    fprintf(stdout, "i have send %s from process 0\n", x);
    fflush(stdout);
  }
  MPI_Finalize();
  return 0;
}
