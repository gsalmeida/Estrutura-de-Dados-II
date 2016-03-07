#ifndef PONTODEINTERESSE_H
#define PONTODEINTERESSE_H

#include "coordenada.h"

class PontoDeInteresse: public Coordenada {
protected:
	Texto descricao;
public:
	PontoDeInteresse(Texto desc, float lat, float lon, unsigned i = 0);
	void setDescricao(Texto desc);
	Texto getDescricao();
	Texto toString();
};

#endif // PONTODEINTERESSE_H
