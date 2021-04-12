/* 

Samuel Kenji Ochiai Gomes da Silva - 31817106
Luan Rocha Damato - 31817051

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef enum{
    ERRO,
    IDENTIFICADOR,
    NUMERO_INTEIRO,
    ATRIBUICAO,
    WHILE,
    EOS
}TAtomo;



typedef struct{
    TAtomo atomo;
    int linha;
    int atributo_numero;
    char atributo_ID[15];
}TInfoAtomo;

char *buffer;
int linha;
int pos_atomo; //posição do ponteiro no átomo

//obtem as infos do atomo
TInfoAtomo obter_atomo(){
    //inicializaçcao das variaveis
    TInfoAtomo info_atomo; //atomo
    char num[15]; //string de NUMERO_INTEIRO
		int val; //valor int de NUMERO_INTEIRO
		    
    q0:
        //salva a linha que o atomo esta
        info_atomo.linha = linha;
        
        //se for letra
        if(isalpha(*buffer)){
            info_atomo.atributo_ID[pos_atomo] = *buffer;
						//incremento do buffer e da posicao atual no atomo
            buffer++;
            pos_atomo++;
            goto q1; //vai para q1
        }

        //se for numero
				else if(isdigit(*buffer)){
						num[pos_atomo] = *buffer;
            //incremento do buffer e da posicao atual no atomo
						buffer++;
						pos_atomo++;
						goto q2; //vai para q2
				}

        //se for sinal de atribuicao
				else if(*buffer == ':' && *(buffer+1) == '='){
					info_atomo.atributo_ID[pos_atomo] = *buffer;
					info_atomo.atributo_ID[pos_atomo+1] = *(buffer+1);
					info_atomo.atomo = 3;
          //inremeta 2 no buffer ja que foi analizado 2 posicoes
					buffer+=2;
					goto final; //vai para final
				}

        //se for espaço (" ")
				else if(isspace(*buffer) && *buffer != '\n'){
            buffer++;
            goto q0; //volta para q0
        }
        
        //se for quebra de linha
        else if(*buffer == '\n' || *buffer=='\r' || *buffer == '\t'){
            //incremento do buffer e da linha
						buffer++;
            linha++;
						info_atomo.atomo = -1; //impede a duplicação dos prints
            goto final; //vai para final
        }

        //se for fim do arquivo
        else if(*buffer == '\0'){
            info_atomo.atomo = 5;
            goto final; //vai para final
				}

        //se nenhuma das opcoes acima
				else
					goto erro;
				

    q1:
        //se for letra ou numero
        if(isalpha(*buffer) || isdigit(*buffer)){
            info_atomo.atributo_ID[pos_atomo] = *buffer;
						//incremento do buffer e da posicao atual no atomo
            buffer++;
            pos_atomo++;
            goto q1; //vai para q1
        } 

        //se nenhuma das opcoes acima (fim da palavra)
        else
            goto res; //vai para res

		q2:
        //se for numero
				if(isdigit(*buffer)){
						num[pos_atomo] = *buffer;
            //incremento do buffer e da posicao atual no atomo
						buffer++;
						pos_atomo++;
						goto q2;//vai para q2
				}

        //se for letra
				else if(isalpha(*buffer)){
						goto erro; //vai para erro
				}

        //se nenhuma das opcoes acima
				else
					goto num; //vai para num
				
    
    res: //verifica se o identificador é uma palavra reservada
        if(strcasecmp(info_atomo.atributo_ID,"WHILE") == 0){
            info_atomo.atomo = 4;
        }
        else
            info_atomo.atomo = 1;
        goto final;

		num: //converte e salva como NUMERO_INTEIRO
				val = atoi(num);
				info_atomo.atributo_numero = val;
				info_atomo.atomo = 2;
				goto final;

    final:
    //retorna as infos obtidas sobre o atomo
        return info_atomo;

    erro:
    //retorna erro
        info_atomo.atomo = 0;
        return info_atomo;

}

void testaAnalisadorLexico(){
    //INICIO
		linha = 1; //atribui 1 a linha atual

    while(1){
        //atribui 0 a posicao atual a ser analisada no atomo
				pos_atomo = 0;

        //recupera as infos do atomo analisado
        TInfoAtomo info_atomo = obter_atomo(); 
        
        //se erro
        if(info_atomo.atomo == 0){
					printf("linha %d - ERRO\n", info_atomo.linha);
					break;
				}

        //se identificador
				else if(info_atomo.atomo == 1){
					printf("linha %d - IDENTIFICADOR - ", info_atomo.linha);
					for(int i=0; i<pos_atomo; i++)
						printf("%c", info_atomo.atributo_ID[i]);
						printf("\n");
				}

        //se NUMERO_INTEIRO
				else if(info_atomo.atomo == 2){
					printf("linha %d - NUMERO_INTEIRO - %d\n", info_atomo.linha,info_atomo.atributo_numero);
				}

        //se sinal de atribuicao
				else if(info_atomo.atomo == 3){
					printf("linha %d - ATRIBUICAO\n", info_atomo.linha);
				}

        //se palavra reservada (WHILE)
				else if(info_atomo.atomo == 4){
					printf("linha %d - WHILE\n", info_atomo.linha);
				}

        //se fim do arquivo
        else if(info_atomo.atomo == 5){  // fim de analise léxica
					printf("linha %d - FIM DE STRING (EOS)\n", info_atomo.linha);

          //sai do while
          break;
        }

    }
}



int main(void){
    FILE *fp_entrada;
    
    fp_entrada = fopen("entrada.txt", "r"); //abre o arquivo
    if(!fp_entrada){ //testa se abriu corretamente
        printf("erro na abertura do arquivo de entrada.\n");
        return 1;
    }

    fseek(fp_entrada, 0, SEEK_END); // move ponteiro do arquivo para o final
    long tamanho = ftell(fp_entrada); // conta a quantidade de bytes deslocados na movimentacao
    fseek(fp_entrada, 0, SEEK_SET); // move novamente para o inicio do arquivo
    buffer = (char*)calloc(tamanho+1,sizeof(char)); // aloca os memoria para guardar o arquivo lido
    fread(buffer, sizeof(char),tamanho,fp_entrada); // le de uma vez so o arquivo
    
    //funcao responsavel pela analise
    testaAnalisadorLexico();
    
    fclose(fp_entrada);//fecha arquivo
    return 0;
}

