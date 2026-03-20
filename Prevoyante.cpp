#include "Prevoyante.h"
#include "IBestiole.h"
#include "Milieu.h"
#include <vector>
#include <cmath>

void Prevoyante::execute(IBestiole& b, Milieu& m) {
    std::vector<IBestiole*> voisins = m.getVoisins(b);
    const double DISTANCE_COLLISION = 15.0;

    for (IBestiole* v : voisins) {
        if (b.getIdentite() != v->getIdentite() && b.jeTeVois(*v)) {
            // Prédiction positions futures
            double fVX = v->getX() + (cos(v->getOrientation()) * v->getVitesse());
            double fVY = v->getY() - (sin(v->getOrientation()) * v->getVitesse());
            double fBX = b.getX() + (cos(b.getOrientation()) * b.getVitesse());
            double fBY = b.getY() - (sin(b.getOrientation()) * b.getVitesse());

            double distFuture = std::sqrt(pow(fVX-fBX, 2) + pow(fVY-fBY, 2));

            if (distFuture < DISTANCE_COLLISION) {
                // Évitement
                double angleFuyant = std::atan2(-(v->getY() - b.getY()), v->getX() - b.getX());
                b.setOrientation(angleFuyant + M_PI);
                break; 
            }
        }
    }

    // MISE À JOUR PHYSIQUE
    b.bouge(m.getWidth(), m.getHeight());
}