#include "Yeux.h"
#include "Bestiole.h" // Pour accéder aux coordonnées de base
#include <cmath>

Yeux::Yeux(IBestiole* b, double d, double a, double g) : Decorator(b), distance(d), angle(a), capacite(g) {}

bool Yeux::jeTeVois(const IBestiole& b) const {
    // 1. Calculer la distance entre les deux bestioles (Pythagore)
    // 2. Calculer l'angle entre les deux bestioles (atan2)
    // 3. Vérifier si c'est dans le champ de vision
    
    // Si c'est vu par les yeux :
    // return true;

    // Sinon, on demande au reste de la "pile" de décorateurs
    return Decorator::jeTeVois(b);
}

