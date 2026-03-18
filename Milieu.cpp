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

void Milieu::step(void)
{
    // 1. On efface l'écran (fond blanc)
    cimg_forXY(*this, x, y) fillC(x, y, 0, white[0], white[1], white[2]);

    // 2. Mise à jour de chaque bestiole
    // On itère sur les unique_ptr
    for (auto& ptr : listeBestioles)
    {
        ptr->action(*this); // Le comportement s'exécute ici
        ptr->draw(*this);   // Affichage
    }

    // 3. Nettoyage : On supprime les bestioles mortes
    listeBestioles.erase(
        std::remove_if(
            listeBestioles.begin(),
            listeBestioles.end(),
            [](const std::unique_ptr<IBestiole>& b) { return b->estMorte(); }
        ),
        listeBestioles.end()
    );
}

void Milieu::addMember(std::unique_ptr<IBestiole> b)
{
    // Ici on suppose que IBestiole a accès à une méthode de placement initial
    // b->initCoords(width, height); 
    listeBestioles.push_back(std::move(b)); // Transfert de propriété au vecteur
}
