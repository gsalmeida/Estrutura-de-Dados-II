#include "vertice.h"

//TODO Verificar na hora de criar por um id unico
Vertice::Vertice(unsigned i) {
    id = i;
    visitado = 0;
}

unsigned Vertice::getId() {
    return id;
}

void Vertice::setVisitado(unsigned valor) {
	visitado = valor;
}

int Vertice::getVisitado() {
	return visitado;
}

Texto Vertice::toString() {
    Texto t(id);
    return t;
}
