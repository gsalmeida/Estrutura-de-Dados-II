#include "coordenada.h"
#include "stdio.h"

Coordenada::Coordenada(float lat, float lon, unsigned i) : Vertice (i) {
    latitude = lat;
    longitude = lon;
}

void Coordenada::setLatitude(float lat) {
    latitude = lat;
}

void Coordenada::setLongitude(float lon) {
    longitude = lon;
}

float Coordenada::getLatitude() {
    return latitude;
}

float Coordenada::getLongitude() {
    return longitude;
}

Texto Coordenada::toString() {
    char aux[50];
    sprintf (aux, "%5.2f, %5.2f", latitude, longitude);
    Texto t(aux);
    return t;
}
