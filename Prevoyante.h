#ifndef PREVOYANTE_H
#define PREVOYANTE_H

#include "IComportement.h"

class Prevoyante : public IComportement {
private:
    const double DISTANCE_COLLISION = 20.0; // Rayon de sécurité

public:
    void execute(IBestiole& b, Milieu& m) override;
};

#endif
