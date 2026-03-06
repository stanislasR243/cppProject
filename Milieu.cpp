#include "Milieu.h"

#include <cstdlib>
#include <ctime>


const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;

}


void Milieu::step( void )
{
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );

   // on change juste Bestiole en IBestiole*
   for ( std::vector<IBestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      // On utilise -> car c'est maintenant un pointeur
      (*it)->action( *this );
      (*it)->draw( *this );
   }
  // Après avoir appelé action() et draw() pour toutes les bestioles
listeBestioles.erase(
    std::remove_if(
        listeBestioles.begin(),
        listeBestioles.end(),
        [](const std::unique_ptr<IBestiole> & b){ return b->estMorte(); }
    ),
    listeBestioles.end()
);
}

void Milieu::addMember(std::unique_ptr<IBestiole> b)
{
    b->initCoords(width, height);           // position aléatoire du clone
    listeBestioles.push_back(std::move(b)); // transfert de propriété
}
int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;

}
