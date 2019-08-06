//
//  TDAPila.hpp
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//

#ifndef TDAPILA_H
#define TDAPILA_H

#include "Object.h"

class TDAPila:public Object{
public:
    virtual ~TDAPila();
    
    //insertar en la pila
    virtual void push(Object*)=0;
    //ver tope de la pila
    virtual Object* top()=0;
    //sacar elemento de la pila
    virtual Object* pop()=0;
    //ver si esta vacia
    virtual bool isEmpty()=0;
    //eliminar elementos de la pila
    virtual void anula()=0;
    
    //Métodos polimórficos de Object
    std::string toString() = 0;
    bool equals(Object*) = 0;
};

#endif
