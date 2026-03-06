#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"

#include <iostream>
#include <vector>

using namespace std;


class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   #include <memory>
   #include <vector>

   std::vector<std::unique_ptr<IBestiole>> listeBestioles;

public :
   Milieu( int _width, int _height );
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );

   void addMember(std::unique_ptr<IBestiole> b); { listeBestioles.push_back(b); listeBestioles.back().initCoords(width, height); }
   int nbVoisins( const Bestiole & b );

};


#endif
