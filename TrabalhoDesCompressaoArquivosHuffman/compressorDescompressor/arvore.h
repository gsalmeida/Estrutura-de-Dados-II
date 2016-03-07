#ifndef ARVORE_H
#define ARVORE_H

#include "info.h"
#include <stdio.h>
#include <string.h>

enum Lado {ESQUERDA, DIREITA};

class Arvore {
protected:
    Info *info;
    Arvore *filho[2];
    Lado ladoEmRelacaoAoPai;
public:
    Arvore(); // Construtor vazio

    // Construtor inicializador
    Arvore(Info *i, Arvore *e=0, Arvore *d=0);
    Arvore(Info *i);//Construtor com apenas Info * como parâmetro. ESQ e DIR ficam com valores 0
    ~Arvore();

    void setFilho(Arvore *arv, Lado lado);
    Arvore *getFilho(Lado lado);

    void setInfo(Info *i);
    Info *getInfo(void);

    void setLadoEmRelacaoAoPai(Lado lado);
    int  getLadoEmRelacaoAoPai();

    int  ehFolha();  

    Arvore * get() {
    	Arvore * resultado = new Arvore();
    	resultado->setInfo(this->getInfo());
    	resultado->setFilho(this->getFilho(ESQUERDA), ESQUERDA);
    	resultado->setFilho(this->getFilho(DIREITA), DIREITA);
    	resultado->setLadoEmRelacaoAoPai(this->ladoEmRelacaoAoPai);
    	return resultado;
    }

    Arvore *operator=(Arvore *arvoreParametro) {
    	return arvoreParametro;
	}

    void preOrder(Arvore *inicio) {
    	if(inicio) {
    		printf("\n.%c->%d.\n", (!inicio->info->getId()) ? '@' : inicio->info->getId(), inicio->info->getQtdeOcorrencias());

    		Arvore * esquerda = inicio->getFilho(ESQUERDA);
			if(esquerda) preOrder(inicio->getFilho(ESQUERDA));

			Arvore * direita = this->getFilho(DIREITA);
			if(direita) preOrder(inicio->getFilho(DIREITA));
    	}
    }

    void removerUltimoCaracter(char texto[256]) {
		int a;
		for(a = 0; texto[a]; a++);
		texto[a] = '\0';
		texto[a-1] = '\0';
	}

    void processaMatrizCharValoresFinais(Arvore *inicio, char **matrizCharValorBinario, char resultado[256] = new char[256]) {
    	if(inicio) {
    		int posicaoCaracter = inicio->info->getId();
    		if(posicaoCaracter) {
				matrizCharValorBinario[posicaoCaracter] = new char [256];
				strcpy(matrizCharValorBinario[posicaoCaracter], resultado);
    		}
			Arvore * esquerda = inicio->getFilho(ESQUERDA);
			if(esquerda) {
				strcat(resultado, "0");
				processaMatrizCharValoresFinais(inicio->getFilho(ESQUERDA), matrizCharValorBinario, resultado);
			}
			Arvore * direita = inicio->getFilho(DIREITA);
			if(direita) {
				strcat(resultado, "1");
				processaMatrizCharValoresFinais(inicio->getFilho(DIREITA), matrizCharValorBinario, resultado);
			}
			removerUltimoCaracter(resultado);
		}
	}


//    bool temFilho() const { return ( (this->filho[ESQUERDA] != 0) || (this->filho[DIREITA] != 0) ); }
};

#endif
