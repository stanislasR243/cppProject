main : main.cpp Aquarium.o Bestiole.o Milieu.o BestioleFactory.o
	g++ -Wall -std=c++17 -o main main.cpp Aquarium.o Bestiole.o Milieu.o BestioleFactory.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++17  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++17  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++17  -c Milieu.cpp -I .

BestioleFactory.o : BestioleFactory.h BestioleFactory.cpp
	g++ -Wall -std=c++17  -c BestioleFactory.cpp -I .

clean:
	rm -rf *.o main