#ifndef ICOMPORTEMENT_H
#define ICOMPORTEMENT_H

class IBestiole;
class Milieu;

class IComportement {
public:
    virtual ~IComportement() {}

    // b : la bestiole qui agit (vue comme interface pour avoir ses accessoires)
    // m : le milieu (pour voir les voisins)
    virtual void execute(IBestiole& b, Milieu& m) = 0;
};

#endif
