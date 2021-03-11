#include <stdio.h>
#include "mpi.h"

 int main(int argc, char *argv[]) {
  int rank,size,m, A[100], B[10];
  float avg = 0, C[10] = {0};
  float avgAll = 0;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  MPI_Status status;
  if(rank == 0){
    fprintf(stdout, "Enter number of students\n" );
    fflush(stdout);
    scanf("%d",&m );
    fprintf(stdout, "Enter %d values\n",size*m );
    fflush(stdout);
    for(int i = 0; i < size*m; i++){
      scanf("%d",&A[i]);
    }
  }
  MPI_Bcast(&m,1,MPI_INT,0,MPI_COMM_WORLD );
  MPI_Scatter(A,m,MPI_INT, B,m, MPI_INT,0,MPI_COMM_WORLD);

  for(int i  = 0; i < m; i++) avg+=B[i];
  avg /= m;

  MPI_Gather(&avg,1,MPI_FLOAT, C,1,MPI_FLOAT,0,MPI_COMM_WORLD);

  if(rank == 0){
    fprintf(stdout, "Result Gathered in root \n" );
    fflush(stdout);

    for(int i = 0; i < size; i++){
      avgAll += C[i];
      printf("%f\n",C[i] );
    }
    printf("Average : %f\n",avgAll/size );
  }

  MPI_Finalize();
  return 0;
}

// To run
/*
mpicc q.c -o q
mpirun -np [arg] ./q
*/
