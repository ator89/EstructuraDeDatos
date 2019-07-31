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


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TDALista* listaEnlazada = new LinkedList();
    listaEnlazada->insertar(new Simbolo('$'), 1);
    
    
    return 0;
}
