#include "BestioleFactory.h"
#include "Bestiole.h"
// Inclure les comportements concrets ici
#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"

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
    // 1. On crée la bestiole de base (corps)
    // On utilise un pointeur vers Bestiole car IBestiole n'a peut-être pas setComportement
    auto b = std::make_unique<Bestiole>();

    // 2. Tirage aléatoire pour le comportement
    double r = static_cast<double>(rand()) / RAND_MAX;

    if (r < pGregaire) 
    {
        // On injecte le comportement Grégaire
        b->setComportement(std::make_unique<Gregaire>());
    } 
    else if (r < (pGregaire + pPeureuse)) 
    {
        // On injecte le comportement Peureuse
        b->setComportement(std::make_unique<Peureuse>());
    } 
    else 
    {
        // Le reste (pKamikaze)
        b->setComportement(std::make_unique<Kamikaze>());
    }

    // 3. Retourne la bestiole "intelligente" castée en IBestiole
    return b;
}