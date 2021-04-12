# define TAMANHO 10
#include <iostream>
#include <stdlib.h>
using namespace std;
int numeros[TAMANHO];
//==============================================================================
// Metodo para imprimir o vetor.
void imprimir() {
    cout << "\n[ ";
    for (int i = 0; i < TAMANHO; i++) {
      if (numeros[i] == -1){
        cout << " - " << " ";
      }else{
        cout << numeros[i] << " ";
      }
    
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
      if (numeros[i] > 0){

      }else{
        numeros[i] = valor;
        return "Inclusao bem sucedida.";
      }
    }
  return "Ocorreu um erro";
}
int excluir(int indice) {
    // verifica se o indice e´ valido
    if (indice < 0) {
      return -1;
    }else if(indice > TAMANHO - 1){
      return -2;
    }
    int numero = numeros[indice];
    numeros[indice] = -1;
    return numero;
}
int busca(int valor) {
    for (int i = 0; i < TAMANHO; i++) {
      if (numeros[i] == valor){
        return i;
      }
    }
    return -1;
}
//==============================================================================
// MAIN
//==============================================================================
int main() {
    //numeros = new int[TAMANHO];
    for (int i = 0; i < TAMANHO; i++) {
        numeros[i] = -1;
    }
    while(true) {
        cout << "\n----------------------------------------------";
        cout << "\n Tabela Hash";
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
          int val = excluir(idx);
          if (val == -2) {
            cout << "Nao ha´ elemento na posicao " << idx;
          }
          else if (val == -1) {
            cout << "ERRO: o indice esta' fora dos limites do vetor.";
          } 
          else {
            cout << "Valor excluido da posicao " << idx << ": " << val;
          }
          cout << "\n\n";
        }
        else if (opc == 4) {
         cout << "Buscar valor: ";
          int idx;
          cin >> idx;
          int val = busca(idx);
          if (val == -1) {
            cout << "Elemento não achado no vetor.";
          } 
          else {
            cout << "o elemento " << idx << " está na posição: " << val;
          }
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