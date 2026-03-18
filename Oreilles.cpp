#include "Oreilles.h"
#include <cmath>

Oreilles::Oreilles(IBestiole* b, double d, double g)
    : Decorator(b), distance(d), capacite(g) {}

bool Oreilles::jeTeVois(const IBestiole& autre) const {

    // 1️⃣ Distance entre les bestioles
    double dx = autre.getX() - bestiole->getX();
    double dy = autre.getY() - bestiole->getY();

    double dist = sqrt(dx * dx + dy * dy);

    // 2️⃣ Test distance
    if (dist > distance)
        return Decorator::jeTeVois(autre);

    // 3️⃣ Test détection vs camouflage
    if (capacite > autre.getCoeffCamouflage())
        return true;

    // Sinon on laisse les autres capteurs décider
    return Decorator::jeTeVois(autre);
}
