// Luan Damato - 31817051

#include  <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>


int main(){
    //o processo pai e o processo filho compartilhem uma variável simples (por exemplo, inteiro - valor 1)

    pid_t filhoId;
    int shm_id;

    shm_id = shmget(IPC_PRIVATE, 512, IPC_CREAT | 0660);
    if (shm_id < 0) {
      printf("shmget error\n");
    }

    //Criando uma variável com ponteiro e colocando ela na memória compartilhada
    int *n = (int*)shmat(shm_id, NULL, 0);
    *n = 5;

    //o processo pai imprime o valor inicial dessa variável; em seguida, cria o processo filho e o espera
    printf("\nO valor inicial da variavel compartilhada = %d\n", *n);
    filhoId = fork();
    printf("\nfilhoId = %d\n", filhoId);

    //o processo filho acessa esta variável, realiza uma operação (por exemplo, adição - valor 2, totalizando 3), modificando o valor; em seguida, o processo filhoId termina
    if (filhoId == 0){     
        *n *= 2;
        printf("Variavel compartilhada * 2 = %d\n", *n);    
    } else {
        //o processo pai realiza uma outra operação (por exemplo, multiplicação - valor 4, totalizando 12), modificando novamente o valor, e imprime novamente a variável 
        wait(NULL);     
        *n += 4 ;
        printf("\nProcesso Pai\n");
        printf("Variavel compartilhada + 4 = %i\n", *n);

    }

    return 0;
}