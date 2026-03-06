#ifndef DECORATOR_H
#define DECORATOR_H

#include "IBestiole.h"

class Decorator : public IBestiole {
protected:
    IBestiole* bestiole; // La bestiole "emballée"

public:
    Decorator(IBestiole* b);
    virtual ~Decorator();

    // Méthodes de base (délégation simple)
    void action(Milieu& m) override { bestiole->action(m); }
    void draw(UImg& img) override { bestiole->draw(img); }
    bool jeTeVois(const IBestiole& b) const override { return bestiole->jeTeVois(b); }

    // Getters de position et identité (délégation)
    double getX() const override { return bestiole->getX(); }
    double getY() const override { return bestiole->getY(); }
    double getOrientation() const override { return bestiole->getOrientation(); }
    int getIdentite() const override { return bestiole->getIdentite(); }

    // Caractéristiques physiques (délégation)
    double getVitesse() const override { return bestiole->getVitesse(); }
    double getProtection() const override { return bestiole->getProtection(); }
    double getCoeffCamouflage() const override { return bestiole->getCoeffCamouflage(); }

    // État de santé
    bool estMorte() const override { return bestiole->estMorte(); }
};

#endif
