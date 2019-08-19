//
//  Nodo.cpp
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//

#include "Nodo.h"

//Constructor por defecto
Nodo::Nodo(){
    next = NULL;
    previous = NULL;
    data = NULL;
}

//Constructor sobrecargado
Nodo::Nodo(Object* data){
    this->data = data;
    next = 0;
    previous = 0;
}

//Destructor
Nodo::~Nodo(){
    if(next)
        delete next;
    if(data)
        delete data;
}

//Accesores
Object* Nodo::getData(){
    return data;
}

Nodo* Nodo::getNext(){
    return next;
}

Nodo* Nodo::getPrevious(){
    return previous;
}

//Mutadores
void Nodo::setData(Object* data){
    this->data = data;
}

void Nodo::setNext(Nodo* siguiente){
    next = siguiente;
}

void Nodo::setPrevious(Nodo* anterior){
    previous = anterior;
}

