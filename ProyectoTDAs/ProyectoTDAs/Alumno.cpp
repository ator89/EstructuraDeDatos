//
//  Alumno.cpp
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//

#include "Alumno.h"

//Constructores y destructor
Alumno::Alumno(){
    cuenta = "";
    nombre = "";
}

Alumno::Alumno(std::string cuenta,std::string nombre){
    this->cuenta = cuenta;
    this->nombre = nombre;
}

Alumno::~Alumno(){}

//Accesores
std::string Alumno::getCuenta(){
    return cuenta;
}
std::string Alumno::getNombre(){
    return nombre;
}

//Mutadores
void Alumno::setCuenta(std::string cuenta){
    this->cuenta = cuenta;
}
void Alumno::setNombre(std::string nombre){
    this->nombre = nombre;
}

//métodos polimórficos
std::string Alumno::toString(){
    return "";
}

bool Alumno::equals(Object* info){
    return false;
}
