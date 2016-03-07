#include "aresta.h"

Aresta::Aresta(Vertice *sai, Vertice *entra, unsigned i) {
	partida = sai;
	chegada = entra;
	id = i;
}


Aresta::Aresta() {
	partida = 0;
	chegada = 0;
	id = 0;
}
