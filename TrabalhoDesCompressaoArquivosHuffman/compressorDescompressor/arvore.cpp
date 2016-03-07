#include "arvore.h"

Arvore::Arvore() {
    info = 0;
    filho[ESQUERDA] = filho[DIREITA] = 0;
    ladoEmRelacaoAoPai = ESQUERDA;
}

Arvore::Arvore(Info *i) {
	info = i;
	filho[ESQUERDA] = filho[DIREITA] = 0;
	ladoEmRelacaoAoPai = ESQUERDA;
}

Arvore::Arvore(Info *i, Arvore *e, Arvore *d) {
	info = i;
	filho[ESQUERDA] = e;
	filho[DIREITA]  = d;
	ladoEmRelacaoAoPai = ESQUERDA;
}

Arvore::~Arvore() {
    // Veremos!!! 
}

void Arvore::setFilho(Arvore *arv, Lado lado){
    filho[lado] = arv;
}

Arvore *Arvore::getFilho(Lado lado){
    return filho[lado];
}

void Arvore::setInfo(Info *i){
    info = i;
}

Info *Arvore::getInfo(void){
    return info;
}


void Arvore::setLadoEmRelacaoAoPai(Lado lado) {
	ladoEmRelacaoAoPai = lado;
}

int  Arvore::getLadoEmRelacaoAoPai() {
	return ladoEmRelacaoAoPai;
}



int Arvore::ehFolha(){
    return !(filho[ESQUERDA] || filho[DIREITA]);
}
