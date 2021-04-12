

#include "arvoreb_no.h"


ArvoreB_No::ArvoreB_No() {
	chaves = new Lista2(false, true, ORDEM - 1);
}

ArvoreB_No::ArvoreB_No(int tam) {
	// chaves = new Lista2(false, true, tam);
	// filhos = new ArvoreB_No[tam + 1];
}

int ArvoreB_No::inserir(unsigned int v) {
	return chaves->inserir(v);
}
