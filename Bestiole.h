#ifndef _BESTIOLE_H_
#define _BESTIOLE_H_

#include "UImg.h"
#include "IBestiole.h"
#include "IComportement.h"
#include <iostream>
#include <memory> 
#include "Gadget.h"  // Nouveau

using namespace std;

class Milieu;

class Bestiole : public IBestiole
{
private:
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;
   static int              next;

   int           identite;
   int           x, y;
   double        cumulX, cumulY;
   double        orientation;
   double        vitesse;
   T             couleur[3];

   int           age;
   int           maxAge;
   std::unique_ptr<IComportement> comportement;
   // Vecteur pour les gadgets
   std::vector<std::unique_ptr<Gadget>> gadgets;

public:                                           
   Bestiole( void );
   Bestiole( const Bestiole & b );
   virtual ~Bestiole( void );
      // --- Méthodes pour gérer les gadgets ---
   void addGadget(std::unique_ptr<Gadget> g) {
       gadgets.push_back(std::move(g));
   }

   void applyGadgets() {
       for (auto& g : gadgets)
           g->apply(this);
   }

   void drawGadgets(UImg & support) {
       for (auto& g : gadgets)
           g->draw(&support, this);
   }

   bool hasGadget(const std::string& name) const {
       for (auto& g : gadgets)
           if (g->getName() == name) return true;
       return false;
   }

   void action( Milieu & monMilieu ) override;
   void draw( UImg & support ) override;
   
   void bouge( int xLim, int yLim );
   void initCoords( int xLim, int yLim );

   // --- NOUVELLES MÉTHODES POUR LA FACTORY ---
   void setComportement(std::unique_ptr<IComportement> c);
   void setCouleur(int r, int g, int b);

   // --- Getters & Setters imposés par IBestiole ---
   void setOrientation(double a) override;
   void setVitesse(double v) override;
   bool jeTeVois( const IBestiole & b ) const override;
   bool estMorte() const override;

   double getX() const override { return static_cast<double>(x); }
   double getY() const override { return static_cast<double>(y); }
   double getOrientation() const override { return orientation; }
   double getVitesse() const override { return vitesse; }
   int getIdentite() const override { return identite; }
   
   double getProtection() const override { return 1.0; } 
   double getCoeffCamouflage() const override { return 0.0; } 

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );
};

#endif
