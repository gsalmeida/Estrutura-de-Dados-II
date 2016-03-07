// Segunda Avaliação da Disciplina de EDII

// balanceamento = alturaDireita - alturaEsquerda. Tem que ser entre -1 e 1, inclusive(s). (-1, 0, 1).
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct no {
    int info;
    int fatorDeBalanceamento; /* alturaDireita - alturaEsquerda */
    struct no *esq, *dir;
}*arvore = NULL;

int cresceuTamanhoArvore;

void imprimirArvore(struct no *arvore) {
    if (arvore != NULL) {
        imprimirArvore(arvore->esq);
        printf("%d", arvore->info);
        printf("(%d)", arvore->fatorDeBalanceamento);
        printf(" ");
        imprimirArvore(arvore->dir);
    }
}

void imprimirArvore2(struct no *arvore) {
    int esquerda, direita;
    struct no *no_atual;
    if (arvore) {
        no_atual = arvore->esq;
        if (no_atual)
            esquerda = no_atual->info;
        else
            esquerda = -99999;

        no_atual = arvore->dir;

        if (no_atual)
            direita = no_atual->info;
        else
            direita = -99999;

        if ((esquerda != -99999) && (direita != -99999))
            printf("\n[%d]<---[%d]--->[%d]", esquerda, arvore->info, direita);
        else if (esquerda != -99999)
            printf("\n[%d]<---[%d]--->[%s]", esquerda, arvore->info, "NULL");
        else if (direita != -99999)
            printf("\n[%s]<---[%d]--->[%d]", "NULL", arvore->info, direita);
        else
            printf("\n[%s]<---[%d]--->[%s]", "NULL", arvore->info, "NULL");
        printf("\n");
        printf("%d", arvore->fatorDeBalanceamento);
        printf("\n");
        imprimirArvore2(arvore->esq);
        imprimirArvore2(arvore->dir);
    }
}

void imprimirNivel(struct no * arvore, int altura) {
    if (arvore != NULL) {
        if (!altura)
            printf("%d  ", arvore->info);
        else {
            imprimirNivel(arvore->esq, altura - 1);
            imprimirNivel(arvore->dir, altura - 1);
        }
    }
}

int altura(struct no *arvore) {
    if (arvore == NULL)
        return 0;
    int alturaEsquerda = altura(arvore->esq);
    int alturaDireita = altura(arvore->dir);
    return alturaEsquerda > alturaDireita ?
            alturaEsquerda + 1 : alturaDireita + 1;
}

//rotação direita
void LL(struct no *&arvore) {
    struct no *b = arvore;
    struct no *a = b->esq;
    b->esq = a->dir;
    a->dir = b;
    a->fatorDeBalanceamento = 0;
    b->fatorDeBalanceamento = 0;
    arvore = a;
}

//rotação esquerda
void RR(struct no *&arvore) {
    struct no *a = arvore;
    struct no *b = a->dir;
    a->dir = b->esq;
    b->esq = a;
    a->fatorDeBalanceamento = 0;
    b->fatorDeBalanceamento = 0;
    arvore = b;
}

//Rotação dupla direita
void LR(struct no *&arvore) {
    struct no *c = arvore;
    struct no *a = c->esq;
    struct no *b = a->dir;
    c->esq = b->dir;
    a->dir = b->esq;
    b->esq = a;
    b->dir = c;
    switch (b->fatorDeBalanceamento) {
    case -1:
        a->fatorDeBalanceamento = 0;
        c->fatorDeBalanceamento = 1;
        break;
    case 0:
        a->fatorDeBalanceamento = 0;
        c->fatorDeBalanceamento = 0;
        break;
    case +1:
        a->fatorDeBalanceamento = -1;
        c->fatorDeBalanceamento = 0;
        break;
    }
    b->fatorDeBalanceamento = 0;
    arvore = b;
}

//Rotação dupla esquerda
void RL(struct no *&arvore) {
    struct no *a = arvore;
    struct no *c = a->dir;
    struct no *b = c->esq;
    c->esq = b->dir;
    a->dir = b->esq;
    b->esq = a;
    b->dir = c;
    switch (b->fatorDeBalanceamento) {
    case -1:
        a->fatorDeBalanceamento = 0;
        c->fatorDeBalanceamento = 1;
        break;
    case 0:
        a->fatorDeBalanceamento = 0;
        c->fatorDeBalanceamento = 0;
        break;
    case +1:
        a->fatorDeBalanceamento = -1;
        c->fatorDeBalanceamento = 0;
        break;
    }
    b->fatorDeBalanceamento = 0;
    arvore = b;
}



int CalculaFatorDeBalanceamento(struct no *arvore) {
    if(arvore == NULL)return 0;
    return (altura(arvore->esq)- altura(arvore->dir));
}


struct no* criarElemento(int valor, struct no *esq, struct no *dir) {
    struct no *n = (struct no *) malloc(sizeof(struct no));
    n->info = valor;
    n->fatorDeBalanceamento = altura(dir) - altura(esq);
    n->esq = esq;
    n->dir = dir;
    return n;
}

int inserirElemento(struct no *&arvore, int valor, int &cresceuTamanhoArvore) {
    if (arvore == NULL) {
        arvore = criarElemento(valor, NULL, NULL);
        cresceuTamanhoArvore = 1;
        return 1;
    }
    if (valor < arvore->info) {
        if (inserirElemento(arvore->esq, valor, cresceuTamanhoArvore)) {
            if (cresceuTamanhoArvore) {
                switch (arvore->fatorDeBalanceamento) {
                case -1:
                    if (arvore->esq->fatorDeBalanceamento == -1)
                        LL(arvore);
                    else
                        LR(arvore);
                    cresceuTamanhoArvore = 0;
                    break;
                case 0:
                    arvore->fatorDeBalanceamento = -1;
                    cresceuTamanhoArvore = 1;
                    break;
                case +1:
                    arvore->fatorDeBalanceamento = 0;
                    cresceuTamanhoArvore = 0;
                    break;
                }
            }
            return 1;
        } else
            return 0;
    }else if (valor >= arvore->info) {
        if (inserirElemento(arvore->dir, valor, cresceuTamanhoArvore)) {
            if (cresceuTamanhoArvore) {
                switch (arvore->fatorDeBalanceamento) {
                case -1:
                    arvore->fatorDeBalanceamento = 0;
                    cresceuTamanhoArvore = 0;
                    break;
                case 0:
                    arvore->fatorDeBalanceamento = +1;
                    cresceuTamanhoArvore = 1;
                    break;
                case +1:
                    if (arvore->dir->fatorDeBalanceamento == +1)
                        RR(arvore);
                    else
                        RL(arvore);
                    cresceuTamanhoArvore = 0;
                    break;
                }
            }
            return 1;
        } else
            return 0;
    }
    return 1;
}

struct no* excluirElemento(struct no *&arvore, int valor, int excluirRepetidos) {
    if (arvore == NULL)
        return NULL;
    else if (arvore->info > valor)
        arvore->esq = excluirElemento(arvore->esq, valor, excluirRepetidos);
    else if (arvore->info < valor)
        arvore->dir = excluirElemento(arvore->dir, valor, excluirRepetidos);
    else {
        //nao tem filhos

        if (arvore->esq == NULL && arvore->dir == NULL) {
			free (arvore);
            arvore = NULL;
        }
        //filho para a direita
        else if (arvore->esq == NULL) {
            struct no *arvoreAux = arvore;
            arvore = arvore->dir;
            free (arvoreAux);
        }
        //filho para a esquerda
        else if (arvore->dir == NULL) {
            struct no *arvoreAux = arvore;
            arvore = arvore->esq;
            free (arvoreAux);
        }
        //filho(s) para esquerda e direita
        else {
            struct no *arvoreAux = arvore->dir;
            if(arvoreAux->info != valor)
                while (arvoreAux->esq != NULL)
                    arvoreAux = arvoreAux->esq;
            arvore->info = arvoreAux->info;
            /*troca as informações*/
            arvoreAux->info = valor;
            arvore->dir = excluirElemento(arvore->dir, valor, excluirRepetidos);
			//free(arvoreAux);
//double free : Error
        }


        //esta linha faz com que recomece a função e remova todos os outros repetidos. Recursividade
//        if(excluirRepetidos)
//            excluirElemento(arvore, valor, excluirRepetidos);
    }
    return arvore;
}

int atualizarFatorDeBalanceamento (struct no *arvore) {
    if (arvore != NULL) {
        arvore->fatorDeBalanceamento = (altura(arvore->dir) - altura(arvore->esq) );
        atualizarFatorDeBalanceamento(arvore->esq);
        arvore->fatorDeBalanceamento = (altura(arvore->dir) - altura(arvore->esq) );
        atualizarFatorDeBalanceamento(arvore->dir);
    }
    return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

struct no *nodo_nivel (struct no *raiz,int nivel, int i){
/* Função retorna o iésimo nodo de um certo nível(i e nível passado como parâmetro).
Para encontrar o nodo o i é transformado em binário com tamanho de nivel bits onde
cada a sequencia de bits determina o caminho utilizado para encontrar o nodo,
'0' vai para filho da esquerda e '1' vai para filho da direita.
Caso nodo não existir devove um nodo nulo.
*/
 int j;
 char *binario;
 struct no *temp=raiz;
 if (nivel==1)
    return raiz;
 else{  // encontra nodo
    binario=(char*) malloc (nivel-1 * sizeof(char));
    dtob(binario,nivel-1,i-1);
    for (j=0;j<nivel-1;j++){
       if (binario[j]=='0')
          if (temp->esq != NULL){
             temp=temp->esq;}
          else
              return NULL;
       else
           if (temp->dir != NULL){
              temp=temp->dir; }
           else
               return NULL;
    }
    return temp;
 }
}

void imprime_nivel(struct no *raiz,int nivel){
/*Imprime todos os nodos de certo nível passado como parâmetro caso exista o nível.
Para isso é utilizada a função de encontrar o iésimo nodo no nível.
É calculado a quantidade de segmentos em cada nível e o tamanho dos segmentos
baseado na altura da árvore e na quantidade total de nodos que um nível pode ter a fim de
utilizar-la na impreção de toda árvore.*/
 int seg=1;
 double div=0;
 int i,j;
 int altura_arvore;
 altura_arvore=altura(raiz);
       printf("\n");
       div=pow((double)2,(double)(nivel-1))+1; // qtde de segmentos do nivel
        seg = (int)(pow((double)2,(double)altura_arvore)/(double)div) -1;// tamanho do segmento

        if (seg<=0) // ultimo nivel
           seg = 1;
        for (i=1;i<(int)div;i++){// imprime todos segmentos
          if (i==1)
            for (j=0;j<seg-1;j++)
                printf("   ");
          else
            for (j=0;j<seg;j++)
                printf("   ");
          if (nodo_nivel(raiz,nivel,i)!=NULL){
             printf("%d(%d)", (nodo_nivel(raiz,nivel,i))->info, (nodo_nivel(raiz,nivel,i))->fatorDeBalanceamento);
//             if ((nodo_nivel(raiz,nivel,i))->pai!= NULL)
//                printf("p=%d",((nodo_nivel(raiz,nivel,i))->pai)->info); // caso queira mostrar o pai de cada nodo, descomentar esse trecho
         } else
             for (j=0;j<seg;j++)
             printf("   ");   // caso nodo não existir, um lugar vazio
        }
        printf("\n");
}


void imprime_arvore(struct no *raiz){
/*Imprime todos os níveis da árvore, utilizando a função de imprimir o nível.
Com um pouco de imaginação é possível ver quem é filho de quem. */
   int i;
   int nivel=altura(raiz);
   for (i=1;i<=nivel;i++){
       imprime_nivel(raiz,i);
       printf("\n");
       printf("\n");
       }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int procura(struct no *arvore, int valor) {
    struct no *arvoreAux;
    for(arvoreAux = arvore; (arvoreAux != NULL); arvoreAux = (valor<arvoreAux->info)? arvoreAux->esq: arvoreAux -> dir) if (arvoreAux->info == valor) return (1);
    return (0);
}








struct no *rotacao_direita(struct no *&N3) {
       struct no *&N2 = N3->esq;
       if(N2->dir) N3->esq = N2->dir;
       else N3->esq = NULL;
       N2->dir = N3;
       return N2;
}

struct no *rotacao_esquerda(struct no *&N1) {
       struct no *&N2 = N1->dir;
       if(N2->esq) N1->dir = N2->esq;
       else N1->dir = NULL;
       N2->esq = N1;
       return N2;
}

struct no *rotacao_dupla_direita (struct no *&N3) {
       struct no *&N1 = N3->esq;
       struct no *&N2 = N1->dir;

       if(N2->esq) N1->dir = N2->esq;
       else N1->dir = NULL;

       if(N2->dir) N3->esq = N2->dir;
       else N3->esq = NULL;

       N2->esq = N1;
       N2->dir = N3;
       
       return N2;
}

struct no *rotacao_dupla_esquerda (struct no *&N1) {
       struct no *&N3 = N1->dir;
       struct no *&N2 = N3->esq;

       if(N2->esq) N1->dir = N2->esq;
       else N1->dir = NULL;

       if(N2->dir) N3->esq = N2->dir;
       else N3->esq = NULL;

       N2->esq = N1;
       N2->dir = N3;
       
       return N2;
}

int calculaFatorDeBalanceamento(struct no *arvore) {
    if(arvore == NULL) return 0;
    return (altura(arvore->esq) - altura(arvore->dir));
}

//struct no *balancearArvoreAVL(struct no *&arvore) {
void balancearArvoreAVL(struct no *&arvore) {
	if(arvore != NULL) {
		arvore->fatorDeBalanceamento = calculaFatorDeBalanceamento(arvore);
		if(arvore->fatorDeBalanceamento == 2) {
			arvore->esq->fatorDeBalanceamento = calculaFatorDeBalanceamento(arvore->esq);
			if(arvore->esq->fatorDeBalanceamento > 0) {
				//arvore = rotacao_direita(arvore);
				LL(arvore);
			} else {
				//arvore =  rotacao_dupla_direita(arvore);
				RL(arvore);
			}
		} else if(arvore->fatorDeBalanceamento == -2) {
			arvore->dir->fatorDeBalanceamento = calculaFatorDeBalanceamento(arvore->dir);
			if(arvore->dir->fatorDeBalanceamento < 0) {
				//arvore = rotacao_esquerda(arvore);
				RR(arvore);
			} else {
				//arvore =  rotacao_dupla_esquerda(arvore);
				LR(arvore);
			}
		}
//		arvore->esq = balancearArvoreAVL(arvore->esq);
//		arvore->dir = balancearArvoreAVL(arvore->dir);
		balancearArvoreAVL(arvore->esq);
		balancearArvoreAVL(arvore->dir);
    }
//    return arvore;
}











void menu() {
    int comando;
    int vidaMenu = 1;

    while (vidaMenu) {
        printf("\n\n1 - Inserir\n2 - Excluir\n3 - Procurar\n4 - Imprimir\n0 - Sair\n\n");
        scanf("%d", &comando);
        if(comando == 11) comando = 1;
        printf("%s", "\n");

        switch (comando) {
            case 1: {//Inserir
                int numero;
                printf("Digite o número");
                scanf("%d", &numero);
                inserirElemento(arvore, numero, cresceuTamanhoArvore);
				atualizarFatorDeBalanceamento(arvore);
                break;
            }
            case 2: { //Excluir
                int numero;
                int opcaoExcluir;
                printf("Digite o número para excluir");
                scanf("%d", &numero);
                printf("1-Excluir Todos \n2 - apenas o primeiro encontrado.");
                scanf("%d", &opcaoExcluir);
                if(opcaoExcluir)
                    excluirElemento(arvore, numero, 1);
                else
                    excluirElemento(arvore, numero, 0);
				atualizarFatorDeBalanceamento(arvore);
				printf("___________________\n");
				printf("%d", arvore->info);
				printf("___________________\n");
//				balancearArvoreAVL(arvore);
                break;
            }
            case 3: { //Buscar
                int numero;
                printf("Digite o número");
                scanf("%d", &numero);
                if(procura(arvore, numero))
                    printf("Número (%d) existe na árvore", numero);
                else
                    printf("Número (%d) não existe na árvore", numero);
                break;
            }
            case 4: { //Imprimir
                atualizarFatorDeBalanceamento(arvore);
                imprimirArvore(arvore);
                printf("\n");imprimirArvore2(arvore);printf("\n");
                printf("\n\nIMPRIMI_ARVORE\n\n");
                imprime_arvore(arvore);
                printf("\n");
                break;
            }
        }
        if(comando == 0) vidaMenu = 0;
        else if( (comando < 1) || (comando > 4) )  {
            comando = 0;
            printf("Comando inválido");
        }
    }
}


int main() {
    
    menu();

    return 0;
} 
