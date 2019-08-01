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


class TDALista:public Object{
public:
    ~TDALista();
    
    //Métodos de la lista
    virtual void insertar(Object*,int)=0;
    virtual void imprimir()=0;
    virtual bool buscar(Object*)=0;
    virtual bool borrar(Object*)=0;
    virtual bool isEmpty()=0;
    virtual Object* posicion(int)=0;
    virtual Object* anterior()=0;
    virtual Object* siguiente()=0;
    virtual bool vaciar(Object*)=0;
    
    virtual Object* top()=0;
    
    //Métodos polimórficos
    std::string toString() = 0;
    bool equals(Object*) = 0;
};

#endif
