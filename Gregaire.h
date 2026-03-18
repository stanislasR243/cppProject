#ifndef GREGAIRE_H
#define GREGAIRE_H

#include "IComportement.h"

class Gregaire : public IComportement {
public:
    // b : la bestiole qui agit
    // m : le milieu pour accéder aux autres
    void execute(IBestiole& b, Milieu& m) override;
};

#endif
