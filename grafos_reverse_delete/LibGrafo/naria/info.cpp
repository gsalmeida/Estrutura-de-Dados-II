/*
 * Classe Info - classe base para informacoes a serem organizadas em EDs
 * Autor : Carlos R Rocha (carlos.rocha@riogrande.ifrs.edu.br)
 * Versao 140807-2230
 */
#include <stdio.h>
#include "info.h"
   
   
int Info::getId() {
    return id;
}


void Info::toString(char *txt) {
    sprintf (txt, "Instancia de Info id: %04d.", id);
}



void Pessoa::toString(char *txt) {
    sprintf (txt, "Pessoa: %s", nome);
}
