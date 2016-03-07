#include <stdio.h>
#include "vertice.h"
#include "aresta.h"
#include "grafo.h"

using namespace std;

int main() {
//    Vertice no(69);
//    printf ("%s\n", (const char *)(no.toString()));

    Grafo * grafo = new Grafo();
    Vertice * vertice5 = new Vertice(5);
    Vertice * vertice30 = new Vertice(30);
    Vertice * vertice50 = new Vertice(50);
    Vertice * vertice45 = new Vertice(45);
    Vertice * vertice150 = new Vertice(150);
    Vertice * vertice99 = new Vertice(99);
    Vertice * vertice200 = new Vertice(200);


    grafo->adicioneVertice(vertice30);
	grafo->adicioneVertice(vertice50);
	grafo->adicioneVertice(vertice45);
	grafo->adicioneVertice(vertice150);
	grafo->adicioneVertice(vertice99);
	grafo->adicioneVertice(vertice5);
	grafo->adicioneVertice(vertice200);

	printf("\n\n_________________________________________\n\n");

    for(int a = 0; grafo->getVerticePelaPosicao(a); a++) {
    	Vertice *verticeAux = grafo->getVerticePelaPosicao(a);
    	printf("\n.%d.\n", verticeAux->getId());
    }

    printf("\n\n_________________________________________\n\n");


//    grafo->adicioneVertice(new Vertice(30));
//    grafo->adicioneVertice(new Vertice(50));
//    grafo->adicioneVertice(new Vertice(45));
//    grafo->adicioneVertice(new Vertice(150));
//    grafo->adicioneVertice(new Vertice(99));

    grafo->excluaVertice(45);
    grafo->excluaVertice(99);
//    grafo->excluaVertice(30);
//    grafo->excluaVertice(45);
    grafo->mostrarVertices();


    printf("\n\n_________________________________________\n\n");
    Vertice * verticeTeste = grafo->getVertice(30);
    if(verticeTeste) printf("\n\nverticeTeste: %d\n\n", verticeTeste->getId());
    printf("\n\nQUANTIDADE DE VÉRTICES: %d\n\n", grafo->quantidadeVertices());

    printf("\n\n_________________________________________\n\n");
    grafo->adicioneAresta(new Aresta(vertice50, vertice30, 0));
    grafo->adicioneAresta(new Aresta(vertice30, vertice150, 1));
    grafo->adicioneAresta(new Aresta(vertice30, vertice50, 2));
    grafo->adicioneAresta(new Aresta(vertice150, vertice30, 4));
    grafo->adicioneAresta(new Aresta(vertice5, vertice200, 5));
    grafo->adicioneAresta(new Aresta(vertice5, vertice150, 3));
    printf("\n\n_________________________________________\n\n");
    grafo->mostraGrafo();


    printf("\n\n_________________________________________\n\n");
    Aresta * arestaAux1 = grafo->getAresta(2);
    printf("\nTestando a função getAresta(unsigned id) -> PARTIDA, CHEGADA, ID: .%d. .%d. .%d.\n", arestaAux1->getPartida()->getId(), arestaAux1->getChegada()->getId(), arestaAux1->getId());
    printf("\n\n_________________________________________\n\n");

//    printf("\n\n_________________________________________\n\n");
////	Aresta * arestaAux2 = grafo->getAresta(vertice50, vertice30);
//	Aresta * arestaAux2 = grafo->getAresta(vertice5, vertice150);
//	if(arestaAux2) {
//		printf("\nTestando a função getAresta(Vertice *s, Vertice *c) -> PARTIDA, CHEGADA, ID: .%d. .%d. .%d.\n", arestaAux2->getPartida()->getId(), arestaAux2->getChegada()->getId(), arestaAux2->getId());
//		printf("\n\n_________________________________________\n\n");
//	}
//
//	printf("\n\n_________________________________________\n\n");
	printf("\n\nBUSCA EM PROFUNDIDADE:\n\n");
	grafo->buscaEmProfundidade(5);
	printf("\n\n_________________________________________\n\n");
	grafo->inicializarCamposVisitadoParaTodosVertices();
	//CUIDAR ESTAS FUNCOES, POIS DEPOIS DE TER EXECUTADO A BUSCA EM PROFUNDIDADE, OS CAMPOS VISITADOS FORAM ALTERADOS.
	//CRIAR MÉTODO PARA INICIALIZAR O CAMPO NOVAMENTE.
	printf("\n\n_________________________________________\n\n");
	printf("\n\nBUSCA EM LARGURA:\n\n");
	grafo->buscaEmLargura(5);
	printf("\n\n_________________________________________\n\n");



	grafo->excluaAresta(vertice5, vertice200);
	grafo->excluaAresta(vertice30, vertice50);
	grafo->excluaAresta(vertice50, vertice30);
	grafo->excluaAresta(vertice200, vertice200); // Nada faz pq é do ponto até ele mesmo.
	grafo->excluaAresta(vertice50, vertice200); // Nada faz pq não existe esta aresta
	printf("\n\n_________________________________________\n\n");



	grafo->mostraGrafo();
	printf("\n\n\n");
	grafo->~Grafo();
	grafo->mostraGrafo();
	printf("\n\n\n");



    return 0;
}

