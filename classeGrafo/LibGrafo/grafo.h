#ifndef GRAFO_H
#define GRAFO_H

#include "vertice.h"
#include "aresta.h"
//#include "igrafo.h"     //. Não estou usando herança entre a classe Grafo e IGrafo, porém, a classe Grafo segue o contrato de IGrafo.
#include <stdio.h>

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

    void setInicioListaAresta(NoAresta * inicioListaAresta) { this->inicioListaAresta = inicioListaAresta; }
    void setAnteriorListaAresta(NoAresta * anteriorListaAresta) { this->anteriorListaAresta = anteriorListaAresta; }
    void setQteArestas(int qte) { this->qteArestas = qte; }
    void setPosAtualAresta(int posicao) { this->posAtualAresta = posicao; }


    friend class Grafo; // Da acesso aos elementos da classe NoVertice para a classe Grafo
};



// Lista simplesmente encadeada para os vértices
//class Grafo : public IGrafo {
class Grafo {
protected:
    NoVertice *inicioListaVertice;   // Aponta para o inicio da lista
    NoVertice *anteriorListaVertice; // Para auxilio em percorrer a lista
    int qteVertices;      // Quantidade de nos
    int posAtualVertice;  // Posicao atual
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


};

#endif // GRAFO_H
