#ifndef TEXTO_H
#define TEXTO_H

/*
 * Texto - classe que representa strings
 * Autor: Carlos R Rocha (cticarlo@gmail.com)
 * Versao: 140914-1000
 */

class Texto {
private:
    char *t;
    char *fim;

public:
    Texto ();
    Texto (const char *);
    Texto (int);
    Texto (const Texto &);
    ~Texto ();

    int comprimento();
    
    Texto& operator = (const Texto &);
    
    int operator== (const Texto &s);

    operator const char*();
};

#endif