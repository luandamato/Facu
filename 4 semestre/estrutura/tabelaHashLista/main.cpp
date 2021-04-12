# define TAMANHO 10
#include <iostream>
#include <stdlib.h>
#include "ListaLigada.h"
using namespace std;
ListaLigada lista[TAMANHO];
//==============================================================================
// Metodo para imprimir o vetor.
void imprimir() {
    cout << "\n[ ";
    for (int i = 0; i < TAMANHO; i++) {
      //if (lista[i].vazia()){
        //cout << " - "
      //}
      lista[i].imprime();    
    }
    cout << "]";
}
//------------------------------------------------------------------------------

string incluir(int valor) {
    // verifica se o valor e´ maior que zero
    if (valor < 0) {
      return "ERRO: o valor tem que ser maior que zero.";
    }
    int indice = valor % TAMANHO;

    for(int i = indice; indice < TAMANHO; i++){
        lista[i].insereFinal(valor);
        return "Inclusao bem sucedida.";
    }
  return "Ocorreu um erro";
}
int excluir(int i, ListaLigada l) {
    // verifica se o indice e´ valido
    if (i < 0) {
      return -1;
    }else if(i > TAMANHO - 1){
      return -2;
    }
    lista[i] = l;
    return 0;
}
void busca(int valor) {
    for (int i = 0; i < TAMANHO; i++) {
      if(lista[i].existe(valor) != -1){
        cout << "O elemento está na posição " << i << " do vetor e " << lista[i].existe(valor) << " da lista";
        return;
      }
    }
    cout << "Elemento nao encontrado";
}
//==============================================================================
// MAIN
//==============================================================================
int main() {
    //numeros = new int[TAMANHO];
    ListaLigada l;
    while(true) {
        cout << "\n----------------------------------------------";
        cout << "\n Tabela Hash com Lista";
        cout << "\n----------------------------------------------";
        cout << "\n0 - sair.";
        cout << "\n1 - imprimir o vetor.";
        cout << "\n2 - inserir um elemento";
        cout << "\n3 - excluir um elemento.";
        cout << "\n4 - localizar elemento";
        cout << "\n---------------------";
        cout << "\nQual a sua opcao -> ";
        int opc;
        cin >> opc;
        if (opc == 0) {
            break;
        } 
        else if (opc == 1) {
            imprimir();
            cout << "\n\n";
        } 
        else if (opc == 2) {
          cout << "Valor do novo elemento: ";
          int val;
          cin >> val;
          cout << incluir(val) << endl;
        } 
        else if (opc == 3) {
          cout << "Indice do elemento a ser removido: ";
          int idx;
          cin >> idx;
          int val = excluir(idx, l);
          if (val == -2) {
            cout << "Nao ha´ elemento na posicao " << idx;
          }
          else if (val == -1) {
            cout << "ERRO: o indice esta' fora dos limites do vetor.";
          } 
          else {
            cout << "Lista excluida da posicao " << idx;
          }
          cout << "\n\n";
        }
        else if (opc == 4) {
         cout << "Buscar valor: ";
          int idx;
          cin >> idx; 
          busca(idx);
        
          cout << "\n\n";
        }

        
    }
    //system("pause");
    cout << "\n-------------------------------------------------";
    cout << "\n\nObrigado e ate' a proxima vez.\n\n\n";
return 0;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------