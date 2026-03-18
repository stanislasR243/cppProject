#include "Peureuse.h"
#include "IBestiole.h"
#include "Milieu.h"
#include <vector>
#include <cmath>

void Peureuse::execute(IBestiole& b, Milieu& m) {
    std::vector<IBestiole*> voisins = m.getVoisins(b);
    
    int nbVoisinsVus = 0;

    // 1. On compte combien de voisins sont visibles
    for (IBestiole* v : voisins) {
        if (b.getIdentite() != v->getIdentite() && b.jeTeVois(*v)) {
            nbVoisinsVus++;
        }
    }

    // 2. Logique de réaction
    if (nbVoisinsVus >= SEUIL_PERSONNES) {
        // --- FUITE ---
        // On fait demi-tour (angle opposé)
        double nouvelleOrientation = b.getOrientation() + M_PI;
        b.setOrientation(nouvelleOrientation);

        // On accélère (on suppose que Bestiole a une vitesse de base stockée)
        // Ici on double la vitesse actuelle pour l'action de fuite
        b.setVitesse(b.getVitesse() * MULTIPLICATEUR_FUITE);
    } 
    else {
        // --- CALME ---
        // On pourrait ici remettre une vitesse normale si elle avait accéléré avant
        // Note : Il faudra que ta classe Bestiole gère une "vitesse de croisière"
    }

    // Le mouvement x += ... est géré par Bestiole::action() juste après
}
