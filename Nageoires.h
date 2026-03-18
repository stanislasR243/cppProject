#ifndef NAGEOIRES_H
#define NAGEOIRES_H

#include "Decorator.h"

class Nageoires : public Decorator {
private:
    double coefficient; // ν : multiplicateur de vitesse

public:
    Nageoires(IBestiole* b, double coeff);
    virtual ~Nageoires() {}

    // Surcharge de la vitesse
    double getVitesse() const override;

    // On délègue tout le reste
    void action(Milieu& m) override { bestiole->action(m); }
    void draw(UImg& img) override { bestiole->draw(img); }
};

#endif
