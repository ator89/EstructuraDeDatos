//
//  Alumno.hpp
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//

#ifndef ALUMNO_H
#define ALUMNO_H
#include <string>
#include "Object.h"

class Alumno:public Object{
private:
    std::string nombre;
    std::string cuenta;
public:
    //Constructores y destructor
    Alumno();
    Alumno(std::string,std::string);
    ~Alumno();
    
    //Accesores
    std::string getCuenta();
    std::string getNombre();
    
    //Mutadores
    void setCuenta(std::string);
    void setNombre(std::string);
    
    //métodos polimórficos
    virtual std::string toString();
    virtual bool equals(Object*);
};

#endif
