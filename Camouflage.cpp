#include "Camouflage.h"

Camouflage::Camouflage(IBestiole* b, double psi)
    : Decorator(b), coeffCamouflage(psi) {}

// Surcharge du coefficient de camouflage
double Camouflage::getCoeffCamouflage() const {
    return coeffCamouflage;
}
