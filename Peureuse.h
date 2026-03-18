#ifndef PEUREUSE_H
#define PEUREUSE_H

#include "IComportement.h"

class Peureuse : public IComportement {
private:
    const int SEUIL_PERSONNES = 3; // Nombre de voisins max avant de fuir
    const double MULTIPLICATEUR_FUITE = 2.0; // Accélération en cas de peur

public:
    void execute(IBestiole& b, Milieu& m) override;
};

#endif
