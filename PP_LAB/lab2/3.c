#include "mpi.h"
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>

int main(int argc,char *argv[])
{
    int rank,size;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Status status;

    if(rank == 0){
      int a[100], toSend;
      for(int i = 1; i < size; i++){
          scanf("%d\n", &a[i]);
      }

      int buffer_size = (MPI_BSEND_OVERHEAD + size *  sizeof(int));
      char* buffer = malloc(buffer_size);
      MPI_Buffer_attach(buffer,buffer_size);

      for(int i = 1; i < size; i++)
        {
          toSend = (int)pow(a[i], 2+ a[i]%2);
          MPI_Bsend(&toSend, 1, MPI_INT,i, i, MPI_COMM_WORLD);
        }
      MPI_Buffer_detach(&buffer,&buffer_size);
    }
    else{
      int n;
      MPI_Recv(&n, 1, MPI_INT,0, rank, MPI_COMM_WORLD,&status);
      printf("Slave Rank : %d received %d from  Rank 0\n",rank, n );
    }

    MPI_Finalize();
    return 0;
}
