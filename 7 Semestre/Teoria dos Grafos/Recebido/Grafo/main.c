/* 
 * REPRESENTACAO DE GRAFOS - Versao 2020/2
  Membros:
  João Vitor Ribeiro Pessini - 31820999
	Samuel Kenji - 31817106
  Zewu Chen - 31808751

 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <memory.h>

#define _BRANCO_  0
#define _CINZA_   1
#define _PRETO_   2


/* 
 * Estrutura de dados para representar grafos
 */
typedef struct a{ /* Celula de uma lista de arestas */
	int    nome;
	struct a *prox;
}Aresta;

typedef struct vert{  /* Cada vertice tem um ponteiro para uma lista de arestas incidentes nele */
	int nome;
	int dist;
	int cor;
	Aresta *prim;
}Vertice;

/*
 * Declaracoes das funcoes para manipulacao de grafos 
 */
void criaGrafo(Vertice **G, int ordem);
void destroiGrafo(Vertice **G, int ordem);
int  acrescentaAresta(Vertice G[], int ordem, int v1, int v2);
int  calculaTamanho(Vertice G[], int ordem);
void imprimeGrafo(Vertice G[], int ordem);

/* Novas fun��es: */
Vertice *calculaComplemento(Vertice G[], int ordem);
int	grauMinimo(Vertice G[], int ordem);  /* EXERCICIO */
int	grauMaximo(Vertice G[], int ordem);  /* EXERCICIO */
int	eRegular(Vertice G[], int ordem);    /* EXERCICIO */
int	eSimples(Vertice G[], int ordem);    /* EXERCICIO */
void calculaDistancia(Vertice G[], int ordem, int vi);
void eConexo(Vertice G[], int ordem);

/*
 * Implementacao das funcoes para manipulacao de grafos 
 */
 
/*
 * Criacao de um grafo com ordem predefinida (passada como argumento),
 *   e, inicilamente, sem nenhuma aresta 
 */
void criaGrafo(Vertice **G, int ordem){
	int i;
	*G= (Vertice*) malloc(sizeof(Vertice)*ordem); /* Alca�ao dinamica de um vetor de vertices */
	
	for(i=0; i<ordem; i++){
		(*G)[i].nome= i;
		(*G)[i].dist= -1;      /* representa INFINITO */
		(*G)[i].cor= _BRANCO_; /* representa nao manipulado*/
		(*G)[i].prim= NULL;    /* Cada vertice sem nenua aresta incidente */
	}
}

/*
 * Deasaloca a memoria dinamica usada para armazenar um grafo.
 */
void destroiGrafo(Vertice **G, int ordem){
	int i;
    Aresta *a, *n;
    
	for(i=0; i<ordem; i++){ /* Remove lista de adjacencia de cada v�rtice */
	    a= (*G)[i].prim;
        while (a!= NULL){
              n= a->prox;
              free(a);
              a= n;
        }
	}
    free(*G);
}

/*  
 * Acrescenta uma nova aresta em um grafo previamente criado. 
 *   Devem ser passados os extremos v1 e v2 da aresta a ser acrescentada 
 * Como o grafo n�o � orientado, para uma aresta com extremos i e j
 *   ser�o criadas, na estrutura de dados, arestas (i,j) e (j,i)
 */
int acrescentaAresta(Vertice G[], int ordem, int v1, int v2){
    Aresta * A1, *A2;
    
	if (v1<0 || v1 >= ordem) /* Testo se v�rtices sao validos */
	   return 0;
	if (v2<0 || v2 >= ordem)
	   return 0;
	
	/* Acrescento aresta na lista do vertice v1 */
	A1= (Aresta *) malloc(sizeof(Aresta));
	A1->nome= v2;
	A1->prox= G[v1].prim;
	G[v1].prim= A1;

	/* Acrescento aresta na lista do vertice v2 se v2 != v1 */
	if (v1 == v2) return 1;
	
	A2= (Aresta *) malloc(sizeof(Aresta));
	A2->nome= v1;
	A2->prox= G[v2].prim;
	G[v2].prim= A2;
	
	return 1;
}

/*  
 * Funcao que retorna o tamanho de um grafo
 */
int  calculaTamanho(Vertice G[], int ordem){
	int i;
	int totalArestas=0;

	for (i=0; i<ordem; i++){
		int j;
		Aresta *aux= G[i].prim;
		for(j=0; aux != NULL; aux= aux->prox, j++)
            if (aux->nome == i) j++; /* laco "conta em dobro" */
		totalArestas += j;	
	}
	return totalArestas/2 + ordem;
}

void calculaDistancia(Vertice G[], int ordem, int vi){
	int i,j;
	int d = 0;
	Aresta *aux= G[i].prim;

	for(i=0; i<ordem; i++){// atribui valores no atributo de distancia 
		if(i == vi)
			G[i].dist = 0;
		else
			G[i].dist = -1;
	}

	for(i=0; i<ordem; i++) {
		for(j=0; j<ordem; j++){
      Aresta *aux= G[j].prim;
			for(; aux != NULL; aux=aux->prox){
        int x = aux->nome;
				if(G[j].dist == -1 && G[x].dist == d){
          G[j].dist = d+1;
        }
			}
		}
    d++;
	}
}

void eConexo(Vertice G[], int ordem){
	int i;
	for(i=0; i<ordem; i++){
		if(G[i].dist == -1){ //Caso haja um vértice que não possui aresta, o grafo é desconexo
			printf("O grafo é desconexo\n");
			return;
		}
	}
	printf("O grafo é conexo\n");
}

/*  
 * Imprime um grafo com uma nota��o similar a uma lista de adjac�ncia.
 */
void imprimeGrafo(Vertice G[], int ordem){
	int i;
	Aresta *aux;
	char * cores[]= { "BRANCO", "CINZA " , "PRETO " };

	printf("\nOrdem:   %d",ordem);
	printf("\nTamanho: %d",calculaTamanho(G, ordem));
	printf("\nLista de Adjacencia:\n");

	for (i=0; i<ordem; i++){
		printf("\n    V%d (Distancia:%2d  Cor:%s): ", i, G[i].dist, cores[G[i].cor]);
		aux= G[i].prim;
		for( ; aux != NULL; aux= aux->prox)
			printf("%3d", aux->nome);
	}
	printf("\n\n");
}

/*
 * Programinha simples para testar a representacao de grafo
 */
int main(int argc, char *argv[]) {
	Vertice *G;
	int ordemG= 6;
	
	Vertice *C;	
	int ordemC;
		
	criaGrafo(&G, ordemG);
	/* acrescentaAresta(G,ordemG,0,0); */
	acrescentaAresta(G,ordemG,3,4);
	acrescentaAresta(G,ordemG,4,3);
	acrescentaAresta(G,ordemG,4,2);
	acrescentaAresta(G,ordemG,5,4);
	acrescentaAresta(G,ordemG,2,3);
	acrescentaAresta(G,ordemG,3,0);
  
	calculaDistancia(G,ordemG,0);// chama a função para determinar a distancia a partir do vertice 0

	imprimeGrafo(G, ordemG);
	eConexo(G, ordemG);
    
	destroiGrafo(&G, ordemG);
  system("PAUSE");
	return 0;
}