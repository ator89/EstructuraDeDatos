//
//  LinkedList.cpp
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//

#include "LinkedList.h"
#include "Alumno.h"
#include <iostream>

//Constructor y destructor
LinkedList::LinkedList(){
    head = NULL;
    size = 0;
}

LinkedList::~LinkedList(){
    if(head)
        delete head;

}

//Crear un nuevo nodo
Nodo* LinkedList::getNewNode(Object* data){
    Nodo* nodo = new Nodo();
    nodo->setData(data);
    nodo->setPrevious(nullptr);
    nodo->setNext(nullptr);
    return nodo;
}

//Insertar elemento en cualquier posición de la lista
void LinkedList::insertar(Object* data,int pos){
    Nodo* temp1 = getNewNode(data);
    if(head == NULL){
        head = temp1;
        return;
    }
    else if(pos == 1){
        head->setPrevious(temp1);
        temp1->setNext(head);
        head = temp1;
        return;
    }else{
        Nodo* temp2 = head;
        for(int i = 0; i < pos-2; i++){
            temp1 = temp1->getNext();
        }
        Nodo* temp3 = temp2->getNext();
        temp1->setNext(temp3);
        temp2->setNext(temp1);
        temp1->setPrevious(temp2);
        temp3->setPrevious(temp1);
    }
}

//Imprimir valores de la lista
void LinkedList::imprimir(){
    Nodo* temp = head;
    while(temp != NULL){
        std::cout << temp->getData()->toString();
        temp = temp->getNext();
    }
    std::cout<< "\n";
}

Object* LinkedList::buscar(Object* elemento){
    Object* retval;
    return retval;
}
Object* LinkedList::borrar(int pos){
    Object* retval;
    return retval;
}
bool LinkedList::isEmpty(){
    return false;
}

Object* LinkedList::posicion(int n){
    Nodo* temp = head;
    temp = temp->getNext();
    Object* retval = temp->getData();
    
    return retval;
}

//Devolver el valor anterior
Object* LinkedList::anterior(int pos){
    if(head == 0)
        return 0;
    else if(head->getPrevious() == 0)
        return 0;
    else
        return head->getPrevious()->getData();
}

//Retornar el valor siguiente
Object* LinkedList::siguiente(int pos){
    if(head == 0)
        return 0;
    else
        return head->getNext()->getData();
}

bool LinkedList::vaciar(){
    return false;
}

//Métodos polimórficos heredados de Object
std::string LinkedList::toString(){
    Nodo* tmp = head;
    std::string s;
    while(tmp != nullptr){
        s+=tmp->getData()->toString();
        tmp = tmp->getNext();
    }
    return s;
}
bool LinkedList::equals(Object*){
    return false;
}
