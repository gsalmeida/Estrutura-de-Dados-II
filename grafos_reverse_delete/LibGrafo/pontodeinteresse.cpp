#include "pontodeinteresse.h"

PontoDeInteresse::PontoDeInteresse(Texto desc, float lat, float lon, unsigned i) : Coordenada(lat,lon,i){
    descricao = desc;
}

void PontoDeInteresse::setDescricao(Texto desc){
    descricao = desc;
}

Texto PontoDeInteresse::getDescricao () {
    return descricao;
}

Texto PontoDeInteresse::toString () {
    return descricao;
}
