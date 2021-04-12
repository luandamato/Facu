#include <stdlib.h>

#include "elemento2.h"

Elemento2::Elemento2() {
	prox = NULL;
	prev = NULL;
	menores = -1;
	maiores = -1;
}

unsigned int Elemento2::getValor(){
	return valor;
}

void Elemento2::setValor(unsigned int v){
	valor = v;
}

Elemento2 * Elemento2::getProx(){
	return prox;
}

void Elemento2::setProx(Elemento2 * e){
	prox = e;
}

Elemento2 * Elemento2::getPrev(){
	return prev;
}

void Elemento2::setPrev(Elemento2 * e){
	prev = e;
}

