//
//  Nodo.hpp
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//

#ifndef NODO_H
#define NODO_H

#include "Object.h"

class Nodo{
private:
    Object* data;
    Nodo* next;
    Nodo* previous;
public:
    //Constructores y destructor
    Nodo();
    Nodo(Object*);
    ~Nodo();
    
    //Accesores
    Object* getData();
    Nodo* getNext();
    Nodo* getPrevious();
    
    //Mutadores
    void setData(Object*);
    void setNext(Nodo*);
    void setPrevious(Nodo*);
};
#endif
