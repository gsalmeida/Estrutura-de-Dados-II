#include <stdio.h>
#include "listaDuplamenteEncadeada.h"
#include "info.h"


int main () {
	ListaDuplamenteEncadeada lde;

	Info *info1 = new Info(1);
	Info *info2 = new Info(2);
	Info *info3 = new Info(3);
	Info *info4 = new Info(4);
	Info *info5 = new Info(5);

	//Não está funcionando para este caso âncora. 1 elemento apenas na lista e remover a posiçao zero.
	lde.inserir(new Info(88), 0);
	lde.mostrarLista();
	lde.remover(0);
	printf("\nREMOVIDO INFO NA POSIÇÃO 0 Com apenas 1 elemento, ou seja, só existe a posição zero mesmo.\n");
	lde.mostrarLista();

	lde.inserir(info2, 0);
	lde.inserir(info1, 0);
	lde.mostrarLista();
	lde.remover(0);
	printf("\nREMOVIDO INFO NA POSIÇÃO 0 Com 2 elementos na lista.\n");

	lde.mostrarLista();

	lde.inserir(info5, 0);

	lde.inserir(info3, 1);
	lde.inserir(info3, 2);
	lde.inserir(info4, 3);
	lde.inserir(info5, 2);
	lde.inserir(info5, 0);
	lde.inserir(new Info(850), 0);
	lde.inserir(new Info(500), 5);
	lde.inserir(new Info(299));

	lde.mostrarLista();
//	lde.inicializar();
//	lde.mostrarLista();

	printf("\n Informação na posição 6: %d \n", lde.obter(6)->getId());

	Info *infoTesteObter1 = lde.obter(-15);
	Info *infoTesteObter2 = lde.obter(1);
	Info *infoTesteObter3 = lde.obter(20);
	if(infoTesteObter1 != NULL) printf("\n Info em infoTesteObter1: %d \n", infoTesteObter1->getId());
	else printf("\n Info em infoTesteObter1: NULL");
	if(infoTesteObter2 != NULL) printf("\n Info em infoTesteObter2: %d \n", infoTesteObter2->getId());
	else printf("\n Info em infoTesteObter2: NULL");
	if(infoTesteObter3 != NULL) printf("\n Info em infoTesteObter3: %d \n", infoTesteObter3->getId());
	else printf("\n Info em infoTesteObter3: NULL");
	printf("\n________________________________________________________________________________________________________________________\nNovos elementos inseridos na lista.\n");
	lde.inserir(new Info(3998));
	lde.inserir(new Info(2000));
	lde.inserir(new Info(719));


	lde.mostrarLista();
	Info *infoRemover = lde.remover(1);
	printf("\nREMOVIDO INFO NA POSIÇÃO 1.\n");
//	printf("\nREMOVIDO INFO NA POSIÇÃO 1: %d\n", infoRemover.getId());
	lde.mostrarLista();

	lde.remover(5);
	printf("\nREMOVIDO INFO NA POSIÇÃO 5\n");
	lde.mostrarLista();

	lde.remover(0);
	printf("\nREMOVIDO INFO NA POSIÇÃO 0\n");
	lde.mostrarLista();

	lde.remover(8);
	printf("\nREMOVIDO INFO NA POSIÇÃO 8\n");
	lde.mostrarLista();

	//Último elemento da lista neste momento.
	lde.remover(8);
	printf("\nREMOVIDO INFO NA POSIÇÃO 8. Último elemento da lista neste momento.\n");
	lde.mostrarLista();

	printf("\n________________________________________________________________________________________________________________________\n");

	Info *infoPesquisaPorId = lde.pesquisarPoId(new Info(500));
	printf("\n Info obtido pela função pesquisarPorId(500): %d \n", infoPesquisaPorId->getId());
	printf("\n________________________________________________________________________________________________________________________\n");

	Info *infoPesquisaPorId2 = lde.pesquisarPoId(new Info(1500));
	if( (infoPesquisaPorId2 == NULL) || (infoPesquisaPorId2 == 0) ) printf("\n Info obtido pela função pesquisarPorId2(1500): NULL\n");
	else printf("\n Info obtido pela função pesquisarPorId2(1500): %d \n", infoPesquisaPorId2->getId());
	printf("\n________________________________________________________________________________________________________________________\n");


	lde.~ListaDuplamenteEncadeada();
	lde.mostrarLista();
	printf("\n________________________________________________________________________________________________________________________\n");

	lde.inserir(new Info(9));
	lde.inserir(new Info(1), 0);
	lde.inserir(new Info(2));
	lde.mostrarLista();
	printf("\n________________________________________________________________________________________________________________________\n");


//	lde2.inserir(new Info(2));
//	lde2.inserir(new Info(8), 0);

//	lde = lde2;

//	lde.mostrarLista();


//	printf("\n-- %d --\n", lde.getInfo()->getId());
//	printf("\n-- %d --\n", lde.getPonteiro(PRIMEIRO)->getInfo()->getId());

	return 0;
}
