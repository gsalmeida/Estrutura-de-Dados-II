#include "texto.h"
#include <stdio.h>

// Determina o tamanho de um CString
int tamanho(const char *s){
    char *f = (char *)s;
    for (; *f; f++);
    return f-s;
}

// Construtor vazio. Cria uma string sem caracteres
Texto::Texto () {
    t = new char[1];
    t[0] = '\0';
    fim = t;
}

// Construtor com inicializacao
// Versao com C-string constante
Texto::Texto (const char *txt){        
    t = new char[tamanho(txt)+1];
    char *q;
    
    for (fim=t, q=(char *)txt; *q; fim++, q++)
        *fim = *q;
    *fim = '\0';
}

// Construtor com inicializacao
// Versao com inteiro
Texto::Texto (int i){
    char s[32];
    sprintf (s,"%d", i);
    t = new char[tamanho(s)+1];
    char *q;
    
    for (fim=t, q=(char *)s; *q; fim++, q++)
        *fim = *q;
    *fim = '\0';
}
    
// Construtor de copia
Texto::Texto (const Texto &s) {
    this->t = new char[s.fim-s.t+1];
    char *q;
    
    for (this->fim=this->t, q=(char *)(s.t); *q; this->fim++, q++)
        *this->fim = *q;
    *this->fim = '\0';  
}

// Destrutor. Desaloca texto
Texto::~Texto() {
   if (t)
       delete[] t;   
}

// Tamanho retorna o numero de caracteres
int Texto::comprimento(){
    return fim-t;
}

// Operador de atribuicao
Texto& Texto::operator = (const Texto &s) {
    if (this->t)
        delete[] this->t;
    this->t = new char[s.fim-s.t+1];
    char *q;
    
    for (this->fim=this->t, q=(char *)(s.t); *q; this->fim++, q++)
        *this->fim = *q;
    *this->fim = '\0';  
    return *this;
}

// Operador de comparacao de igualdade
int Texto::operator== (const Texto &s) {
  char *q=this->t, *r=s.t;
  
  for (; *q && *r && (*q == *r); q++, r++);  
  return *q == *r;  
}

// Operador de casting para char *

Texto::operator const char *(){
    return t;
}    
