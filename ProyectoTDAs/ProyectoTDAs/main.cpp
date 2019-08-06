//
//  main.cpp
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//

#include <iostream>
#include "Object.h"
#include "TDALista.h"
#include "LinkedList.h"
#include "Alumno.h"
#include "Simbolo.h"

#include <fstream>
using std::ofstream;
using std::ifstream;

int main(int argc, const char * argv[]) {
    
    TDALista* listaEnlazada = new LinkedList();
    listaEnlazada->insertar(new Simbolo('$'), 1);
    listaEnlazada->insertar(new Simbolo('&'), 1);
    listaEnlazada->insertar(new Simbolo('('), 1);
    listaEnlazada->insertar(new Alumno("nombre","cuenta"), 1);
    
    //std::cout << listaEnlazada->toString();
    listaEnlazada->imprimir();
    std::cout << std::endl;
    
    //Object* tmp = listaEnlazada->top();
    //std::cout << tmp->toString();
    
    delete listaEnlazada;
    return 0;
}

