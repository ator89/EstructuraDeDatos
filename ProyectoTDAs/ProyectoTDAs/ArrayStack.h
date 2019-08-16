//
//  ArrayStack.hpp
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "TDAPila.h"
#include <string>

class ArrayStack:public TDAPila{
private:
    int size;//cantidad de elementos en la pila
    int capacity;//capacidad del arreglo
    Object** array;//arreglo de objetos
    void resize();/*aumenta la capacidad del arreglo*/
public:
    ArrayStack();
    ~ArrayStack();
    
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
