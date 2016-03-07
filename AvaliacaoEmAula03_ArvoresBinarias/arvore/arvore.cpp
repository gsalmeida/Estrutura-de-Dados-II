#include "arvore.h"

Arvore::Arvore() {
	info = 0;
	filho[ESQUERDA] = filho[DIREITA] = 0;
}

Arvore::Arvore(int i, Arvore *e, Arvore *d) {
	info = i;
	filho[ESQUERDA] = e;
	filho[DIREITA] = d;
}

Arvore::~Arvore() {

}

void Arvore::setFilho(Arvore *arv, Lado lado) {
	filho[lado] = arv;
}

Arvore* Arvore::getFilho(Lado lado) {
	return filho[lado];
}

void Arvore::setInfo(int i) {
	info = i;
}

int Arvore::getInfo(void) {
	return info;
}

int Arvore::ehFolha() {
//	return ( (filho[ESQUERDA] == 0) && (filho[DIREITA] == 0) );
//	return !filho[ESQUERDA] && !filho[DIREITA]
	return ( (!filho[ESQUERDA]) || (!filho[DIREITA]) );
}




//void ArvoreBinPesquisa::insere(int i) {
//
//}



