/* 
 * BUSCA EM GRAFOS - Versao 2020/2
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
	int tIni;
	int tFim;
	int cor;
	Aresta *prim;
}Vertice;

/*
 * Declaracoes das funcoes para manipulacao de grafos 
 */
void criaGrafo(Vertice **G, int ordem);
void destroiGrafo(Vertice **G, int ordem);
int  acrescentaAresta(Vertice G[], int ordem, int v1, int v2);
void imprimeGrafo(Vertice G[], int ordem);

/* Novas fun��es: */
void buscaProf(Vertice G[], int ordem);
int buscaProf_Visit(Vertice G[], int vi, int tempo);
 
/*
 * Criacao de um grafo com ordem predefinida (passada como argumento),
 *   e, inicilamente, sem nenhuma aresta 
 */
void criaGrafo(Vertice **G, int ordem){
	int i;
	*G= (Vertice*) malloc(sizeof(Vertice)*ordem); /* Alocaçao dinamica de um vetor de vertices */
	
	for(i=0; i<ordem; i++){
		(*G)[i].nome= i;
		(*G)[i].dist= -1;      /* representa INFINITO */
		(*G)[i].tIni= -1;      
		(*G)[i].tFim= -1;      
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
 * Como o grafo é orientado, para uma aresta com extremos i e j
 *   serão criadas, na estrutura de dados, arestas (i,j)
 */
int acrescentaAresta(Vertice G[], int ordem, int v1, int v2){
    Aresta * A1, *A2;
    
	if (v1<0 || v1 >= ordem) /* Testo se vértices sao validos */
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
	
	/* A2= (Aresta *) malloc(sizeof(Aresta));
	A2->nome= v1;
	A2->prox= G[v2].prim;
	G[v2].prim= A2; */
	
	return 1;
}

void buscaProf(Vertice G[], int ordem){
	int i, tempo;

	for(i=0; i<ordem; i++){
		G[i].cor = 0;
		G[i].tIni = 0;
		G[i].tFim = 0;
	}

	tempo = 0;
	for(i=0; i<ordem; i++){
		if(G[i].cor == 0){
			tempo = buscaProf_Visit(G, i, tempo);
		}
	}

	imprimeGrafo(G, ordem);
}

int buscaProf_Visit(Vertice G[], int vi, int tempo){
	Aresta *aux;
	tempo = tempo + 1;
	G[vi].tIni = tempo;
	G[vi].cor = 1;

	aux= G[vi].prim;
	for( ; aux != NULL; aux= aux->prox){
		if(G[aux->nome].cor == 0){
			tempo = buscaProf_Visit(G, aux->nome, tempo);
		}
	}

	G[vi].cor = 2;
	tempo = tempo + 1;
	G[vi].tFim = tempo;

	return tempo;
}

/*  
 * Imprime um grafo com uma nota��o similar a uma lista de adjac�ncia.
 */
void imprimeGrafo(Vertice G[], int ordem){
	int i;
	Aresta *aux;
	char * cores[]= { "BRANCO", "CINZA " , "PRETO " };

	printf("\nOrdem:   %d",ordem);
	printf("\nLista de Adjacencia:\n");

	for (i=0; i<ordem; i++){
		printf("\n    V%d (Tempo Inicial:%2d	Tempo Final:%2d  Cor:%s): ", i, G[i].tIni, G[i].tFim, cores[G[i].cor]);
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
	acrescentaAresta(G,ordemG,0,3);
	acrescentaAresta(G,ordemG,0,1);
	acrescentaAresta(G,ordemG,1,4);
	acrescentaAresta(G,ordemG,2,4);
	acrescentaAresta(G,ordemG,2,5);
	acrescentaAresta(G,ordemG,3,1);
	acrescentaAresta(G,ordemG,4,3);
	acrescentaAresta(G,ordemG,5,5);
  
	buscaProf(G, ordemG);

	//imprimeGrafo(G, ordemG);
    
	destroiGrafo(&G, ordemG);
  system("PAUSE");
	return 0;
}