//
//  Object.hpp
//  ProyectoTDAs
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
