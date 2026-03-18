#include "Nageoire.h"

Nageoire::Nageoire(IBestiole* b, double coeff)
    : Decorator(b), coefficient(coeff) {}

// On surcharge la vitesse : vitesse originale * coefficient
double Nageoire::getVitesse() const {
    return bestiole->getVitesse() * coefficient;
}
