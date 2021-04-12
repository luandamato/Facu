#include <stdio.h>
#include <omp.h>

#define N 500

int main(void) {

  int a[N][N];
  int b[N][N];

	//Iniciacao dos valores
	int i,j,k;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			a[i][j] = b[i][j] = i*N+j+1;
		}
	}

  int c[N][N];

#pragma omp parallel shared(a, b, c) private (i,j,k)
	{
#pragma omp for schedule(static)
    for(i = 0; i < N; i++) {
      for(k = 0; k < N; k++) {
        for(j = 0; j < N; j++) {
          c[i][j] += a[i][k] * b[k][j];
        }
      }
    }
	}


  return 0;
}