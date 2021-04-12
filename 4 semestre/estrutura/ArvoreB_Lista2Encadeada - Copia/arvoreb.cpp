#include <iostream>
#include <stdlib.h>

#include "arvoreb.h"
#include "arvoreb_no.h"


ArvoreB::ArvoreB() {
	raiz = novoNo();
	ordem = ORDEM;
}


int ArvoreB::inserir(unsigned int v) {

	//*** se a arvore esta' vazia -> cria o primeiro no' e insere a primeira chave
	if (vazia()) {
		raiz->inserir(v);
		return 0;
	}
	//+++

	//*** localizar posicao do novo elemento
	ArvoreB_No * cursorB = raiz; //* criar um cursor para percorrer os nos da arvore

	while (true) {

		Elemento2 * cursorE = cursorB->chaves->getInicio(); //* criar um cursor para percorrer a lisat de chaves

		while (cursorE != NULL) {

			//* se nao ha' ponteiro para no' inferior -> trata-se do ultimo nivel.
			if (cursorE->menores < 0) {
				int x = cursorB->inserir(v);
				if (x == 0 || x == 2) {
					return x;
				} else {
					****************************************
					*** IMPLEMENTAR A DIVISAO DO NO RAIZ ***
					****************************************
					std::cout << "No' cheio!!!";
					return 1;
				}
			}

			//* caso haja ponteiro para o no' inferior -> precisa procurar o no'
			//  certo para insercao.
			//**** AINDA NAO IMPLEMENTADO


		}

	}

}

bool ArvoreB::vazia() {
	return raiz->chaves->inicio == NULL;
}

bool ArvoreB::isInicio(ArvoreB_No * n, Elemento2 * e) {
	return e == n->chaves->inicio;
}

ArvoreB_No * ArvoreB::novoNo() {
	return new ArvoreB_No();
}


void ArvoreB::imprimirRaizEFilhos() {

	if (vazia()) {
		std::cout << "A arvore esta' vazia.";
		return;
	}

	imprimirNo(raiz);

	Elemento2 * cursor = raiz->chaves->inicio;
	if (cursor->menores < 0) return;
	ArvoreB_No * noB = raiz->filhos[cursor->menores];
	// raiz->filhos[cursor->menores];

	if (noB == NULL) {
		std::cout << "\n*** A raiz nao tem filhos ***";
		return;
	}
	imprimirNo(noB);

	while (cursor != NULL) {
		noB = raiz->filhos[cursor->maiores];
		imprimirNo(noB);
		cursor = cursor->getProx();
	}

}


void ArvoreB::imprimirNo(ArvoreB_No * no) {
	if (no == NULL) no = raiz;;
	no->chaves->imprimir();
}
