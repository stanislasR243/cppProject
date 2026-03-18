#ifndef CAMOUFLAGE_H
#define CAMOUFLAGE_H

#include "Decorator.h"

class Camouflage : public Decorator {
private:
    double coeffCamouflage; // ψ : 0 = pas de camouflage, 1 = camouflage parfait

public:
    Camouflage(IBestiole* b, double psi);
    virtual ~Camouflage() {}

    // On surcharge uniquement le coeff de camouflage
    double getCoeffCamouflage() const override;

    // Les autres méthodes restent déléguées
    void action(Milieu& m) override { bestiole->action(m); }
    void draw(UImg& img) override { bestiole->draw(img); }
};

#endif
