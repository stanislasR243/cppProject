#include "Aquarium.h"
#include "Milieu.h"
#include "BestioleFactory.h"
#include <iostream>

using namespace std;

int main()
{
    int width = 640;
    int height = 480;
    Aquarium ecosysteme(width, height, 30);

    // Récupération de l'instance de la Factory
    BestioleFactory* factory = BestioleFactory::getInstance();

    for ( int i = 1; i <= 20; ++i )
    {
        // 1. La factory crée une bestiole (avec accessoires/capteurs aléatoires)
        auto b = factory->creerBestiole();
        
        // 2. On initialise ses coordonnées avec la taille de l'aquarium
        // Note : initCoords doit être dans IBestiole.h pour que cela compile ici
        b->initCoords(width, height);
        
        // 3. On l'ajoute au milieu
        ecosysteme.getMilieu().addMember( std::move(b) ); 
    }

    cout << "Simulation lancée avec 20 bestioles variées." << endl;
    ecosysteme.run();

    return 0;
}