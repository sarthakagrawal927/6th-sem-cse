#include <stdio.h>
#include <string.h>
#include "mpi.h"

 int main(int argc, char *argv[]) {
  int rank,size,m,ans=0;
  char s[100], s2[100];
  int b[100] = {0};

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  MPI_Status status;
  if(rank == 0){
    fprintf(stdout, "Enter string\n" );
    fflush(stdout);
    scanf("%s",s );
    m = strlen(s);
  }

  MPI_Bcast(&m,1,MPI_INT,0,MPI_COMM_WORLD );

  MPI_Scatter(s, m/size ,MPI_CHAR, s2, m/size, MPI_INT,0,MPI_COMM_WORLD);

  int count = 0;

  for(int i  = 0; i < m/size; i++)
    if (strchr("aeiouAEIOU", s2[i]) == NULL)
			count += 1;
  // printf("%d\n",count );

  MPI_Gather(&count,1,MPI_INT, b,1,MPI_INT,0,MPI_COMM_WORLD);

  if(rank == 0){
    fprintf(stdout, "Result Gathered in root \n" );
    fflush(stdout);

    for(int i = 0; i < size; i++){
      printf("%d\n",b[i] );
      ans += b[i];
    }
    printf("Answer : %d\n",ans );
  }

  MPI_Finalize();
  return 0;
}

// To run
/*
mpicc q.c -o q
mpirun -np [arg] ./q
*/
