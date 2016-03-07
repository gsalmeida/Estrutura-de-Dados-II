#include <stdio.h>
#include "vertice.h"
#include "aresta.h"
#include "grafo.h"

using namespace std;

int main() {

	Grafo * grafo = new Grafo();
    Vertice * vertice1 = new Vertice(1);
    Vertice * vertice2 = new Vertice(2);
    Vertice * vertice3 = new Vertice(3);
    Vertice * vertice4 = new Vertice(4);
    Vertice * vertice5 = new Vertice(5);
    Vertice * vertice6 = new Vertice(6);
    Vertice * vertice7 = new Vertice(7);
    //----------------------------------------------------------------------------------------------------
	grafo->adicioneVertice(vertice7);
	grafo->adicioneVertice(vertice6);
	grafo->adicioneVertice(vertice5);
	grafo->adicioneVertice(vertice4);
	grafo->adicioneVertice(vertice3);
	grafo->adicioneVertice(vertice2);
    grafo->adicioneVertice(vertice1);
    //----------------------------------------------------------------------------------------------------
	grafo->adicioneAresta(new Aresta(vertice1, vertice3, 7));
	grafo->adicioneAresta(new Aresta(vertice1, vertice2, 5));

	grafo->adicioneAresta(new Aresta(vertice2, vertice3, 9));
	grafo->adicioneAresta(new Aresta(vertice2, vertice5, 15));
	grafo->adicioneAresta(new Aresta(vertice2, vertice6, 6));

	grafo->adicioneAresta(new Aresta(vertice3, vertice5, 7));
	grafo->adicioneAresta(new Aresta(vertice3, vertice4, 8));

//	grafo->adicioneAresta(new Aresta(vertice4, vertice5, 5));
	grafo->adicioneAresta(new Aresta(vertice5, vertice4, 5));

	grafo->adicioneAresta(new Aresta(vertice5, vertice7, 9));

	grafo->adicioneAresta(new Aresta(vertice6, vertice7, 11));
	grafo->adicioneAresta(new Aresta(vertice6, vertice5, 8));
	//----------------------------------------------------------------------------------------------------

	printf("\n\n_________________________________________\n\n");
	printf("\n\t\tGRAFO\t\t\n");
	grafo->mostraGrafo();
	printf("\n");

	printf("\n\nBUSCA EM PROFUNDIDADE:\n\n");
	grafo->buscaEmProfundidade(1);
	printf("\n\n_________________________________________\n\n");
	grafo->inicializarCamposVisitadoParaTodosVertices();
	printf("\n\n_________________________________________\n\n");
	printf("\n\nBUSCA EM LARGURA:\n\n");
	grafo->buscaEmLargura(5);
	printf("\n");


	//A arvore monta ok nestes tres exemplos abaixo.
	ArvoreN * arvoreNTeste = grafo->montaArvoreNAria();
//	ArvoreN * arvoreNTeste = grafo->montaArvoreNAria(1);
//	ArvoreN * arvoreNTeste = grafo->montaArvoreNAria(1, 3);
	if(arvoreNTeste) {
		printf("\n\nÁRVORE N-ÁRIA GERADA A PARTIR DO GRAFO:\n\n__________________________________________________________________________________________\n");
		arvoreNTeste->preOrder(arvoreNTeste);  // arvoreNTeste->preOrder2(arvoreNTeste);
		printf("\n\nAPÓS EXCLUSÃO REVERSA:\n\n__________________________________________________________________________________________\n");
		grafo->exclusaoReversa();
		arvoreNTeste->~ArvoreN();
		arvoreNTeste = grafo->montaArvoreNAria();
//		arvoreNTeste = grafo->montaArvoreNAria(1);
//		arvoreNTeste = grafo->montaArvoreNAria(1, 3);
		if(arvoreNTeste) {
			arvoreNTeste->preOrder(arvoreNTeste);
			printf("\n\n_________________________________________\n\n");
			grafo->mostraGrafo();
			printf("\n\n\n");
		}
	}

//	getNoVerticePelaPosicao(0);
//	Vertice * verticeAux = grafo->getNoVerticePelaPosicao(0)->getDado();
//	if(verticeAux) grafo->preOrder(new ArvoreN(verticeAux));

	return 0;

}

