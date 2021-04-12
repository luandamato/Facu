#include <stdlib.h>

#include "no.h"

No::No(int v) {
	valor = v;
	fesq = NULL;
	fdir = NULL;
	pesq = 0;
	pdir = 0;
}

int No::getValor() {
	return this->valor;
}

No * No::getFesq() {
	return fesq;
}

No * No::getFdir() {
	return fdir;
}

void No::setFesq(No * n) {
	fesq = n;
}

void No::setFdir(No * n) {
	fdir = n;
}

int No::getPesq() {
	return pesq;
}

int No::getPdir() {
	return pdir;
}

void No::setPesq(int v) {
	pesq = v;
}

void No::setPdir(int v) {
	pdir = v;
}






