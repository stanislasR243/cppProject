#ifndef BESTIOLEFACTORY_H
#define BESTIOLEFACTORY_H

#include "IBestiole.h"
#include "Milieu.h"
#include <memory>

class BestioleFactory
{
private:
    static BestioleFactory* instance;

    double pGregaire;
    double pPeureuse;
    double pKamikaze;

    BestioleFactory();

    double randMinMax(double min, double max);

public:
    static BestioleFactory* getInstance();

    std::unique_ptr<IBestiole> creerBestiole();
};

#endif
