#ifndef YEUX_H
#define YEUX_H

#include "Gadget.h"
#include "IBestiole.h"
#include "UImg.h"
#include <cmath>

class Yeux : public Gadget {
private:
    double distance;   // δy (distance max)
    double angle;      // α (angle de vision en radians)
    double capacite;   // γ (capacité de détection)

public:
    Yeux(double d, double a, double g)
        : distance(d), angle(a), capacite(g) { name = "Yeux"; }

    virtual ~Yeux() = default;

    // Appliquer l'effet sur la bestiole (ici on pourrait stocker les valeurs dans IBestiole)
    void apply(IBestiole* b) override {
        // b->setVision(distance, angle, capacite); // optionnel si IBestiole gère la vision
    }

    // Dessiner le gadget sur la bestiole
    void draw(UImg* img, IBestiole* b) override {
        // Exemple : un cercle vert représentant le champ de vision
        // img->draw_circle(b->getX(), b->getY(), distance, 0, 255, 0);
    }

    // Clonage : pour avoir une copie indépendante du gadget
    std::unique_ptr<Gadget> clone() const override {
        return std::make_unique<Yeux>(distance, angle, capacite);
    }

    // Méthode spécifique pour la détection visuelle
    bool jeTeVois(const IBestiole& autre) const {
        // Calcul simple de distance et angle
        double dx = autre.getX() - 0; // Remplacer 0 par b->getX() si besoin
        double dy = autre.getY() - 0; // idem
        double dist = std::sqrt(dx*dx + dy*dy);
        if(dist > distance) return false;

        // Calcul de l'angle relatif
        double theta = std::atan2(dy, dx);
        // Ici tu peux comparer avec l'orientation de la bestiole si nécessaire

        return true; // placeholder : logique complète à implémenter plus tard
    }
};

#endif
