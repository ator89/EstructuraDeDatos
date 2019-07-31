//
//  LinkedList.cpp
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//

#include "LinkedList.h"
#include "Alumno.h"

//Constructor y destructor
LinkedList::LinkedList(){
    head = NULL;
}
LinkedList::~LinkedList(){
    if(head)
        delete head;
}

//Métodos administración de la lista
void LinkedList::insertar(Object* data,int pos){
    Nodo* temp1 = new Nodo();
    temp1->setData(data);
    temp1->setNext(nullptr);
    temp1->setPrevious(nullptr);
    if(head == NULL){
        return;
    }
    else if(pos == 1){
        temp1->setNext(head);
        head->setPrevious(temp1);
        head = temp1;
        return;
    }else{
        for(int i = 0; i < pos-2; i++){
            temp1 = temp1->getNext();
        }
        Nodo* temp2 = temp1->getNext();
        temp1->setNext(temp2->getNext());
        temp2->setNext(temp1);
    }
}

void LinkedList::imprimir(Object* lista){}

bool LinkedList::buscar(Object* elemento){
    return false;
}
bool LinkedList::borrar(Object*){
    return false;
}
bool LinkedList::isEmpty(){
    return false;
}
Object* LinkedList::posicion(int n){
    Object* temp = new Alumno();
    return temp;
}
Object* LinkedList::anterior(Object* anterior){
    return anterior;
}
Object* LinkedList::siguiente(Object* siguiente){
    return siguiente;
}
bool LinkedList::vaciar(Object*){
    return false;
}

//Métodos polimórficos heredados de Object
std::string toString(){
    return "";
}
bool equals(Object*){
    return false;
}
