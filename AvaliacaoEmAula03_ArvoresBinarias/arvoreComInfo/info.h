/*
 * info - classes de informacoes a serem organizadas em EDs
 * Autor : Carlos R Rocha (carlos.rocha@riogrande.ifrs.edu.br)
 * Versao 140807-2230
 */
#ifndef INFO_H
#define INFO_H

#include <string.h>

/*
 *    O #ifndef serve para evitar mais de um carregamento de header e
 * com isso, redefinicoes, o que causaria erros de compilacao
 * 
 *    O carregamento depende da macro INFO_H estar definida
 * 
 *    Na primeira vez, ela nao esta definida, e o header eh carregado
 * quando acontece a definicao da macro, e com isso, nao carrega mais
 */

/*
 * Info - Classe raiz da hierarquia de informacoes
 */
class Info {
  protected:
    int id; // Numero de identificacao unico para objeto

  public:
    Info()       {id=0;} // Construtor default
    Info (int i) {id=i;} // Construtor com parametro de inicializacao

    int  getId();             // Retorna a id do objeto    
    
    void toString(char *txt); // Retorna uma representacao textual do objeto
    //Se forem usar polimorfismo, usem a versao da linha abaixo, ao inves sa linha de cima
    //virtual void toString(char *txt); // Retorna uma representacao textual do objeto
    
    // Descomente a linha abaixo para ver o destrutor em acao. O virtual eh para o polimorfismo
    //virtual ~Info() {printf ("Destrutor de Info: %d\n",id);};

};


/*
 * Classe Pessoa - classe derivada de Info
 * Autor : Carlos R Rocha (carlos.rocha@riogrande.ifrs.edu.br)
 * Versao 140807-2230
 */
class Pessoa : public Info { // Heranca publica - mantem public da base como public
  protected:
    char nome[101];

  public:
    Pessoa() : Info()  {nome[0] = 0;} // Construtor default - tambem invoca o construtor da classe base
    Pessoa(int i, const char *n) : Info (i) {strcpy(nome, n);} // Construtor com parametro de inicializacao - invoca o construtor da classe base e depois executa seu codigo
    
    ~Pessoa() {printf ("Destrutor de Pessoa: %d\n",id);}; // Destrutor usado apenas para mostrar o efeito na desalocacao de objetos

    void toString(char *txt); // Retorna uma representacao textual do objeto
};

#endif
