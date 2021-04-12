#ifndef ARVOREB_H
#define ARVOREB_H

#include "arvoreb_no.h"

class ArvoreB {

	private:

	/**
	 * ************
	 * *** raiz ***
	 * ************
	 * No raiz da arvore
	 */
	ArvoreB_No * raiz;

	/**
	 * *************
	 * *** ordem ***
	 * *************
	 * Ordem da arvore. O criterio utilizado é o da quantidade de chaves
	 */
	int ordem;

	/**
	 * ****************
	 * *** novoNo() ***
	 * ****************
	 * Metodo auxiliar: cria um no'.
	 *
	 */
	ArvoreB_No * novoNo();

	/**
	 * *********************************************
	 * *** isInicio(ArvoreB_No * , Elemento2 * ) ***
	 * *********************************************
	 * Metodo auxiliar para verificar se um elemento e' o primeiro da lista.
	 */
	bool isInicio(ArvoreB_No * , Elemento2 * );


	public:
	/**
	 * ******************
	 * *** Construtor ***
	 * ******************
	 */
	ArvoreB();

	/**
	 * *******************************
	 * *** inserir(unsigned int v) ***
	 * *******************************
	 * Insere um novo elemento na arvore.
	 * Vide o metodo inserir na classe "ArvoreB_No".
	 */
	int inserir(unsigned int v);

	/**
	 * ***************
	 * *** vazia() ***
	 * ***************
	 * Verifica se a arvore esta' vazia, ou seja, nao ha' nenhum elemento no
	 * no' raiz. O no' raiz sempre existe (nunca e' NULL).
	 *
	 */
	bool vazia();

	void imprimirRaizEFilhos();

	/**
	 * **********************
	 * *** imprimirNo() ***
	 * **********************
	 * Imprime o conteudo de um no' da arvore.
	 * Se no' for nulo -> imprime o no' raiz.
	 */
	void imprimirNo(ArvoreB_No * );


};

#endif
