// Gadget.h
#ifndef GADGET_H
#define GADGET_H

#include <string>
#include <memory>

class IBestiole;
class UImg;

class Gadget {
protected:
    std::string name;

public:
    Gadget() : name("Gadget") {}
    virtual ~Gadget() = default;

    std::string getName() const { return name; }
    void setName(const std::string& n) { name = n; }

    // Appliquer l’effet sur la bestiole
    virtual void apply(IBestiole* bestiole) = 0;

    // Dessiner le gadget
    virtual void draw(UImg* img, IBestiole* bestiole) = 0;

    // Clonage pour avoir des gadgets indépendants
    virtual std::unique_ptr<Gadget> clone() const = 0;
};

#endif
