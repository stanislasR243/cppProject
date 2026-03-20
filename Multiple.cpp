#include "Multiple.h"
#include "Gregaire.h"
#include "Kamikaze.h"
#include "Peureuse.h"
#include "IBestiole.h"
#include <cstdlib>

Multiple::Multiple() {
    listeComportements.push_back(new Gregaire());
    listeComportements.push_back(new Kamikaze());
    listeComportements.push_back(new Peureuse());
    
    comportementCourant = listeComportements[rand() % listeComportements.size()];
    probaChangement = 0.02;
}

Multiple::~Multiple() {
    for (auto c : listeComportements) delete c;
}

void Multiple::execute(IBestiole& b, Milieu& m) {
    if ((static_cast<double>(rand()) / RAND_MAX) < probaChangement) {
        comportementCourant = listeComportements[rand() % listeComportements.size()];
    }

    if (comportementCourant) {
        // La sous-stratégie (Gregaire, etc.) appellera b.bouge()
        comportementCourant->execute(b, m);
    }
}