#include "listaDuplamenteEncadeada.h"
#include <stdio.h>
#include <math.h>

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada() {
	ponteiro[ANT] = ponteiro[PROX] = 0;
	this->info = NULL;
}

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada(Info *info) {
	ponteiro[ANT] = ponteiro[PROX] = 0;
	this->info = info;
	this->ponteiro[PRIMEIRO] = this;
}


ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada() {
	ListaDuplamenteEncadeada *lista = this->ponteiro[PRIMEIRO];
	ListaDuplamenteEncadeada *listaAux;
	while (lista != NULL) {
		listaAux = lista;
		lista = lista->ponteiro[PROX];
		listaAux->setPonteiro(NULL, ANT);
		listaAux->setPonteiro(NULL, PROX);
		delete (listaAux->info);
//		delete (listaAux);
	}
	this->setPonteiro(NULL, PRIMEIRO);
//	delete (listaAux);
}

void ListaDuplamenteEncadeada::inserir(Info* elemento, int posicao) {
	if (posicao < 0) return;
	//Nada tem na lista.
	if( (this->ponteiro[ANT] == 0) && (this->ponteiro[PROX] == 0) && (this->info == NULL) ) {
		this->info = elemento;
		this->ponteiro[ANT] = NULL;
		this->ponteiro[PROX] = NULL;
		this->ponteiro[PRIMEIRO] = this;
	}else {
		Info *infoAux = elemento;
//		if(infoAux) {
			ListaDuplamenteEncadeada *listaNova = new ListaDuplamenteEncadeada();
			ListaDuplamenteEncadeada *listaAtual = this->ponteiro[PRIMEIRO];
			if (!posicao) {
				listaNova->setInfo(infoAux);
				listaNova->ponteiro[PROX] = listaAtual;
				listaNova->ponteiro[ANT] = NULL;
				if (listaAtual != NULL) listaAtual->ponteiro[ANT] = listaNova;
				listaAtual = listaNova;
				this->ponteiro[PRIMEIRO] = listaAtual;
			} else {
				int contador = 0;
				ListaDuplamenteEncadeada *listaAux = this->ponteiro[PRIMEIRO];
				while(listaAux != NULL) {
					if(contador == posicao) {
						ListaDuplamenteEncadeada *anterior = (listaAux->ponteiro[ANT] == NULL) ? NULL : listaAux->ponteiro[ANT];
						ListaDuplamenteEncadeada *proximo = (listaAux == NULL) ? NULL : listaAux;

						listaNova->setInfo(infoAux);
						listaNova->ponteiro[PROX] = proximo;
						listaNova->ponteiro[ANT] = anterior;

						if(proximo) proximo->ponteiro[ANT] = listaNova;
						if(anterior) anterior->ponteiro[PROX] = listaNova;
						break;
					}
					contador++;
					listaAux = listaAux->ponteiro[PROX];
				}

			}
//		}

	}
}


void ListaDuplamenteEncadeada::mostrarLista()  {
	ListaDuplamenteEncadeada *listaAtual = this->ponteiro[PRIMEIRO];
	printf("\nLISTA DUPLAMENTE ENCADEADA\n");
	while(listaAtual != NULL) {
//		printf("\t | (%d)<-(%d)->(%d)  | \t",
//				(listaAtual->ponteiro[ANT] == NULL) ? -9999 : listaAtual->ponteiro[ANT]->getInfo()->getId(),
//				listaAtual->getInfo()->getId(),
//				(listaAtual->ponteiro[PROX] == NULL) ? -9999 : listaAtual->ponteiro[PROX]->getInfo()->getId() );
		printf(" <-(%d)-> ", listaAtual->getInfo()->getId());
		listaAtual = listaAtual->ponteiro[PROX];
	}
	printf("\n");
}


Info* ListaDuplamenteEncadeada::obter(int posicao) {
	if(posicao < 0) return NULL;
	ListaDuplamenteEncadeada *listaAtual = this->ponteiro[PRIMEIRO];
	int contador = 0;
	while(listaAtual != NULL) {
		if(contador == posicao) return listaAtual->info;
		listaAtual = listaAtual->ponteiro[PROX];
		contador++;
	}
//	return listaAtual->info;
	return NULL;
}


Info* ListaDuplamenteEncadeada::remover(int posicao) {
	if(posicao < 0) return NULL;
	ListaDuplamenteEncadeada *listaAtual = this->ponteiro[PRIMEIRO];
	if(!posicao) {
		ListaDuplamenteEncadeada *proximo = (listaAtual->ponteiro[PROX] == NULL) ? NULL : listaAtual->ponteiro[PROX];
		Info *informacaoRetorno = new Info(listaAtual->info->getId());
		if(proximo != NULL) {
			proximo->setPonteiro(NULL, ANT);
			listaAtual->ponteiro[PROX] = NULL;
			listaAtual->info = NULL;
			delete(listaAtual->info);
//			delete(listaAtual);
			this->setPonteiro(proximo, PRIMEIRO);
			return informacaoRetorno;
		} else {
			listaAtual->info = NULL;
			delete(listaAtual->info);
//			delete(listaAtual);
			this->setPonteiro(0, PRIMEIRO);
			return informacaoRetorno;
		}
	} else {
		int contador = 0;
		while(listaAtual != NULL) {
			if(contador == posicao) {
				ListaDuplamenteEncadeada *ldeAnterior = listaAtual->ponteiro[ANT];
				ListaDuplamenteEncadeada *ldeProximo = (listaAtual->ponteiro[PROX] == NULL) ? NULL : listaAtual->ponteiro[PROX];
				Info *informacaoRetorno = new Info(listaAtual->info->getId());
				if(ldeProximo != NULL) {
					ldeAnterior->setPonteiro(ldeProximo, PROX);
					ldeProximo->setPonteiro(ldeAnterior, ANT);
				} else ldeAnterior->setPonteiro(NULL, PROX);
				listaAtual->info = NULL;
				delete(listaAtual->info);
//				delete(listaAtual);
				return informacaoRetorno;
			}
			listaAtual = listaAtual->ponteiro[PROX];
			contador++;
		}
	}
//	return listaAtual->info;
	return NULL;
}

Info* ListaDuplamenteEncadeada::pesquisarPoId(Info* i) {
	ListaDuplamenteEncadeada *listaAtual = this->ponteiro[PRIMEIRO];
	while(listaAtual != NULL) {
		if(i->getId() == listaAtual->info->getId()) {
			Info *infoAux = listaAtual->info;
			return infoAux;
		}
		listaAtual = listaAtual->ponteiro[PROX];
	}
//	return listaAtual->info;
	return NULL;
}

void ListaDuplamenteEncadeada::setPonteiro(ListaDuplamenteEncadeada *listaDuplamenteEncadeada, Lado lado) {
	ponteiro[lado] = listaDuplamenteEncadeada;
}

ListaDuplamenteEncadeada* ListaDuplamenteEncadeada::getPonteiro(Lado lado) {
	return ponteiro[lado];
}

ListaDuplamenteEncadeada &ListaDuplamenteEncadeada::operator=(ListaDuplamenteEncadeada &listaParametro) {
//	this->~ListaDuplamenteEncadeada();
//	printf("OLÁ");
//	ListaDuplamenteEncadeada *lista = &listaParametro;
//	ListaDuplamenteEncadeada *listaAux;
//	int contador = 0;
//	while (lista != NULL) {
//		listaAux = lista;
//		lista = lista->ponteiro[PROX];
//		this->inserir(listaAux->info, contador);
//		contador++;
//	}

}



