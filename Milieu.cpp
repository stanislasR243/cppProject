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

void Milieu::step(void)
{
    // 1. Effacer l'écran
    cimg_forXY(*this, x, y) fillC(x, y, 0, white[0], white[1], white[2]);

    // 2. Mise à jour (Boucle safe car on ne touche pas à listeBestioles dedans)
    for (auto& ptr : listeBestioles)
    {
        ptr->action(*this);
        ptr->draw(*this);
    }

    // 3. Intégration des nouveaux nés (Clonage)
    if (!nouvellesBestioles.empty()) {
        for (auto & nb : nouvellesBestioles) {
            listeBestioles.push_back(std::move(nb));
        }
        nouvellesBestioles.clear();
    }

    // 4. Nettoyage des morts
    listeBestioles.erase(
        std::remove_if(
            listeBestioles.begin(),
            listeBestioles.end(),
            [](const std::unique_ptr<IBestiole>& b) { return b->estMorte(); }
        ),
        listeBestioles.end()
    );
}
