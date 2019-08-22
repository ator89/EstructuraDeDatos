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
    Nodo* getNewNode(Object*);
    int size;
    int posBusqueda;
public:
    //Constructor y destructor
    LinkedList();
    ~LinkedList();
    
    //Métodos de la lista
    virtual void insertar(Object*,int);
    virtual void imprimir();
    virtual Object* buscar(std::string);
    virtual Object* borrar(int);
    virtual Object* posicion(int);
    virtual Object* anterior(int);
    virtual Object* siguiente(int);
    virtual bool isEmpty();//si no está vacía, imprimir elementos
    virtual void vaciar();
    
    virtual int getSize();
    virtual int getPosBusqueda();
    
    //Métodos polimórficos heredados de Object
    virtual std::string toString();
    virtual bool equals(Object*);
};

#endif
