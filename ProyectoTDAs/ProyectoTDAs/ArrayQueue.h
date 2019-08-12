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
    virtual void queue(Object*)=0;
    //ver tope de la cola
    virtual Object* front()=0;
    //sacar elemento de la cola
    virtual Object* deQueue()=0;
    //ver si esta vacia
    virtual bool isEmpty()=0;
    //eliminar elementos de la cola
    virtual void clear()=0;
    
    //Métodos polimórficos heredados de Object
    std::string toString() = 0;
    bool equals(Object*) = 0;
};

#endif
