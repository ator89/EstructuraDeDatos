//
//  ArrayList.hpp
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "TDALista.h"

class ArrayList:public TDALista{
private:
    Object** array;//arreglo de apuntadores a object
    int capacity;//tamaño del arreglo
    int size;//cantidad de elementos en la lista
    void resize();/*aumenta la capacidad del arreglo*/
public:
    ArrayList();
    ~ArrayList();
    
    virtual void insertar(Object*,int);
    virtual void imprimir();
    virtual Object* buscar(Object*);
    virtual Object* borrar(int);
    virtual Object* posicion(int);
    virtual Object* anterior(int);
    virtual Object* siguiente(int);
    virtual bool isEmpty();//si no está vacía, imprimir elementos
    virtual void vaciar();
    
    //Métodos polimórficos
    virtual std::string toString();
    virtual bool equals(Object*);
};

#endif
