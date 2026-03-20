#ifndef IBESTIOLE_H
#define IBESTIOLE_H

#include "UImg.h"
#include <iostream>
#include <vector>
#include <memory>
class Gadget; // Forward declaration
class Milieu;

class IBestiole {
public:
    virtual ~IBestiole() {}
    
    virtual void initCoords(int xLim, int yLim) = 0; // À ajouter

    virtual void bouge(int xLim, int yLim) = 0;
    // Logique de simulation
    virtual void action(Milieu& m) = 0;
    virtual void draw(UImg& img) = 0;
    // Pour que le comportement puisse diriger la bestiole
    virtual void setOrientation(double a) = 0;
    virtual void setVitesse(double v) = 0;
    virtual bool jeTeVois(const IBestiole& b) const = 0;

    // Getters de base (indispensables pour les capteurs)
    virtual double getX() const = 0;
    virtual double getY() const = 0;
    virtual double getOrientation() const = 0;
    virtual int getIdentite() const = 0; // Pour distinguer les individus

    virtual void addGadget(std::unique_ptr<Gadget> g) = 0;
    virtual void applyGadgets() = 0;
    virtual void drawGadgets(UImg& img) = 0;
    
    // Caractéristiques physiques (modifiables par Decorator)
    virtual double getVitesse() const = 0;
    virtual double getProtection() const = 0;
    virtual double getCoeffCamouflage() const = 0;
    
    // État de santé
    virtual bool estMorte() const = 0; 
};

#endif
