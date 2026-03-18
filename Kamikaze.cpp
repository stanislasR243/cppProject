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

    // 1. Recherche de la cible la plus proche parmi les voisins visibles
    for (IBestiole* v : voisins) {
        if (b.getIdentite() != v->getIdentite() && b.jeTeVois(*v)) {
            // Calcul de la distance euclidienne
            double dx = v->getX() - b.getX();
            double dy = v->getY() - b.getY();
            double dist = std::sqrt(dx*dx + dy*dy);

            if (dist < distanceMin) {
                distanceMin = dist;
                cibleProche = v;
            }
        }
    }

    // 2. Si une cible a été trouvée, on fonce vers elle
    if (cibleProche != nullptr) {
        double dx = cibleProche->getX() - b.getX();
        double dy = cibleProche->getY() - b.getY();
        
        // atan2(y, x) donne l'angle vers la cible. 
        // Note : en informatique (UImg), l'axe Y est souvent inversé, 
        // on utilise donc parfois -dy selon ton implémentation de draw.
        double directionAttaque = std::atan2(-dy, dx); 
        
        b.setOrientation(directionAttaque);
    }

    // Le mouvement effectif est géré par Bestiole::action() après cet appel.
}
