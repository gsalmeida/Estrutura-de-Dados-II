#ifndef VIA_H
#define VIA_H

#include "aresta.h"

class Via: public Aresta {
protected:
	float distancia;
public:
	Via(float dist, Vertice *sai, Vertice *chega, unsigned i = 0);
	void setDistancia(float dist);
	float getDistancia(void);
};

#endif // VIA_H
