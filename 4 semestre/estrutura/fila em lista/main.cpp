#include <cstdlib>
#include <iostream>
#include "ListaLigada.h"

using namespace std;

void ni();
void pausa();

int main() {
    
    ListaLigada lista;
    
    
    while (true) {
        
        cout << "\n0 - sair";
        cout << "\n1 - inserir elemento";
        cout << "\n2 - excluir elemento";
        cout << "\n3 - imprimir a lista";
        cout << "\n4 - buscar elemento na lista";
        cout << "\n5 - informar total de elementos na lista";
        cout << "\n\nInforme sua opcao: ";
        int opc;
        cin >> opc;
        
        if (opc == 0) {
            break;
        } else if (opc == 1) {
            int opc1;
            cout << "Valor do elemento: ";
            cin >> opc1;
            lista.insereFinal(opc1);
            system("pause");
        } else if (opc == 2) {
            cout<<lista.excluir();
        } else if(opc == 3) {
           lista.imprime();
        } else if (opc == 4) {
            int opc4;
            cout << "Valor do elemento: ";
            cin >> opc4;
            cout<<lista.existe(opc4);
        } else if (opc == 5) {
           cout<< lista.tamanho()+1;
        }
    }
    return 0;
}