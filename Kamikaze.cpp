#include "Kamikaze.h"
#include "IBestiole.h"
#include "Milieu.h"
#include <vector>
#include <cmath>
#include <limits>

void Kamikaze::execute(IBestiole& b, Milieu& m) {
    std::vector<IBestiole*> voisins = m.getVoisins(b);
    IBestiole* cibleProche = nullptr;
    double distanceMin = std::numeric_limits<double>::max();

    for (IBestiole* v : voisins) {
        if (b.getIdentite() != v->getIdentite() && b.jeTeVois(*v)) {
            double dx = v->getX() - b.getX();
            double dy = v->getY() - b.getY();
            double dist = std::sqrt(dx*dx + dy*dy);

            if (dist < distanceMin) {
                distanceMin = dist;
                cibleProche = v;
            }
        }
    }

    if (cibleProche != nullptr) {
        double dx = cibleProche->getX() - b.getX();
        double dy = cibleProche->getY() - b.getY();
        // On s'aligne vers la cible
        double directionAttaque = std::atan2(-dy, dx); 
        b.setOrientation(directionAttaque);
    }

    // MISE À JOUR PHYSIQUE
    b.bouge(m.getWidth(), m.getHeight());
}