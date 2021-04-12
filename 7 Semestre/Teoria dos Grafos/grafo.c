/* 
 * REPRESENTACAO DE GRAFOS - VersAO 2020
 * 
 * Bruno Fiore Negreiros - 31700713
 * Guilherme Araujo Sette - 41783441
 * Luiz Henrique Monteiro de Carvalho - 41719468
 * 
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
typedef struct aresta{ /* Celula de uma lista de arestas */
	int nome;
	struct aresta *prox;
}Aresta;

typedef struct vert{  /* Cada vertice tem um ponteiro para uma lista de arestas incidentes nele */
	int nome;
	int distancia;
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
int      grauMinimo(Vertice G[], int ordem);  /* EXERCICIO */
int      grauMaximo(Vertice G[], int ordem);  /* EXERCICIO */
int      eRegular(Vertice G[], int ordem);    /* EXERCICIO */
int      eSimples(Vertice G[], int ordem);    /* EXERCICIO */

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
		(*G)[i].distancia= -1; /* representa INFINITO */
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

	/* Acrescento aresta na lista do vertice v2 */
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
		for(j=0; aux != NULL; aux= aux->prox, j++);
		totalArestas += j;	
	}
	return totalArestas/2 + ordem;
}

int eConexo(Vertice G[], int ordem) {
  int d = 0;
  Aresta  *aux;
  int i;

  if (G[0].prim == NULL) //Aqui verifico se o primeiro vertice e desconexo do grafo ou nao
    {
    return 0;
    }
  i = 0;

  while (i < ordem) // laco que acontece ate a distancia ser calculada
  {
    aux= G[i].prim;
    
    d++;
    for( ; aux != NULL; aux= aux->prox) {
      if (G[aux->nome].distancia == -1) // Adiciona a distancia ao vertice que ainda nao foi calculado
      {
        G[aux->nome].distancia = d;
      }  
    }
    i++; // Passa para o proximo vertice
  }

  for (i = 0; i < ordem; i++) {
    if (G[i].distancia == -1) {
      return 0;
    }
  }
  return 1;
}

int calculaDistancia(Vertice G[], int ordem, int vOrigem, int vDestino) {
  int auxOrdena;
  if (vOrigem > vDestino) // Coloca a origem -> destino na ordem crescente
  {
    auxOrdena = vOrigem;
    vOrigem = vDestino;
    vDestino = auxOrdena;
  }
  if (vDestino > ordem)
  {
    printf("\nVertice ultrapassa ordem do grafo - Distancia = %d", -1);
    return -1;
  }
  int d = 0;
  Aresta  *aux;
  int i;
  G[vOrigem].distancia = 0;
  aux= G[vOrigem].prim;
  i = vOrigem;
  aux= G[i].prim;
  if (!eConexo(G, ordem)) // Verifica se o grafo é conexo se nao for, retorna -1
  {
    printf("\nGrafo  desconexo - Distancia v%d -> v%d = %d",vOrigem, vDestino, G[vDestino].distancia);
    return -1;
  }
  
  for( ; aux != NULL; aux= aux->prox) { // Seta como 1 a distancia dos vertices adjacentes ao original
        G[aux->nome].distancia = 1;
    }
  i = 0;
  while (G[vDestino].distancia < 0 || i < ordem) // laco que acontece ate a distancia ser calculada
  {
    aux= G[i].prim;
    d++;
    for( ; aux != NULL; aux= aux->prox) {
      if (G[aux->nome].distancia == -1) // Adiciona a distancia ao vertice que ainda nao foi calculado
      {
        G[aux->nome].distancia = d;
      }  
    }
    i++; // Passa para o proximo vertice
  }
  printf("\nDistancia v%d -> v%d = %d",vOrigem, vDestino, G[vDestino].distancia);
  return G[vDestino].distancia;
}

/*  
 * Imprime um grafo co  uma nota��o similar a uma lista de adjac�ncia.
 */
void imprimeGrafo(Vertice G[], int ordem){
	int i;
	Aresta *aux;
	char * cores[]= { "BRANCO", "CINZA " , "PRETO " };

	printf("\nOrdem:   %d",ordem);
	printf("\nTamanho: %d",calculaTamanho(G, ordem));
  printf("\nGrau minimo: %d",grauMinimo(G, ordem));
  printf("\nGrau maximo: %d",grauMaximo(G, ordem));
  /*EXECUCAO DA FUNCAO QUE CALCULA A DISTANCIA*/
  calculaDistancia(G, ordem, 0, 5);
  /*EXECUCAO DA FUNCAO QUE VERIFICA SE O GRAFO EH CONEXO*/
  printf("\nConexo? %d",eConexo(G, ordem));
	printf("\nLista de Adjacencia:\n");

	for (i=0; i<ordem; i++){
		printf("\n    V%d (Distancia:%2d  Cor:%s): ", i, G[i].distancia, cores[G[i].cor]);
		aux= G[i].prim;
		for( ; aux != NULL; aux= aux->prox)
			printf("%3d", aux->nome);
	}
	printf("\n\n");
}

/*
 * Fun��o que recebe um grafo como argumento e, se tal grafo for simples,
 *   retorna seu complemento. Se o grafo nao for simples, retorna NULL.
 * Precisa implemntar a funcao eSimples, que esta retornando sempre 1
 *   para permitir a execucao desta funcao.
 */
Vertice *calculaComplemento(Vertice G[], int ordem){
    int i, j;
	Aresta  *aux;
    Vertice *Compl;
    int *iAdj; /* Vetor que marcara� todos os v�rtices adjacentes ao vertice i */
    
    if (!eSimples(G, ordem))   /* Grafo deve ser simples */
         return NULL;
         
    criaGrafo(&Compl, ordem);  /* Crio um grafo de mesma ordem */
    iAdj= (int*)malloc(sizeof(int)*ordem);

	for (i=0; i<ordem; i++){
        for (j=0; j<ordem; j++) iAdj[j]=0; /* Inicializo vetor de adjacentes a i */
        iAdj[i]=1;             /* marco o pr�prio i para nao gerar laco*/
        
		aux= G[i].prim;        /* anoto os v�rtices adjacentes a i */
		for( ; aux != NULL; aux= aux->prox)
			iAdj[aux->nome]=1;
			
        /* crio arestas para os nao-adjacentes a i */
        for (j=0; j<ordem; j++){
            if (iAdj[j] == 0){         /* se i nao e� adjacente a j em G... */
               aux= (Aresta *) malloc(sizeof(Aresta)); /* crio aresta (i,j) */
               aux->nome= j;                           /*    no complemento */
               aux->prox= Compl[i].prim;
               Compl[i].prim= aux;
            }
        }
			
	}
    free(iAdj);
    return Compl;
}


// Verifica se tem arestas duplicadas
// Testando se existem vertices repetidos na representação
int duplicado (Aresta *aux, int vertice){
  int quantidade = 0;
  for( ; aux != NULL; aux= aux->prox) {
    if (vertice == aux->nome)
    {
      quantidade++;
    }
    if (quantidade >= 2)
    {
      return 1;
    }
  }
  return 0;
}

/*
 * Fun��o que recebe um grafo como argumento e retorna o menor grau dentre
 *   os graus dos v�rtices do grafo.
 */
int grauMinimo(Vertice G[], int ordem){
  int min = 100;
  int numero_vertices;
  Aresta  *aux;
  int i;
  for (i = 0; i < ordem; i++) {// Laco que passa por cada vertice do grafo
    aux= G[i].prim;
    numero_vertices = 0;
    for( ; aux != NULL; aux= aux->prox) { //Esse laco calcula o numero de arestas incidentes no vertice
      numero_vertices++;
    }
    if (numero_vertices < min) {
      min = numero_vertices;
    }
  }
  
  return min;
}
/*
 * Fun��o que recebe um grafo como argumento e retorna o menor grau dentre
 *   os graus dos v�rtices do grafo.
 */
int grauMaximo(Vertice G[], int ordem){
  int max = 0;
  int numero_vertices;
  Aresta  *aux;
  int i;
  for (i = 0; i < ordem; i++) {// Laco que passa por cada vertice do grafo
    aux= G[i].prim;
    numero_vertices = 0;
    for( ; aux != NULL; aux= aux->prox) { //Esse laco calcula o numero de arestas incidentes no vertice
      numero_vertices++;
    }
    if (numero_vertices > max) {
      max = numero_vertices;
    }
  }
  
  return max; 
}

/*
 * Fun��o que recebe um grafo como argumento e retorna:
 *   1, se o grafo for regular
 *   0, caso contr�rio
 */
int eRegular(Vertice G[], int ordem){
  int numero_vertices = 0;
  int numero_vertices_anterior = 0;
  Aresta  *aux;
  int i;
  for (i = 0; i < ordem; i++) {// Laco que passa por cada vertice do grafo
    aux= G[i].prim;
    numero_vertices_anterior = numero_vertices;
    numero_vertices = 0;
    for( ; aux != NULL; aux= aux->prox) { //Esse laco calcula o numero de arestas incidentes no vertice
      numero_vertices++;
    }
    if (i == 0) // Como é o primeiro vertice, ele e igual a ele mesmo
    {
      numero_vertices_anterior = numero_vertices;
    }
    if (numero_vertices != numero_vertices_anterior) // Verifica sempre se é igual ao anterior, assim verifica se e regular
    {
      return 0;
    }
    
  }
  
  return 1;
}

/*
 * Fun��o que recebe um grafo como argumento e retorna:
 *   1, se o grafo for simples
 *   0, caso contr�rio
 */
int  eSimples(Vertice G[], int ordem){
  int max = 0;
  int numero_vertices;
  Aresta  *aux;
  int i;
  for (i = 0; i < ordem; i++) {// Laco que passa por cada vertice do grafo
    aux= G[i].prim;
    numero_vertices = 0;
    for( ; aux != NULL; aux= aux->prox) { //Esse laco calcula o numero de arestas incidentes no vertice
      if (aux->nome == i) // Verifica se o vertice tem uma aresta que incide nele mesmo
      {
        return 0;
      }
      if (duplicado(aux, aux->nome)) { //Verifica se o vertice tem arestas paralelas
        return 0;
      }
    }

  }
  return 1;  
}

/*
 * Programinha simples para testar a representacao de grafo
 */
int main(int argc, char *argv[]) {
	Vertice *G;
	int ordemG= 6;
	
	Vertice *C;	
	int ordemC;

  Vertice *D;
	int ordemD= 6;

  Vertice *F;
	int ordemF= 6;
		
  // Grafo original do programa
	criaGrafo(&G, ordemG);
	acrescentaAresta(G,ordemG,3,4);
	acrescentaAresta(G,ordemG,4,2);
	acrescentaAresta(G,ordemG,5,4);
	acrescentaAresta(G,ordemG,2,3);
	acrescentaAresta(G,ordemG,3,0);
	imprimeGrafo(G, ordemG);
	
	C= calculaComplemento(G, ordemG);
	ordemC= ordemG;
	imprimeGrafo(C, ordemG);
	
  //Grafo conexo grau 6 (Grafo do enunciado do projeto)
	criaGrafo(&D, ordemD);
  acrescentaAresta(D,ordemD,0,1);
  acrescentaAresta(D,ordemD,0,3);
	acrescentaAresta(D,ordemD,1,2);
  acrescentaAresta(D,ordemD,1,4);
  acrescentaAresta(D,ordemD,1,5);
  acrescentaAresta(D,ordemD,1,3);
  acrescentaAresta(D,ordemD,2,5);
  acrescentaAresta(D,ordemD,4,5);

  imprimeGrafo(D, ordemD);

  // Grafo desconexo grau 6
  criaGrafo(&F, ordemF);
	acrescentaAresta(F,ordemF,1,2);
  acrescentaAresta(F,ordemF,1,4);
  acrescentaAresta(F,ordemF,1,5);
  acrescentaAresta(F,ordemF,1,3);
  acrescentaAresta(F,ordemF,2,5);
  acrescentaAresta(F,ordemF,4,5);

  imprimeGrafo(F, ordemD);
	
	destroiGrafo(&G, ordemG);
	destroiGrafo(&C, ordemG);
  destroiGrafo(&D, ordemD);
  destroiGrafo(&F, ordemF);
	
    system("PAUSE");
	return 0;
}