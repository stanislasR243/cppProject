#include "BestioleFactory.h"
#include "Bestiole.h"
// Inclure les comportements concrets ici
#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"

#include "Yeux.h"
#include "Oreilles.h"
#include "Nageoires.h"
#include "Carapace.h"
#include "Camouflage.h"

#include <cstdlib>
#include <ctime>

// Initialisation du singleton à nullptr
BestioleFactory* BestioleFactory::instance = nullptr;

BestioleFactory::BestioleFactory()
{
    // Initialisation des probabilités de comportements
    pGregaire = 0.3;
    pPeureuse = 0.3;
    pKamikaze = 0.4;
}

BestioleFactory* BestioleFactory::getInstance()
{
    if(instance == nullptr)
        instance = new BestioleFactory();

    return instance;
}

// Fonction utilitaire pour l'aléatoire
double BestioleFactory::randMinMax(double min, double max)
{
    return min + (static_cast<double>(rand()) / RAND_MAX) * (max - min);
}

// Création d'une bestiole avec comportement aléatoire
std::unique_ptr<IBestiole> BestioleFactory::creerBestiole()
{
    auto b = std::make_unique<Bestiole>();

    // --- Comportement ---
    double r = static_cast<double>(rand()) / RAND_MAX;
    if (r < pGregaire) 
        b->setComportement(std::make_unique<Gregaire>());
    else if (r < (pGregaire + pPeureuse)) 
        b->setComportement(std::make_unique<Peureuse>());
    else 
        b->setComportement(std::make_unique<Kamikaze>());

    // --- Capteurs et accessoires (50% de chance chacun) ---
    if (rand() % 2)
        b->addGadget(std::make_unique<Yeux>(randMinMax(30, 60), M_PI/2, randMinMax(0.5,1.0)));
    if (rand() % 2)
        b->addGadget(std::make_unique<Oreilles>(randMinMax(40, 80), randMinMax(0.3,0.8)));

    if (rand() % 2)
        b->addGadget(std::make_unique<Nageoires>(randMinMax(1.0,2.0)));
    if (rand() % 2)
        b->addGadget(std::make_unique<Carapace>(randMinMax(1.0,2.0), randMinMax(1.0,2.0)));
    if (rand() % 2)
        b->addGadget(std::make_unique<Camouflage>(randMinMax(0.0,1.0)));

    return b;
}
