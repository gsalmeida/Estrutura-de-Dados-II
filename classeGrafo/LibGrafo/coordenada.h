#ifndef COORDENADA_H
#define COORDENADA_H

#include "vertice.h"

class Coordenada: public Vertice {
protected:
	float latitude, longitude;

public:
	Coordenada(float lat, float lon, unsigned i = 0);

	void setLatitude(float lat);
	void setLongitude(float lon);
	float getLatitude();
	float getLongitude();

	Texto toString();
};

#endif // COORDENADA_H
