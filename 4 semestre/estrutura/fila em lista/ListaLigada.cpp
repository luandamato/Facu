#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Celula.h"
#include "ListaLigada.h"

using namespace std;


ListaLigada::ListaLigada() {
	prim = NULL;
  tail = NULL;
	qtdCelulas = 0;
}

bool ListaLigada::vazia() {
	return prim == NULL;
}

int ListaLigada::tamanho() {
	return this->qtdCelulas;
}

void ListaLigada::insereFinal(int i) {
	Celula * c = new Celula(i);

  if(vazia())
		{
			prim = c;
			tail = c;
		}
		else
		{
      tail->setProx(c);
      tail = c;
      qtdCelulas++;
    }
}


string ListaLigada::excluir() {

	stringstream ss;
  if (!vazia()){
      prim = prim->getProx();
      ss << "Item removido ";
      qtdCelulas--;
  }else{
    ss << "a lista esta vazia ";
  }

	return ss.str();

}


void ListaLigada::imprime() {
	Celula * cursor = prim;
	cout << "[ ";
	while (cursor != NULL) {
		cout << cursor->getInfo() << " ";
		cursor = cursor->getProx();
	}
	cout << "]\n";
}

int ListaLigada::existe(int v)
	{
		Celula * c = prim;
    int q;
		
		while(c)
		{
			if(c->getInfo() == v)
				return q;
			c = c->getProx();
      q++;
		}
		return -1;
	}



