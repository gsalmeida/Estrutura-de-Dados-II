#ifndef ARESTA_H
#define ARESTA_H

#include "vertice.h"

class Aresta {
protected:
	unsigned id;
	Vertice *partida;
	Vertice *chegada;
public:
	Aresta(Vertice *sai, Vertice *entra, unsigned i = 0);
	Aresta();

	unsigned getId() { return this->id; }
	Vertice * getPartida() { return this->partida; }
	Vertice * getChegada() { return this->chegada; }

	int getValidacaoObjetoAresta() {
		return ( ((!this->id) && (!getPartida()) && (!getChegada()) ) ? 1 : 0);
	}

};

#endif // ARESTA_H
