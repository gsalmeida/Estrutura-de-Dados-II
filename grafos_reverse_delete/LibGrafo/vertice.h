#ifndef VERTICE_H
#define VERTICE_H

#include "texto.h"


#include "naria/info.h"
class Vertice : public Info {
protected:
    unsigned id;
    int visitado;
//    pai e ou filho pra montar a Árvore N-ária
public:
    Vertice(unsigned i=0);

    unsigned getId();

    void setVisitado(unsigned valor);

    int getVisitado();



    virtual Texto toString();

};

#endif // VERTICE_H
