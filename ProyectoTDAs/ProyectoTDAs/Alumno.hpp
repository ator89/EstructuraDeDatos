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
    //Constructores
    Alumno();
    Alumno(std::string,std::string);
    ~Alumno();
    
};

#endif
