//
//  LinkedQueue.hpp
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "Nodo.h"
#include "TDALista.h"

class LinkedQueue:public TDALista{
private:
    Nodo* inicio;
    Nodo* final;
    
public:
    LinkedQueue();
    ~LinkedQueue();
    
    //insertar en la cola
    virtual void queue(Object*);
    //ver tope de la cola
    virtual Object* front();
    //sacar elemento de la cola
    virtual Object* dequeue();
    //ver si esta vacia
    virtual bool isEmpty();
    //eliminar elementos de la cola
    virtual void clear();
    
    //Métodos polimórficos de Object
    std::string toString();
    bool equals(Object*);
};

#endif
