#ifndef ARVOREB_NO_H
#define ARVOREB_NO_H

#define ORDEM 5

#include "lista2.h"

class ArvoreB_No {

	private:
	/**
	 * **************
	 * *** chaves ***
	 * **************
	 * Lista duplamente ligada com as chaves (Elemento2)
	 */
	Lista2 * chaves;

	/**
	 * **************
	 * *** filhos ***
	 * **************
	 * Trata-se de um vetor de ponteiros que apontam para os nohs filhos.
	 * O indice do vetor que corresponde a determinado ponteiro esta' no Elemento2
	 *   nos atributos "menores" e "maiores" que apontam, respectivamente,
	 *   para os nohs com valores menores que o de cada elemento especifico.
	 */
	ArvoreB_No * filhos[ORDEM];

	friend class ArvoreB; // para a classe ArvoreB poder acessar os membros privados

	public:
	/**
	 * ********************
	 * *** Construtores ***
	 * ********************
	 */
	ArvoreB_No();
	ArvoreB_No(int tam);

	/**
	 * *******************************
	 * *** inserir(unsigned int v) ***
	 * *******************************
	 * Insere um valor int na lista ligada do no'. Vide tambem o metodo
	 *   inserir na classe ArvoreB.
	 */
	int inserir(unsigned int v);



};

#endif
