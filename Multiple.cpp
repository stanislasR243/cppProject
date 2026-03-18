#include "Multiple.h"
#include "Gregaire.h"
#include "Kamikaze.h"
#include "Peureuse.h"
#include "IBestiole.h"
#include <cstdlib> // Pour rand()

Multiple::Multiple() {
    // 1. On initialise la liste des personnalités possibles
    listeComportements.push_back(new Gregaire());
    listeComportements.push_back(new Kamikaze());
    listeComportements.push_back(new Peureuse());

    // 2. On commence avec un comportement au hasard
    int indiceInitial = rand() % listeComportements.size();
    comportementCourant = listeComportements[indiceInitial];

    probaChangement = 0.02; // 2% de chance de changer à chaque appel de execute
}

Multiple::~Multiple() {
    // On libère la mémoire de tous les comportements stockés
    for (auto c : listeComportements) {
        delete c;
    }
}

void Multiple::execute(IBestiole& b, Milieu& m) {
    // 1. Test de probabilité pour le changement de personnalité
    double tirage = static_cast<double>(rand()) / RAND_MAX;
    
    if (tirage < probaChangement) {
        int nouvelIndice = rand() % listeComportements.size();
        comportementCourant = listeComportements[nouvelIndice];
    }

    // 2. On délègue l'exécution au comportement actuellement actif
    if (comportementCourant) {
        comportementCourant->execute(b, m);
    }
}
