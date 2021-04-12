#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <memory.h>

#define _BRANCO_ 0
#define _CINZA_ 1
#define _PRETO_ 2

/* Estrutura de dados para representar grafos*/
typedef struct a
{ /* Celula de uma lista de arestas */
	int nome;
	struct a *prox;
} Aresta;

/* Cada vertice tem um ponteiro para uma lista de arestas incidentes nele */
typedef struct vert
{
	int nome;
	int dist;
	int cor;
	Aresta *prim;
} Vertice;

/*Declaracoes das funcoes para manipulacao de grafos */
void criaGrafo(Vertice **G, int ordem);
void destroiGrafo(Vertice **G, int ordem);
int acrescentaAresta(Vertice G[], int ordem, int v1, int v2);
int calculaTamanho(Vertice G[], int ordem);
void imprimeGrafo(Vertice G[], int ordem);

/*Novas funcoes*/
Vertice *calculaComplemento(Vertice G[], int ordem);
int grauMinimo(Vertice G[], int ordem); /* EXERCICIO */
int grauMaximo(Vertice G[], int ordem); /* EXERCICIO */
int eRegular(Vertice G[], int ordem);	/* EXERCICIO */
int eSimples(Vertice G[], int ordem);	/* EXERCICIO */
int calculaDistancia(Vertice G[], int ordem, int vi);

/*Implementacao das funcoes para manipulacao de grafos*/

/*Criacao de um grafo com ordem predefinida (passada como argumento), e, inicialmente, sem arestas*/
void criaGrafo(Vertice **G, int ordem)
{
	int i;
	/* Alocacao dinamica de um vetor de vertices*/
	*G = (Vertice *)malloc(sizeof(Vertice) * ordem);

	for (i = 0; i < ordem; i++)
	{
		(*G)[i].nome = i;
		/*Representa INFINITO */
		(*G)[i].dist = -1;
		/*Representa nao manipulado*/
		(*G)[i].cor = _BRANCO_;
		/*Cada vertice sem aresta incidente*/
		(*G)[i].prim = NULL;
	}
}

/*Desaloca a memoria dinamica usada para armazenar um grafo.*/
void destroiGrafo(Vertice **G, int ordem)
{
	int i;
	Aresta *a, *n;
	/*Remove lista de adjacencia de cada vertice*/
	for (i = 0; i < ordem; i++)
	{
		a = (*G)[i].prim;
		while (a != NULL)
		{
			n = a->prox;
			free(a);
			a = n;
		}
	}
	free(*G);
}

/*Acrescenta uma nova aresta em um grafo previamente criado. 
  Devem ser passados os extremos v1 e v2 da aresta a ser acrescentada 
  Como o grafo nao e orientado, para uma aresta com extremos i e j
  serao criadas, na estrutura de dados, arestas (i,j) e (j,i)*/
int acrescentaAresta(Vertice G[], int ordem, int v1, int v2)
{
	Aresta *A1, *A2;

	/*Teste se os vertices sao validos */
	if (v1 < 0 || v1 >= ordem)
		return 0;
	if (v2 < 0 || v2 >= ordem)
		return 0;

	/*Acrescentando aresta na lista do vertice v1*/
	A1 = (Aresta *)malloc(sizeof(Aresta));
	A1->nome = v2;
	A1->prox = G[v1].prim;
	G[v1].prim = A1;

	/* Acrescentando aresta na lista do vertice v2 se v2 != v1 */
	if (v1 == v2)
		return 1;

	A2 = (Aresta *)malloc(sizeof(Aresta));
	A2->nome = v1;
	A2->prox = G[v2].prim;
	G[v2].prim = A2;

	return 1;
}

/*Funcao que retorna o tamanho de um grafo*/
int calculaTamanho(Vertice G[], int ordem)
{
	int i;
	int totalArestas = 0;

	for (i = 0; i < ordem; i++)
	{
		int j;
		Aresta *aux = G[i].prim;
		for (j = 0; aux != NULL; aux = aux->prox, j++)
		{
			/*Laco "conta em dobro"*/
			if (aux->nome == i)
				j++;
		}
		totalArestas += j;
	}
	return totalArestas / 2 + ordem;
}

/*Imprime um grafo com uma notacaoo similar a uma lista de adjacencia.*/
void imprimeGrafo(Vertice G[], int ordem)
{
	int i;
	Aresta *aux;
	char *cores[] = {"BRANCO", "CINZA", "PRETO"};

	printf("\nOrdem:   %d", ordem);
	printf("\nTamanho: %d", calculaTamanho(G, ordem));
	printf("\nLista de Adjacencia:\n");

	for (i = 0; i < ordem; i++)
	{
		printf("\n    V%d (Distancia:%2d  Cor:%s): ", i, G[i].dist, cores[G[i].cor]);
		aux = G[i].prim;
		for (; aux != NULL; aux = aux->prox)
		{
			printf("%3d", aux->nome);
		}
	}
	printf("\n\n");
}

/*Funcao auxiliar que recebe um grafo como argumento e um dado vertice e retorna o grau do vertice.*/
int calculaGrauVertice(Vertice G[], int ordem, int v)
{
	/*Exercicio*/
	int grauVertice = 0;
	Aresta *aux = G[v].prim;
	if (v > ordem || v < 0)
		return -1;
	for (; aux != NULL; aux = aux->prox)
		grauVertice++;
	return grauVertice;
}

/*Funcao que recebe um grafo como argumento e retorna o menor grau dentre os graus dos vertices do grafo.*/
int grauMinimo(Vertice G[], int ordem)
{
	/*Exercicio*/
	int i, grauMin, temp;
	if (ordem > 0)
		grauMin = calculaGrauVertice(G, ordem, 0);
	else
		return -1;
	for (i = 1; i < ordem; ++i)
	{
		temp = calculaGrauVertice(G, ordem, i);
		if (temp < grauMin)
			grauMin = temp;
	}
	return grauMin;
}
/*Funcao que recebe um grafo como argumento e retorna o menor grau dentre os graus dos vertices do grafo.*/
int grauMaximo(Vertice G[], int ordem)
{
	/*Exercicio*/
	int i, grauMax, temp;
	if (ordem > 0)
		grauMax = calculaGrauVertice(G, ordem, 0);
	else
		return -1;
	for (i = 1; i < ordem; ++i)
	{
		temp = calculaGrauVertice(G, ordem, i);
		if (temp > grauMax)
			grauMax = temp;
	}
	return grauMax;
}

/*Funcao que recebe um grafo como argumento e retorna 1 se o grafo for regular e 0 caso contrario*/
int eRegular(Vertice G[], int ordem)
{
	/*Exercicio*/
}

/*Funcao que recebe um grafo como argumento e retorna 1 se o grafo for simples e 0 caso contrario*/
int eSimples(Vertice G[], int ordem)
{
	/*Exercicio*/
}

int calculaDistancia(Vertice G[], int ordemG, int vi)
{
	if (vi > ordemG || vi < 0)
	{
		return -1;
	}
	else
	{
		G[vi].dist = 0;
		int i, d = 0;
		while (G[i])
	}
}

/*Main para testar a representacao de grafo*/
int main(int argc, char *argv[])
{
	Vertice *G;
	int ordemG = 6;

	Vertice *C;
	int ordemC;

	criaGrafo(&G, ordemG);
	/* acrescentaAresta(G,ordemG,0,0); */
	acrescentaAresta(G, ordemG, 0, 1);
	acrescentaAresta(G, ordemG, 0, 3);
	acrescentaAresta(G, ordemG, 1, 2);
	acrescentaAresta(G, ordemG, 1, 3);
	acrescentaAresta(G, ordemG, 1, 4);
	acrescentaAresta(G, ordemG, 1, 5);
	acrescentaAresta(G, ordemG, 2, 4);
	acrescentaAresta(G, ordemG, 4, 5);

	imprimeGrafo(G, ordemG);

	fprintf(stdout, "%d\n", calculaGrauVertice(G, ordemG, 0));
	fprintf(stdout, "%d\n", calculaGrauVertice(G, ordemG, 1));
	fprintf(stdout, "%d\n", calculaGrauVertice(G, ordemG, 2));
	fprintf(stdout, "%d\n", calculaGrauVertice(G, ordemG, 3));
	fprintf(stdout, "%d\n", calculaGrauVertice(G, ordemG, 4));
	fprintf(stdout, "%d\n", calculaGrauVertice(G, ordemG, 5));
	puts(" ");
	fprintf(stdout, "Min = %d\n", grauMinimo(G, ordemG));
	fprintf(stdout, "Max = %d\n", grauMaximo(G, ordemG));
	calculaDistancia(G, ordemG, 2);

	/*destroiGrafo(&G, ordemG);*/
	/*system("PAUSE");*/
	return 0;
}