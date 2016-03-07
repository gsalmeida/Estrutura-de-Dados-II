#include <stdio.h>
#include "arvore.h"

int main () {

	ArvoreBinPesquisa arvore;

//	printf("\n %d \n", arvore.temFilho());
//	arvore.insere(5);
//	arvore.insere(10);
//	arvore.insere(8);
//	arvore.insere(19);
//	arvore.insere(2);
//	arvore.insere(-2);

//	arvore.insere(-6);
//	arvore.insere(-1);
//	arvore.insere(0);
//	arvore.insere(8);

//	arvore.mostraArvore();


	arvore.insere(0);
	arvore.insere(-2);
	arvore.insere(-9);
	arvore.insere(-7);
	arvore.insere(5);
//	arvore.insere(2);
	arvore.insere(2);
	arvore.insere(10);
	arvore.insere(12);
	arvore.insere(8);
	arvore.insere(9);
	arvore.insere(7);
	arvore.insere(6);

//	arvore.imprime_arvore();
	arvore.imprimirArvore2();
	arvore.exclui(0);
	printf("\n\n________________________________________________________________________________\n\n");
	arvore.imprimirArvore2();

	return 0;
}
