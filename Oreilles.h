#ifndef OREILLES_H
#define OREILLES_H

#include "Decorator.h"

class Oreilles : public Decorator {
private:
    double distance; // δo
    double capacite; // γo

public:
    Oreilles(IBestiole* b, double d, double g);
    virtual ~Oreilles() {}

    bool jeTeVois(const IBestiole& autre) const override;
};

#endif
