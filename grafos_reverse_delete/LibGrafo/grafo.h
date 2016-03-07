#ifndef GRAFO_H
#define GRAFO_H

#include "vertice.h"
#include "aresta.h"
//#include "igrafo.h"     //. Não estou usando herança entre a classe Grafo e IGrafo, porém, a classe Grafo segue o contrato de IGrafo.
#include <stdio.h>

//O Grafo é uma árvore
#include "naria/arvoren.h"


class NoVertice; // Necessario para NoVertice saber que existe a classe Grafo como amiga
//class Grafo; // Necessario para NoVertice saber que existe a classe Grafo como amiga
class NoAresta {
protected:
    Aresta* dado;
    NoAresta*   proximo;
public:
    NoAresta(Aresta *i);
    NoAresta(NoAresta& n);
    ~NoAresta();

    void setProximo(NoAresta* a) { this->proximo = a; }
    NoAresta * getProximo () { return this->proximo; }

    void setDado(Aresta * dado) { this->dado = dado; }
    Aresta * getDado() { return this->dado; }

    friend class NoVertice; // Da acesso aos elementos da classe NoAresta para a classe NoVertice
//    friend class Grafo;
};


class Grafo; // Necessario para NoVertice saber que existe a classe Grafo como amiga
// NoVertice da lista. Nao deve aparecer publicamente
class NoVertice {
protected:
    Vertice* dado;
    NoVertice*   proximo;

    NoAresta *inicioListaAresta;   // Aponta para o inicio da lista
    NoAresta *anteriorListaAresta; // Para auxilio em percorrer a lista
	int qteArestas;      // Quantidade de nos
	int posAtualAresta;  // Posicao atual

public:
    NoVertice(Vertice *i);
    NoVertice(NoVertice& n);
    ~NoVertice();

    NoAresta* getInicioListaAresta() { return this->inicioListaAresta; }
    NoAresta* getAnteriorListaAresta() { return this->anteriorListaAresta; }
    int getQteArestas() { return this->qteArestas; }
    int getPosAtualAresta() { return this->posAtualAresta; }
    Vertice * getDado() { return dado; }
    void setInicioListaAresta(NoAresta * inicioListaAresta) { this->inicioListaAresta = inicioListaAresta; }
    void setAnteriorListaAresta(NoAresta * anteriorListaAresta) { this->anteriorListaAresta = anteriorListaAresta; }
    void setQteArestas(int qte) { this->qteArestas = qte; }
    void setPosAtualAresta(int posicao) { this->posAtualAresta = posicao; }


    friend class Grafo; // Da acesso aos elementos da classe NoVertice para a classe Grafo
};



// Lista simplesmente encadeada para os vértices
//class Grafo : public IGrafo {
//class Grafo {

//O grafo é uma Árvore-Nária
class Grafo {
protected:
    NoVertice *inicioListaVertice;   // Aponta para o inicio da lista
    NoVertice *anteriorListaVertice; // Para auxilio em percorrer a lista
    int qteVertices;      // Quantidade de nos
    int posAtualVertice;  // Posicao atual
    ArvoreN * arvoreN;
//    ArvoreN * raiz;
//    ArvoreN * arvoreNFilhoAtual;
//    ArvoreN * arvoreNPaiAtual;

//    int visitado;
//    pai e ou filhos   -> para montar a Árvore N-ária resultado.

public:
    Grafo();      // Construtor default - Lista vazia
    Grafo(Grafo &); // Construtor de copia
    ~Grafo();     // Destrutor da lista


//    Inclui o elemento na posAtualVerticeicao desejada
    void adicioneVertice(Vertice *v);
	Vertice *getVertice(unsigned id);
	Vertice * getVerticePelaPosicao(unsigned posicao);
	NoVertice * getNoVerticePelaPosicao(unsigned posicao);
	void excluaVertice(unsigned id);
	// Pesquisa o elemento pelo seu id e retorna a sua posicao
	int pesquisarVerticePorId (Vertice* i);
	void mostrarVertices();
	int quantidadeVertices(void) {return qteVertices;};

	ArvoreN * getArvoreN () { return this->arvoreN; }
//	ArvoreN * getArvoreNFilhoAtual () { return this->arvoreNFilhoAtual; }
//	ArvoreN * getArvoreNPaiAtual () { return this->arvoreNPaiAtual; }


	void adicioneAresta(Aresta *a);
	void adicionaAjdacentes(NoVertice *v, Aresta *a);
	Aresta *getAresta(unsigned id);
	Aresta *getAresta(Vertice *s, Vertice *c);
	void excluaAresta(Vertice *s, Vertice *c);
//	virtual void excluaAresta(Vertice *s, Vertice *c) = 0;   // Se fosse filha de IGrafo

//     Sobrecarga da atribuicao (deep copy)
//     Grafo& operator= (Grafo &outra);

	void mostraGrafo();
    void buscaEmProfundidade(unsigned idPartida);
    void inicializarCamposVisitadoParaTodosVertices();
    void buscaEmLargura(unsigned idPartida);


    ArvoreN * montaArvoreNAria(unsigned idPartida = 0, unsigned idChegada = 0, ArvoreN * arvoreN = 0) {
    	for(int a = 0, a2 = 0; getNoVerticePelaPosicao(a); a++) {
				Vertice * verticeAux = getNoVerticePelaPosicao(a)->dado;
				if(verticeAux) {
					if(!idPartida) idPartida = verticeAux->getId();
					if(verticeAux->getId() == idPartida) {
//						if(!(verticeAux->getVisitado())) {
//							verticeAux->setVisitado(1);
							if(!(verticeAux->getVisitado())) verticeAux->setVisitado(1);

							if(!arvoreN) {
//								arvoreN = getArvoreN();
								arvoreN = new ArvoreN(verticeAux);
							}
							else ArvoreN * novoFilho = new ArvoreN(verticeAux);

							NoVertice * noVerticeAux = getNoVerticePelaPosicao(a);
							NoAresta * noArestaAux = noVerticeAux->getInicioListaAresta();
							for(; noArestaAux; noArestaAux = noArestaAux->getProximo()) {
//								ArvoreN * existeArvoreN = arvoreN->getArvoreNPeloIddaInfo(getArvoreN(), noArestaAux->getDado()->getChegada()->getId());
//								if(existeArvoreN) printf("\n >>> %d <<< \n", existeArvoreN->getInfo()->getId());
								ArvoreN * arvoreNFilhoAtual = new ArvoreN(noArestaAux->getDado()->getChegada());
								arvoreN->setFilho(arvoreNFilhoAtual, a2);
								a2++;
								if(noArestaAux->getDado()->getChegada()->getId() != idChegada)
									montaArvoreNAria(noArestaAux->getDado()->getChegada()->getId(), idChegada, arvoreNFilhoAtual);
							}
//						}
//						else {
//							ArvoreN * arvoreNFilhoAtual = arvoreN->getArvorePeloIddaInfo(arvoreN, verticeAux->getId());
//							printf("\n--->%d<---\n", arvoreNFilhoAtual->getInfo()->getId());
////							ArvoreN * arvoreNFilhoAtual = arvoreN->getArvorePeloIddaInfo(idPartida);
////							arvoreN->setFilho(arvoreNFilhoAtual, arvoreN->getFilhos()->quantidade());
//						}
					}
				}
		}
    	return arvoreN;
    }

    Aresta * getArestaMaiorCusto() {
    	unsigned id = 0;
    	Aresta * arestaRetorno;
    	for(int a = 0; getNoVerticePelaPosicao(a); a++) {
    		Vertice * verticeAuxiliar;
    		if(getNoVerticePelaPosicao(a)->dado) {
					NoVertice * noVerticeAux = getNoVerticePelaPosicao(a);
					NoAresta * noArestaAux = noVerticeAux->getInicioListaAresta();

					for(; noArestaAux; noArestaAux = noArestaAux->getProximo())
						if(noArestaAux->getDado())
							if( (noArestaAux->getDado()->getId() > id) && (podeExcluirArestaNoProcessoDeExclusaoReversa((Aresta *) noArestaAux->getDado())) ) {
								arestaRetorno = noArestaAux->getDado();
								id = noArestaAux->getDado()->getId();
							}

//    			}
    		}
    	}
    	if(arestaRetorno) return arestaRetorno;
    	arestaRetorno = new Aresta(new Vertice(0), new Vertice(0), 0);
//    	return arestaRetorno;
    }


    // se consegue chegar na chegada da aresta a partir de outro inicio, a não ser o da própria aresta.
    int podeExcluirArestaNoProcessoDeExclusaoReversa(Aresta * arestaPar) {
    	for(int a = 0; getNoVerticePelaPosicao(a); a++) {
    		if(getNoVerticePelaPosicao(a)->dado) {
    			Vertice * verticeAux = getNoVerticePelaPosicao(a)->dado;
    			if(verticeAux != arestaPar->getPartida()) {
					NoVertice * noVerticeAux = getNoVerticePelaPosicao(a);
					NoAresta * noArestaAux = noVerticeAux->getInicioListaAresta();
					for(; noArestaAux; noArestaAux = noArestaAux->getProximo())
						if(noArestaAux->getDado())
							if(noArestaAux->getDado()->getChegada()->getId() == arestaPar->getChegada()->getId()) return 1;
    			}
			}
		}
    	return 0;
    }

    void exclusaoReversa() {
    	Aresta * aresta;
    	int a  = 0;
    	aresta = getArestaMaiorCusto();
    	printf("\nARESTAS REMOVIDAS NA EXCLUSÃO REVERSA.\n");
    	for(; aresta->getPartida(); ) {
    		printf("\nARESTA(PARTIDA, CHEGADA, CUSTO): %d ===> %d ===> %d\n", aresta->getPartida()->getId(), aresta->getChegada()->getId(),aresta->getId());
    		excluaAresta((Vertice *) aresta->getPartida(), (Vertice *) aresta->getChegada());
    		aresta = getArestaMaiorCusto();
    	}
    }


//    void exclusaoReversaInformandoGrafo(unsigned idPartida = 0, Grafo * grafo) {
//		Aresta * aresta;
//		int a  = 0;
//		aresta = grafo->getArestaMaiorCusto(idPartida, Grafo * grafo);
//		printf("\nARESTAS REMOVIDAS NA EXCLUSÃO REVERSA.\n");
//		for(; aresta->getPartida(); ) {
//			printf("\nARESTA(PARTIDA, CHEGADA, CUSTO): %d ===> %d ===> %d\n", aresta->getPartida()->getId(), aresta->getChegada()->getId(),aresta->getId());
//			grafo->excluaAresta((Vertice *) aresta->getPartida(), (Vertice *) aresta->getChegada());
//			aresta = grafo->getArestaMaiorCusto(idPartida, Grafo * grafo);
//		}
//	}



};

#endif // GRAFO_H

//g++ aresta.cpp coordenada.cpp grafo.cpp igrafo.cpp pontodeinteresse.cpp texto.cpp vertice.cpp via.cpp mainAntigo.cpp ./naria/lse.cpp ./naria/info.cpp ./naria/arvoren.cpp -o teste
