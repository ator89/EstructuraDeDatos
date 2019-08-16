//
//  Simbolo.hpp
//  ProyectoTDAs
//

#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <string>
#include <sstream>
#include "Object.h"

class Simbolo:public Object{
private:
    char simbolo;
public:
    //Constructores y Destructor
    Simbolo();
    Simbolo(char);
    ~Simbolo();
    
    //Accesor
    char getSimbolo();
    
    //Mutador
    void setSimbolo(char);
    
    //Métodos polimórficos
    virtual std::string toString();
    virtual bool equals(Object*);
};

#endif
