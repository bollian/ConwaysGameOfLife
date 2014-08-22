#ifndef GRID_H_
#define GRID_H_

using namespace std;

// class containing all data and helper functions for one grid in Conway's Game of Life
class Grid {
public:
	Grid(const int, const int);
	virtual ~Grid();

	int getWidth();
	int getHeight();

	void display();
	void process();

	const static char ALIVE = '0';
	const static char DEAD = ' ';

private:

	int width;
	int height;

	bool** real;
	bool** stub;

	void copy();
	int adjAndAlive(int, int);
	bool inBounds(int, int);
};

#endif
