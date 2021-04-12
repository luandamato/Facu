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

void ListaLigada::insereInicio(int i) {
	Celula * c = new Celula(i);
  if(vazia())
		{
			prim = c;
			tail = c;
		}
		else
		{
      c->setProx(prim);
      prim = c;
      qtdCelulas++;
    }
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

string ListaLigada::insereEmN(Celula * c, int pos, int x) {

	stringstream ss;

  if (x==4){
    pos++;
  }else if(x==5){
    pos--;
  }

	while (true) {

		if (pos < 1) {
			ss << "A posicao deve ser maior ou igual a 1";
			break;
		}

		if (pos > qtdCelulas + 1) {
			ss << "Nao existe esta posicao. A fila esta' com " << qtdCelulas << " elemento(s)";
			break;
		}

		if (pos == 1) {
			insereInicio(c->getInfo()); // o metodo insereInicio ja' estava implementado; aqui foi feita uma adaptacao.
			ss << "Inserido no inicio";
			break;
		}

		Celula * cursor = this->prim;
		for (int i = 1; i < pos - 1; i++) {
			cursor = cursor->getProx();
		}

		c->setProx(cursor->getProx());
		cursor->setProx(c);
		
		qtdCelulas++;

		ss << "Inserido na posicao " << pos;

		break;
	}

	return ss.str();

}

string ListaLigada::excluideN(int pos, int x) {

	stringstream ss;

  if (x==7){
    pos++;
  }else if(x==8){
    pos--;
  }

	while (true) {

		if (pos < 1) {
			ss << "A posicao deve ser maior ou igual a 1";
			break;
		}

		if (pos > qtdCelulas + 1) {
			ss << "Nao existe esta posicao. A fila esta' com " << qtdCelulas << " elemento(s)";
			break;
		}

    if (pos==1){
      prim = prim->getProx();
    }
		Celula * cursor = this->prim;
    Celula * ant = this->prim;
		for (int i = 1; i < pos - 1; i++) {
      ant=cursor;
			cursor = cursor->getProx();
		}
		ant->setProx(cursor->getProx());
    
		qtdCelulas--;

		ss << "Item removido " << pos;

		break;
	}

	return ss.str();

}


void ListaLigada::imprime() {
	Celula * cursor = prim;
	cout << "{ ";
	while (cursor != NULL) {
		cout << cursor->getInfo() << " ";
		cursor = cursor->getProx();
	}
	cout << "}";
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



