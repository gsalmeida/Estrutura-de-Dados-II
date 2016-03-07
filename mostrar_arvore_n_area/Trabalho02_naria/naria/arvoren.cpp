#include "arvoren.h"


ArvoreN::ArvoreN() {
   info = 0;
   pai = 0;
   altura = 0;
}

ArvoreN::ArvoreN(Info *i) {
   info = i;
   pai = 0;
   altura = 0;
}

ArvoreN::~ArvoreN() {
    ArvoreN* arv;
    for (int i=0; i < filhos.quantidade(); i++) {
        arv = (ArvoreN*) filhos.obter(i);
        if (arv)
            delete arv;
    }
}

void ArvoreN::setPai(ArvoreN *arv) {
    pai = arv;
}

ArvoreN* ArvoreN::getPai() { return pai; }

Info* ArvoreN::getInfo() {return info; }



void ArvoreN::setFilho(ArvoreN *arv, int pos) {
    if (arv) {
        if (pos >= filhos.quantidade()) {
        	int quantidadeFilhosNaLista = filhos.quantidade();
            filhos.inserir((Info *) arv, quantidadeFilhosNaLista);
        } else {
            filhos.set(arv, pos); //TODO A ser implementado    /// IMPLEMENTADO!!!
        }
    } else {
        filhos.remover (pos);
    }
}

ArvoreN* ArvoreN::getFilho(int pos) {
    return (ArvoreN *) filhos.obter(pos);
}

