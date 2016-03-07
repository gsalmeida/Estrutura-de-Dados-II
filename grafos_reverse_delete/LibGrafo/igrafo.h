#ifndef IGRAFO_H
#define IGRAFO_H

#include "vertice.h"
#include "aresta.h"

class IGrafo {
public:
	IGrafo(unsigned numVertices, unsigned numArestas) {
	}
	;
	~IGrafo();

	void adicioneVertice(Vertice *v);
	Vertice *getVertice(unsigned id);
	void excluaVertice(unsigned id);

	void adicioneAresta(Aresta *a);
	Aresta *getAresta(unsigned id);
	Aresta *getAresta(Vertice *s, Vertice *c);
	virtual void excluaAresta(unsigned id) = 0;
};

#endif // IGRAFO_H
