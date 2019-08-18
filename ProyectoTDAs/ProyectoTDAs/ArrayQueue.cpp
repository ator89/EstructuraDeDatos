//
//  ArrayQueue.cpp
//  ProyectoTDAs
//


#include "ArrayQueue.h"

//Constructor
ArrayQueue::ArrayQueue()
{
    capacity=1024;
    array=new Object*[capacity];
    size=0;
}

ArrayQueue::~ArrayQueue()
{
    //liberar memoria de los objetos que están en la cola
    for(int i =0;i<size;i++){
        if(array[i]!=NULL){//validar
            delete array[i];
            array[i]=NULL;
        }
    }
    delete[] array;
}

/*retorna si la cola está vacía*/
bool ArrayQueue::isEmpty(){
    return size==0;
}

/*aumenta la capacidad del arreglo*/
void ArrayQueue::resize(){
    int newCapacity=capacity*2;//aumentar capacidad
    Object** newArray=new Object*[newCapacity];//crear nuevo arreglo
    for(int  i = 0; i<size;i++){
        newArray[i]=array[i];
        array[i]=NULL;
    }
    delete[] array;//liberar espacio
    array=newArray;
    capacity=newCapacity;
}

/*pone el parámetro en la cola, al inicio del arreglo*/
void ArrayQueue::queue(Object* data){
    //revisar que hay espacio para insertar
    if(size==capacity){
        resize();//si no hay, expandir el arreglo
    }
    
    //hacer corrimientos para insertar en la casilla 0
    for(int i = size;i>0;i--){
        array[i]=array[i-1];
    }
    
    //insertar
    array[0]=data;
    //incrementar size
    size++;
}

/*retorna el objeto en el frente de la cola*/
Object* ArrayQueue::front(){
    if(size!=0)
        return array[size-1];
    else
        return NULL;
}

/*saca el objeto del frente de la cola*/
Object* ArrayQueue::deQueue(){
    if(size>0){
        Object* tmp=array[size-1];
        array[size-1]=NULL;
        size--;
        return tmp;
    }else
        return NULL;
}
/*borra los elementos de la cola*/
void ArrayQueue::clear(){
    for(int i =0;i<size;i++){
        if(array[i]!=NULL){//validar
            delete array[i];
            array[i]=NULL;
        }
    }
    size=0;
}

//Métodos polimórficos heredados de Object
std::string ArrayQueue::toString(){
    std::string s;
    for(int i=size-1; i>=0;i--){
        s += array[i]->toString() + "\n";
    }
    return s;
}

bool ArrayQueue::equals(Object*){
    return false;
}
