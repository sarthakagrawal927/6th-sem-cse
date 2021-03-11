#include <stdio.h>
#include <string.h>
#include "mpi.h"

 int main(int argc, char *argv[]) {
  int rank,size,m;
  char s[100], s2[100], res[100], res2[100], temp[100],ans[100];


  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  MPI_Status status;
  if(rank == 0){
    fprintf(stdout, "Enter string\n" );
    fflush(stdout);
    scanf("%s",s );
    scanf("%s",s2 );
    m = strlen(s);
  }

  MPI_Bcast(&m,1,MPI_INT,0,MPI_COMM_WORLD );

  MPI_Scatter(s, m/size ,MPI_CHAR, res, m/size, MPI_INT,0,MPI_COMM_WORLD);
  MPI_Scatter(s2, m/size ,MPI_CHAR, res2, m/size, MPI_INT,0,MPI_COMM_WORLD);

  int j = 0;
  for(int i  = 0; i < m/size; i++)
    {
      temp[j++] = res[i];
      temp[j++] = res2[i];
    }

  MPI_Gather(temp,j,MPI_CHAR, ans,j,MPI_CHAR,0,MPI_COMM_WORLD);

  if(rank == 0){
    fprintf(stdout, "Result Gathered in root \n" );
    fflush(stdout);
    printf("Answer : %s\n",ans );
  }

  MPI_Finalize();
  return 0;
}

// To run
/*
mpicc q.c -o q
mpirun -np [arg] ./q
*/
