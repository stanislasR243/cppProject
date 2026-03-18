#ifndef YEUX_H
#define YEUX_H

#include "Decorator.h"
#include <cmath>

class Yeux : public Decorator {
private:
    double distance; // δy (distance max)
    double angle;    // α (angle de vision en radians)
    double capacite; // γ (capacité de détection)

public:
    Yeux(IBestiole* b, double d, double a, double g);
    virtual ~Yeux() {}

    // Détection visuelle
    bool jeTeVois(const IBestiole& autre) const override;

};

#endif
