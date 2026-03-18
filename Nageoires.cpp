#include "Nageoires.h"

Nageoires::Nageoires(IBestiole* b, double coeff)
    : Decorator(b), coefficient(coeff) {}

// On surcharge la vitesse : vitesse originale * coefficient
double Nageoires::getVitesse() const {
    return bestiole->getVitesse() * coefficient;
}
