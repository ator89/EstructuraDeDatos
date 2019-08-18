//
//  TDALista.hpp
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//

#ifndef TDALISTA_H
#define TDALISTA_H

#include "Object.h"
#include <iostream>
#include <sstream>


class TDALista:public Object{
public:
    ~TDALista();
    
    //Métodos de la lista
    virtual void insertar(Object*,int)=0;
    virtual void imprimir()=0;
    virtual Object* buscar(Object*)=0;
    virtual Object* borrar(int)=0;
    virtual Object* posicion(int)=0;
    virtual Object* anterior(int)=0;
    virtual Object* siguiente(int)=0;
    virtual bool isEmpty()=0;//si no está vacía, imprimir elementos
    virtual void vaciar()=0;
    
    virtual int getSize()=0;

    //Métodos polimórficos
    virtual std::string toString() = 0;
    virtual bool equals(Object*) = 0;
};

#endif
