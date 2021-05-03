#include <stdio.h>
#include "mpi.h"

int main(int argc, char *argv[]) {
	int rank,size,i,j,a[3][3],b[3],key,count,countsum;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if(rank==0){
		printf(" Enter values in 3x3 matrix:\n");
		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j){
				scanf("%d",&a[i][j]);
			}
		}
		printf(" Enter ele to search:\n");
		scanf("%d",&key);
	}
	int error_code,len_error_string,error_class;
 MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
 error_code=MPI_Comm_rank(MPI_COM_WORLD,&rank);
 if(error_code!=MPI_SUCCESS)
 {
		 MPI_Error_class(error_code,&error_class);
		 MPI_Error_string(error_class,error_string,&len_error_string);
		 printf("%s\n",error_string);
 }

	MPI_Bcast(&key, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(a,3,MPI_INT,b,3,MPI_INT,0,MPI_COMM_WORLD);

	for(int i=0;i<3;++i){
    key == b[i] && count++;
	}

	MPI_Reduce(&count,&countsum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD );

	if(rank==0){
		printf("total no of occurances of %d  = %d",key,countsum);
	}

  MPI_Finalize();
  return 0;
}

// To run
/*
mpicc q.c -o q
mpirun -np [arg] ./1

*/
