#ifndef CARAPACE_H
#define CARAPACE_H

#include "Decorator.h"

class Carapace : public Decorator {
private:
    double protectionCoeff; // ω : réduit la probabilité de mourir
    double vitesseCoeff;    // η : réduit la vitesse

public:
    Carapace(IBestiole* b, double protection, double vitesse);
    virtual ~Carapace() {}

    // On surcharge la protection
    double getProtection() const override;

    // On surcharge la vitesse
    double getVitesse() const override;

    // Les autres méthodes restent déléguées
    void action(Milieu& m) override { bestiole->action(m); }
    void draw(UImg& img) override { bestiole->draw(img); }
};

#endif
