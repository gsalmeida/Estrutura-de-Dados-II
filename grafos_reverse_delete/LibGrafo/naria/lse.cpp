#include "lse.h"

/*
 * Classe No - representa um no de uma lista simplesmente encadeada
 * Autor : Carlos R Rocha (carlos.rocha@riogrande.ifrs.edu.br)
 * Versao 140814-1600
 */
No::No(Info *i) {
	dado = i;
	proximo = 0;
}

No::No(No& n) { // Construtor de copia
	dado = new Info(*(n.dado));
	proximo = 0;
}

No::~No() {
	dado = 0;
}

/*
 * Classe LSE - implementa uma lista simplesmente encadeada
 * Autor : Carlos R Rocha (carlos.rocha@riogrande.ifrs.edu.br)
 * Versao 140814-1600
 */

// Construtor default - lista vazia - Questao 1
LSE::LSE() {
	inicio = anterior = 0;
	qte = pos = 0;
}

// Construtor de copia - Questao 1
LSE::LSE(LSE& outra) {
	// Copiar a lista outra
	this->qte = outra.qte;
	this->pos = 0;
	if (outra.qte) {
		this->inicio = new No(*outra.inicio);
		this->anterior = this->inicio;
		for (No *p = outra.inicio->proximo; p; p = p->proximo) {
			this->anterior->proximo = new No(*p);
			this->anterior = this->anterior->proximo;
		}
	} else {
		this->inicio = 0;
	}
	this->anterior = 0;
}

// Destrutor - Questao 7
LSE::~LSE() {
	while (this->inicio) {
		this->anterior = this->inicio;
		this->inicio = this->inicio->proximo;
		delete this->anterior;
	}
}

// Insere um elemento  na posicao indicada ou na primeira. - Questao 2
// Licenca "poetica" - Se a posicao for maior que a quantidade de elementos
// ira inserir no final da lista
void LSE::inserir(Info *elemento, int posicao) {
	if ((!elemento) || (posicao < 0))
		throw; // Nao ha elemento a inserir - vale uma excecao

	No* novo = new No(elemento); // Cria o no a ser inserido na lista

	if (posicao) { // Posicao diferente do inicio da lista
		int p;
		No* a;

		if (anterior && (posicao >= pos))
			for (p = pos, a = anterior; (p < posicao) && a->proximo; p++, a = a->proximo);
		else
			for (p = 1, a = inicio; (p < posicao) && a->proximo; p++, a = a->proximo);

		novo->proximo = a->proximo;
		a->proximo = novo;
		anterior = a;
		pos = p;
	} else {
		novo->proximo = inicio;
		inicio = novo;
		anterior = 0;
		pos = 0;
	}
	qte++;
}

// Obtem um elemento da posicao indicada, disparando uma excecao
// Caso a posicao esteja fora dos limites da lista - Questao 3
Info* LSE::obter(int posicao) {
	if (qte) {
		if (posicao) {
			if (posicao < 0) return 0;   // throw; // Refinar isso para uma excecao decente
			else {
				int p;
				No *a;

				if (anterior && (posicao >= pos))
					for (p = pos, a = anterior; (p < posicao) && a->proximo; p++, a = a->proximo);
				else
					for (p = 1, a = inicio; (p < posicao) && a->proximo; p++, a = a->proximo);

				if (a->proximo) {
					pos = p;
					anterior = a;
					return a->proximo->dado;
				}
			}
		} else {
			pos = 0;
			anterior = 0;
			return inicio->dado;
		}
//		throw;  // Passou dos limites
		return 0;
	}
	return 0; // Nao ha info para retornar
}

// Remove um elemento da lista, retornando-o, se existir. - Questao 4
// Se não existir, dispara uma excecao    
Info* LSE::remover(int posicao) {
	if ((posicao >= qte) || (posicao < 0))
		throw;
	Info* retorno;
	if (posicao) {
		int p;
		No *a;
		if (anterior && (posicao >= pos))
			for (p = pos, a = anterior; (p < posicao) && a->proximo;
					p++, a = a->proximo)
				;
		else
			for (p = 1, a = inicio; (p < posicao) && a->proximo;
					p++, a = a->proximo)
				;
		if (a->proximo) {
			anterior = a;
			a = a->proximo;
			anterior->proximo = a->proximo;
			retorno = a->dado;
			delete a;
			pos = p;
		} else {
			throw;
		}
	} else {
		anterior = inicio;
		inicio = inicio->proximo;
		retorno = anterior->dado;
		delete anterior;
		anterior = 0;
		pos = 0;
	}
	qte--;
	return retorno;
}

// Varre a lista procurando pelo no com a Info cujo id seja o mesmo
// Retorna a posicao na lista ou -1 - Questao 5
int LSE::pesquisarPorId(Info* i) {
	if (qte && i) {
		pos = 0;
		anterior = 0;
		if (inicio->dado->getId() != i->getId()) {
			pos = 1;
			anterior = inicio;
			while (anterior->proximo
					&& (anterior->proximo->dado->getId() != i->getId())) {
				pos++;
				anterior = anterior->proximo;
			}
			if (anterior->proximo)
				return pos;
		} else
			return 0;
	}
	return -1;
}

// Operador de copia - Faz deep copy da lista, criando copias dos nos E das infos
// Questao 6
LSE& LSE::operator=(LSE &outra) {
	// Apagar a lista anterior
	while (this->inicio) {
		this->anterior = this->inicio;
		this->inicio = this->inicio->proximo;
		delete this->anterior;
	}
	// Copiar a lista outra
	this->qte = outra.qte;
	this->pos = 0;
	if (outra.qte) {
		this->inicio = new No(*outra.inicio);
		this->anterior = this->inicio;
		for (No *p = outra.inicio->proximo; p; p = p->proximo) {
			this->anterior->proximo = new No(*p);
			this->anterior = this->anterior->proximo;
		}
	} else {
		this->inicio = 0;
	}
	this->anterior = this->inicio;
	return *this;
}



void LSE::set(Info *elemento, int posicao) {
	if (posicao < 0) return; // Refinar isso para uma excecao decente
	if (qte) {
		if (posicao) {
			int p;
			No *a;

			if (anterior && (posicao >= pos))
				for (p = pos, a = anterior; (p < posicao) && a->proximo; p++, a = a->proximo);
			else
				for (p = 1, a = inicio; (p < posicao) && a->proximo; p++, a = a->proximo);

			if (a->proximo) {
				pos = p;
				anterior = a;
				if(!elemento) remover(posicao);
				else {
					a->proximo->dado = 0;
					a->proximo->dado = elemento;
					return;
//					return a->proximo->dado;
//					return 1;
				}
			}
		} else {
			pos = 0;
			anterior = 0;
			if(!elemento) remover(posicao);
			else {
				inicio->dado = 0;
				inicio->dado = elemento;
				return;
//				return inicio->dado;
//				return 1;
			}
		}
	}
	return;
//	return 0; // Nao ha info para retornar
}


//void LSE::set(Info *elemento, int posicao) {
//	if (posicao < 0) throw; // Nao ha elemento a inserir - vale uma excecao
//	if(!elemento) {
////		remover(posicao);
//		Info * infoAux = remover(posicao);
//		return;
//	} else {
//		No* novo = new No(elemento); // Cria o no a ser inserido na lista
//		if (posicao) { // Posicao diferente do inicio da lista
//			int p;
//			No* a;
//			if (anterior && (posicao >= pos))
//				for (p = pos, a = anterior; (p < posicao) && a->proximo; p++, a = a->proximo);
//			else
//				for (p = 1, a = inicio; (p < posicao) && a->proximo; p++, a = a->proximo);
//
//			novo->proximo = a->proximo;
//			a->proximo = novo;
//			anterior = a;
//			pos = p;
//		} else {
//			novo->proximo = inicio;
//			inicio = novo;
//			anterior = 0;
//			pos = 0;
//		}
//	}
//}
