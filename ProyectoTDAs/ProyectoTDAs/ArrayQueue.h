//
//  ArrayQueue.hpp
//  ProyectoTDAs
//


#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "TDACola.h"

class ArrayQueue:public TDACola{
private:
    Object** array;//arreglo de apuntadores a object
    int capacity;//tamaño del arreglo
    int size;//cantidad de elementos en la cola
    void resize();/*aumenta la capacidad del arreglo*/
public:
    ArrayQueue();
    ~ArrayQueue();
    
    //insertar en la cola
    virtual void queue(Object*);
    //ver tope de la cola
    virtual Object* front();
    //sacar elemento de la cola
    virtual Object* deQueue();
    //ver si esta vacia
    virtual bool isEmpty();
    //eliminar elementos de la cola
    virtual void clear();
    
    //Métodos polimórficos heredados de Object
    virtual std::string toString();
    virtual bool equals(Object*);
};

#endif
