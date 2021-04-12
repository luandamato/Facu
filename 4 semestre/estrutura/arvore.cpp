#include <cstdlib>
#include <iostream>

using namespace std;

class No
{
private:
	No *esq, *dir;
	int chave;

public:
	No(int chave)
	{
		this->chave = chave;
		esq = NULL;
		dir = NULL;
	}

	int getChave()
	{
		return chave;
	}

	// fun??es getters e setters

	No* getEsq()
	{
		return esq;
	}

	No* getDir()
	{
		return dir;
	}

	void setEsq(No *no)
	{
		esq = no;
	}

	void setDir(No *no)
	{
		dir = no;
	}

	void display(No *no){
		cout << "chave = " << no->getChave();
		cout << "Filho direita = " << no->getDir()->getChave();
		cout << "Filho Esquerda = " << no->getEsq()->getChave();
	}
};

class Arvore
{
private:
	No *raiz;

public:
	Arvore()
	{
		raiz = NULL;
	}

	int altura(No* no){
        int alt_esq = 0;
        int alt_dir = 0;
        if (no->getEsq() != NULL){
            alt_esq = altura(no->getEsq())
        }
        if (no->getDir() != NULL){
            alt_dir = altura(no->getDir())
        }

        return max(alt_dir, alt_esq) + 1;
	}

	int fatorBalanceamento(No* no){
        int fator = 0;
        if (no->getEsq() != NULL){
            fator += altura(no->getEsq())
        }
        if (no->getDir() != NULL){
            fator += altura(no->getDir())
        }
        return fator;
	}

	No* rotacionarEsq_Esq(No* no){

	}

	void inserir(int chave)
	{
		if(raiz == NULL) // verifica se a ?rvore est? vazia
			raiz = new No(chave); // cria um novo n?
		else
			inserirAux(raiz, chave);
	}

	void inserirAux(No *no, int chave)
	{
		// se for menor, ent?o insere ? esquerda
		if(chave < no->getChave())
		{
			// verifica se a esquerda ? nulo
			if(no->getEsq() == NULL)
			{
				No *novo_no = new No(chave);
				no->setEsq(novo_no); // seta o novo_no ? esquerda
			}
			else
			{
				// sen?o, continua percorrendo recursivamente
				inserirAux(no->getEsq(), chave);
			}
		}
		// se for maior, ent?o insere ? direita
		else if(chave > no->getChave())
		{
			// verifica se a direita ? nulo
			if(no->getDir() == NULL)
			{
				No *novo_no = new No(chave);
				no->setDir(novo_no); // seta o novo_no ? direita
			}
			else
			{
				// sen?o, continua percorrendo recursivamente
				inserirAux(no->getDir(), chave);
			}
		}
		// se for igual, n?o vai inserir
		// n?o pode existir 2 chaves iguais

		balanceia(no->getChave())
	}

	No* getRaiz()
	{
		return raiz;
	}

	int altura(No* aux){
        if(!aux){
            return 0;
        }

        int ae = altura(aux->esquerda);
        int ad = altura(aux->direita);

        return (ae > ad) ? ae + 1: ad + 1;
    }

    No* arvore* rot_direita(No* aux){
        struct arvore *esq = aux->esquerda;

        aux->esquerda = esq->direita;
        esq->direita = aux;

        if(aux->esquerda){
            aux->esquerda->pai = aux;
        }

        esq->pai = aux->pai;
        aux->pai = esq;

        if(aux == raiz){
            raiz = esq;
        }

        if(esq->pai){
            if(esq->n < esq->pai->n){
                esq->pai->esquerda = esq;
            }
            else{
                esq->pai->direita = esq;
            }
        }

        esq->fb = altura(esq->direita) - altura(esq->esquerda);
        aux->fb = altura(aux->direita) - altura(aux->esquerda);

        return esq;
    }

    No* rot_esquerda(No* aux){
        struct arvore *dir = aux->direita;

        aux->direita = dir->esquerda;
        dir->esquerda = aux;

        if(aux->direita){
            aux->direita->pai = aux;
        }

        dir->pai = aux->pai;
        aux->pai = dir;

        if(aux == raiz){
            raiz = dir;
        }

        if(dir->pai){
            if(dir->n < dir->pai->n){
                dir->pai->esquerda = dir;
            }
            else{
                dir->pai->direita = dir;
            }
        }

        dir->fb = altura(dir->direita) - altura(dir->esquerda);
        aux->fb = altura(aux->direita) - altura(aux->esquerda);
        return dir;
    }

     No* balanceia(No *aux){
        if(aux->fb < -1){
            if(aux->esquerda->fb > 0){
                aux->esquerda = rot_esquerda(aux->esquerda);
            }

            aux = rot_direita(aux);
        }

        else if(aux->fb > 1){
            if(aux->direita->fb < 0){
                aux->direita = rot_direita(aux->direita);
            }

            aux = rot_esquerda(aux);
        }

        return aux;
    }

	void emOrdem(No* no)
	{
		if(no != NULL)
		{
			emOrdem(no->getEsq());
			cout << no->getChave() << " ";
			emOrdem(no->getDir());
		}
	}

		void preOrdem(No* no)
	{
		if(no != NULL)
		{
			cout << no->getChave() << " ";
			emOrdem(no->getEsq());
			emOrdem(no->getDir());
		}
	}

		void posOrdem(No* no)
	{
		if(no != NULL)
		{
			emOrdem(no->getEsq());
			emOrdem(no->getDir());
			cout << no->getChave() << " ";
		}
	}

	int count(No* no)
	{
		if (no != NULL){
			return 1 + count(no->getEsq()) + count(no->getDir());
		}
		return 0;
	}

	No* busca (No* r, int v){ //Busca elemento na arvore
	    if (r == NULL){
	        return NULL;
	    }else if (v<r->getChave()) {
	        //return busca (r->getEsq, v);
	    }else if (v>r->getChave()){
	        //return busca (r->getDir, v);
	    }else return r;
	}

	int Menor (No* no){
		if (no != NULL && no->getEsq() == NULL){
			return no->getChave();
		}else{
			return Menor(no->getEsq());
		}
		return 0;
	}

	int Maior (No* no){
		if (no != NULL && no->getDir() == NULL){
			return no->getChave();
		}else{
			return Maior(no->getDir());
		}
		return 0;
	}

};

void ni();
void pausa();

int main() {

	Arvore arvore;
	No *no;


	arvore.inserir(50)
	arvore.inserir(40)
	arvore.inserir(30)
	arvore.inserir(13)
	arvore.inserir(12)
	arvore.inserir(11)
	arvore.emOrdem(arvore.getRaiz());


	while (true) {


		cout << "\n0 - sair do programa";
		cout << "\n1 - inserir um elemento";
		cout << "\n2 - imprimir a árvore em ordem";
		cout << "\n3 - imprimir a árvore em pré-ordem";
		cout << "\n4 - imprimir a árvore em pós-ordem";
		cout << "\n5 - contar os elementos (sem impressao)";
		cout << "\n6 - localizar um elemento pelo seu valor";
		cout << "\n7 - achar o menor elemento (menor valor)";
		cout << "\n8 - achar o maior elemento (maior valor)";
		cout << "\n\nInforme sua opcao: ";
		int opc;
		cin >> opc;

		if (opc == 0) {
			break;
		} else if (opc == 1) {
			int opc1;
			cout << "Valor do elemento: ";
			cin >> opc1;
			arvore.inserir(opc1);
			system("pause");
		} else if (opc == 2) {
			arvore.emOrdem(arvore.getRaiz());
		} else if(opc == 3) {
			arvore.preOrdem(arvore.getRaiz());
		} else if (opc == 4) {
			arvore.posOrdem(arvore.getRaiz());
		} else if (opc == 5) {
			cout<<arvore.count(arvore.getRaiz());
		} else if (opc == 6) {
			int opc6;
			No* busca;
			cout << "Buscar por: ";
			cin >> opc6;
			busca = arvore.busca(arvore.getRaiz(), opc6);
			if (busca != NULL){
				no->display(busca);
			}else{
				cout << "Valor nao encontrado na arvore.";
			}
		} else if (opc == 7) {
			cout<< arvore.Menor(arvore.getRaiz());
		} else if (opc == 8) {
			cout<< arvore.Maior(arvore.getRaiz());
		}

		cout << "\n\n\n";

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




