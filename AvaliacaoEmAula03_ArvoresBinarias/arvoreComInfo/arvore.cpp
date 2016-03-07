#include "arvore.h"

Arvore::Arvore() {
	info = 0;
	filho[ESQUERDA] = filho[DIREITA] = 0;
}

Arvore::Arvore(Info *i, Arvore *e, Arvore *d) {
	info = i;
	filho[ESQUERDA] = e;
	filho[DIREITA] = d;
}

Arvore::~Arvore() {

}

void Arvore::setFilho(Arvore *arv, Lado lado) {
	filho[lado] = 0;
}

Arvore* Arvore::getFilho(Lado lado) {
	return filho[lado];
}

void Arvore::setInfo(Info *i) {
	info = i;
}

Info* Arvore::getInfo(void) {
	return info;
}

int Arvore::ehFolha() {
//	return ( (filho[ESQUERDA] == 0) && (filho[DIREITA] == 0) );
//	return !filho[ESQUERDA] && !filho[DIREITA]
	return ( (!filho[ESQUERDA]) || (!filho[DIREITA]) );
}
