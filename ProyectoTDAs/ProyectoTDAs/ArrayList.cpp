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

//1.1 Insertar en posición n
void ArrayList::insertar(Object* data, int pos){
    if(size==capacity){//revisar si hay capacidad para el elemento
        resize();
    }
    //insertar al inicio
    if(pos == 1){
        for(int i = size;i>0;i--){
            array[i]=array[i-1];
        }
        array[0] = data;
    }
    //insertar al final
    else if(pos == size){
        array[size]=data;
    }
    else{
        for(int i = size-1; i>=pos;i--)
            array[i+1] = array[i];
        array[pos] = data;
    }
    
    size++;
}

//1.2 Imprimir valores de la lista
void ArrayList::imprimir(){
    for(int i=size-1; i>=0;i--){
        std::cout << i <<" - " <<array[i]->toString() + "\n";
    }
}

//1.3 
Object* ArrayList::buscar(std::string data){
    Object* retval;
    return retval;
}

//1.4
Object* ArrayList::borrar(int pos){
    Object* retval;
    return retval;
}

//1.5 Verificar si no está vacía
bool ArrayList::isEmpty(){
    return size == 0;
    //si no está vacía, imprimir elementos
}

//1.6
Object* ArrayList::posicion(int pos){
    Object* retval = array[pos];
    return retval;
}

//1.7
Object* ArrayList::siguiente(int pos){
    Object* retval = array[pos+1];
    return retval;
}

//1.8
Object* ArrayList::anterior(int pos){
    Object* retval = array[pos-1];
    return retval;
}



//1.9 Vaciar la lista
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

int ArrayList::getSize(){
    return size;
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
