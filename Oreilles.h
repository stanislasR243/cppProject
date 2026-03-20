#ifndef OREILLES_H
#define OREILLES_H

#include "Gadget.h"
#include "IBestiole.h"
#include "UImg.h"

class Oreilles : public Gadget {
private:
    double distance;   // δo : distance de perception
    double capacite;   // γo : capacité de détection

public:
    Oreilles(double d, double g)
        : distance(d), capacite(g) { name = "Oreilles"; }

    virtual ~Oreilles() = default;

    // Appliquer l'effet sur la bestiole
    void apply(IBestiole* b) override {
        // Par exemple : b->setOreilles(distance, capacite);
    }

    // Dessiner le gadget (optionnel pour les oreilles)
    void draw(UImg* img, IBestiole* b) override {
        // Exemple : petit cercle bleu autour de la bestiole
        // int x = static_cast<int>(b->getX());
        // int y = static_cast<int>(b->getY());
        // img->draw_circle(x, y, static_cast<int>(distance), 0, 0, 255);
    }

    // Clonage pour avoir une copie indépendante
    std::unique_ptr<Gadget> clone() const override {
        return std::make_unique<Oreilles>(distance, capacite);
    }

    // Méthode spécifique pour la détection sonore
    bool jeTeVois(const IBestiole& autre) const {
        double dx = autre.getX() - 0; // remplacer par la position de la bestiole équipée
        double dy = autre.getY() - 0;
        double dist = std::sqrt(dx*dx + dy*dy);
        return dist <= distance;
    }
};

#endif
