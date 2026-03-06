#ifndef IBESTIOLE_H
#define IBESTIOLE_H

#include "UImg.h"
#include <iostream>
#include <vector>

class Milieu;

class IBestiole {
public:
    virtual void action(Milieu& m) = 0;
    virtual void draw(UImg& img) = 0;
    virtual bool jeTeVois(const IBestiole& b) const = 0;
    
    // Ajouts pour les accessoires
    virtual double getVitesse() const = 0;
    virtual double getProtection() const = 0;
    virtual double getCoeffCamouflage() const = 0; // Pour le camouflage
    
    virtual ~IBestiole() {}
};
#endif
