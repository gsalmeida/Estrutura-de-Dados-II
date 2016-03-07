// Arvore Binaria de Busca (A.B.B.)

#include <iostream>

using namespace std;

// Classe No

class No {

   public:
	   int info;
	   No *noEsquerda, *noDireita;

	   // Construtor
	   No() : info(0), noEsquerda(NULL), noDireita(NULL) {
	   }

	   // Destrutor
	   ~No() {
	   }
};

// Classe ABB

class ABB {

   private:
	   No *pRaiz;

   public:
	   // Construtor
	   ABB() : pRaiz(NULL) {
	   }

	   // Inserir em A.B.B.
	   void inserirABB(int valor) {

		  No *pNovo = new No();
		  pNovo->info = valor;

		  if ( pRaiz == NULL ) {
			  pRaiz = pNovo;
		  }else {
			  No *pAtual = pRaiz;
			  No *pAncestral = NULL;
			  while ( true ) {
				  pAncestral = pAtual;
				  if ( valor < pAtual->info ) {
					  pAtual = pAtual->noEsquerda;
					  if ( pAtual == NULL ) {
						  pAncestral->noEsquerda = pNovo;
						  return;
					  }
				  }else {
					  if ( valor == pAtual->info ) {
						  delete pNovo;
						  return;
					  }else {
						  pAtual = pAtual->noDireita;
						  if ( pAtual == NULL ) {
							  pAncestral->noDireita = pNovo;
							  return;
						  }
					  }
				  }
			  };
		  }
	   }

	   // preOrdem:
	   void preOrdem(No *pRaiz) {
		   if (pRaiz != NULL) {
			   cout << " " << pRaiz->info;
			   preOrdem(pRaiz->noEsquerda);
			   preOrdem(pRaiz->noDireita);
		   }
	   }

	   // inOrdem:
	   void inOrdem(No *pRaiz) {
		   if (pRaiz != NULL) {
			   inOrdem(pRaiz->noEsquerda);
			   cout << " " << pRaiz->info;
			   inOrdem(pRaiz->noDireita);
		   }
	   }


	   // posOrdem:
	   void posOrdem(No *pRaiz) {
		   if (pRaiz != NULL) {
			   posOrdem(pRaiz->noEsquerda);
			   posOrdem(pRaiz->noDireita);
			   cout << " " << pRaiz->info;
		   }
	   }


	   // Chamada dos Percursos pre, in e pos-ordem:
	   void percorrerABB(void) {
		   cout << "\npre: ";
		   preOrdem(pRaiz);
		   cout << "\nin: ";
		   inOrdem(pRaiz);
		   cout << "\npos: ";
		   posOrdem(pRaiz);
	   }

	   //  Calculo do nro. de nos:
	   int nroNos(No *pRaiz) {
		   int n1=0, n2=0;
		   if (pRaiz == NULL) return ( 0 );
		   else {
			   n1 = nroNos(pRaiz->noEsquerda);
			   n2 = nroNos(pRaiz->noDireita);
			   return ( n1 + n2 + 1 );
		   }
	   }


	   //  Chamada e exibicao da quantidade de nos:
	   void quantidadeNos(void) {
		   int qtd = nroNos(pRaiz);
		   cout << "\nA quantidade de nos e': " << qtd;
	   }

	   //  Calculo do Somatorio das Chaves:
	   int somatorioNos(No *pRaiz) {
		   int s1=0, s2=0;
		   if (pRaiz == NULL) return ( 0 );
		   else {
			   s1 += somatorioNos(pRaiz->noEsquerda);
			   s2 += somatorioNos(pRaiz->noDireita);
			   return ( pRaiz->info + s1 + s2 );
		   }
	   }


	   //  Chamada e exibicao da Media Aritmetica das Chaves:
	   void somaChavesABB(void) {
		   int soma = somatorioNos(pRaiz);
		   cout << "\nA somatoria das chaves e': " << soma;
	   }

	   //  Chamada e exibicao da Somatoria das Chaves:
	   void mediaAritmeticaABB(void) {
		   float media = (float) somatorioNos(pRaiz) / (float) nroNos(pRaiz);
		   cout << "\nA Media Aritmetica das chaves e': " << media;
	   }};

// Programa Principal
void main (void) {

	ABB exemplo;

	exemplo.inserirABB(25);
	exemplo.inserirABB(10);
	exemplo.inserirABB(12);
	exemplo.inserirABB(16);
	exemplo.inserirABB(15);
	exemplo.inserirABB(30);
	exemplo.inserirABB(45);
	exemplo.inserirABB(36);
	exemplo.inserirABB(33);
	exemplo.inserirABB( 4);

	exemplo.percorrerABB();
	exemplo.quantidadeNos();
	exemplo.somaChavesABB();
	exemplo.mediaAritmeticaABB();

	cout << endl;
}
