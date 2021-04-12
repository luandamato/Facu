
#include <stdio.h>
#include <stdlib.h>

char *buffer;
void remove_comentario(FILE *fp);

int main(void){
    FILE *fp_entrada, *fp_saida;
    char *iniBuffer;
    // abre o arquivo
    fp_entrada = fopen("reconhece_num.c", "r");
    if(!fp_entrada){ // testa se abriu corretamente
        printf("erro na abertura do arquivo de entrada.\n");
        return 1;
    }
    fseek(fp_entrada, 0, SEEK_END); // move ponteiro do arquivo para o final
    long tamanho = ftell(fp_entrada); // conta a quantidade de bytes deslocados na movimentacao
    fseek(fp_entrada, 0, SEEK_SET); // move novamente para o inicio do arquivo
    buffer = (char*)calloc(tamanho+1,sizeof(char)); // aloca os memoria para guardar o arquivo lido
    fread(buffer, sizeof(char),tamanho,fp_entrada); // le de uma vez so o arquivo
    printf("%s",buffer);

    // abre o arquivo de saida
    fp_saida = fopen("saida.c", "w+");// w+ abre para escrita e se o arquivo nao existir cria
    if(!fp_saida){ // testa se abriu corretamente
        printf("erro na abertura do arquivo de saida.\n");
        return 1;
    }
    // implementa a remocao dos comentarios baseado no automoto da aula 2
    iniBuffer = buffer;
    remove_comentario(fp_saida);

    free(iniBuffer);
    fclose(fp_entrada);
    fclose(fp_saida); //fecha o arquivo de saida
    return 0;
}
void remove_comentario(FILE *fp){

q0:
    if(*buffer == '/'){
        buffer++;
        goto q1;
    }
    // trata o final do buffer
    else if(*buffer == 0)
        return;
    else{// outro
        // grava no arquivo de saida e incrementa o buffer
        fprintf(fp,"%c",*buffer++);
        goto q0;
    }
    return;
q1:
    if(*buffer == '*'){
        buffer++;
        goto q2;
    }
    else{// outro
        // grava / no arquivo de saida e nao incrementa o buffer
        fprintf(fp,"/");
        goto q0;
    }
    return;
q2:
    if(*buffer == '*'){
        buffer++;
        goto q3;
    }
    else{// outro
        //  incrementa o buffer
        buffer++;
        goto q2;
    }
    return;
q3:
    if(*buffer == '/'){
        buffer++;
        goto q0;
    }
    else{// outro
        //  incrementa o buffer
        buffer++;
        goto q2;
    }
    return;

}
