/* 

Samuel Kenji Ochiai Gomes da Silva - 31817106
Luan Rocha Damato - 31817051

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // isdigit, isalpha
#include <string.h>
#include <stdbool.h>

char *buffer; // buffer lido
char *iniBuffer; // guarda o inicio do buffer para desalocar
int contaLinha=1; // faz a contagem de linha do programa

// constantes para os atomos do mini analisador léxico
typedef enum{
    ERRO,
    IDENTIFICADOR,
    NUMERO_INTEIRO,
    ATRIBUICAO,
    EOS,
		AND,
		BEGIN,
		BOOLEAN,
		CHAR,
		DO,
		ELSE,
		END,
		FALSE,
		IF,
		INTEGER,
		MOD,
		NOT,
		OR,
		PROGRAM,
		READ,
		REAL,
		THEN,
		TRUE,
		WRITE,
		WHILE,
		ABRE_PAR,
		FECHA_PAR,
		PONTO,
		PONTO_VIRGULA,
		SUBTRACAO,
		ADICAO,
		DIVISAO,
		MULTIPLICACAO,
		ME,
		MEI,
		IG,
		DI,
		MA,
		MAI,
		COMENTARIO,
		NUMERO_REAL,
		CARACTERE
}TAtomo;

// vetor de mensagems para o analisador lexico
char *strAtomo[] = {
    "ERRO LEXICO",
    "IDENTIFICADOR",
    "NUMERO_INTEIRO",
    "ATRIBUICAO",
    "END OF STRING",
		"AND",
		"BEGIN",
		"BOOLEAN",
		"CHAR",
		"DO",
		"ELSE",
		"END",
		"FALSE",
		"IF",
		"INTEGER",
		"MOD",
		"NOT",
		"OR",
		"PROGRAM",
		"READ",
		"REAL",
		"THEN",
		"TRUE",
		"WRITE",
		"WHILE",
		"ABRE_PAR",
		"FECHA_PAR",
		"PONTO",
		"PONTO_VIRGULA",
		"SUBTRACAO",
		"ADICAO",
		"DIVISAO",
		"MULTIPLICACAO",
		"MENOR QUE",
		"MENOR IGUAL A",
		"IGUAL A",
		"DIFERENTE DE",
		"MAIOR QUE",
		"MAIOR IGUAL A",
		"COMENTARIO",
		"NUMERO_REAL",
		"CARACTERE"
};

// estrutura para retornar as informações de um atomo (tokens)
typedef struct{
    TAtomo atomo;
    int linha;
    int atributo_numero;
    char numero_real[15];
    char atributo_ID[15];
		char comentario[100];
    char caractere[100];
}TInfoAtomo;

TInfoAtomo obter_atomo();
void reconhece_nuns(TInfoAtomo *infoAtomo);
int reconhece_ID(TInfoAtomo *infoAtomo);
void reconhece_com(TInfoAtomo *infoAtomo);
void reconhece_car(TInfoAtomo *infoAtomo);

int main(void){
    FILE *fp_entrada;
    TInfoAtomo infoAtomo;

    // abre o arquivo
    fp_entrada = fopen("teste.pas", "r");
    if(!fp_entrada){ // testa se abriu corretamente
        printf("erro na abertura do arquivo de entrada.\n");
        return 1;
    }
    // abertura e leitura de arquivo
    fseek(fp_entrada, 0, SEEK_END); // move ponteiro do arquivo para o final
    long tamanho = ftell(fp_entrada); // conta a quantidade de bytes deslocados na movimentacao
    fseek(fp_entrada, 0, SEEK_SET); // move novamente para o inicio do arquivo
    buffer = (char*)calloc(tamanho+1,sizeof(char)); // aloca os memoria para guardar o arquivo lido
    fread(buffer, sizeof(char),tamanho,fp_entrada); // le de uma vez so o arquivo
    fclose(fp_entrada); // fecha arquivo

    printf("%s",buffer);
    printf("\n------------------------------\n");

    while(1){
        infoAtomo = obter_atomo();
        printf("\nlinha %d | %s ", infoAtomo.linha,strAtomo[infoAtomo.atomo]);
        if( infoAtomo.atomo == NUMERO_INTEIRO )
            printf("| %d ", infoAtomo.atributo_numero);
        if( infoAtomo.atomo == NUMERO_REAL )
            printf("| %s ", infoAtomo.numero_real);
        if( infoAtomo.atomo == IDENTIFICADOR )
            printf("| %s ", infoAtomo.atributo_ID);
				if( infoAtomo.atomo == COMENTARIO )
            printf("| %s ", infoAtomo.comentario);
        if( infoAtomo.atomo == CARACTERE )
            printf("| %s ", infoAtomo.caractere);
        else if( infoAtomo.atomo == EOS || infoAtomo.atomo == ERRO ){
            break;
        }
    }
    printf("\nfim de analise lexica.\n");
    free(iniBuffer);
    return 0;
}
/*
A rotina obter_atomo() do mini analisador léxico retorna para cada átomo reconhecido uma codificação inteira (constante) para representar o
valor do átomo e o seu atributo, caso se faça necessário para o átomo.
*/
TInfoAtomo obter_atomo(){
    TInfoAtomo infoAtomo;

    // descarta carateres delimitadores
    while( *buffer == '\n' || *buffer == '\r' || *buffer == '\t' || *buffer == ' '){
        if( *buffer == '\n' )
            contaLinha++;
        buffer++;
    }

    infoAtomo.atomo = ERRO;
    infoAtomo.linha = contaLinha;
    // if(buffer[0] ==':' && buffer[1] =='=')
    if(*buffer ==':' && *(buffer+1) =='='){ // reconhece atribuicao
        buffer+=2; // incrementa o buffer duas posicoes
        infoAtomo.atomo = ATRIBUICAO;
    }
		else if(*buffer =='('){ // reconhece abre par
        buffer++; // incrementa o buffer
        infoAtomo.atomo = ABRE_PAR;
    }
		else if(*buffer ==')'){ // reconhece fecha par
        buffer++; // incrementa o buffer
        infoAtomo.atomo = FECHA_PAR;
    }
		else if(*buffer =='.'){ // reconhece ponto
        buffer++; // incrementa o buffer
        infoAtomo.atomo = PONTO;
    }
		else if(*buffer ==';'){ // reconhece ponto e virgula
        buffer++; // incrementa o buffer
        infoAtomo.atomo = PONTO_VIRGULA;
    }
		else if(*buffer =='-'){ // reconhece subtracao
        buffer++; // incrementa o buffer
        infoAtomo.atomo = SUBTRACAO;
    }
		else if(*buffer =='+'){ // reconhece adicao
        buffer++; // incrementa o buffer
        infoAtomo.atomo = ADICAO;
    }
		else if(*buffer =='/'){ // reconhece divisao
        buffer++; // incrementa o buffer
        infoAtomo.atomo = DIVISAO;
    }
		else if(*buffer =='*'){ // reconhece multiplicacao
        buffer++; // incrementa o buffer
        infoAtomo.atomo = MULTIPLICACAO;
    }
		else if(*buffer =='<'){ // reconhece menor
        buffer++; // incrementa o buffer
        infoAtomo.atomo = ME;
    }
		else if(*buffer =='<' && *(buffer+1) == '='){ // reconhece menor igual
        buffer+=2; // incrementa o buffer duas posicoes
        infoAtomo.atomo = MEI;
    }
		else if(*buffer =='='){ // reconhece igual
        buffer++; // incrementa o buffer
        infoAtomo.atomo = IG;
    }
		else if(*buffer =='!' && *(buffer+1) == '='){ // reconhece diferente
        buffer+=2; // incrementa o buffer duas posicoes
        infoAtomo.atomo = DI;
    }
		else if(*buffer =='>'){ // reconhece maior
        buffer++; // incrementa o buffer
        infoAtomo.atomo = MA;
    }
		else if(*buffer =='>' && *(buffer+1) == '='){ // reconhece maior igual
        buffer+=2; // incrementa o buffer duas posicoes
        infoAtomo.atomo = MAI;
    }
		else if(*buffer == '{' || *buffer == '#'){
				reconhece_com(&infoAtomo);
		}
    else if(*buffer == '\''){
				reconhece_car(&infoAtomo);
		}
    
    else if(isdigit(*buffer)){ // reconhece numero inteiro
        reconhece_nuns(&infoAtomo);
    }
    else if( isalpha(*buffer)){ // reconhece identificador
        int res = reconhece_ID(&infoAtomo);
				infoAtomo.atomo = res;
    }
    else if(*buffer == 0) // reconhece fim de string
        infoAtomo.atomo = EOS;

    return infoAtomo;

}

void reconhece_nuns(TInfoAtomo *infoAtomo){
    char *iniNum = buffer;
    bool inteiro = true;

    while( isdigit(*buffer))
        buffer++;

    if( *buffer == '.'){
      buffer++;
      if (isdigit(*buffer)){
        inteiro = false;
        buffer++;
        while( isdigit(*buffer))
          buffer++;
        if( isalpha(*buffer)){
          if (*buffer == 'e' || *buffer == 'E'){
            buffer++;
            if (isdigit(*buffer))
              buffer++;
            else return;
            while( isdigit(*buffer))
              buffer++;
            if( isalpha(*buffer))
              return;
          }
          else return;
        }
      }
     
      else return;
      
    } 
    else if( isalpha(*buffer)){
        return;
    }
        

    strncpy(infoAtomo->atributo_ID,iniNum,buffer-iniNum);
    infoAtomo->atributo_ID[buffer-iniNum]=0; // finalizador de string
    if (inteiro){
      infoAtomo->atributo_numero = atoi(infoAtomo->atributo_ID);
      infoAtomo->atomo = NUMERO_INTEIRO;
    }
    else{
      //infoAtomo->numero_real = strtof(infoAtomo->atributo_ID, NULL);
      strncpy(infoAtomo->numero_real,iniNum,buffer-iniNum);
      infoAtomo->numero_real[buffer-iniNum]=0; // finalizador de caractere
      infoAtomo->atomo = NUMERO_REAL;
    }
    

}

int reconhece_ID(TInfoAtomo *infoAtomo){
    char *iniID = buffer;

    while(isalpha(*buffer) || isdigit(*buffer))
        buffer++;

    strncpy(infoAtomo->atributo_ID,iniID,buffer-iniID);
    infoAtomo->atributo_ID[buffer-iniID]=0; // finalizador de string
		int tam = (int) (sizeof(strAtomo)/sizeof(strAtomo[0]));
		for(int i=0; i<tam; i++){
			if( strcasecmp(infoAtomo->atributo_ID,strAtomo[i])==0 )
				return i; //PALAVRA RESERVADA
		}
		return 1; //IDENTIFICADOR
}

void reconhece_com(TInfoAtomo *infoAtomo){
	char *iniCom = buffer;

	if(*buffer == '#'){
		while( *buffer != '\n' && *buffer != '\r' && *buffer != '\t' && *buffer != ' ' && *buffer != '\0' ){
			buffer++;
			
		}
		//contaLinha++;
		strncpy(infoAtomo->comentario,iniCom,buffer-iniCom);
    infoAtomo->comentario[buffer-iniCom]=0; // finalizador de comentario
		infoAtomo->atomo = COMENTARIO;
	}
	else if(*buffer == '{'){
		while( *buffer != '}'){
			buffer++;
      
      if( *buffer == '\n' )
          contaLinha++;
			if( *buffer == '\0')
				return;
		}
		buffer++;
		strncpy(infoAtomo->comentario,iniCom,buffer-iniCom);
    infoAtomo->comentario[buffer-iniCom]=0; // finalizador de comentario
		infoAtomo->atomo = COMENTARIO;
	}
}

void reconhece_car(TInfoAtomo *infoAtomo){
	char *iniCar = buffer;
  buffer++;
	//char aspas[10] = 039 + '0';

  while( *buffer != '\''){
    buffer++;
    if( *buffer == '\0')
      return;
    if( *buffer == '\n')
      return;
  }
  buffer++;
  strncpy(infoAtomo->caractere,iniCar,buffer-iniCar);
  infoAtomo->caractere[buffer-iniCar]=0; // finalizador de caractere
  infoAtomo->atomo = CARACTERE;
}