//
//  ArrayStack.cpp
//  ProyectoTDAs
//


#include "ArrayStack.h"

//constructor
ArrayStack::ArrayStack(){
    size=0;
    capacity=1024;
    array=new Object*[capacity];
    
}

//destructor
ArrayStack::~ArrayStack(){
    //liberar memoria de los objetos que están en la pila
    for(int i =0;i<size;i++){
        if(array[i]!=NULL){//validar
            delete array[i];
            array[i]=NULL;
        }
    }
    delete[] array;
}
//borra los elementos de la pila
void ArrayStack::anula(){
    //liberar memoria de los objetos que están en la pila
    for(int i =0;i<size;i++){
        if(array[i]!=NULL){//validar
            delete array[i];
            array[i]=NULL;
        }
    }
    size=0;
}


//aumenta la capacidad del arreglo
void ArrayStack::resize(){
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

//inserta un elemento en la pila
void ArrayStack::push(Object* data){
    if(size==capacity){//revisar si hay capacidad para el elemento
        resize();
    }
    array[size]=data;
    size++;
}

//saca el elemento del tope de la pila
Object* ArrayStack::pop(){
    if(size==0)
        return NULL;
    else{
        Object* tmp=array[size-1];
        array[size-1]=NULL;
        size--;
        return tmp;
    }
}


//retorna el elemento en el tope de la pila
Object* ArrayStack::top(){
    if(size==0)
        return NULL;
    else
        return array[size-1];
}

/*retorna si la cola está vacía*/
bool ArrayStack::isEmpty(){
    return size==0;
}


//Métodos polimórficos heredados de Object
std::string ArrayStack::toString(){
    std::string s;
    for(int i=size-1; i>=0;i--){
        s += array[i]->toString();
    }
    return s;
}

bool ArrayStack::equals(Object*){
    return false;
}
