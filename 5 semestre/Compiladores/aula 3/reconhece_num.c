/*
    comentario de varias linhas
    1
    2
    3
    4
    5
    6
*/
#include <stdio.h>

char *palavra = "1*23";

int main(void){
    printf("analisando %s:",palavra);
    if( reconhece_num())
        printf("palavra aceita\n");
    else
        printf("palavra rejeitada\n");

    return 0;
}
int reconhece_num(){

q0:
    if(*palavra == '+'||*palavra == '-'){
        //consome o caracter
        palavra++;
        goto q1;
    }
    if(isdigit(*palavra)){
        //consome o caracter
        palavra++;
        goto q2;
    }
    //porque q0 nao eh estado final
    return 0;
q1:
    if(isdigit(*palavra)){
        //consome o caracter
        palavra++;
        goto q2;
    }
    //porque q1 nao eh estado final
    return 0;
q2:
    if(isdigit(*palavra)){
        //consome o caracter
        palavra++;
        goto q2;
    }
    /*retorna 1 se cheguei ao final da cadeia e estou no  estado q2, eh estado final*/
    return *palavra == '\x0';

}
