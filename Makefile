CC = g++

CXXFLAGS = -Wall -pedantic -std=c++11

main.exe: matrice.o main.o
	$(CC) -o main.exe matrice.o main.o

matrice.o: matrice.hpp matrice.cpp
	$(CC) -c matrice.cpp $(CXXFLAGS)

main.o: matrice.o main.cpp
	$(CC) -c main.cpp $(CXXFLAGS)

clean:
	rm *.o
