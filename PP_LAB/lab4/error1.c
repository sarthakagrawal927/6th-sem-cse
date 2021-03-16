#include<stdio.h>
#include "mpi.h"
int main(int argc,char *argv[])
{
    int rank,size,fact=1,factsum,i;
    char *error_string;
    int MPI_COM_WORLD;

    MPI_Init(&argc,&argv);

    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

     int error_code,len_error_string,error_class;
    MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
    error_code=MPI_Comm_rank(MPI_COM_WORLD,&rank);
    if(error_code!=MPI_SUCCESS)
    {
        MPI_Error_class(error_code,&error_class);
        MPI_Error_string(error_class,error_string,&len_error_string);
        printf("%s\n",error_string);
    }

    for(i=1;i<=rank+1;i++)
        fact=fact*i;

    MPI_Scan(&fact,&factsum,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);

    if(rank==size-1){
        fprintf(stdout,"process %d has value %d\n",rank,factsum);
        fflush(stdout);
    }

    MPI_Finalize();
    return 0;
}
