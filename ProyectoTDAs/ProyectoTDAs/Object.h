//
//  Object.hpp
//  ProyectoTDAs
//
//  Created by Angel Torres on 7/30/19.
//  Copyright © 2019 Angel Torres. All rights reserved.
//

#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object{
public:
    virtual ~Object();
    
    virtual std::string toString() = 0;
    virtual bool equals(Object*) = 0;
};
#endif
