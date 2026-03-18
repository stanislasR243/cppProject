#ifndef MULTIPLE_H
#define MULTIPLE_H

#include "IComportement.h"
#include <vector>
#include <memory>

class Multiple : public IComportement {
private:
    IComportement* comportementCourant;
    std::vector<IComportement*> listeComportements;
    double probaChangement; // Valeur entre 0 et 1 (ex: 0.05 pour 5% de chance par tour)

public:
    Multiple();
    virtual ~Multiple();
    void execute(IBestiole& b, Milieu& m) override;
};

#endif
