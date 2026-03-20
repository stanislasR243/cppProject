#include "Bestiole.h"
#include "Milieu.h"
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cstring>

const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 30.;
int               Bestiole::next = 0;

Bestiole::Bestiole( void )
{
   identite = ++next;
   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = (static_cast<double>(rand()) / RAND_MAX) * 2. * M_PI;
   vitesse = (static_cast<double>(rand()) / RAND_MAX) * MAX_VITESSE;
   
   age = 0;
   maxAge = rand() % 200 + 100;

   // Remplissage direct du tableau (pas de 'new')
   couleur[0] = rand() % 231;
   couleur[1] = rand() % 231;
   couleur[2] = rand() % 231;

   cout << "const Bestiole (" << identite << ") par defaut" << endl;
}

Bestiole::Bestiole( const Bestiole & b )
{
   identite = ++next;
   x = b.x;
   y = b.y;
   cumulX = b.cumulX;
   cumulY = b.cumulY;
   orientation = b.orientation;
   vitesse = b.vitesse;
   age = b.age;
   maxAge = b.maxAge;

   // Copie simple des valeurs du tableau
   couleur[0] = b.couleur[0];
   couleur[1] = b.couleur[1];
   couleur[2] = b.couleur[2];

   cout << "Copie Bestiole (" << b.identite << " -> " << identite << ")" << endl;
}

Bestiole::~Bestiole( void )
{
   // Plus besoin de delete[], le tableau couleur[3] est géré automatiquement
   cout << "dest Bestiole (" << identite << ")" << endl;
}

void Bestiole::initCoords( int xLim, int yLim )
{
   x = rand() % xLim;
   y = rand() % yLim;
}

void Bestiole::bouge( int xLim, int yLim )
{
   double         nx, ny;
   double         dx = cos( orientation ) * vitesse;
   double         dy = -sin( orientation ) * vitesse;
   int            cx, cy;

   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }
}

void Bestiole::action(Milieu & monMilieu)
{
    age++;
    bouge(monMilieu.getWidth(), monMilieu.getHeight());

    const double PROBA_CLONAGE = 0.01;
    if (((double)rand() / RAND_MAX) < PROBA_CLONAGE)
    {
        // On crée un clone et on le déplace (move) dans le milieu
        auto clone = std::make_unique<Bestiole>(*this);
        monMilieu.addMember(std::move(clone));
    }
}

void Bestiole::draw( UImg & support )
{
   double         xt = x + cos( orientation ) * AFF_SIZE / 2.1;
   double         yt = y - sin( orientation ) * AFF_SIZE / 2.1;

   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE / 5., -orientation / M_PI * 180., couleur );
   support.draw_circle( xt, yt, AFF_SIZE / 2., couleur );
}

bool operator==( const Bestiole & b1, const Bestiole & b2 )
{
   return ( b1.identite == b2.identite );
}

bool Bestiole::jeTeVois( const IBestiole & b ) const
{
   return false; 
}

bool Bestiole::estMorte() const 
{
    return (age >= maxAge);
}

void Bestiole::setOrientation(double a) 
{
    orientation = a;
}

void Bestiole::setVitesse(double v) 
{
    vitesse = (v > MAX_VITESSE) ? MAX_VITESSE : v;
}