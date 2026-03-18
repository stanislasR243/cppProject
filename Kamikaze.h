#ifndef KAMIKAZE_H
#define KAMIKAZE_H

#include "IComportement.h"
#include "IBestiole.h"
#include "Milieu.h"
#include <vector>

class Kamikaze : public IComportement {
public:
    void execute(IBestiole& b, Milieu& m) override;
};

#endif
