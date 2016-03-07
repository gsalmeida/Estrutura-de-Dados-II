#ifndef INFO_H
#define INFO_H

#include <string.h>

/*
 * Info - Classe raiz da hierarquia de informacoes
 */

class Info {
  protected:
    int id; // Numero de identificacao unico para objeto
    int qtdeOcorrencias;


  public:
    Info() {id = 0; qtdeOcorrencias = 0;} // Construtor default
    Info(int i, int qtdeOcorrenciasParametro) {id = i; qtdeOcorrencias = qtdeOcorrenciasParametro; } // Construtor com parametro de inicializacao

    int  getId();             // Retorna a id do objeto    
    int getQtdeOcorrencias();
    
    //Se forem usar polimorfismo, usem a versao da linha abaixo, ao inves sa linha de cima
//    virtual void toString(char *txt); // Retorna uma representacao textual do objeto
};


#endif
