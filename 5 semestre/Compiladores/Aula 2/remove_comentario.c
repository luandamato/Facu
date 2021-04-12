
#include <stdio.h>
#include <stdlib.h>

char *buffer;

int main(void){
    FILE *fp;
    fp = fopen("reconhece_num.c", "r");
    if(!fp){
        printf("erro na abertura do arquivo.\n");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    long tamanho = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    buffer = (char*)calloc(tamanho+1,sizeof(char));
    fread(buffer, sizeof(char),tamanho,fp);
    printf("%s",buffer);
    free(buffer);
    fclose(fp);
    return 0;
}
