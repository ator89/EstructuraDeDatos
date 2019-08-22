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
    capacity = 1024;
    array = new Object*[capacity];
    size = 0;
    posBusqueda = 0;
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

//Retornar el tamaño de la lista
int ArrayList::getSize(){
    return size;
}

//Retornar la posición en la búsqueda
int ArrayList::getPosBusqueda(){
    return posBusqueda;
}

//1.1 Insertar en posición n
void ArrayList::insertar(Object* data, int pos){
    size++;
    pos--;
    if(size==capacity){//revisar si hay capacidad para el elemento
        resize();
    }
    //insertar al inicio
    if(pos == 0){
        //hacer corrimiento
        for(int i = size; i>0; i--){
            array[i] = array[i-1];
        }
        array[0] = data;
    }
    //insertar al final
    else if(pos == size-1){
        array[size-1] = data;
    }
    else{
        //hacer corrimiento
        for(int i = size-1; i>=pos; i--)
            array[i+1] = array[i];
        array[pos] = data;
    }
    
}

//1.2 Imprimir valores de la lista
void ArrayList::imprimir(){
    //for(int i=size-1; i>=0;i--){
    int i = 0;
    int pos = 1;
    while(i != size){
        std::cout << pos <<" - " <<array[i]->toString() + "\n";
        i++;
        pos++;
    }
}

//1.3 
Object* ArrayList::buscar(std::string data){
    Object* retval =0;
    
    return retval;
}

//1.4 Eliminar elemento
Object* ArrayList::borrar(int pos){
    pos--;
    //Borrar del final
    if(pos == size-1){
        Object* retval = array[pos];
        array[size-1]=NULL;
        size--;
        return retval;
    }
    //borrar de posición n
    else{
        Object* retval = array[pos];
        for(int i=pos; i < size-1; i++){
            array[i] = array[i+1];
        }
        size--;
        return retval;
    }
    
}

//1.5 Verificar si no está vacía
bool ArrayList::isEmpty(){
    return size == 0;
}

//1.6 Retonar el valor que está en la posición
Object* ArrayList::posicion(int pos){
    pos--;
    Object* retval = array[pos];
    return retval;
}

//1.7 Retornar valor siguiente
Object* ArrayList::siguiente(int pos){
    pos--;
    Object* retval = array[pos+1];
    return retval;
}

//1.8 Retornar valor anterior
Object* ArrayList::anterior(int pos){
    pos--;
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
