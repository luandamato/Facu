  
#include "matrizes.h"
#include <stdio.h>
#include <stdlib.h>

matriz **matriz1;
matriz **matriz2;

void main(int argc, char *argv[]) {
	printf("*********** Bem Vindo a Calculadora de Matrizes ***********\n");
	printf("\n");
	printf("Desenvolvido por: Anderson Schott\n\n");
	printf("ATENCAO: Este programa suporta realizar operacoes com matrizes de tamanho maximo 10x10 \n");
	
	menu();
}

void menu(){
	int opcao;
	
	printf("\n");
	printf("Escolha uma das opcoes para continuar:\n");
	printf("[1] - Igualdade entre matrizes (A = B)\n");
	printf("[2] - Adicao entre matrizes (A + B)\n");
	printf("[3] - Subtracao entre matrizes (A - B)\n");
	printf("[4] - Multiplicacao entre matrizes (A * B)\n");
	printf("[5] - Multiplicacao de um numero real por uma matriz (A * n)\n");
	printf("[6] - Matriz elevada a um número inteiro (An)\n");
	printf("[7] - Transposta de Matriz (At)\n");
	printf("[0] - Sair\n");
	printf("\n");
	printf("Informe a opcao desejada: ");
	scanf("%d",&opcao);
	
	switch (opcao){
        case 1: //Igualdade entre matrizes (A = B)
        	 system("cls");
    		 printf("Insira a Matriz 1:\n");
             matriz1 = recebeTeclado();
             printf("Insira a Matriz 2:\n");
             matriz2 = recebeTeclado();
             system("cls");
             printf("Matriz [1]\n");
             visualizaMatriz(matriz1);
             printf("Matriz [2]\n");
             visualizaMatriz(matriz2);
             char resultado;
             resultado = igualdade(matriz1,matriz2);
             if(resultado == 'T')
             	printf("Resultado:\n--> As matrizes sao IDENTICAS!\n\n");
             else
             	printf("Resultado:\n--> As matrizes sao DIFERENTES!\n\n");
             system("pause");
             system("cls");
             menu();
             break;
        case 2: //Adicao entre matrizes (A + B)
             system("cls");
    		 printf("Insira a Matriz 1:\n");
             matriz1 = recebeTeclado();
             printf("Insira a Matriz 2:\n");
             matriz2 = recebeTeclado();
             system("cls");
             printf("Matriz [1]\n");
             visualizaMatriz(matriz1);
             printf("Matriz [2]\n");
             visualizaMatriz(matriz2);
             matriz1 = somarMatrizes(matriz1,matriz2);
             printf("Resultado:\n");
             visualizaMatriz(matriz1);
             system("pause");
             system("cls");
             menu();
             break;
    	case 3: //Subtracao entre matrizes (A - B)   		
    		 system("cls");
    		 printf("Insira a Matriz 1:\n");
             matriz1 = recebeTeclado();
             printf("Insira a Matriz 2:\n");
             matriz2 = recebeTeclado();
             system("cls");
             printf("Matriz [1]\n");
             visualizaMatriz(matriz1);
             printf("Matriz [2]\n");
             visualizaMatriz(matriz2);
             matriz1 = subtrairMatrizes(matriz1,matriz2);
             printf("Resultado:\n");
             visualizaMatriz(matriz1);
             system("pause");
             system("cls");
             menu();
             break;
    	case 4: //Multiplicacao entre matrizes (A * B)
    		 system("cls");
    		 printf("Insira a Matriz 1:\n");
             matriz1 = recebeTeclado();
             printf("Insira a Matriz 2:\n");
             matriz2 = recebeTeclado();
             system("cls");
             printf("Matriz [1]\n");
             visualizaMatriz(matriz1);
             printf("Matriz [2]\n");
             visualizaMatriz(matriz2);
             matriz1 = multiplicaMatriz(matriz1,matriz2);
             printf("Resultado:\n");
             visualizaMatriz(matriz1);
             system("pause");
             system("cls");
             menu();
             break;
        case 5: //Multiplicacao de um numero real por uma matriz (A * n)
        	 system("cls");
    		 printf("Insira a Matriz 1:\n");
             matriz1 = recebeTeclado();
             printf("Insira um numero real:\n");
             int num;
			 scanf("%d",&num);
             system("cls");
             printf("Matriz [1]\n");
             visualizaMatriz(matriz1);             
             matriz1 = multiplicaEscalar(matriz1,num);
             printf("Resultado:\n");
             visualizaMatriz(matriz1);
             system("pause");
             system("cls");
             menu();
             break;
        case 6: //Matriz elevada a um número inteiro (An)
        	 system("cls");
    		 printf("Insira a Matriz 1:\n");
             matriz1 = recebeTeclado();
             system("cls");
             printf("Matriz [1]\n");
             visualizaMatriz(matriz1); 
              printf("Informe o expoente:\n");
			 float potencia;
			 scanf("%f",&potencia);            
             matriz1 = elevaMatriz(matriz1,potencia);
             printf("Resultado:\n");
             visualizaMatriz(matriz1);
             system("pause");
             system("cls");
             menu();
             break;
        case 7: //Transposta de Matriz (At)
        	 system("cls");
    		 printf("Insira a Matriz 1:\n");
             matriz1 = recebeTeclado();
             system("cls");
             printf("Matriz [1]\n");
             visualizaMatriz(matriz1);             
             matriz1 = transpor(matriz1);
             printf("Resultado:\n");
             visualizaMatriz(matriz1);
             system("pause");
             system("cls");
             menu();
             break;
        case 0: //Sair
        	system("cls");
        	printf("OBRIGADO por utilizar o sistema!:\n\n");
        	printf("Desenvolvido por: Anderson Schott\n\n");
        	system("exit");
        	break;
        default:
            system("cls");
            printf("OPCAO INVALIDA!!! \n\n");
            menu();
            break;
    }
}

//=== INICIO METODOS MANIPULACAO DE MATRIZES ===

matriz *recebeTeclado()
{
	int i,j,lin,col;
	matriz *m;

	printf("Numero de linhas: ");	
	scanf("%d",&lin);
	if(lin > 10)
	{
		system("cls");
		printf("\nDesculpe \nQuantidade de Linhas invalido. (Max: 10)\n");
		menu();
	}
	printf("Numero de colunas: ");
	scanf("%d",&col);
	if(col > 10)
	{
		system("cls");
		printf("\nDesculpe \nQuantidade de Colunas invalido. (Max: 10)\n");
		menu();
	}

	m=alocaMatriz(lin,col);

	m->linhas=lin;
	m->colunas=col;
	
	for(i=0;i<m->linhas;i++)
	{
		for(j=0;j<m->colunas;j++)
		{
			scanf("%f",&m->valores[i][j]);
		}
	}
	return m;
}

void visualizaMatriz(matriz *m)
{
	int i,j;
	
	printf("%d x ",m->linhas);
	printf("%d\n",m->colunas);

		for(i=0;i<m->linhas;i++)
		{
			printf("\n");
			for(j=0;j<m->colunas;j++)
				printf("%g ",m->valores[i][j]);
		}
		printf("\n");
}

matriz *alocaMatriz(int linhas,int colunas)
{
    matriz *mat;
    int i,j;
    
    mat=(matriz*)malloc(sizeof(matriz));
    
    if(mat==NULL)
     	return NULL;
     	
    mat->valores=(float**)malloc(linhas*sizeof(float*));
    
    if(mat->valores==NULL)
    {
		free(mat);
		return NULL;
    }
    
    for(i=0;i<linhas;i++)
    {
	     mat->valores[i]=(float*)malloc(colunas*sizeof(float));
	     if(mat->valores[i]==NULL)
	     {
		      for(j=i-1;j>=0;j--)
		      	free(mat->valores[j]);
		      free(mat->valores);
		      free(mat);
		      return NULL;	                              
	     }
    }
    return mat;
}

matriz *multiplicaMatriz(matriz* m1, matriz* m2)
{
	matriz *result;
	int i,j,k;

	result = alocaMatriz(m1->linhas, m2->colunas);	

	if(m1->colunas != m2->linhas)
	{	
		result->linhas=0;		
		result->colunas=0;
		return result;
	}
	
	for(i=0;i<m1->linhas;i++)
	{
		for(j=0;j<m2->colunas;j++)
		{
			result->valores[i][j] = 0;
	
			for(k=0;k<m1->colunas;k++)
				result->valores[i][j] = result->valores[i][j] + m1->valores[i][k]  * m2->valores[k][j];

		}
	}

	result->linhas = m1->linhas;
	result->colunas = m2->colunas;
	return result;
}

void somarMatrizes(matriz* m1, matriz* m2)
 {
	matriz *result;

	result = alocaMatriz(m1->linhas, m2->colunas);	

	if(m1->colunas != m2->linhas)
	{	
		result->linhas=0;		
		result->colunas=0;
		return result;
	}
	
     int i, j, k;
     for (i=0;i<m1->linhas;i++)
     {
         for (j=0;j<m2->colunas;j++) 
         	result->valores[i][j] = m1->valores[i][j]  + m2->valores[i][j];
	}
	
	result->linhas = m1->linhas;
	result->colunas = m2->colunas;
	return result;	 	
 }

void subtrairMatrizes(matriz* m1, matriz* m2)
 {
	matriz *result;

	result = alocaMatriz(m1->linhas, m2->colunas);	

	if(m1->colunas != m2->linhas)
	{	
		result->linhas=0;		
		result->colunas=0;
		return result;
	}
	
     int i, j, k;
     for (i=0;i<m1->linhas;i++)
     {
         for (j=0;j<m2->colunas;j++) 
         	result->valores[i][j] = m1->valores[i][j]  - m2->valores[i][j];
	}
	
	result->linhas = m1->linhas;
	result->colunas = m2->colunas;
	return result;	 	
 }

matriz *multiplicaEscalar(matriz *m,int k)
{
    matriz *resultado;
    int i,j;
    
    resultado=alocaMatriz(m->linhas,m->colunas);
    
    if(resultado==NULL)
    {
                         return NULL;
    }
    
    resultado->linhas=m->linhas;
    resultado->colunas=m->colunas;
    
    if(k==0)
            return resultado;
    
    for(i=0;i<(resultado->linhas);i++)
    {
      for(j=0;j<(resultado->colunas);j++)
          {
            resultado->valores[i][j]=m->valores[i][j]*k;               
          }
    }
    return resultado;
}

matriz *transpor(matriz *m)
{
    matriz *transposta;
    int i,j;
    
    transposta=alocaMatriz(m->linhas,m->colunas);
    
    if(transposta==NULL)
    {
    	return NULL;
    }
    
    transposta->linhas=m->linhas;
    transposta->colunas=m->colunas;
    
    for(i=0;i<(transposta->linhas);i++)
    {
		for(j=0;j<(transposta->colunas);j++)
        	transposta->valores[i][j]=m->valores[j][i];
    }
    return transposta;
}

matriz *elevaMatriz(matriz *m, float potencia) 
 { 
	int i, j;
	float r,b;
	for (i=0;i<m->linhas;i++)
	{
		for (j=0;j<m->colunas;j++) 
		{
		 	b = m->valores[i][j];
		 	r = (pow(b,potencia));
		 	m->valores[i][j] = r;
		 }
	} 	
	return m;	 
 } 
 
 char *igualdade(matriz *m1, matriz *m2)
 {
 	char retorno = 'F';
 	
 	if((m1->colunas != m2->colunas) || (m1->linhas != m2->linhas))
 		return 'F';
 		
 	int i,j;	
 	for(i=0;i<m1->linhas;i++)
 	{
 		for(j=0;j<m1->colunas;j++)
 		{
 			if(m1->valores[i][j] == m2->valores[i][j])
 				retorno = 'T';
 			else
 				retorno = 'F';
		}
	}	
	return retorno;
 }