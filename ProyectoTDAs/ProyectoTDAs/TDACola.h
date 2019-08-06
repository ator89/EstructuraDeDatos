//
//  TDACola.hpp
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//

#ifndef TDACOLA_H
#define TDACOLA_H

#include "Object.h"
#include <string>

class TDACola:public Object{
public:
    virtual ~TDACola();
    
    //insertar en la cola
    virtual void queue(Object*)=0;
    //ver tope de la cola
    virtual Object* front()=0;
    //sacar elemento de la cola
    virtual Object* dequeue()=0;
    //ver si esta vacia
    virtual bool isEmpty()=0;
    //eliminar elementos de la cola
    virtual void clear()=0;
    
    //Métodos polimórficos heredados de Object
    std::string toString() = 0;
    bool equals(Object*) = 0;
};

#endif
