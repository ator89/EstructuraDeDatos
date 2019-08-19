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
    /*Nodo* temp1 = getNewNode(data);
    if(head == NULL){
        head = temp1;
        size++;
        return;
    }
    else if(pos == 1){
        head->setPrevious(temp1);
        temp1->setNext(head);
        head = temp1;
        size++;
        return;
    }else{
        Nodo* temp2 = head;
        for(int i = 0; i < pos-2; i++){
            temp2 = temp2->getNext();
        }
        temp1->setNext(temp2->getNext());
        temp2->setNext(temp1);
        //verificar que temp1->next() != NULL
        temp1->getNext()->setPrevious(temp1);
        temp1->setPrevious(temp2);
        
        size++;
    }*/
    /*if(pos >= 1 && pos <= size+1){
        Nodo* nodo = new Nodo();
        nodo->setData(data);
        nodo->setPrevious(nullptr);
        nodo->setNext(nullptr);
        if(head == 0 || size == 0){
            head = nodo;
        }else if(pos == 1){
            nodo->setNext(head);
            head->setPrevious(nodo);
            head = nodo;
        }else{
            Nodo* temp = head;
            for(int i=2; i<pos-1; i++)
                temp = temp->getNext();
            nodo->setNext(temp->getNext());
            temp->setNext(nodo);
            nodo->getNext()->setPrevious(nodo);
            nodo->setPrevious(temp);
        }
    }*/
    if (pos <= size + 1)
    {
        Nodo *nuevo = new Nodo();
        nuevo->setData(data);
        if (pos == 1)
        {
            nuevo->setNext(head);
            if (head != NULL)
                head->setPrevious(nuevo);
            head = nuevo;
        }
        else
            if (pos == size + 1)
            {
                Nodo *reco = head;
                while (reco->getNext() != NULL)
                {
                    reco = reco->getNext();
                }
                reco->setNext(nuevo);
                nuevo->setPrevious(reco);
                nuevo->setNext(nullptr);
            }
            else
            {
                Nodo *reco = head;
                for (int f = 1; f <= pos - 2; f++)
                    reco = reco->getNext();
                Nodo *siguiente = reco = reco->getNext();
                reco->setNext(nuevo);
                nuevo->setPrevious(reco);
                nuevo->setNext(siguiente);
                siguiente->setPrevious(nuevo);
            }
    }
    size++;
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
    Object* retval = temp->getData();;
    while(temp != nullptr){
        if(typeid(*retval)==typeid(Alumno)){
            Alumno* alumno = dynamic_cast<Alumno*>(retval);
            if(cuenta.compare(alumno->getCuenta()) == 0)
                retval = temp->getData();
        }
        temp = temp->getNext();
    }
    return retval;
}

//1.4 Borrar un elemento por posición
Object* LinkedList::borrar(int pos){
    Nodo* temp = head;
    Object* retval = temp->getData();
    if(pos >= 1 && pos <= size){
        if(pos == 1){
            head = temp->getNext();
            temp->setNext(nullptr);
            //validar inicio/head != null
            head->setPrevious(nullptr);
        }
    }
    size--;
    return retval;
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
