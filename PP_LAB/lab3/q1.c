#include <stdio.h>
#include "mpi.h"


int fact(int n){
  if(n <= 1) return 1;
  int s = 1;
  for(int i = 1; i <= n; i++) s*=i;
  return s;
}

 int main(int argc, char *argv[]) {
  int rank,size, A[10], B[10],c;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  MPI_Status status;
  if(rank == 0){
    fprintf(stdout, "Enter %d values\n",size );
    fflush(stdout);
    for(int i = 0; i < size; i++){
      scanf("%d",&A[i] );
    }
  }
  MPI_Scatter(A,1,MPI_INT, &c,1, MPI_INT,0,MPI_COMM_WORLD);

  fprintf(stdout, "got %d value in process %d\n",c,rank );
  fflush(stdout);

  c = fact(c);
  MPI_Gather(&c,1,MPI_INT, B,1,MPI_INT,0,MPI_COMM_WORLD);

  if(rank == 0){
    fprintf(stdout, "Result Gathered in root \n" );
    fflush(stdout);
    for(int i = 0; i < size; i++){
      printf("%d\n",B[i] );
    }
  }

  MPI_Finalize();
  return 0;
}

// To run
/*
mpicc q.c -o q
mpirun -np [arg] ./q
*/
