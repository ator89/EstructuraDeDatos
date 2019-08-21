//
//  LinkedList.cpp
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//

#include "LinkedList.h"
#include "Alumno.h"
#include <typeinfo>


//Constructor y destructor
LinkedList::LinkedList(){
    head = NULL;
    size = 0;
}

//Destructor
LinkedList::~LinkedList(){
    if(head){
        vaciar();
    }
}

//Crear un nuevo nodo
Nodo* LinkedList::getNewNode(Object* data){
    Nodo* nodo = new Nodo();
    nodo->setData(data);
    nodo->setPrevious(nullptr);
    nodo->setNext(nullptr);
    return nodo;
}

//1.1 Insertar elemento en cualquier posición de la lista
void LinkedList::insertar(Object* data,int pos){
    Nodo* temp1 = getNewNode(data);
    //Agregar si la lista está vacía
    if(head == NULL){
        head = temp1;
        size++;
        return;
    }
    //Agregar al inicio
    if(pos == 1){
        head->setPrevious(temp1);
        temp1->setNext(head);
        head = temp1;
        size++;
        return;
    }
    //Agregar al final
    if(pos == size+1){
        Nodo* temp2 = head;
        while(temp2->getNext() != nullptr)
            temp2 = temp2->getNext();
        temp2->setNext(temp1);
        temp1->setPrevious(temp2);
        size++;
        return;
    }else{
        Nodo* temp2 = head;
        for(int i = 0; i < pos-2; i++)
            temp2 = temp2->getNext();
        temp1->setPrevious(temp2);
        temp1->setNext(temp2->getNext());
        temp2->getNext()->setPrevious(temp1);
        temp2->setNext(temp1);
        size++;
        return;
    }
}

//1.2 Imprimir valores de la lista
void LinkedList::imprimir(){
    Nodo* temp = head;
    int i = 1;
    while(temp != NULL){
        std::cout << i << " - " <<temp->getData()->toString()<<"\n";
        temp = temp->getNext();
        i++;
    }
    std::cout<< "\n";
}

//1.3 Buscar un elemento por número de cuenta
Object* LinkedList::buscar(std::string cuenta){
    Nodo* temp = head;
    Object* retval = temp->getData();
    while(temp != nullptr){
        if(cuenta.find(temp->getData()->toString()) != std::string::npos)
            retval = temp->getData();
        else
            retval = nullptr;
        temp = temp->getNext();
    }
    //std::cout << retval->toString();
    return retval;
}

//1.4 Borrar un elemento por posición
Object* LinkedList::borrar(int pos){
    
    if(pos >= 1 && pos <= size){
        //validar si sólo hay un elemento
        if(size == 1){
            Nodo* temp = head;
            Object* tempData = temp->getData();
            temp->setData(NULL);
            delete temp;
            head = NULL;
            size--;
            return tempData;
            
        }
        //posición inicial y la lista tiene más de 1 elemento
        if(pos == 1){
            Nodo* temp = head;
            Object* retval = temp->getData();
            head = temp->getNext();
            temp->setNext(nullptr);
            //validar inicio/head != null
            head->setPrevious(nullptr);
            size--;
            return retval;
        }
        //borrar posición final
        if(pos == size){
            Nodo* temp = head;
            for(int i = 0; i<pos-2; i++)
                temp = temp->getNext();
            Nodo* temp2 = temp->getNext();
            Object* retval = temp2->getData();
            temp2->setData(nullptr);
            temp->setNext(nullptr);
            temp2->setPrevious(nullptr);
            delete temp2;
            size--;
            return retval;
        }
        //borrar entre elementos
        else{
            Nodo* temp = head;
            for(int i = 0; i<pos-2; i++)
                temp = temp->getNext();
            Nodo* temp2 = temp->getNext();
            Object* retval = temp2->getData();
            temp->setNext(temp2->getNext());
            temp2->getNext()->setPrevious(temp);
            temp2->setData(nullptr);
            temp2->setNext(nullptr);
            temp2->setPrevious(nullptr);
            delete temp2;
            size--;
            return retval;
        }
    }else{
        return nullptr;
    }
}

//1.5 Verificar si la lista está vacía
bool LinkedList::isEmpty(){
    return head == NULL;
}

//Retornar la cantidad de elementos en la lista
int LinkedList::getSize(){
    return size;
}


//1.6 Obtener elemento por posición
Object* LinkedList::posicion(int n){
    Nodo* temp = head;
    int pos = 1;
    Object* retval = temp->getData();
    while(temp != nullptr){
        if(n == pos)
            retval = temp->getData();
        temp = temp->getNext();
        pos++;
    }
    return retval;
}

//1.7 Retornar el valor siguiente
Object* LinkedList::siguiente(int pos){
    Nodo* temp = head;
    int count = 1;
    Object* retval = temp->getData();
    while(temp->getNext() != nullptr){
        if(count == pos)
            retval = temp->getNext()->getData();
        temp = temp->getNext();
        count++;
    }
    return retval;
}

//1.8 Devolver el valor anterior
Object* LinkedList::anterior(int pos){
    Nodo* temp = head;
    int count = 1;
    Object* retval = temp->getData();
    while(temp != nullptr){
        if(count == pos)
            retval = temp->getPrevious()->getData();
        temp = temp->getNext();
        count++;
    }
    return retval;
}

//1.9 vaciar elementos de la lista
void LinkedList::vaciar(){
    Nodo* temp = head;
    while(temp->getNext() != nullptr){
        //std::cout << "borrando " << temp->getData() << "\n";
        temp = temp->getNext();
        temp->setPrevious(nullptr);
        head->setNext(nullptr);
        delete head;
        head = temp;
    }
    delete head;
    //std::cout << "último dato " << head->getData() << "\n";
    head = NULL;
    size = 0;
}


//Métodos polimórficos heredados de Object
std::string LinkedList::toString(){
    Nodo* tmp = head;
    //std::stringstream ss;
    std::string s;
    int i = 1;
    
    while(tmp != nullptr){
        s += tmp->getData()->toString() + "\n";
        //ss << i << " " << tmp->getData()->toString() << "\n";
        tmp = tmp->getNext();
        i++;
    }
    //return ss.str();
    return s;
}

//
bool LinkedList::equals(Object*){
    return false;
}
