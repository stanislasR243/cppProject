#include "BestioleFactory.h"
#include "Bestiole.h"
#include "Yeux.h"
#include "Oreilles.h"
#include "Nageoires.h"
#include "Carapace.h"
#include "Camouflage.h"

#include <cstdlib>
#include <cmath>

BestioleFactory* BestioleFactory::instance = nullptr;

BestioleFactory::BestioleFactory()
{
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

// Fonction aléatoire
double BestioleFactory::randMinMax(double min, double max)
{
    return min + (double)rand() / RAND_MAX * (max - min);
}

// Création complète
std::unique_ptr<IBestiole> BestioleFactory::creerBestiole()
{
    double r = (double)rand() / RAND_MAX;

    std::unique_ptr<IBestiole> b;

    //  Comportement (pour l'instant Bestiole simple)
    b = std::make_unique<Bestiole>();

    //  Gregaire / Peureuse / Kamikaze plus tard

    //  Capteurs (50%)
    if (rand() % 2)
        b = std::make_unique<Yeux>(b.release(), randMinMax(30, 60), M_PI/2, randMinMax(0.5, 1.0));

    if (rand() % 2)
        b = std::make_unique<Oreilles>(b.release(), randMinMax(40, 80), randMinMax(0.3, 0.8));

    //  Accessoires (50%)
    if (rand() % 2)
        b = std::make_unique<Nageoires>(b.release(), randMinMax(1.0, 2.0));

    if (rand() % 2)
        b = std::make_unique<Carapace>(b.release(), randMinMax(1.0,2.0), randMinMax(1.0,2.0));

    if (rand() % 2)
        b = std::make_unique<Camouflage>(b.release(), randMinMax(0.0,1.0));

    return b;
}
