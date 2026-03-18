#include "Prevoyante.h"
#include "IBestiole.h"
#include "Milieu.h"
#include <vector>
#include <cmath>

void Prevoyante::execute(IBestiole& b, Milieu& m) {
    std::vector<IBestiole*> voisins = m.getVoisins(b);

    for (IBestiole* v : voisins) {
        if (b.getIdentite() != v->getIdentite() && b.jeTeVois(*v)) {
            
            // 1. Prédire la position future du voisin (V) à t+1
            double futureVX = v->getX() + (cos(v->getOrientation()) * v->getVitesse());
            double futureVY = v->getY() - (sin(v->getOrientation()) * v->getVitesse());

            // 2. Prédire sa propre position future (b) à t+1
            double futureBX = b.getX() + (cos(b.getOrientation()) * b.getVitesse());
            double futureBY = b.getY() - (sin(b.getOrientation()) * b.getVitesse());

            // 3. Calculer la distance entre ces deux positions futures
            double dx = futureVX - futureBX;
            double dy = futureVY - futureBY;
            double distFuture = std::sqrt(dx*dx + dy*dy);

            // 4. Si la distance est trop faible, on ajuste l'orientation
            if (distFuture < DISTANCE_COLLISION) {
                // Stratégie d'évitement : on prend l'orientation opposée au voisin
                double angleVersVoisin = std::atan2(-(v->getY() - b.getY()), v->getX() - b.getX());
                b.setOrientation(angleVersVoisin + M_PI); // On tourne le dos au voisin
                
                // Une fois qu'on a évité un risque majeur, on peut arrêter la boucle 
                // pour ce tour afin d'éviter des changements d'angle trop erratiques
                break; 
            }
        }
    }
}
