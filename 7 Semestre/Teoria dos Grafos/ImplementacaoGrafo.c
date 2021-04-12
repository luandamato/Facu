

/* 
Raphael Prandini Thome de Abrantes 31828728
Luan Rocha Damato - 31817051
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <memory.h>



typedef struct a{
	int    nome;
	struct a *prox;
}Aresta;

typedef struct vert{  
	int nome;
	int marca;
  int distancia;
	Aresta *prim;
}Vertice;

void criaGrafo(Vertice **G, int ordem);
void destroiGrafo(Vertice **G, int ordem);
int  acrescentaAresta(Vertice G[], int ordem, int v1, int v2);
int  calculaTamanho(Vertice G[], int ordem);
void imprimeGrafo(Vertice G[], int ordem);
int isArvore(Vertice G[], int ordem);

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
    (*G)[i].distancia= -1;
		(*G)[i].marca= 0; /* representa nao manipulado*/
		(*G)[i].prim= NULL;    /* Cada vertice sem nenua aresta incidente */
	}
}

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


void imprimeGrafo(Vertice G[], int ordem){
	int i;
	Aresta *aux;

	printf("\nOrdem:   %d",ordem);
	printf("\nLista de Adjacencia:\n");

	for (i=0; i<ordem; i++){
		printf("\n    V%d (Marca:%d): ", i, G[i].marca);
		aux= G[i].prim;
		for( ; aux != NULL; aux= aux->prox)
			printf("%3d", aux->nome);
	}
	printf("\n\n");
}

int eConexo(Vertice G[], int ordem){
    int i;
	Aresta *aux;
	G[0].marca = 1;

    for (i=0; i<ordem; i++){
		if (G[i].prim == NULL) return 0;
		aux= G[i].prim;
		// printf("\n   analisando %d", i);
		// printf(" vendo %d:", aux->nome);
		if (G[aux->nome].marca == 1 && i < ordem - 1){
			//printf (" Ja marcado como 1");
			return 0;
		} 
		G[aux->nome].marca = 1;
		//printf(" V%d marcado como 1 ", aux->nome);
            
	}

    for (i=0; i<ordem; i++){
		if(G[i].marca == 0)
            return 0;
	}
    return 1;
}




int main(int argc, char *argv[]) {
	Vertice *G;
	int ordemG= 6;
		
	criaGrafo(&G, ordemG);
	acrescentaAresta(G,ordemG,0,1);
	acrescentaAresta(G,ordemG,0,2);
    acrescentaAresta(G,ordemG,1,2);
	acrescentaAresta(G,ordemG,2,3);
    acrescentaAresta(G,ordemG,3,4);
    acrescentaAresta(G,ordemG,4,5);

	imprimeGrafo(G, ordemG);
    if(eConexo(G, ordemG) ){
        printf("\no Grafo é uma árvore\n\n");
    }
    else{
        printf("\no Grafo não é uma árvore\n\n");
    }

    
	destroiGrafo(&G, ordemG);
    system("");
	return 0;
}
