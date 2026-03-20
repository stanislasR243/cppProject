// Gadget.h
#ifndef GADGET_H
#define GADGET_H

#include <string>
#include <memory>

class IBestiole; // Forward declaration
class UImg;      // Forward declaration pour le dessin

class Gadget {
protected:
    std::string name; // Nom du gadget

public:
    Gadget() : name("Gadget") {}
    virtual ~Gadget() = default;

    // Getter/Setter du nom
    std::string getName() const { return name; }
    void setName(const std::string& n) { name = n; }

    // Appliquer l'effet du gadget sur la bestiole
    virtual void apply(IBestiole* bestiole) = 0;

    // Dessiner le gadget sur l'image
    virtual void draw(UImg* img, IBestiole* bestiole) = 0;

    // Clonage : pour créer une copie indépendante du gadget
    virtual std::unique_ptr<Gadget> clone() const = 0;
};

#endif
