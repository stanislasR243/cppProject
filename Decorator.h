#ifndef DECORATOR_H
#define DECORATOR_H

#include "IBestiole.h"

class Decorator : public IBestiole
{
protected:
    IBestiole* bestiole;

public:
    Decorator(IBestiole* b);

    virtual void action(Milieu&) override;
    virtual void draw(UImg&) override;
    virtual bool jeTeVois(const IBestiole&) const override;

    virtual ~Decorator();
};

#endif
