#ifndef LISTA2_H
#define LISTA2_H

#include "elemento2.h"

class Lista2 {

	/**
	 * *********************
	 * *** P R I V A T E ***
	 * *********************
	 */
	private:
	//**************************************************************************
	//                        PARAMETROS DA LISTA
	//            devem ser configurados via metodo construtor
	//
	//* Aceita valores repetidos (true/false)
	bool repete;
	//* Ordenada (true/false)
	bool ordenada;
	//* Tamanho maximo (0 = tamanho ilimitado)
	int maxTam;
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	Elemento2 * inicio;
	Elemento2 * fim;
	int tamanho;
	
	int insereNoInicio(Elemento2 *);
	Elemento2 * criaElemento(unsigned int v);
	
	friend class ArvoreB;

	/**
	 * *******************
	 * *** P U B L I C ***
	 * *******************
	 */
	public:
	Lista2(bool rep, bool ord, int max);
	~Lista2();
	/**
	 * *** int inserir(int v); ***
	 * Insere um elemento na lista.
	 * Retorno:
	 *   0 = inserido com sucesso
	 *   1 = Lista cheia (caso de controle de tamanho maximo - maxTam > 0
	 *   2 = Ja' consta na lista (caso controle de repeticao)
	 */
	int inserir(unsigned int v);
	/**
	 * *** Elemento * remover(unsigned int v) ***
	 * Retorna o elemento ou NULL se nao estiver na Lista.
	 */
	Elemento2 * remover(unsigned int v);
	bool vazia();
	int getTamanho();
	bool cheia();
	
	void imprimir();
	
	
	Elemento2 * getInicio();
	

};

#endif
