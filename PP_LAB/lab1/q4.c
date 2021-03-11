#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "mpi.h"

int main(int argc, char *argv[]) {
  int rank,size,x= 5;
  char name[] = "saRthAk";

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if( 97 <= name[rank % strlen(name)] && name[rank % strlen(name)] <= 122) name[rank % strlen(name)] = (char)(name[rank % strlen(name)] - 32);
  else name[rank % strlen(name)] = (char)(name[rank % strlen(name)] + 32);

  printf("rank :  %d -> %s \n",rank,name);

  MPI_Finalize();
  return 0;
}
