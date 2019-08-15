//
//  ArrayList.cpp
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//

#include "ArrayList.h"

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
