#include "Yeux.h"
#include <cmath>
#include <algorithm>

Yeux::Yeux(IBestiole* b, double d, double a, double g)
    : Decorator(b), distance(d), angle(a), capacite(g) {}

bool Yeux::jeTeVois(const IBestiole& autre) const {

    // 1️⃣ Distance entre les deux bestioles
    double dx = autre.getX() - bestiole->getX();
    double dy = autre.getY() - bestiole->getY();

    double dist = sqrt(dx * dx + dy * dy);

    if (dist > distance)
        return Decorator::jeTeVois(autre);

    // 2️⃣ Calcul de l'angle
    double orientation = bestiole->getOrientation();

    double vx = cos(orientation);
    double vy = sin(orientation);

    double normV = sqrt(vx * vx + vy * vy);
    double normD = dist;

    if (normD == 0)
        return false;

    double dot = vx * dx + vy * dy;
    double cosAngle = dot / (normV * normD);

    // Sécurité pour acos
    cosAngle = std::max(-1.0, std::min(1.0, cosAngle));

    double angleEntre = acos(cosAngle);

    // 3️⃣ Vérifier champ de vision
    if (angleEntre > angle / 2.0)
        return Decorator::jeTeVois(autre);

    // 4️⃣ Vérifier détection vs camouflage
    if (capacite > autre.getCoeffCamouflage())
        return true;

    // Sinon on laisse les autres capteurs décider
    return Decorator::jeTeVois(autre);
}
