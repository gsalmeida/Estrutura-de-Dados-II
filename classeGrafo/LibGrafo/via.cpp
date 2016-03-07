#include "via.h"

Via::Via(float dist, Vertice *sai, Vertice *chega, unsigned i) : Aresta(sai, chega, i) {
	distancia = dist;
}

void Via::setDistancia(float dist) {
	distancia = dist;
}

float Via::getDistancia(void) {
	return distancia;
}
