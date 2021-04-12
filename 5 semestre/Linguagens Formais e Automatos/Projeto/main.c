#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* File pointer to hold reference to our file */
FILE * fPtr;
#define DATA_SIZE 1000

typedef enum{
    ERRO,
    NUMERO_INTEIRO,
    PONTO_FLUTUANTE,
    EOS
}TAtomo;



typedef struct{
    TAtomo tipo;
    int numero_numero;
    float ponto_flutuante;
}TInfoAtomo;

TInfoAtomo scanner(char *fita){
  TInfoAtomo info_atomo;

	q0:
    //printf("q0");
    if(isdigit(*fita)){
      
      if (*fita == '0'){
        fita++;
        goto q1;
      } 
      else{
        fita++;
        goto q3;
      }
        
    }

    else if (*fita == '.'){
      fita++;
      goto q2;
    }

    else if(*fita == '\0'){
        info_atomo.tipo = EOS;
        return info_atomo;
		}

    else if(isspace(*fita) && *fita != '\n'){
        fita++;
        goto q0; //volta para q0
    }

    else{
      fita++;
      while (!isspace(*fita) && *fita != '\0'){
        fita++;
      }
        
      goto erro;
    }

	q1:
    //printf("q1");
		if(isdigit(*fita)){
      fita++;
      while (!isspace(*fita) && *fita != '\0'){
        fita++;
      }
        
      goto erro;
    }
		else if(*fita == '.'){
			fita++;
			goto q2;
		}
    else if(isspace(*fita) && *fita != '\n'){
        fita++;
        info_atomo.tipo = NUMERO_INTEIRO;
        return info_atomo;
        //goto q0; //volta para q0
    }
    info_atomo.tipo = NUMERO_INTEIRO;
    return info_atomo;
	q2:
    //printf("q2");
    if(isdigit(*fita)){
			fita++;
			goto q2;
		}
    else if (isalpha(*fita)){
      goto erro;
    }
    else{
      info_atomo.tipo = PONTO_FLUTUANTE;
      printf("<P.FLUTUANTE>\n");
      fputs("<P.FLUTUANTE>\n", fPtr);
      goto q0;
    }
    

	q3:
    //printf("q3");
		if(isdigit(*fita)){
			fita++;
			goto q3;
		}
    else if (*fita == '.'){
      fita++;
      goto q2;
    }
    else{
        info_atomo.tipo = NUMERO_INTEIRO;
        printf("<INTEIRO>\n");
        fputs("<INTEIRO>\n", fPtr);
        goto q0; //volta para q0
    }

  final:
    return info_atomo;

  erro:
    printf("<ERRO>\n");
    fputs("<ERRO>\n", fPtr);
    info_atomo.tipo = ERRO;
    goto q0;
    //return info_atomo;

}

void criarArquivo(){
  char data[DATA_SIZE];
    /* 
     * Open file in w (write) mode. 
     * "data/saidaAutomato.txt" is complete path to create file
     */
    fPtr = fopen("saidaAutomato.txt", "w");


    /* fopen() return NULL if last operation was unsuccessful */
    if(fPtr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
}

int main(void) {
    criarArquivo();

    TInfoAtomo info_atomo = scanner("21 +45.67 0.123 .456 -42 xx 00.123");
    if (info_atomo.tipo  == EOS){
      printf("Fim \n");
    }
      
  fclose(fPtr);
  return 0;
}

