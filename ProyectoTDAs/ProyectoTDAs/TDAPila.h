//
//  TDAPila.h
//  ProyectoTDAs
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
    virtual std::string toString() = 0;
    virtual bool equals(Object*) = 0;
};

#endif
