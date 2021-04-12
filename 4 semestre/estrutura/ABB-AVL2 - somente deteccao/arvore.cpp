#include <iostream>
#include <stdlib.h>
#include <math.h>

#include "arvore.h"

ArvoreAvl::ArvoreAvl() {}

/**
 * Esse construtor tem a opcao de ligar a funcao AVL ou nao.
 * Se nao for ligado o AVL, a arvore opera como ABB convencional.
 */
ArvoreAvl::ArvoreAvl(bool aL) {
	avlLiga = aL;
	raiz = NULL;
	pos = -1;
}


No * ArvoreAvl::getRaiz() {
	return this->raiz;
}

//******************************************************************************
//*** Inclui um novo no'. Verifica se ja' consta na arvore.
//
bool ArvoreAvl::inclui(int v) {

	//* se raiz for nula -> novo no' sera' a raiz
	if (raiz == NULL) {
		raiz = new No(v);
		return true;
	}

	//* se encontrou um no' com o mesmo valor -> nao pode incluir
	if (localiza(v) != NULL) {
		return false;
	}

	//* instancia do novo no'
	No * no = new No(v);

	//* conectar ao pai. O pai e' o ultimo registro no vetor.
	//  precisa verificar se e' filho direito ou esquerdo.
	//No * cursor = &vetor[pos];
	if (v < vetor[pos]->getValor()) {
		vetor[pos]->setFesq(no);
	} else {
		vetor[pos]->setFdir(no);
	}

	//* registrar o novo no' no vetor
	pos++;
	vetor[pos] = no;

	if (avlLiga){
		balancear();
	}

	return true;

}

//******************************************************************************
//*** Procura um no' na arvore. Se achar -> retorna o No', caso contrario retorna NULL.
//
No * ArvoreAvl::localiza(int v) {

	//* se raiz for NULL -> arvore vazia -> retorna NULL
	if (raiz == NULL) {
		return NULL;
	}

	//* preparar vetor de registro de percurso
	pos = -1;
	No * cursor = raiz;

	while (cursor != NULL) {

		//* registra posicao atual no vetor de percurso
		pos++;
		vetor[pos] = cursor;

		//std::cout << vetor[pos]->getValor();

		//* se achou o valor -> retorna o no'
		if (cursor->getValor() == v) {
			return cursor;
		}

		//* se valor desejado e' maior que o no' em curso -> vai para direita
		if (v > cursor->getValor()) {
			cursor = cursor->getFdir();
		}

		//* se valor desejado e' menor que o no' em curso -> vai para esquerda
		else {
			cursor = cursor->getFesq();
		}

	}

	//* chegou ao final do ramo correspondente ao valor desejado e nao localizou
	return NULL;

}

//******************************************************************************
//              Imprime a arvore no percurso Em Ordem
//
void ArvoreAvl::imprimirEmOrdem(No * n) {
	if (n != NULL) {
		imprimirEmOrdem(n->getFesq());
		std::cout << n->getValor() << " - ";
		imprimirEmOrdem(n->getFdir());
	}
}


void ArvoreAvl::imprimeVetor() {

	for (int i = 0; i <= pos; i++) {
		//cursor = &vetor[i];
		std::cout << vetor[i]->getValor() << " ";
	}

}


//******************************************************************************
// verifica o balanceamento do ramo em que foi inserido o novo no' e, caso
// esteja desbalanceado, faz as rotacoes necessarias.
void ArvoreAvl::balancear() {

	/**
	 * Verifica se o novo no' tem irmao. Se tiver, significa que a profundidade
	 * do ramo em questao nao aumentou e a unica coisa a fazer e' incrementar
	 * o atributo profundidade (pesq ou pdir) do no' pai (0->1).
	 * O no' pai esta' em vetor[pos-1]
	 */

	//*** ver se filho esquerdo ou direito para incrementar a profundidade no pai.
	if (filhoLado(pos) == -1) { // filho esquerdo
		vetor[pos - 1]->setPesq(1); // nao pode ser maior que 1, pois o novo no' sempre e' folha.
	} else if (filhoLado(pos) == 1) { // filho direito
		vetor[pos - 1]->setPdir(1); // idem
	} else {
		std::cout << "ERRO INESPERADO. VERIFIQUE A LOGICA DO ALGORITMO.";
		return;
	}

	//* se o novo no' tem irmao -> ambos os filhos do pai estao diferentes de nulo.
	// -> nao aumentou a profundidade do ramo -> nada a fazer.
	if (vetor[pos - 1]->getFesq() != NULL && vetor[pos - 1]->getFdir() != NULL) {
		return;
	}

	//* O novo no' nao tem irmao -> aumentou a profundidade do pai.
	//  Subir o ramo (via vetor) para verificar se algum no' esta' com fator
	//  de balanco maior que 1.
	//  O pai ja' esta' com o fator de balanco atualizado, precisa subir a partir dele.

	for (int i = pos - 1; i > 0; i--) { // relembrando que pos-1 e' onde esta' o pai do novo no'

		//* incrementar pesq ou pdir
		if (filhoLado(i) == -1) { // filho esquerdo
			vetor[i - 1]->setPesq(vetor[i - 1]->getPesq() + 1);
		} else {
			vetor[i - 1]->setPdir(vetor[i - 1]->getPdir() + 1);
		}

		//* |pesq-pdir| >= 2 --> o no' esta' desbalanceado.
		if ( fabs(vetor[i - 1]->getPesq() - vetor[i - 1]->getPdir()) >= 2 ) {
			std::cout << "\n*** ARVORE DESBALANCEADA (NO' " << vetor[i - 1]->getValor() << ")";
			return;
		}
	}

}

/**
 * Dado um no' pela sua posicao no vetor, verifica se e' filho esquerdo do seu pai ou filho direito.
 * Retorna -1 se filho esquerdo, 1 se filho direito ou zero se for no' raiz.
 * Em caso de erro (que nao deve ocorrer) retorna 9.
 */
int ArvoreAvl::filhoLado(int p) {

	//* posicao zero sempre e' o raiz neste modelo.
	if (p == 0) {
		return 0;
	}

	//* o pai esta' na posicao p-1.
	else if (vetor[p - 1]->getFesq() != NULL && vetor[p - 1]->getFesq()->getValor() == vetor[p]->getValor()) {
		return -1;
	}

	else if (vetor[p - 1]->getFdir() != NULL && vetor[p - 1]->getFdir()->getValor() == vetor[p]->getValor()) {
		return 1;
	}

	else return 9;

}
