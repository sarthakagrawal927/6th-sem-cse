#include <stdio.h>
#include <math.h>
#include "mpi.h"

int main(int argc, char *argv[]) {
  int rank,size,a= 10, b = 5;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

 switch(rank%4){
   case 0: printf("rank : %d >>  %d + %d = %d\n", rank, a,b, a+b );
   break;
   case 1: printf("rank : %d >>  %d * %d = %d\n", rank, a,b, a*b );break;
   case 2: printf("rank : %d >>  %d - %d = %d\n", rank, a,b, a-b );break;
   case 3:  printf("rank : %d >>  %d / %d = %d\n", rank, a,b, a/b );break;
   default: break;
 }

  MPI_Finalize();
  return 0;
}
