#ifndef CARAPACE_H
#define CARAPACE_H

#include "Gadget.h"
#include "IBestiole.h"
#include "UImg.h"

class Carapace : public Gadget {
private:
    double protectionCoeff; // ω : réduit la probabilité de mourir
    double vitesseCoeff;    // η : réduit la vitesse

public:
    Carapace(double protection, double vitesse)
        : protectionCoeff(protection), vitesseCoeff(vitesse) {
        name = "Carapace";
    }

    virtual ~Carapace() = default;

    // Appliquer l'effet sur la bestiole
    void apply(IBestiole* b) override {
        // Ex: b->setProtection(b->getProtection() * protectionCoeff);
        //     b->setVitesse(b->getVitesse() / vitesseCoeff);
    }

    // Dessiner la carapace sur l'image
    void draw(UImg* img, IBestiole* b) override {
        // Par exemple : un cercle ou contour pour montrer la carapace
        // int x = static_cast<int>(b->getX());
        // int y = static_cast<int>(b->getY());
        // img->draw_circle(x, y, 10, 255, 0, 0); // rouge pour la carapace
    }

    // Clonage pour copies indépendantes
    std::unique_ptr<Gadget> clone() const override {
        return std::make_unique<Carapace>(protectionCoeff, vitesseCoeff);
    }
};

#endif
