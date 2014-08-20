#include <iostream>
#include <cstdlib>
#include "Grid.h"

using namespace std;

Grid::Grid(const int w, const int h)
{
	cout << "Start Construction" << endl;
	width = w;
	height = h;

	real = new bool*[width];
	stub = new bool*[width];

	for (int x = 0; x < width; ++x)
	{
		real[x] = new bool[height];
		stub[x] = new bool[height];
		for (int y = 0; y < height; ++y)
		{
			real[x][y] = (bool)(rand() & 1);
			stub[x][y] = real[x][y];
		}
	}
}

Grid::~Grid()
{
	for (int x = 0; x < width; ++x)
	{
		delete[] real[x];
		delete[] stub[x];
	}
	delete[] real;
	delete[] stub;
}

int Grid::getWidth()
{
	return width;
}

int Grid::getHeight()
{
	return height;
}

void Grid::process()
{
	cout << "Grid::process" << endl;
	int count;
	for (int x = 0; x < width; ++x)
	{
		for (int y = 0; y < height; ++y)
		{
			count = adjAndAlive(x, y);

			if (stub[x][y]) // if alive
			{
				if (count < 2 || count > 3)
				{
					real[x][y] = false; // die
				}
			}
			else // if dead
			{
				if (count == 3)
				{
					real[x][y] = true;
				}
			}
		}
	}
	copy();
}

void Grid::display()
{
	cout << "Grid::display" << endl;
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			if (real[x][y]) // if alive
			{
				cout << ALIVE;
			}
			else
			{
				cout << DEAD;
			}
		}
		cout << endl;
	}
}

void Grid::copy()
{
	cout << "Grid::copy" << endl;
	for (int x = 0; x < width; ++x)
	{
		for (int y = 0; y < height; ++y)
		{
			stub[x][y] = real[x][y];
		}
	}
}

bool Grid::inBounds(int x, int y)
{
	cout << "Grid::inBounds" << endl;
	return (x >= 0) && (x < width) && (y >= 0) && (y < height);
}

int Grid::adjAndAlive(int x, int y)
{
	cout << "Grid::adjAndAlive" << endl;
	int x2 = x - 2;
	int	y2 = y - 2;
	int	output = 0;

	for (int i = 0; i < 3; ++i)
	{
		++x2;
		for (int k = 0; k < 3; ++k)
		{
			++y2;
			if (inBounds(x, y)) // not outside board
			{
				cout << "Past Grid::inBounds" << endl;
				if (!(x2 == x && y2 == y)) // not on function target
				{
					cout << "Past Function Target Check" << endl;
					stub[x2][y2];
					cout << "Past Access Check" << endl;
					if (stub[x2][y2] == 1) // TODO: fix segfault + figure out why it's happening
					{
						cout << "Past State Check" << endl;
						++output;
					}
				}
			}
		}
	}

	return output;
}
