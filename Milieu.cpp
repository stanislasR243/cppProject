#include "Milieu.h"
#include <cstdlib>
#include <ctime>
#include <algorithm> // Pour std::remove_if

const T Milieu::white[] = { (T)255, (T)255, (T)255 };

Milieu::Milieu(int _width, int _height) : 
    UImg(_width, _height, 1, 3), 
    width(_width), height(_height)
{
    std::cout << "const Milieu" << std::endl;
    std::srand(std::time(NULL));
}

Milieu::~Milieu(void)
{
    std::cout << "dest Milieu" << std::endl;
}

// Implémentation du radar pour les comportements
std::vector<IBestiole*> Milieu::getVoisins(const IBestiole& b)
{
    std::vector<IBestiole*> voisins;

    for (auto const& ptr : listeBestioles)
    {
        // On vérifie que ce n'est pas la bestiole elle-même via son ID
        if (ptr->getIdentite() != b.getIdentite())
        {
            // .get() extrait le pointeur brut IBestiole* du unique_ptr
            voisins.push_back(ptr.get());
        }
    }
    return voisins;
}

void Milieu::addMember(std::unique_ptr<IBestiole> b)
{
    // On ajoute dans le tampon, pas dans la liste principale
    nouvellesBestioles.push_back(std::move(b)); 
}

void Milieu::gererCollisions() {
    // On parcourt toutes les paires possibles (i, j) sans doublons
    for (auto it1 = listeBestioles.begin(); it1 != listeBestioles.end(); ++it1) {
        for (auto it2 = std::next(it1); it2 != listeBestioles.end(); ++it2) {
            
            // On récupère des références pour plus de clarté
            IBestiole& b1 = **it1;
            IBestiole& b2 = **it2;

            // Calcul de la distance au carré (plus rapide car évite la racine carrée)
            double dx = b1.getX() - b2.getX();
            double dy = b1.getY() - b2.getY();
            double distInterne = dx * dx + dy * dy;

            // 8.0 * 8.0 = 64.0 (Seuil de collision)
            if (distInterne < 70.0) {
                // RÉACTION : Rebond simple
                // On inverse l'orientation des deux bestioles
                b1.setOrientation(b1.getOrientation() + M_PI);
                b2.setOrientation(b2.getOrientation() + M_PI);
                
                // Optionnel : on peut aussi les décaler un peu pour éviter 
                // qu'elles restent collées au tour suivant
            }
        }
    }
}

void Milieu::step(void)
{
    // 1. Effacer l'écran
    cimg_forXY(*this, x, y) fillC(x, y, 0, 255, 255, 255); // Remplacer white par 255 si white n'est pas défini

    // 2. Mise à jour des positions
    for (auto& ptr : listeBestioles)
    {
        ptr->action(*this);
    }

    // --- AJOUT ICI : Gestion des collisions ---
    // On le fait APRES que tout le monde ait bougé, mais AVANT le dessin
    gererCollisions(); 

    // 3. Dessin des bestioles
    for (auto& ptr : listeBestioles)
    {
        ptr->draw(*this);
    }

    // 4. Intégration des nouveaux nés (Clonage)
    if (!nouvellesBestioles.empty()) {
        for (auto & nb : nouvellesBestioles) {
            listeBestioles.push_back(std::move(nb));
        }
        nouvellesBestioles.clear();
    }

    // 5. Nettoyage des morts
    listeBestioles.erase(
        std::remove_if(
            listeBestioles.begin(),
            listeBestioles.end(),
            [](const std::unique_ptr<IBestiole>& b) { return b->estMorte(); }
        ),
        listeBestioles.end()
    );
}
