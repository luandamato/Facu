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
	void insereInicio(int i);
  void insereFinal(int i);
	string insereEmN(Celula * c, int pos, int x);
  string excluideN(int pos, int x);
	void imprime();
  int existe(int v);
	// ... outros mÈtodos ...
	
};
