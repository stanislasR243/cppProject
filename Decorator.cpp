#include "Decorator.h"

Decorator::Decorator(IBestiole* b) : bestiole(b) {}

Decorator::~Decorator() {
    delete bestiole; // Détruit récursivement toute la pile (ex: Yeux -> Carapace -> Bestiole)
}

// --- AJOUTS RÉCENTS (Manquants dans ton erreur de compilation) ---

void Decorator::initCoords(int xLim, int yLim) {
    bestiole->initCoords(xLim, yLim);
}

void Decorator::setOrientation(double a) {
    bestiole->setOrientation(a);
}

void Decorator::setVitesse(double v) {
    bestiole->setVitesse(v);
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

// --- Délégation des getters ---

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