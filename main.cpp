#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );

   for ( int i = 1; i <= 20; ++i )
      // On crée un unique_ptr qui contient une nouvelle Bestiole
      ecosysteme.getMilieu().addMember( std::make_unique<Bestiole>() ); 
   ecosysteme.run();


   return 0;

}
