/*******************************************************************************
 *         PROGRAMA PARA ESTUDO DA ARVORE BINARIA DE BUSCA AVL
 *            - uma implementacao com metodos iterativos -
 *     *** nesta versao apenas detecta se ocorreu o desbalanceamento ***
 *                       prof. Marcio Feitosa
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <iostream>
#include <stdlib.h>
#include <conio.h>

#include "arvore.h"


using namespace std;

int main() {

	//** LIGA (true) / DESLIGA (false) A OPERACAO DE BALANCEAMENTO *************
	bool ligaAvl = true;
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	ArvoreAvl avl(ligaAvl);

	bool encerrar = false;

	while(!encerrar) {

		system("cls");

		cout << "---------------------------------------------------------------";
		cout << "\n           PROGRAMA PARA ESTUDO DA ARVORE AVL";
		cout << "\n                  prof. Marcio Feitosa";
		cout << "\n---------------------------------------------------------------";

		if (!ligaAvl) {
			cout << "\nOperacao AVL desligada. Veja atributo \"ligaAvl\" no metodo main";
			cout << "\n---------------------------------------------------------------";
		}
		cout << "\n\n0 - sair";
		cout << "\n1 - inserir";
		cout << "\n9 - imprimir em ordem";

		cout << "\n20 - print o vetor";

		cout << "\n\nSua opcao: ";
		int opc;
		cin >> opc;

		switch(opc) {

		case 0:
			encerrar = true;
			break;
		case 1:
			cout << "\nInforme o valor do elemento: ";
			int opc1;
			cin >> opc1;
			if (opc1 < 0) {
				cout << "\n*** O NUMERO NAO PODE SER NEGATIVO ***";
				getch();
				break;
			}
			if (avl.inclui(opc1)) {
				cout << "\nInclusao bem sucedida";
			} else {
				cout << "\n*** FALHA NA INCLUSAO ***";
			}
			getch();
			break;
		case 9:
			avl.imprimirEmOrdem(avl.getRaiz());
			cout << "\npress. qqr. tecla";
			getch();
			break;
		case 20:
			avl.imprimeVetor();
			cout << "\npress. qqr. tecla";
			getch();
			break;
		default:
			cout << "\n\n*** OPCAO INVALIDA (" << opc << ") ***";
			getch();
		}



	}

	cout << "\n\n--- Obrigado e ate' a proxima ---\n\n";

	return 0;
}

