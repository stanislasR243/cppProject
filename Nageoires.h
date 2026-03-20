#ifndef NAGEOIRES_H
#define NAGEOIRES_H

#include "Gadget.h"
#include "IBestiole.h"
#include "UImg.h"

class Nageoires : public Gadget {
private:
    double coefficient; // ν : multiplicateur de vitesse

public:
    Nageoires(double coeff)
        : coefficient(coeff) {
        name = "Nageoires";
    }

    virtual ~Nageoires() = default;

    // Appliquer l'effet sur la bestiole
    void apply(IBestiole* b) override {
        // Par exemple : b->setVitesse(b->getVitesse() * coefficient);
    }

    // Dessiner les nageoires sur l'image (optionnel)
    void draw(UImg* img, IBestiole* b) override {
        // Exemple : un petit triangle ou ligne bleue derrière la bestiole
        // int x = static_cast<int>(b->getX());
        // int y = static_cast<int>(b->getY());
        // img->draw_line(x, y, x+5, y-5, 0, 0, 255);
    }

    // Clonage pour copier indépendamment
    std::unique_ptr<Gadget> clone() const override {
        return std::make_unique<Nageoires>(coefficient);
    }
};

#endif
