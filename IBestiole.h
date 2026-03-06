#ifndef IBESTIOLE_H
#define IBESTIOLE_H

#include "UImg.h"
#include <iostream>

class Milieu;

class IBestiole {
public:
    virtual ~IBestiole() {}

    // Logique de simulation
    virtual void action(Milieu& m) = 0;
    virtual void draw(UImg& img) = 0;
    virtual bool jeTeVois(const IBestiole& b) const = 0;

    // Getters de base (indispensables pour les capteurs)
    virtual double getX() const = 0;
    virtual double getY() const = 0;
    virtual double getOrientation() const = 0;
    virtual int getIdentite() const = 0; // Pour distinguer les individus
    
    // Caractéristiques physiques (modifiables par Decorator)
    virtual double getVitesse() const = 0;
    virtual double getProtection() const = 0;
    virtual double getCoeffCamouflage() const = 0;
    
    // État de santé
    virtual bool estMorte() const = 0; 
};

#endif
