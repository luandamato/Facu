#include <string.h>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

int main() {
   map< string, vector<string> > Carros;
   vector <string> myVec;
   while(true) {
        cout << "\n----------------------------------------------";
        cout << "\n MAPA";
        cout << "\n----------------------------------------------";
        cout << "\n0 - Sair.";
        cout << "\n1 - Incluir elemento.";
        cout << "\n2 - Localizar elemento.";
        cout << "\n3 - Excluir elemento.";
        cout << "\n4 - Imprimir elementos do mapa.";
        cout << "\n---------------------";
        cout << "\nQual a sua opcao -> ";
        int opc;
        cin >> opc;
        if (opc == 0) {
            break;
        } 
        else if (opc == 1) {
          string Placa;
          cout << "Placa do carro: ";
          cin >> Placa;

          string Modelo;
          cout << "Modelo do carro: ";
          cin >> Modelo;
          string Ano;
          cout << "Ano do carro: ";
          cin >> Ano;
          string Cor;
          cout << "Cor do carro: ";
          cin >> Cor;

          Carros.insert(std::pair<string,vector<string> >(Placa,{Modelo,Ano,Cor}));
          cout << "\n\n";
        } 
        else if (opc == 2) {
          string Placa;
          cout << "Placa do carro para localizar: ";
          cin >> Placa;
          
          map<string, vector<string> >::iterator contem = Carros.find(Placa);

          if (contem != Carros.end()){
            vector <string> inVect = Carros.find(Placa)->second;
            for (unsigned j=0; j<inVect.size(); j++){
              cout << inVect[j] << " ";
            }
          }else{
            cout << "Veiculo não encontrado";
          }
          
          cout << endl;


          map<string, vector<string>>::iterator it;
          cout << "\n\n";
        } 
        else if (opc == 3) {
          string Placa;
          cout << "Placa do carro para excluir: ";
          cin >> Placa;

          map<string, vector<string> >::iterator contem = Carros.find(Placa);

          if (contem != Carros.end()){
            Carros.erase(contem);
            cout << "Veiculo excluido com sucesso";
          }else{
            cout << "Veiculo não encontrado";
          }
         cout << "\n\n";
        }
        else if (opc == 4) {
         cout << "Tamanho do Mapa: " << Carros.size() << endl;

          for(map<string, vector<string> >::iterator ii=Carros.begin(); ii!=Carros.end(); ++ii){
              cout << (*ii).first << " => ";
              vector <string> inVect = (*ii).second;
              for (unsigned j=0; j<inVect.size(); j++){
                  cout << inVect[j] << " ";
              }
              cout << endl;
          }
          cout << "\n\n";
        }

        
    }
    //system("pause");
    cout << "\n-------------------------------------------------";
    cout << "\n\nObrigado e ate' a proxima vez.\n\n\n";

   
}

