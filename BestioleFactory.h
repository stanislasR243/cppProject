#ifndef BESTIOLEFACTORY_H
#define BESTIOLEFACTORY_H

#include "Bestiole.h"
#include "Milieu.h"

class BestioleFactory
{
private:
    static BestioleFactory* instance;

    double pGregaire;
    double pPeureuse;
    double pKamikaze;

    BestioleFactory(); // constructeur privé

public:
    static BestioleFactory* getInstance();

    Bestiole creerBestiole(Milieu& m);
};

#endif
