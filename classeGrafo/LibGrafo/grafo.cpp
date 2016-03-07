#include "grafo.h"
#include <stdio.h>

NoVertice::NoVertice(Vertice *i) {
	dado = i;
	proximo = 0;
}

NoVertice::NoVertice(NoVertice& n) {
	dado = new Vertice(*(n.dado));
	proximo = 0;
}

NoVertice::~NoVertice() {
	dado = 0;
}


NoAresta::NoAresta(Aresta *i) {
	dado = i;
	proximo = 0;
}

NoAresta::NoAresta(NoAresta& n) {
	dado = new Aresta(*(n.dado));
	proximo = 0;
}

NoAresta::~NoAresta() {
	dado = 0;
}

//Grafo::Grafo(unsigned numVertices, unsigned numArestas) : IGrafo (numVertices, numArestas) {
Grafo::Grafo() {
	inicioListaVertice = anteriorListaVertice = 0;
	qteVertices = posAtualVertice = 0;
//	visitado = 0;
}

// Construtor de copia - Questao 1
Grafo::Grafo(Grafo& outra) {
	// Copiar a lista outra
	this->qteVertices = outra.qteVertices;
	this->posAtualVertice = 0;
	if (outra.qteVertices) {
		this->inicioListaVertice = new NoVertice(*outra.inicioListaVertice);
		this->anteriorListaVertice = this->inicioListaVertice;
		for (NoVertice *p = outra.inicioListaVertice->proximo; p; p =p->proximo) {
			this->anteriorListaVertice->proximo = new NoVertice(*p);
			this->anteriorListaVertice = this->anteriorListaVertice->proximo;
		}
	} else {
		this->inicioListaVertice = 0;
	}
	this->anteriorListaVertice = 0;
}

// Destrutor - Questao 7
//Não está destruindo as arestas.
Grafo::~Grafo() {
	printf("\nDESTRUTOR DE GRAFO.\n");
	while (this->inicioListaVertice) {
		this->anteriorListaVertice = this->inicioListaVertice; //anterior Vertice
		this->inicioListaVertice = this->inicioListaVertice->proximo; //proximo Vertice
//		NoAresta * arestaInicio = this->inicioListaVertice->getInicioListaAresta(); //anterior Aresta
//		NoAresta * arestaProxmo = arestaInicio->getProximo(); //proximo Aresta
		delete this->anteriorListaVertice;
	}
}

//void Grafo::inserir (Vertice *elemento, int posicao){
void Grafo::adicioneVertice(Vertice *v) {
	if (!v)
		return;
	NoVertice* novo = new NoVertice(v);
	novo->proximo = inicioListaVertice;
	inicioListaVertice = novo;
	anteriorListaVertice = 0;
	posAtualVertice = 0;
	qteVertices++;
}


void Grafo::excluaVertice(unsigned id) {
	int posicao = pesquisarVerticePorId(new Vertice(id));
	if ((posicao >= qteVertices) || (posicao < 0)) return;
	Vertice* retorno;
	if (posicao) {
		int p;
		NoVertice *a;
		if (anteriorListaVertice && (posicao >= posAtualVertice))
			for (p = posAtualVertice, a = anteriorListaVertice; (p < posicao) && a->proximo; p++, a = a->proximo);
		else
			for (p = 1, a = inicioListaVertice; (p < posicao) && a->proximo; p++, a = a->proximo);
		if (a->proximo) {
			anteriorListaVertice = a;
			a = a->proximo;
			anteriorListaVertice->proximo = a->proximo;
			retorno = a->dado;
			delete a;
			posAtualVertice = p;
		} else return;
	} else {
		anteriorListaVertice = inicioListaVertice;
		inicioListaVertice = inicioListaVertice->proximo;
		retorno = anteriorListaVertice->dado;
		delete anteriorListaVertice;
		anteriorListaVertice = 0;
		posAtualVertice = 0;
	}
	qteVertices--;
	return;
}


void Grafo::excluaAresta(Vertice *s, Vertice *c) {
	for(int a = 0; getNoVerticePelaPosicao(a); a++) {
		Vertice * verticeAux = getNoVerticePelaPosicao(a)->dado;
		if(verticeAux) if(verticeAux->getId() == s->getId()) {
			NoVertice * noVerticeAux = getNoVerticePelaPosicao(a);
			NoAresta * noArestaAux = noVerticeAux->getInicioListaAresta();
			for(int b = 0; noArestaAux; noArestaAux = noArestaAux->getProximo(), b++) {
				//se if, eh pq eh essa a posicao da aresta a ser exlcuída.
				if( (noArestaAux->getDado()->getPartida()->getId() == s->getId()) && (noArestaAux->getDado()->getChegada()->getId() == c->getId()) ) {
					Aresta* retorno;
					int posicao = b;
					if (posicao) {
						int p;
						NoAresta *a;
						if (noVerticeAux->getAnteriorListaAresta() && (posicao >= noVerticeAux->getPosAtualAresta()))
							for (p = noVerticeAux->getPosAtualAresta(), a = noVerticeAux->getAnteriorListaAresta(); (p < posicao) && a->getProximo(); p++, a = a->getProximo());
						else
							for (p = 1, a = noVerticeAux->getInicioListaAresta(); (p < posicao) && a->getProximo(); p++, a = a->getProximo());
						if (a->getProximo()) {
							noVerticeAux->setAnteriorListaAresta(a);
							a = a->getProximo();
							noVerticeAux->getAnteriorListaAresta()->setProximo(a->getProximo());
							retorno = a->getDado();
							delete a;
							noVerticeAux->setPosAtualAresta(p);
						} else return;
					} else {
						noVerticeAux->setAnteriorListaAresta(noVerticeAux->getInicioListaAresta());
						noVerticeAux->setInicioListaAresta(noVerticeAux->getInicioListaAresta()->getProximo());
						retorno = noVerticeAux->getAnteriorListaAresta()->getDado();
						delete noVerticeAux->getAnteriorListaAresta();
						noVerticeAux->setAnteriorListaAresta(0);
						noVerticeAux->setPosAtualAresta(0);
					}
					noVerticeAux->setQteArestas( (noVerticeAux->getQteArestas() - 1) );
					return;
				}
			}
		}
	}
}

int Grafo::pesquisarVerticePorId(Vertice* i) {
	if (qteVertices && i) {
		posAtualVertice = 0;
		anteriorListaVertice = 0;
		if (inicioListaVertice->dado->getId() != i->getId()) {
			posAtualVertice = 1;
			anteriorListaVertice = inicioListaVertice;
			while (anteriorListaVertice->proximo && (anteriorListaVertice->proximo->dado->getId() != i->getId())) {
				posAtualVertice++;
				anteriorListaVertice = anteriorListaVertice->proximo;
			}
			if (anteriorListaVertice->proximo) return posAtualVertice;
		} else return 0;
	}
	return -1;
}

void Grafo::mostrarVertices() {
	if (qteVertices) {
		posAtualVertice = 0;
		anteriorListaVertice = 0;
		if (inicioListaVertice->dado) {
			printf("\n\nVertice: %d \n\n", inicioListaVertice->dado->getId());
			posAtualVertice = 1;
			anteriorListaVertice = inicioListaVertice;
			while (anteriorListaVertice->proximo && (anteriorListaVertice->proximo->dado)) {
				printf("\n\nVertice: %d \n\n", anteriorListaVertice->proximo->dado->getId());
				posAtualVertice++;
				anteriorListaVertice = anteriorListaVertice->proximo;
			}
			if (anteriorListaVertice->proximo) return;
		} else return;
	}
	return;
}

Vertice* Grafo::getVertice(unsigned id) {
	for(int a = 0; getVerticePelaPosicao(a); a++) if(getVerticePelaPosicao(a)->getId() == id) return getVerticePelaPosicao(a);
	return 0;
}

NoVertice* Grafo::getNoVerticePelaPosicao(unsigned posicao) {
	if (qteVertices) {
		if (posicao) {
			if (posicao < 0) return 0;
			else {
				int p;
				NoVertice *a;

				if (anteriorListaVertice && (posicao >= posAtualVertice))
					for (p = posAtualVertice, a = anteriorListaVertice; (p < posicao) && a->proximo; p++, a = a->proximo);
				else
					for (p = 1, a = inicioListaVertice; (p < posicao) && a->proximo; p++, a = a->proximo);
				if (a->proximo) {
					posAtualVertice = p;
					anteriorListaVertice = a;
					return a->proximo;
				}
			}
		} else {
			posAtualVertice = 0;
			anteriorListaVertice = 0;
			return inicioListaVertice;
		}
		return 0;
	}
	return 0;
}



Vertice* Grafo::getVerticePelaPosicao(unsigned posicao) {
	if (qteVertices) {
		if (posicao) {
			if (posicao < 0) return 0;
			else {
				int p;
				NoVertice *a;

				if (anteriorListaVertice && (posicao >= posAtualVertice))
					for (p = posAtualVertice, a = anteriorListaVertice; (p < posicao) && a->proximo; p++, a = a->proximo);
				else
					for (p = 1, a = inicioListaVertice; (p < posicao) && a->proximo; p++, a = a->proximo);
				if (a->proximo) {
					posAtualVertice = p;
					anteriorListaVertice = a;
					return a->proximo->dado;
				}
			}
		} else {
			posAtualVertice = 0;
			anteriorListaVertice = 0;
			return inicioListaVertice->dado;
		}
		return 0;
	}
	return 0;
}




void Grafo::adicionaAjdacentes(NoVertice *noVertice, Aresta *a) {
	if ( (!noVertice) || (!a) ) return;
	NoAresta* novaAresta = new NoAresta(a);
	novaAresta->setProximo(noVertice->getInicioListaAresta());
	noVertice->setInicioListaAresta(novaAresta);
	noVertice->setAnteriorListaAresta(0);
	noVertice->setPosAtualAresta(0);
	int novaQtdeArestas = noVertice->getQteArestas(); novaQtdeArestas++;
	noVertice->setQteArestas(novaQtdeArestas);
}

void Grafo::adicioneAresta(Aresta *aresta) {
	Vertice * partida = aresta->getPartida();
	Vertice * chegada = aresta->getChegada();

	for(int a = 0; getVerticePelaPosicao(a); a++)
		if(getVerticePelaPosicao(a)->getId() == partida->getId()) {
			// este vértice verticePontoPartida que irá adicionar as arestas, visto que é ele o ponto de partida, ou seja, o vértice inicial da aresta.
			NoVertice * noVerticePontoPartida =  getNoVerticePelaPosicao(a);
			printf("\nTESTE: %d\n", noVerticePontoPartida->dado->getId());
			adicionaAjdacentes(noVerticePontoPartida, aresta);
		}
}

Aresta * Grafo::getAresta(unsigned id) {
	for(int a = 0; getNoVerticePelaPosicao(a); a++) {
		if(getNoVerticePelaPosicao(a)->dado) {
			NoVertice * noVerticeAux = getNoVerticePelaPosicao(a);
			NoAresta * noArestaAux = noVerticeAux->getInicioListaAresta();
			for(; noArestaAux; noArestaAux = noArestaAux->getProximo())
				if(noArestaAux->getDado())
					if(noArestaAux->getDado()->getId() == id)  {
						Aresta * arestaRetorno = noArestaAux->getDado();
						return arestaRetorno;
					}

		}
	}
	return 0;
}

Aresta * Grafo::getAresta(Vertice *s, Vertice *c) {
	if( (!s) || (!c) ) return 0;
	for(int a = 0; getNoVerticePelaPosicao(a); a++) {
		if(getNoVerticePelaPosicao(a)->dado) if(getNoVerticePelaPosicao(a)->dado->getId() == s->getId()) {
//		if(getNoVerticePelaPosicao(a)->dado) {
			NoVertice * noVerticeAux = getNoVerticePelaPosicao(a);
			NoAresta * noArestaAux = noVerticeAux->getInicioListaAresta();
			for(; noArestaAux; noArestaAux = noArestaAux->getProximo())
				if(noArestaAux->getDado())
					if( (noArestaAux->getDado()->getPartida()->getId() == s->getId()) && (noArestaAux->getDado()->getChegada()->getId() == c->getId()) ) {
						Aresta * arestaRetorno = noArestaAux->getDado();
						return arestaRetorno;
					}
		}
	}
	return 0;
}


void Grafo::mostraGrafo() {
	for(int a = 0; getNoVerticePelaPosicao(a); a++) {
		if(getNoVerticePelaPosicao(a)->dado) {
			printf("\nVERTICE: %d\n", getNoVerticePelaPosicao(a)->dado->getId());
			NoVertice * noVerticeAux = getNoVerticePelaPosicao(a);
			NoAresta * noArestaAux = noVerticeAux->getInicioListaAresta();
			for(; noArestaAux; noArestaAux = noArestaAux->getProximo())
				printf("\nARESTA (partida, chegada, id): .%d. .%d. .%d. \n", noArestaAux->getDado()->getPartida()->getId(),
						noArestaAux->getDado()->getChegada()->getId(), noArestaAux->getDado()->getId());
		}
	}
}

void Grafo::buscaEmProfundidade(unsigned idPartida) {
	for(int a = 0; getNoVerticePelaPosicao(a); a++) {
//			if(getNoVerticePelaPosicao(a)->dado) {
			Vertice * verticeAux = getNoVerticePelaPosicao(a)->dado;
			if(verticeAux) {
				if(verticeAux->getId() == idPartida) {
					if(!(verticeAux->getVisitado())) {
						printf("\n %d \n", verticeAux->getId());
						verticeAux->setVisitado(1);
						NoVertice * noVerticeAux = getNoVerticePelaPosicao(a);
						NoAresta * noArestaAux = noVerticeAux->getInicioListaAresta();
						for(; noArestaAux; noArestaAux = noArestaAux->getProximo()) {
							buscaEmProfundidade(noArestaAux->getDado()->getChegada()->getId());
						}
					}
				}
			}
//			}
	}
}



void Grafo::inicializarCamposVisitadoParaTodosVertices() {
	for(int a = 0; getNoVerticePelaPosicao(a); a++) {
		Vertice * verticeAux = getNoVerticePelaPosicao(a)->dado;
		if(verticeAux) {
			verticeAux->setVisitado(0);
			NoVertice * noVerticeAux = getNoVerticePelaPosicao(a);
			NoAresta * noArestaAux = noVerticeAux->getInicioListaAresta();
			for(; noArestaAux; noArestaAux = noArestaAux->getProximo()) {
				noArestaAux->getDado()->getChegada()->setVisitado(0);
			}
		}
	}
}

void Grafo::buscaEmLargura(unsigned idPartida) {
	for(int a = 0; getNoVerticePelaPosicao(a); a++) {
		Vertice * verticeAux0 = getNoVerticePelaPosicao(a)->dado;
			if(verticeAux0) {
				if(verticeAux0->getId() == idPartida) {
					for(int b = a; getNoVerticePelaPosicao(b); b++) {
						Vertice * verticeAux = getNoVerticePelaPosicao(b)->dado;
						if(verticeAux) {
							if(!(verticeAux->getVisitado())) printf("\n %d \n", verticeAux->getId());
							verticeAux->setVisitado(1);
							NoVertice * noVerticeAux = getNoVerticePelaPosicao(b);
							NoAresta * noArestaAux = noVerticeAux->getInicioListaAresta();
							for(; noArestaAux; noArestaAux = noArestaAux->getProximo()) {
								if( !(noArestaAux->getDado()->getChegada()->getVisitado()) ) {
									noArestaAux->getDado()->getChegada()->setVisitado(1);
									printf("\n %d \n", noArestaAux->getDado()->getChegada()->getId());
								}
							}
						}
					}
					break;
				}
			}
	}
}




//// Operador de copia - Faz deep copy da lista, criando copias dos nos E das infos
//Grafo& Grafo::operator=(Grafo &outra) {
//	// Apagar a lista anteriorListaVertice
//	while (this->inicioListaVertice) {
//		this->anteriorListaVertice = this->inicioListaVertice;
//		this->inicioListaVertice = this->inicioListaVertice->proximo;
//		delete this->anteriorListaVertice;
//	}
//	// Copiar a lista outra
//	this->qteVertices = outra.qteVertices;
//	this->posAtualVertice = 0;
//	if (outra.qteVertices) {
//		this->inicioListaVertice = new NoVertice(*outra.inicioListaVertice);
//		this->anteriorListaVertice = this->inicioListaVertice;
//		for (NoVertice *p = outra.inicioListaVertice->proximo; p; p = p->proximo) {
//			this->anteriorListaVertice->proximo = new NoVertice(*p);
//			this->anteriorListaVertice = this->anteriorListaVertice->proximo;
//		}
//	} else {
//		this->inicioListaVertice = 0;
//	}
//	this->anteriorListaVertice = this->inicioListaVertice;
//	return *this;
//}

