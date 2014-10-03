all: CGL_run

debug: CGL_dbg

CGL_run: main_run.o Grid_run.o bin
	g++ main_run.o Grid_run.o -o bin/CGL

CGL_dbg: main_dbg.o Grid_dbg.o bin
	g++ -g main_dbg.o Grid_dbg.o -o bin/CGL_dbg

main_run.o: main.cpp
	g++ -c main.cpp -o main_run.o

main_dbg.o: main.cpp
	g++ -c -g main.cpp -o main_dbg.o

Grid_run.o: Grid.cpp
	g++ -c Grid.cpp -o Grid_run.o

Grid_dbg.o: Grid.cpp
	g++ -c -g Grid.cpp -o Grid_dbg.o

bin:
	mkdir bin
