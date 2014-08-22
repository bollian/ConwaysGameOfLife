all: ConwaysGameOfLife

ConwaysGameOfLife: main.o Grid.o
	g++ main.o Grid.o -o bin/ConwaysGameOfLife

main.o: main.cpp
	g++ -c main.cpp

Grid.o: Grid.cpp
	g++ -c Grid.cpp