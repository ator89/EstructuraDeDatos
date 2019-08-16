//
//  LinkedStack.hpp
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "TDAPila.h"
#include "Nodo.h"
#include <string>

class LinkedStack:public TDAPila{
private:
    Nodo* head;
public:
    LinkedStack();
    ~LinkedStack();
    
    //insertar en la pila
    virtual void push(Object*);
    //ver tope de la pila
    virtual Object* top();
    //sacar elemento de la pila
    virtual Object* pop();
    //ver si esta vacia
    virtual bool isEmpty();
    //eliminar elementos de la pila
    virtual void anula();
    
    //Métodos polimórficos de Object
    virtual std::string toString();
    virtual bool equals(Object*);
};

#endif
