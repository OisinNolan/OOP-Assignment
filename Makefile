CFLAGS= -ansi -pedantic -Wall -std=c++11
MAP= -D MAP

main : main.o Trajet.o TrajetSimple.o TrajetCompose.o TrajetList.o Catalogue.o StringList.o
	g++ main.o Trajet.o TrajetSimple.o TrajetCompose.o TrajetList.o Catalogue.o StringList.o -o main

main.o : main.cpp
	g++ $(CFLAGS) -o main.o -c main.cpp

Trajet.o : Trajet.cpp
	g++ $(CFLAGS) -o Trajet.o -c Trajet.cpp

TrajetSimple.o : TrajetSimple.cpp
	g++ $(CFLAGS) -o TrajetSimple.o -c TrajetSimple.cpp

TrajetCompose.o : TrajetCompose.cpp
	g++ $(CFLAGS) -o TrajetCompose.o -c TrajetCompose.cpp

TrajetList.o : TrajetList.cpp
	g++ $(CFLAGS) -o TrajetList.o -c TrajetList.cpp

Catalogue.o : Catalogue.cpp
	g++ $(CFLAGS) -o Catalogue.o -c Catalogue.cpp

StringList.o : StringList.cpp
	g++ $(CFLAGS) -o StringList.o -c StringList.cpp

.PHONY: clean
clean:
	rm -f *.o core
	rm main