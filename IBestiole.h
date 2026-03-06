#ifndef IBESTIOLE_H
#define IBESTIOLE_H

#include "UImg.h"
#include <iostream>
#include <vector>

class Milieu;

class IBestiole 
    {
    public:
    virtual void action(Milieu&)=0;
    virtual void draw(UImg&)=0;
    virtual bool jeTeVois(const IBestiole&) const =0;
    virtual ~IBestiole() {};
};
#endif