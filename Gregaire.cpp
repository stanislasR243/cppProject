#include "Gregaire.h"
#include "IBestiole.h"
#include "Milieu.h"
#include <vector>
#include <cmath>

void Gregaire::execute(IBestiole& b, Milieu& m) {
    // 1. Récupérer tous les voisins présents dans le milieu
    std::vector<IBestiole*> voisins = m.getVoisins(b);

    double sommeCos = 0;
    double sommeSin = 0;
    int nbVoisinsVus = 0;

    // 2. Calculer la direction moyenne des voisins que l'on "voit" réellement
    for (IBestiole* v : voisins) {
        // On ne s'écoute pas soi-même et on vérifie si la bestiole est dans le champ de vision
        if (b.getIdentite() != v->getIdentite() && b.jeTeVois(*v)) {
            // Utilisation de cos/sin pour une moyenne angulaire robuste
            sommeCos += std::cos(v->getOrientation());
            sommeSin += std::sin(v->getOrientation());
            nbVoisinsVus++;
        }
    }

    // 3. Si on voit au moins un voisin, on s'aligne sur le groupe
    if (nbVoisinsVus > 0) {
        double orientationMoyenne = std::atan2(sommeSin, sommeCos);
        b.setOrientation(orientationMoyenne);
    }
    
    // 4. DÉPLACEMENT PHYSIQUE (L'étape qui manquait)
    // On demande à la bestiole de mettre à jour ses coordonnées X et Y
    // en fonction de sa vitesse et de sa (nouvelle) orientation.
    b.bouge(m.getWidth(), m.getHeight());
}