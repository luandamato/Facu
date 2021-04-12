#include <cstdlib>
#include <iostream>
#include "ListaLigada.h"

using namespace std;

void ni();
void pausa();

int main() {

	ListaLigada lista;


	while (true) {

		system("cls");

		cout << "\n0 - sair";
		cout << "\n1 - inserir no inicio";
		cout << "\n2 - inserir no final";
		cout << "\n3 - inserir na posicao 'n'";
		cout << "\n4 - inserir apos a posicao 'n'";
		cout << "\n5 - inserir antes da posicao 'n'";
		cout << "\n6 - excluir da posicao 'n'";
		cout << "\n7 - excluir apos a posicao 'n'";
		cout << "\n8 - excluir antes da posicao 'n'";
		cout << "\n9 - informar total de elementos na lista";
		cout << "\n10 - imprimir a lista";
    cout << "\n11 - buscar elemento na lista";
		cout << "\n\nInforme sua opcao: ";
		int opc;
		cin >> opc;

		if (opc == 0) {
			break;
		} else if (opc == 1) {
			int opc1;
			cout << "Valor do elemento: ";
			cin >> opc1;
			lista.insereInicio(opc1);
			system("pause");
		} else if (opc == 2) {
			int opc2;
			cout << "Valor do elemento: ";
			cin >> opc2;
			lista.insereFinal(opc2);
		} else if(opc == 3) {
			int opc3a;
			int opc3b;
			cout << "\nValor do elemento: ";
			cin >> opc3a;
			cout << "Posicao a ser inserido: ";
			cin >> opc3b;
			Celula * c = new Celula(opc3a);
			cout << lista.insereEmN(c, opc3b, opc);
			pausa();
		} else if (opc == 4) {
			int opc4a;
			int opc4b;
			cout << "\nValor do elemento: ";
			cin >> opc4a;
			cout << "vai ser inserido apos a posicao: ";
			cin >> opc4b;
			Celula * c = new Celula(opc4a);
			cout << lista.insereEmN(c, opc4b, opc);
			pausa();
		} else if (opc == 5) {
			int opc5a;
			int opc5b;
			cout << "\nValor do elemento: ";
			cin >> opc5a;
			cout << "vai ser inserido antes a posicao: ";
			cin >> opc5b;
			Celula * c = new Celula(opc5a);
			cout << lista.insereEmN(c, opc5b, opc);
			pausa();
		} else if (opc == 6) {
			int opc5b;
			cout << "vai ser excluido da posicao: ";
			cin >> opc5b;
			cout << lista.excluideN(opc5b+1, opc);
			pausa();
		} else if (opc == 7) {
			int opc5b;
			cout << "vai ser excluido apos a posicao: ";
			cin >> opc5b;
			cout << lista.excluideN(opc5b+1, opc);
			pausa();
		} else if (opc == 8) {
			int opc5b;
			cout << "vai ser excluido antes a posicao: ";
			cin >> opc5b;
			cout << lista.excluideN(opc5b+1, opc);
			pausa();
		} else if (opc == 9) {
			cout << "\n\nTamanho da lista = " << lista.tamanho()+1 << " elemento(s)";
			pausa();
		} else if (opc == 10) {
			cout << "\n\nImpressao dos elemento da lista -> ";
			lista.imprime();
			pausa();
		} else if (opc == 11) {
      int opc11;
      cout << "\nProcurar elemento: ";
			cin >> opc11;
			cout<< lista.existe(opc11);
			pausa();
    }

	}

	return 0;
}


void ni() {
	system("cls");
	cout << "\n\n\n\n\n          ***********************";
	cout << "\n\n          AINDA NAO IMPLEMENTADO.\n\n";
	cout << "          ***********************\n\n\n\n\n\n\n\n\n";
	system("pause");
}


void pausa() {
	cout << "\n\n\n\n";
	system("pause");
}



