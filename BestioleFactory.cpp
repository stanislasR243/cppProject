#include "BestioleFactory.h"
#include <cstdlib>

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
