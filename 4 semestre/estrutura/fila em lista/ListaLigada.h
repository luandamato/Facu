#include <iostream>
#include <string.h>
#include "Celula.h"

using namespace std;

class ListaLigada {
	
	//= privado
	private:
	Celula * prim;
  Celula * tail;
	int qtdCelulas;
	
	//= publico
	public:
	ListaLigada();
	bool vazia();
	int tamanho();
  void insereFinal(int i);
  string excluir();
	void imprime();
  int existe(int v);
	// ... outros mÈtodos ...
	
};
