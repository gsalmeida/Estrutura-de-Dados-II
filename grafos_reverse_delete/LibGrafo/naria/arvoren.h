#ifndef ARVOREN_H
#define ARVOREN_H
#include <stdio.h>
#include <stdlib.h>
#include "lse.h"
//#include "info.h"

class ArvoreN : public Info {
protected:
	Info *info;
	ArvoreN *pai;
	LSE filhos;
	int altura;

public:
	ArvoreN();
	ArvoreN(Info *i);
	~ArvoreN();

	void setPai(ArvoreN *arv);
	ArvoreN* getPai();

	void setFilho(ArvoreN *arv, int pos = 0);
	ArvoreN* getFilho(int pos = 0);

	int getAltura(void);
	void setInfo(Info * info) { this->info = info; };
	Info* getInfo();

	LSE * getFilhos() { return &(this->filhos); }

//	NÃO CONSEGUI IMPLEMENTAR NO .CPP POR CAUSA DOS VALORES DEFAULT DAS VARIAVEIS DE PARAMETRO.
//	void preOrder(ArvoreN* inicio, int qtdeEspacos, int espacosAnterior);
//	void preOrder2(ArvoreN* inicio, int qtdeEspacos);


//	ArvoreN * getArvoreNPeloIddaInfo(ArvoreN* inicio, unsigned idInfo) {
//		if(!inicio) return 0;
//		if(inicio->getInfo()->getId()) {
////			printf("(%d)\n|", inicio->getInfo()->getId());
//			if(inicio->getInfo()->getId() == idInfo) return inicio;
//			ArvoreN * esquerda = inicio->getFilho(0);
//			if(esquerda) {
//				Info* infoEsquerda = esquerda->getInfo();
//				if(infoEsquerda) {
//					if(infoEsquerda->getId()) {
//						int a = 0;
//						esquerda->getArvoreNPeloIddaInfo(esquerda, idInfo);
//					}
//				}
//			}
//			if(inicio->getFilho(0)) {
//				for(int a = 1; this->getFilho(a); a++) {
//					ArvoreN * direita = this->getFilho(a);
//					if(direita) {
//						Info* infoDireita = direita->getInfo();
//						if(infoDireita) {
//							if(infoDireita->getId()) {
//								int a2 = 0;
//								direita->getArvoreNPeloIddaInfo(direita, idInfo);
//							}
//						}
//					}
//				}
//			}
//		}
//	}

	void preOrder(ArvoreN* inicio, int qtdeEspacos = 3, int espacosAnterior = 0) {
		if(inicio->getInfo()->getId()) {
			printf("(%d)\n|", inicio->getInfo()->getId());
			if( (abs(inicio->getInfo()->getId()) >= 99)) qtdeEspacos++;
			if( (abs(inicio->getInfo()->getId()) > 999))qtdeEspacos++;
			if( (abs(inicio->getInfo()->getId()) > 9999)) qtdeEspacos++;
			if( (abs(inicio->getInfo()->getId()) > 99999)) qtdeEspacos++;
			if( (abs(inicio->getInfo()->getId()) > 999999)) qtdeEspacos++;
			if( (abs(inicio->getInfo()->getId()) > 9999999)) { qtdeEspacos++; qtdeEspacos++; }
			if( (abs(inicio->getInfo()->getId()) >= 99999999)) qtdeEspacos++;

			int qtdeEspacosAux = qtdeEspacos;
			ArvoreN * esquerda = inicio->getFilho(0);
			if(esquerda) {
				Info* infoEsquerda = esquerda->getInfo();
				if(infoEsquerda) {
					if(infoEsquerda->getId()) {
						int a = 0;
						for(a = 0; a <= qtdeEspacosAux; a++) if( (espacosAnterior) && (espacosAnterior == a) ) printf("|"); else printf(" ");
						printf("+--");
						qtdeEspacos += 5;
						esquerda->preOrder(esquerda, qtdeEspacos, a);
					}
				}
			}
			if(inicio->getFilho(0)) {
				for(int a = 1; this->getFilho(a); a++) {
					ArvoreN * direita = this->getFilho(a);
					if(direita) {
						Info* infoDireita = direita->getInfo();
						if(infoDireita) {
							if(infoDireita->getId()) {
								int a2 = 0;
								for(a2 = 0; a2 <= qtdeEspacosAux; a2++) if( (espacosAnterior) && (espacosAnterior == a2) ) printf("|"); else printf(" ");
								printf("+--");
								direita->preOrder(direita, qtdeEspacos, a2);
							}
						}
					}
				}
			}
			qtdeEspacos -= 5;
		}
	}


	void preOrder2(ArvoreN* inicio, int qtdeEspacos = 3) {
		if(inicio->getInfo()->getId()) {
			printf("(%d)\n", inicio->getInfo()->getId());

			if( (abs(inicio->getInfo()->getId()) >= 99)) qtdeEspacos++;
			if( (abs(inicio->getInfo()->getId()) > 999))qtdeEspacos++;
			if( (abs(inicio->getInfo()->getId()) > 9999)) qtdeEspacos++;
			if( (abs(inicio->getInfo()->getId()) > 99999)) qtdeEspacos++;
			if( (abs(inicio->getInfo()->getId()) > 999999)) qtdeEspacos++;
			if( (abs(inicio->getInfo()->getId()) > 9999999)) { qtdeEspacos++; qtdeEspacos++; }
			if( (abs(inicio->getInfo()->getId()) >= 99999999)) qtdeEspacos++;

			int qtdeEspacosAux = qtdeEspacos;
			ArvoreN * esquerda = inicio->getFilho(0);
			if(esquerda) {
				Info* infoEsquerda = esquerda->getInfo();
				if(infoEsquerda) {
					if(infoEsquerda->getId()) {
						for(int a = 0; a <= qtdeEspacosAux; a++) printf(" "); printf("+--");
						qtdeEspacos += 5;
						esquerda->preOrder2(esquerda, qtdeEspacos);
					}
				}
			}
			if(inicio->getFilho(0)) {
				for(int a = 1; this->getFilho(a); a++) {
					ArvoreN * direita = this->getFilho(a);
					if(direita) {
						Info* infoDireita = direita->getInfo();
						if(infoDireita) {
							if(infoDireita->getId()) {
								for(int a2 = 0; a2 <= qtdeEspacosAux; a2++) printf(" "); printf("+--");
								direita->preOrder2(direita, qtdeEspacos);
							}
						}
					}
				}
			}
			qtdeEspacos -= 5;
		}
	}




//
//	void preOrder3(ArvoreN* inicio, int qtdeEspacos = 3, int espacosAnterior = 0, LSE * lista = new LSE()) {
//			if(inicio->getInfo()->getId()) {
//	//			printf("\nqtdeEspacos: %d\n", qtdeEspacos);
//				printf("(%d)\n|", inicio->getInfo()->getId());
//
//				//				printf("QTDE ESPAÇOS: %d", qtdeEspacos);
//				if( (inicio->getInfo()->getId() >= 99)) qtdeEspacos++;
//				if( (inicio->getInfo()->getId() > 999))qtdeEspacos++;
//				if( (inicio->getInfo()->getId() > 9999)) qtdeEspacos++;
//				if( (inicio->getInfo()->getId() > 99999)) qtdeEspacos++;
//				if( (inicio->getInfo()->getId() > 999999)) qtdeEspacos++;
//				if( (inicio->getInfo()->getId() > 9999999)) { qtdeEspacos++; qtdeEspacos++; }
//				if( (inicio->getInfo()->getId() >= 99999999)) qtdeEspacos++;
//
//				int qtdeEspacosAux = qtdeEspacos;
//	//				for(int a1 = 0; a1 <= (qtdeEspacosAux); a1++, qtdeEspacos--) printf(" "); printf("|");
//				ArvoreN * esquerda = inicio->getFilho(0);
//				int achou = 0;
//				if(esquerda) {
//					Info* infoEsquerda = esquerda->getInfo();
//					if(infoEsquerda) {
//						if(infoEsquerda->getId()) {
//							int a = 0;
//							for(a = 0; a <= qtdeEspacosAux; a++)
//								if( (espacosAnterior) && (espacosAnterior == a) ) {
//									lista->inserir(new Info(a), lista->quantidade());
////									printf("|");
//								}
//							for(a = 0; a <= qtdeEspacosAux; a++) {
//								achou = 0;
//								for(int pos = 0; lista->obter(pos); pos++) {
//									if(a == lista->obter(pos)->getId()) {
//										if(lista->obter(pos)->getId() > 0) {
//											printf("|");
//											achou = pos;
//										}
//									}
//								}
//								if(!achou) printf(" ");
//							}
////								else printf(" ");
//							printf("+--");
//							qtdeEspacos += 5;
//							esquerda->preOrder3(esquerda, qtdeEspacos, a, lista);
//						}
//					}
//				}
////				for(int a = 0; lista->obter(a); a++) printf("\t.%d.", lista->obter(a)->getId());
//
//	//			printf("\nQTDE ESPAÇOS %d: \n", qtdeEspacos);
//				if(inicio->getFilho(0)) {
//					for(int a = 1; this->getFilho(a); a++) {
//						ArvoreN * direita = this->getFilho(a);
//	//					ArvoreN * direita = inicio->getFilho(1);
//						if(direita) {
//							Info* infoDireita = direita->getInfo();
//							if(infoDireita) {
//								if(infoDireita->getId()) {
//									int a2 = 0;
//									for(a2 = 0; a2 <= qtdeEspacosAux; a2++)
//										if( (espacosAnterior) && (espacosAnterior == a2) ) {
//											lista->inserir(new Info(a), lista->quantidade());
////											printf("|");
//										}
//									for(a = 0; a <= qtdeEspacosAux; a++) {
//										achou = 0;
//										for(int pos = 0; lista->obter(pos); pos++) {
//											if(a == lista->obter(pos)->getId()) {
//												if(lista->obter(pos)->getId()) {
//													printf("|");
//													achou = pos;
//												}
//											}
//										}
//										if(!achou) printf(" ");
//									}
////										else printf(" ");
//									printf("+--");
//									direita->preOrder3(direita, qtdeEspacos, a2, lista);
////									lista->remover((lista->quantidade() - 1));
//								}else lista->remover(lista->quantidade());
//	//							else {
//	//								qtdeEspacos -= 5;
//	//							}
//							}
//						}
//					}
////					lista->remover((lista->quantidade() - 1));
////					contadorLSE--;
//				} else {
//					if(lista->obter(lista->quantidade() - 1)) {
//						Info * infoTemp = lista->obter(lista->quantidade() - 1);
//						if (infoTemp > 0) lista->remover( (lista->quantidade() - 1) );
//					}
//				}
//				qtdeEspacos -= 5;
//
//			}
//		}



};

#endif // ARVOREN_H
