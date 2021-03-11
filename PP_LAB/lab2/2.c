#include "mpi.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc,char *argv[])
{
    int rank,size;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Status status;

    if(rank == 0){
      int n; printf("Enter Broadcast Number\n" );
      scanf("%d",&n);
      for(int i = 1; i < size; i++)
        MPI_Send(&n, 1, MPI_INT,i, i, MPI_COMM_WORLD);
    }
    else{
      int n;
      MPI_Recv(&n, 1, MPI_INT,0, rank, MPI_COMM_WORLD,&status);
      printf("Slave Rank : %d received %d from  Rank 0\n",rank, n );
    }

    MPI_Finalize();
    return 0;
}
