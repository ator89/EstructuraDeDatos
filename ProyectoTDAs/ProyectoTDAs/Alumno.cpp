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

//Constructor sobrecargado
Alumno::Alumno(std::string cuenta,std::string nombre){
    this->cuenta = cuenta;
    this->nombre = nombre;
}

//Destructor
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
    std::string s;
    std::stringstream ss;
    ss << nombre << cuenta;
    ss >> s ;
    return s;
}

bool Alumno::equals(Object* obj){
    if(obj == NULL)
        return false;
    else if(typeid(*obj)==typeid(Alumno)){
        Alumno* temp = dynamic_cast<Alumno*>(obj);
        return temp->getNombre() == nombre;
    }else{
        return false;
    }
}
