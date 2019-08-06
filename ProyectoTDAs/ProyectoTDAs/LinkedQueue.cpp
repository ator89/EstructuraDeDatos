//
//  LinkedQueue.cpp
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//

#include "LinkedQueue.h"


LinkedQueue::LinkedQueue(){
    inicio = NULL;
    final = NULL;
}

LinkedQueue::~LinkedQueue(){
    if(final)
        delete final;
}

//insertar en la cola
void LinkedQueue::queue(Object* data){
    Nodo* newNode = new Nodo();
    newNode->setData(data);
    if(inicio == NULL && final==NULL){
        final = newNode;
        inicio = newNode;
    }else{
        newNode->setNext(final);
        final->setPrevious(newNode);
        final = newNode;
    }
}

//ver tope de la cola
Object* LinkedQueue::front(){
    if(inicio)
        return inicio->getData();
    else
        return NULL;
}

//sacar elemento de la cola
Object* LinkedQueue::dequeue(){
    if(inicio==NULL){
        return NULL;
    }
    else if(inicio==final){
        Nodo* temp = inicio;
        Object* tempData = temp->getData();
        temp->setData(NULL);
        delete temp;
        inicio = NULL;
        final = NULL;
        return tempData;
    }else{
        Nodo* temp= inicio;
        inicio = temp->getPrevious();
        Object* tempData = temp->getData();
        temp->setData(NULL);
        delete temp;
        inicio->setNext(NULL);
        return tempData;
    }
}

//ver si la cola está vacia
bool LinkedQueue::isEmpty(){
    return inicio == NULL;
}

//eliminar elementos de la cola
void LinkedQueue::clear(){
    if(final)
        delete final;
    final = NULL;
    inicio = NULL;
}

//Métodos polimórficos heredados de Object
std::string LinkedQueue::toString(){
    Nodo* tmp = inicio;
    std::string s;
    while(tmp != nullptr){
        s+=tmp->getData()->toString();
        tmp = tmp->getNext();
    }
    return s;
}

bool LinkedQueue::equals(Object*){
    return false;
}
