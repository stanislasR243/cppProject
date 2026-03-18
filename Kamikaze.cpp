#ifndef KAMIKAZE_H
#define KAMIKAZE_H

#include "IComportement.h"

class Kamikaze : public IComportement {
public:
    void execute(IBestiole& b, Milieu& m) override;
};

#endif
