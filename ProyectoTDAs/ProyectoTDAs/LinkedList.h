//
//  LinkedList.h
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include "TDALista.h"
#include "Nodo.h"

class LinkedList:public TDALista{
private:
    Nodo* head;
public:
    //Constructor y destructor
    LinkedList();
    ~LinkedList();
    
    //Métodos administración de la lista
    virtual void insertar(Object*,int);
    virtual void imprimir(Object*);
    virtual bool buscar(Object*);
    virtual bool borrar(Object*);
    virtual bool isEmpty();
    virtual Object* posicion(int);
    virtual Object* anterior(Object*);
    virtual Object* siguiente(Object*);
    virtual bool vaciar(Object*);
    
    //Métodos polimórficos heredados de Object
    virtual std::string toString();
    virtual bool equals(Object*);
};

#endif
