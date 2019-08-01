//
//  Simbolo.cpp
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//

#include "Simbolo.h"

//Constructores y Destructor
Simbolo::Simbolo(){
    simbolo = ' ';
}

Simbolo::Simbolo(char simbolo){
    this->simbolo = simbolo;
}

Simbolo::~Simbolo(){}

//Accesor
char Simbolo::getSimbolo(){
    return simbolo;
}

//Mutador
void Simbolo::setSimbolo(char simbolo){
    this->simbolo = simbolo;
}

//Métodos polimórficos
std::string Simbolo::toString(){
    std::string s;
    s.push_back(simbolo);
    return s;
}
bool Simbolo::equals(Object* info){
    return false;
}
