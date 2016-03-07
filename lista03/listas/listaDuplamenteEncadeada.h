#include "info.h"

#include <stdio.h>

enum Lado {ANT, PROX, PRIMEIRO};

class ListaDuplamenteEncadeada {
	private:
		Info *info;
		ListaDuplamenteEncadeada *ponteiro[3];

	public:
		ListaDuplamenteEncadeada();
		ListaDuplamenteEncadeada(Info *info);

		~ListaDuplamenteEncadeada();

		void inserir(Info* elemento, int posicao = 0);

		Info* obter(int posicao = 0);
		Info* remover(int posicao = 0);
		Info* pesquisarPoId (Info* i);

		void setPonteiro(ListaDuplamenteEncadeada *listaDuplamenteEncadeada, Lado lado);

		ListaDuplamenteEncadeada* getPonteiro(Lado lado);

		void setInfo(Info *info) {
			this->info = info;
		}

		Info * getInfo() { return this->info; }

		void mostrarLista();

		ListaDuplamenteEncadeada & operator=(ListaDuplamenteEncadeada &listaParametro);

		/*
		void inicializar() {
			ListaDuplamenteEncadeada *lista = this->ponteiro[PRIMEIRO];
			printf("\n INICIALIZAR -> Primeiro item: %d \n", lista->info->getId());
			ListaDuplamenteEncadeada *listaAux;
			while (lista != NULL) {
				listaAux = lista;
				lista = lista->ponteiro[PROX];
				printf("\n  Objeto deletado: %d  \n", listaAux->info->getId());
				listaAux = NULL;
//				delete(listaAux->info);
				delete(listaAux);
			}
		}
		*/


};
