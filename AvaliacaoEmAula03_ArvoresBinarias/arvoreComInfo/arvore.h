#ifndef ARVORE_H
#define ARVORE_H

#include "info.h"

enum Lado {ESQUERDA, DIREITA};

class Arvore {

private:
	Info *info;
	Arvore *filho[2];

public:
	Arvore();
	Arvore(Info * i, Arvore *e = 0, Arvore *d = 0);
	~Arvore();

	void setFilho(Arvore *arv, Lado lado);

	Arvore *getFilho(Lado lado);

	void setInfo(Info *i);
	Info *getInfo(void);
	int ehFolha();

};

#endif
