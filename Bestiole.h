#ifndef _BESTIOLE_H_
#define _BESTIOLE_H_

#include "UImg.h"
#include "IBestiole.h"
#include <iostream>

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
   T couleur[3];

   int           age;
   int           maxAge;

public:                                           
   Bestiole( void );
   Bestiole( const Bestiole & b );
   virtual ~Bestiole( void );

   void action( Milieu & monMilieu ) override;
   void draw( UImg & support ) override;
   
   void bouge( int xLim, int yLim );
   void initCoords( int xLim, int yLim );

   // Getters & Setters imposés par IBestiole
   void setOrientation(double a) override;
   void setVitesse(double v) override;
   bool jeTeVois( const IBestiole & b ) const override;
   bool estMorte() const override;

   double getX() const override { return static_cast<double>(x); }
   double getY() const override { return static_cast<double>(y); }
   double getOrientation() const override { return orientation; }
   double getVitesse() const override { return vitesse; }
   int getIdentite() const override { return identite; }
   
   double getProtection() const override { return 1.0; } // Valeur par défaut
   double getCoeffCamouflage() const override { return 0.0; } // Valeur par défaut

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );
};

#endif