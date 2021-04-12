#ifndef ARVORE_H
#define ARVORE_H

#include "no.h"

class ArvoreAvl{

private:
	bool avlLiga;
    No * raiz; // no' raiz da arvore
    No * vetor[10]; // vetor de navegacao
    int pos; // posicao em que se esta' no vetor de navegacao
    void balancear();

public:
	ArvoreAvl();
    ArvoreAvl(bool aL);
    No * getRaiz();
    bool inclui(int v);
    No * localiza(int v);
    void imprimirEmOrdem(No * n);
    void imprimeVetor();
    int filhoLado(int p);
};



#endif // ARVORE_H
