#include "Carapace.h"

Carapace::Carapace(IBestiole* b, double protection, double vitesse)
    : Decorator(b), protectionCoeff(protection), vitesseCoeff(vitesse) {}

// La protection : probabilité de mourir réduite
double Carapace::getProtection() const {
    return bestiole->getProtection() * protectionCoeff;
}

// La vitesse : réduite par un facteur η
double Carapace::getVitesse() const {
    return bestiole->getVitesse() / vitesseCoeff; // facteur η > 1 ralentit
}
