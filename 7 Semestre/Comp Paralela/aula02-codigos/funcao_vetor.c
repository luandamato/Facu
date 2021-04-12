#include <stdio.h>

#define TAM_MAX 5

void Imprimevet (int tam, int vet[TAM_MAX])
{
    int i;
    for (i=0; i< tam; i++)
    {
      printf("%d ", vet[i]);
    }    
	printf("\n");
}

int main()
{
  	int notas[TAM_MAX] = {1, 2, 3, 4, 5};

    Imprimevet(TAM_MAX, notas); // Passa o vetor 'notas' como
                                 // parâmetro

    return 0;

}