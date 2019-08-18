//
//  LinkedStack.cpp
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//


#include "LinkedStack.h"

//Constructor
LinkedStack::LinkedStack(){
    head = NULL;
}

//Destructor
LinkedStack::~LinkedStack(){
    if(head)
        delete head;
}

//insertar en la pila
void LinkedStack::push(Object* data){
    Nodo* newNode = new Nodo();
    newNode->setData(data);
    if(head == NULL){
        head = newNode;
    }else{
        head->setPrevious(newNode);
        newNode->setNext(head);
        head = newNode;
    }
}

//ver tope de la pila
Object* LinkedStack::top(){
    if(head == 0) // si el inicio es null
        return 0;
    else{
        return head->getData();
    }
}

//sacar elemento de la pila
Object* LinkedStack::pop(){
    if(head == 0)
        return 0;
    else{
        //Copiar la dirección del nodo que se va a eliminar
        Nodo* tmp = head;
        //enlazar inicio
        head=head->getNext();
        //obtener el objeto a retornar
        Object* retVal = tmp->getData();
        //Preparar para liberar el nodo que no se necesita máscanf
        tmp->setData(0);//asignar null
        tmp->setNext(0);//asignar null
        //liberar la memoria del nodo
        delete tmp;
        //retornar
        return retVal;
    }
}

//ver si esta vacia
bool LinkedStack::isEmpty(){
    return head == NULL;
}

//eliminar elementos de la pila
void LinkedStack::anula(){
    if(head)
        delete head;
    head = NULL;
}

//Métodos polimórficos heredados de Object
std::string LinkedStack::toString(){
    Nodo* tmp = head;
    std::string s;
    while(tmp != nullptr){
        s+=tmp->getData()->toString() + "\n";
        tmp = tmp->getNext();
    }
    return s;
}

bool LinkedStack::equals(Object*){
    return false;
}
