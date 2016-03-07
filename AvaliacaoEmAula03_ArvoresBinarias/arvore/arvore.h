#ifndef ARVORE_H
#define ARVORE_H

//#include "info.h"


#include <stdio.h>

#include <cmath>
#include <stdlib.h>
#include <string.h>


enum Lado {ESQUERDA, DIREITA};

class Arvore {

protected:
	int info;
	Arvore *filho[2];

public:
	Arvore();
	Arvore(int i, Arvore *e = 0, Arvore *d = 0);
	~Arvore();

	void setFilho(Arvore *arv, Lado lado);

	Arvore *getFilho(Lado lado);

	void setInfo(int i);
	int getInfo(void);
	int ehFolha();

	bool temFilho() const { return ( (this->filho[ESQUERDA] != 0) || (this->filho[DIREITA] != 0) ); }
//	bool temFilho() const { return ( (this->filho[ESQUERDA] != NULL) || (this->filho[DIREITA] != NULL) ); }

};

#endif




#ifndef ARVORE_BIN_PESQUISA_H
#define ARVORE_BIN_PESQUISA_H

class ArvoreBinPesquisa : public Arvore {
public:
	ArvoreBinPesquisa() : Arvore() {};
	ArvoreBinPesquisa(int i, Arvore *e = 0, Arvore*d = 0) : Arvore(i, e, d) {};
//	~ArvoreBinPesquisa();

//	ArvoreBinPesquisa * pesquisa(int i);

	ArvoreBinPesquisa * pesquisa(int i) {
		if(i == this->info) return this;

		if( (i < this->info) && (this->filho[ESQUERDA] != 0) )
			return ((ArvoreBinPesquisa*) this->filho[ESQUERDA])->pesquisa(i);

		if( (i > this->info) && (this->filho[DIREITA] != 0) )
			return ((ArvoreBinPesquisa*) this->filho[DIREITA])->pesquisa(i);
		return 0;
	}

//	void insere(int i);
	void insere(int i) {
//		printf("\n GETINFO(0): %d \n", this->info);
//		if(!temFilho()) {
//			Arvore *arvoreAux = new ArvoreBinPesquisa(i, NULL, NULL);
//			if(i < (this->info) ) this->setFilho(arvoreAux, ESQUERDA);
//			else if(i >= (this->info) ) this->setFilho(arvoreAux, DIREITA);
//			printf("\n GETINFO(999): %d \n", this->info);
//		}else {
			if(i < (this->info) ) {
				ArvoreBinPesquisa *avl = (ArvoreBinPesquisa *) this->getFilho(ESQUERDA);
				if(this->getFilho(ESQUERDA) == NULL) {
					Arvore *arvoreAux = new ArvoreBinPesquisa(i, NULL, NULL);
					this->setFilho(arvoreAux, ESQUERDA);
					printf("\n GETINFO CADASTRADO NA ÁRVORE(0): %d \n", arvoreAux->getInfo());
				} else avl->insere(i);
			} else if(i >= (this->info) ) {
				ArvoreBinPesquisa *avl = (ArvoreBinPesquisa *) this->getFilho(DIREITA);
				if(this->getFilho(DIREITA) == NULL) {
					Arvore *arvoreAux = new ArvoreBinPesquisa(i, NULL, NULL);
					this->setFilho(arvoreAux, DIREITA);
					printf("\n GETINFO CADASTRADO NA ÁRVORE(1): %d \n", arvoreAux->getInfo());
				} else avl->insere(i);
			}
//		}
	}

//	void mostraArvoreAux(Arvore *pRaiz) {
//		if(pRaiz != NULL) printf(" .%d. ", pRaiz->getInfo());
//	}
//
//	void mostraArvore() {
//		printf(" .%d. ", this->getInfo());
//		mostraArvoreAux(this->getFilho(ESQUERDA));
//		mostraArvoreAux(this->getFilho(DIREITA));
//	}



//	void exclui(int i);

	ArvoreBinPesquisa *pai;
	void exclui(int i) {
		if(this == 0) return;
		if(this->pai == 0) {
			this->pai = this;
		}
//		if(i != (this->info) ) pai = this;
		if(i < (this->info) ) {
			ArvoreBinPesquisa *avl = (ArvoreBinPesquisa *) this->getFilho(ESQUERDA);
			pai = this;
//			printf("\nDEBUG 1\n");
			if(avl) {
				avl->pai = this;
				printf("\n1) EXCLUIU O ELEMENTO %d E O SEU PAI É: %d\n", this->info, pai->getInfo());
				avl->exclui(i);
			}
		} else if(i > (this->info) ) {
			ArvoreBinPesquisa *avl = (ArvoreBinPesquisa *) this->getFilho(DIREITA);
			pai = this;
//			printf("\nDEBUG 2: %d\n", avl->getInfo());
			if(avl) {
				avl->pai = this;
				printf("\n2) EXCLUIU O ELEMENTO %d E O SEU PAI É: %d\n", this->info, pai->getInfo());
				avl->exclui(i);
			}
		} else {
	        //nao tem filhos
			printf("\n3) EXCLUIU O ELEMENTO %d E O SEU PAI É: %d\n", this->info, pai->getInfo());
	        if ( (this->filho[ESQUERDA] == NULL) && (this->filho[DIREITA] == NULL) ) {

//	        	if(pai->getInfo() < this->info) pai->setFilho(NULL, ESQUERDA);
//	        	else if(pai->getInfo() >= this->info) pai->setFilho(NULL, DIREITA);

	        	delete (this);
	        }
	        //filho para a direita
	        else if (this->filho[ESQUERDA] == NULL) {
	        	ArvoreBinPesquisa *noParaRemover =  (ArvoreBinPesquisa *) this;
//	        	ArvoreBinPesquisa *noAtual = (ArvoreBinPesquisa *) this;
//	        	noAtual =  (ArvoreBinPesquisa *) this->filho[DIREITA];
	        	delete (noParaRemover);
	        }
	        //filho para a esquerda
	        else if (this->filho[DIREITA] == NULL) {
	        	ArvoreBinPesquisa *noParaRemover = (ArvoreBinPesquisa *) this;
//	        	ArvoreBinPesquisa *noAtual = (ArvoreBinPesquisa *) this;
//	        	noAtual = (ArvoreBinPesquisa *) this->filho[ESQUERDA];
				delete (noParaRemover);
	        }
	        //filho(s) para esquerda e direita
	        else {
	        	ArvoreBinPesquisa *arvoreAux = (ArvoreBinPesquisa *) this->filho[DIREITA];
	        	printf("\nTeste 2: %d \n", arvoreAux->getInfo());
	            if(arvoreAux->info != i)
	                while (arvoreAux->filho[ESQUERDA] != NULL)
	                    arvoreAux = (ArvoreBinPesquisa *) arvoreAux->filho[ESQUERDA];
	            printf("\nTeste 2: %d \n", arvoreAux->getInfo());
	            this->info = arvoreAux->info;
//	            this->setFilho(arvoreAux->getFilho());
	            /*troca as informações*/
	            arvoreAux->info = i;

//	            arvore->dir = excluirElemento(arvore->dir, valor, excluirRepetidos);
	            ArvoreBinPesquisa *avlFilhoDireita = (ArvoreBinPesquisa *) this->filho[DIREITA];
	            avlFilhoDireita->exclui(i);
//	            delete(this);

				//free(arvoreAux);
	//double free : Error
	        }
	        //esta linha faz com que recomece a função e remova todos os outros repetidos. Recursividade
	//        if(excluirRepetidos)
	//            excluirElemento(arvore, valor, excluirRepetidos);
	    }
	}


/*
	void preOrdem() {
		if (this != 0) {
			cout << " " << this->info;
			preOrdem(this->filho[ESQUERDA]);
			preOrdem(this->filho[DIREITA]);
		}
	}

	   // inOrdem:
	void inOrdem() {
	   if (this != 0) {
		   inOrdem(this->filho[ESQUERDA]);
		   cout << " " << this->info;
		   inOrdem(this->filho[DIREITA]);
	   }
	}

	   // posOrdem:
   void posOrdem() {
	   if (this != 0) {
		   posOrdem(this->filho[ESQUERDA]);
		   posOrdem(this->filho[DIREITA]);
		   cout << " " << this->info;
	   }
   }
*/


	int altura() {
	    if (this == 0)
	        return 0;
	    ArvoreBinPesquisa *abpEsquerda = (ArvoreBinPesquisa *) this->filho[ESQUERDA];
	    int alturaEsquerda = abpEsquerda->altura();

	    ArvoreBinPesquisa *abpDireita = (ArvoreBinPesquisa *) this->filho[DIREITA];
	    int alturaDireita = abpDireita->altura();
	    return alturaEsquerda > alturaDireita ?
	            alturaEsquerda + 1 : alturaDireita + 1;
	}


	//iésimo = menor elemento
	char itoc(int i) {
	/*Transforma um número em caracter, função utilizada na conversão de um decimal em binário*/
	    switch (i) {
	           case 0: return '0';
	           case 1: return '1';
	           case 2: return '2';
	           case 3: return '3';
	           case 4: return '4';
	           case 5: return '5';
	           case 6: return '6';
	           case 7: return '7';
	           case 8: return '8';
	           case 9: return '9';
	    }
	}

	void dtob(char *bin,int n, int d){
	/* Função transforma um número decimal d passado como parâmetro para um número binário
	armazenando este na string bin. O tamanho do número binário é passado como parâmetro n.
	O número binário é gerado com zeros à esquerda. Esta função é utilizada na procura do iésimo nodo
	de cada nível.*/
	  int i, a,aux;

	  for(i=0;i<n;i++)
	      bin[i]='0';
	  bin[n]=0;
	  a=n-1;
	  while (d>0){
	    bin[a]=itoc(d%2);
	    a--;
	    d = d/2;
	  }
	}


	ArvoreBinPesquisa *nodo_nivel (int nivel, int i){
	/* Função retorna o iésimo nodo de um certo nível(i e nível passado como parâmetro).
	Para encontrar o nodo o i é transformado em binário com tamanho de nivel bits onde
	cada a sequencia de bits determina o caminho utilizado para encontrar o nodo,
	'0' vai para filho da esquerda e '1' vai para filho da direita.
	Caso nodo não existir devove um nodo nulo.
	*/
		 int j;
		 char *binario;
		 ArvoreBinPesquisa *temp = this;
		 if (nivel==1)
			return this;
		else{  // encontra nodo
			binario=(char*) malloc (nivel-1 * sizeof(char));
			dtob(binario,nivel-1,i-1);
			for (j = 0; j < (nivel-1); j++) {
			   if (binario[j]=='0')
				  if (temp->filho[ESQUERDA] != NULL){
					 temp = (ArvoreBinPesquisa *) temp->filho[ESQUERDA];
				  } else return NULL;
			   else
				   if (temp->filho[DIREITA] != NULL){
					  temp = (ArvoreBinPesquisa *) temp->filho[DIREITA];
				   } else return NULL;
			}
			return temp;
		}
	}


	void imprime_nivel(int nivel){
	/*Imprime todos os nodos de certo nível passado como parâmetro caso exista o nível.
	Para isso é utilizada a função de encontrar o iésimo nodo no nível.
	É calculado a quantidade de segmentos em cada nível e o tamanho dos segmentos
	baseado na altura da árvore e na quantidade total de nodos que um nível pode ter a fim de
	utilizar-la na impreção de toda árvore.*/
	 int seg=1;
	 double div=0;
	 int i,j;
	 int altura_arvore;
	 altura_arvore=altura();
	       printf("\n");
	       div=pow((double)2,(double)(nivel-1))+1; // qtde de segmentos do nivel
	        seg = (int)(pow((double)2,(double)altura_arvore)/(double)div) -1;// tamanho do segmento

	        if (seg<=0) // ultimo nivel
	           seg = 1;
	        for (i=1;i<(int)div;i++){// imprime todos segmentos
	          if (i==1)
	            for (j=0;j<seg-1;j++)
	                printf(" ");
	          else
	            for (j=0;j<seg;j++)
	                printf(" ");
	          if (nodo_nivel(nivel,i)!=NULL){
//	             printf("%d(%d)", (nodo_nivel(nivel,i))->info, (nodo_nivel(nivel,i))->fatorDeBalanceamento);
	             printf(".%d.", (nodo_nivel(nivel,i))->info);
	//             if ((nodo_nivel(nivel,i))->pai!= NULL)
	//                printf("p=%d",((nodo_nivel(raiz,nivel,i))->pai)->info); // caso queira mostrar o pai de cada nodo, descomentar esse trecho
	         } else
	             for (j=0;j<seg;j++)
	             printf(" ");   // caso nodo não existir, um lugar vazio
	        }
	        printf("\n");
	}

	void imprime_arvore(){
		//Imprime todos os níveis da árvore, utilizando a função de imprimir o nível imprimirNivel.
		int i;
		int nivel=altura();
		for (i=1;i<=nivel;i++){
		   imprime_nivel(i);
		   printf("\n");
		   printf("\n");
		}
	}




	void imprimirArvore2() {
	    int esquerda, direita;
	    ArvoreBinPesquisa *no_atual;
	    if (this) {
	        no_atual = (ArvoreBinPesquisa *) this->filho[ESQUERDA];
	        if (no_atual)
	            esquerda = no_atual->info;
	        else
	            esquerda = -99999;

	        no_atual = (ArvoreBinPesquisa *) this->filho[DIREITA];

	        if (no_atual)
	            direita = no_atual->info;
	        else
	            direita = -99999;

	        if ((esquerda != -99999) && (direita != -99999))
	            printf("\n[%d]<---[%d]--->[%d]", esquerda, this->info, direita);
	        else if (esquerda != -99999)
	            printf("\n[%d]<---[%d]--->[%s]", esquerda, this->info, "NULL");
	        else if (direita != -99999)
	            printf("\n[%s]<---[%d]--->[%d]", "NULL", this->info, direita);
	        else
	            printf("\n[%s]<---[%d]--->[%s]", "NULL", this->info, "NULL");
	        printf("\n");
	        printf("\n");

	        ArvoreBinPesquisa *abp = (ArvoreBinPesquisa *) this->filho[ESQUERDA];
	        abp->imprimirArvore2();
	        ArvoreBinPesquisa *abp2 = (ArvoreBinPesquisa *) this->filho[DIREITA];
	        abp2->imprimirArvore2();
	    }
	}



};

#endif
