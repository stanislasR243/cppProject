#ifndef _MILIEU_H_
#define _MILIEU_H_

#include "UImg.h"
#include "IBestiole.h" // On inclut l'interface

#include <iostream>
#include <vector>
#include <memory>

class Milieu : public UImg
{
private:
    static const T white[];

    int width, height;
    
    // Conteneur de gestion de mémoire (Propriété unique)
    std::vector<std::unique_ptr<IBestiole>> listeBestioles;

public:
    Milieu(int _width, int _height);
    ~Milieu(void);

    int getWidth(void) const { return width; }
    int getHeight(void) const { return height; }

    // La méthode cruciale pour les comportements
    std::vector<IBestiole*> getVoisins(const IBestiole& b);

    void step(void);
    void addMember(std::unique_ptr<IBestiole> b);
};

#endif
