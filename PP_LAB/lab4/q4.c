#include "mpi.h"
#include <stdio.h>
#include <string.h>

int main (int argc, char* argv[]) {

    int rank, size;
    int i = 0, j;
    int k = 0, fac = 1, ans[1000], sum = 0;
    int n, a[100][100], b[100];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

		int error_code,len_error_string,error_class;
	 	MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
	 error_code=MPI_Comm_rank(MPI_COM_WORLD,&rank);
	 if(error_code!=MPI_SUCCESS)
	 {
			 MPI_Error_class(error_code,&error_class);
			 MPI_Error_string(error_class,error_string,&len_error_string);
			 printf("%s\n",error_string);
	 }

    if (rank == 0) {
        printf("Enter the elements of i/p matrix \n");
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                scanf("%d", &a[i][j]);
            }
        }
    }

    MPI_Scatter(a, 100, MPI_INT, b, 100, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scan(b, ans, 4, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    for (i = 0; i < 4; i++)  printf("%d ", ans[i]);
    printf("\n");

    MPI_Finalize();

    return 0;
}
