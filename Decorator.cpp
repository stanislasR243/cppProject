#include "Decorator.h"

Decorator::Decorator(IBestiole* b) : bestiole(b) {}

Decorator::~Decorator() {
    delete bestiole; // Très important : détruit toute la pile d'accessoires
}

// --- Délégation des actions de base ---

void Decorator::action(Milieu& m) {
    bestiole->action(m);
}

void Decorator::draw(UImg& img) {
    bestiole->draw(img);
}

bool Decorator::jeTeVois(const IBestiole& b) const {
    return bestiole->jeTeVois(b);
}

// --- Délégation des getters de position et identité ---

double Decorator::getX() const {
    return bestiole->getX();
}

double Decorator::getY() const {
    return bestiole->getY();
}

double Decorator::getOrientation() const {
    return bestiole->getOrientation();
}

int Decorator::getIdentite() const {
    return bestiole->getIdentite();
}

// --- Délégation des caractéristiques physiques ---

double Decorator::getVitesse() const {
    return bestiole->getVitesse();
}

double Decorator::getProtection() const {
    return bestiole->getProtection();
}

double Decorator::getCoeffCamouflage() const {
    return bestiole->getCoeffCamouflage();
}

// --- État de santé ---

bool Decorator::estMorte() const {
    return bestiole->estMorte();
}
