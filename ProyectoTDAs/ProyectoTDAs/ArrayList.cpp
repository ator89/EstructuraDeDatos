//
//  ArrayList.cpp
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//

#include "ArrayList.h"
#include <iostream>

//Constructor
ArrayList::ArrayList(){
    capacity=1024;
    array=new Object*[capacity];
    size=0;
}

//Destructor
ArrayList::~ArrayList()
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

//Insertar en posición n
void ArrayList::insertar(Object* data, int pos){
    if(size==capacity){//revisar si hay capacidad para el elemento
        resize();
    }
    for(int i = size-1; i>=pos; i--)
        array[i+1] = array[i];
    array[pos] = data;
    size++;
}

//Imprimir valores de la lista
void ArrayList::imprimir(){
    for(int i=size-1; i>=0;i--){
        std::cout << array[i]->toString() + "\n";
    }
}

Object* ArrayList::buscar(Object* data){
    Object* retval;
    return retval;
}

Object* ArrayList::borrar(int pos){
    Object* retval;
    return retval;
}

Object* ArrayList::posicion(int pos){
    Object* retval;
    return retval;
}

Object* ArrayList::anterior(int pos){
    Object* retval;
    return retval;
}

Object* ArrayList::siguiente(int pos){
    Object* retval;
    return retval;
}

//Verificar si no está vacía
bool ArrayList::isEmpty(){
    return size == 0;
    //si no está vacía, imprimir elementos
}

//Vaciar la lista
void ArrayList::vaciar(){
    //liberar memoria de los objetos que están en la lista
    for(int i = 0; i < size; i++){
        if(array[i] != NULL){//validar
            delete array[i];
            array[i] = NULL;
        }
    }
    size = 0;
}


/*aumenta la capacidad del arreglo*/
void ArrayList::resize(){
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

//Métodos polimórficos heredados de Object
std::string ArrayList::toString(){
    std::string s;
    for(int i=size-1; i>=0;i--){
        s += array[i]->toString() + "\n";
    }
    return s;
}

bool ArrayList::equals(Object*){
    return false;
}
