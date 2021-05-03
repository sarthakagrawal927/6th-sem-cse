#include <stdio.h>
#include <math.h>
#include "mpi.h"

int main(int argc, char *argv[]) {
  int rank,size;
  float fact,factsum=0,rect=0;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  // fact = 4 * (atan(rank+1) - atan(rank));
  float x = (rank+0.5)/size;
	float x2 = x*x;
	rect = (4/(1+x2))*(1/(float)size);

  int error_code,len_error_string,error_class;
 MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
 error_code=MPI_Comm_rank(MPI_COM_WORLD,&rank);
 if(error_code!=MPI_SUCCESS)
 {
     MPI_Error_class(error_code,&error_class);
     MPI_Error_string(error_class,error_string,&len_error_string);
     printf("%s\n",error_string);
 }

  MPI_Scan(&rect, &factsum, 1, MPI_FLOAT, MPI_SUM, MPI_COMM_WORLD); //automatically stores everything in the last process
  rank == size-1 && printf("Area :  %f\n",factsum );

  MPI_Finalize();
  return 0;
}

// To run
/*
mpicc q.c -o q
mpirun -np [arg] ./1

*/
