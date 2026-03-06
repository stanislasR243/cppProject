#ifndef YEUX_H
#define YEUX_H

#include "Decorator.h"

class Yeux : public Decorator {
private:
    double distance; // delta_y
    double angle;    // alpha
    double capacite; // gamma
public:
    Yeux(IBestiole* b, double d, double a, double g);
    virtual ~Yeux() {}

    // On surcharge uniquement ce qui change
    bool jeTeVois(const IBestiole& b) const override;
    void draw(UImg& img) override;
};

#endif
