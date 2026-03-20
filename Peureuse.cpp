#include "Peureuse.h"
#include "IBestiole.h"
#include "Milieu.h"
#include <vector>
#include <cmath>

void Peureuse::execute(IBestiole& b, Milieu& m) {
    std::vector<IBestiole*> voisins = m.getVoisins(b);
    int nbVoisinsVus = 0;

    for (IBestiole* v : voisins) {
        if (b.getIdentite() != v->getIdentite() && b.jeTeVois(*v)) {
            nbVoisinsVus++;
        }
    }

    if (nbVoisinsVus >= 3) { // Seuil arbitraire de 3
        // Demi-tour
        b.setOrientation(b.getOrientation() + M_PI);
        // On booste la vitesse (vitesse max limitée par setVitesse dans Bestiole)
        b.setVitesse(b.getVitesse() * 2.0);
    } 

    // MISE À JOUR PHYSIQUE
    b.bouge(m.getWidth(), m.getHeight());
}