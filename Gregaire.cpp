#include "Gregaire.h"
#include "IBestiole.h"
#include "Milieu.h"
#include <vector>
#include <cmath>

void Gregaire::execute(IBestiole& b, Milieu& m) {
    // 1. Récupérer les voisins via le milieu
    std::vector<IBestiole*> voisins = m.getVoisins(b);

    double sommeCos = 0;
    double sommeSin = 0;
    int nbVoisinsVus = 0;

    // 2. Parcourir pour calculer la direction moyenne des voisins visibles
    for (IBestiole* v : voisins) {
        // On ne se compte pas soi-même et on vérifie la visibilité (capteurs)
        if (b.getIdentite() != v->getIdentite() && b.jeTeVois(*v)) {
            sommeCos += cos(v->getOrientation());
            sommeSin += sin(v->getOrientation());
            nbVoisinsVus++;
        }
    }

    // 3. S'aligner sur le groupe si on voit du monde
    if (nbVoisinsVus > 0) {
        // Calcul de la moyenne trigonométrique pour éviter les bugs de saut d'angle
        double orientationMoyenne = atan2(sommeSin / nbVoisinsVus, sommeCos / nbVoisinsVus);
        b.setOrientation(orientationMoyenne);
    }
    
    // Note : le déplacement physique (x += ...) se fait dans Bestiole::action() 
    // juste après l'appel de cette stratégie.
}
