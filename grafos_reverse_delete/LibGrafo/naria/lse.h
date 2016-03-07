/*
 * lse - classe de lista simplesmente encadeada
 * Autor : Carlos R Rocha (carlos.rocha@riogrande.ifrs.edu.br)
 * Versao 140814-1600
 */
#ifndef LSE_H
#define LSE_H

#include "info.h"
//#include "arvoren.h"

class LSE; // Necessario para No saber que existe a classe LSE como amiga

// No da lista. Nao deve aparecer publicamente
class No {
protected:
    Info* dado;
    No*   proximo;
   
public:
    No(Info *i); // Construtor de inicializacao. Nao ha sentido em ter outro
    No(No& n);   // Construtor de copia
    ~No();       // Destrutor do no
    friend class LSE; // Da acesso aos elementos da classe No para a classe LSE
};


// Lista simplesmente encadeada
class LSE {  
protected:
    No *inicio;   // Aponta para o inicio da lista
    No *anterior; // Para auxilio em percorrer a lista
    int qte;      // Quantidade de nos
    int pos;  // Posicao atual
    
public:
    LSE();      // Construtor default - Lista vazia
    LSE(LSE &); // Construtor de copia
    ~LSE();     // Destrutor da lista
    
    // Inclui o elemento na posicao desejada
    void inserir (Info *elemento, int posicao=0);
    // Retorna o elemento da posicao especificada
    Info* obter (int posicao=0);
    // Remove o elemento da lista e o retorna
    Info* remover (int posicao=0);
    // Pesquisa o elemento pelo seu id e retorna a sua posicao
    int pesquisarPorId (Info* i);
    // Sobrecarga da atribuicao (deep copy)
    LSE& operator= (LSE &outra);
    // Retorna o numero de elementos inseridos
    int quantidade(void) {return qte;};

    void set(Info *elemento, int posicao);




};

#endif
