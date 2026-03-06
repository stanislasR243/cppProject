#include "Decorator.h"

Decorator::Decorator(IBestiole* b) : bestiole(b) {}

Decorator::~Decorator()
{
    delete bestiole;
}

void Decorator::action(Milieu& m)
{
    bestiole->action(m);
}

void Decorator::draw(UImg& img)
{
    bestiole->draw(img);
}

bool Decorator::jeTeVois(const IBestiole& b) const
{
    return bestiole->jeTeVois(b);
}
