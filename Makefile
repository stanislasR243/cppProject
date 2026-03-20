# Liste des objets (on ajoute les comportements ici)
OBJS = Aquarium.o Bestiole.o Milieu.o BestioleFactory.o Gregaire.o Peureuse.o Kamikaze.o

# Règle principale : on utilise la variable OBJS pour ne rien oublier
main : main.cpp $(OBJS)
	g++ -Wall -std=c++17 -o main main.cpp $(OBJS) -I . -lX11 -lpthread

# Compilations individuelles
Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++17 -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++17 -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++17 -c Milieu.cpp -I .

BestioleFactory.o : BestioleFactory.h BestioleFactory.cpp
	g++ -Wall -std=c++17 -c BestioleFactory.cpp -I .

# Nouvelles règles pour les comportements
Gregaire.o : Gregaire.h Gregaire.cpp IComportement.h
	g++ -Wall -std=c++17 -c Gregaire.cpp -I .

Peureuse.o : Peureuse.h Peureuse.cpp IComportement.h
	g++ -Wall -std=c++17 -c Peureuse.cpp -I .

Kamikaze.o : Kamikaze.h Kamikaze.cpp IComportement.h
	g++ -Wall -std=c++17 -c Kamikaze.cpp -I .

clean:
	rm -rf *.o main