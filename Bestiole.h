#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"
#include "IBestiole.h" // inclure l'interface
#include <iostream>

using namespace std;


class Milieu;


class Bestiole : public IBestiole //héritage publique de IBestiole
{

private :
   static const double      AFF_SIZE;
   static const double      MAX_VITESSE;
   static const double      LIMITE_VUE;

   static int              next;

private :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;

   T               * couleur;

   // <--- AJOUTS : Pour la gestion de la vie 
   int               age;
   int               maxAge;

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   virtual ~Bestiole( void );                      // <--- MODIFICATION : Destructeur virtuel obligatoire                                           
                                                   // Operateur d'affectation binaire par defaut
   
   // --- Méthodes de l'interface IBestiole (OVERRIDE) ---
   
   void action( Milieu & monMilieu ) override;
   void draw( UImg & support ) override;
   
   // Note : On utilise maintenant IBestiole dans la signature
   bool jeTeVois( const IBestiole & b ) const override; 

   // Getters de position et identité
   double getX() const override { return x; }
   double getY() const override { return y; }
   double getOrientation() const override { return orientation; }
   int getIdentite() const override { return identite; }

   // Caractéristiques physiques de base (sans accessoires)
   double getVitesse() const override { return vitesse; }
   double getProtection() const override { return 1.0; } // Valeur neutre
   double getCoeffCamouflage() const override { return 1.0; } // Pas camouflée

   // État de santé
   bool estMorte() const override;

   void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

};


#endif
