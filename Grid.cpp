#include <iostream>
#include <cstdlib>
#include <vector>
#include "Grid.h"

using namespace std;

Grid::Grid(const int w, const int h)
{
	width = w;
	height = h;
	
	real = new bool*[width];
	stub = new bool*[width];
	
	for (int i = 0; i < width; ++i)
	{
		real[i] = new bool[height];
		stub[i] = new bool[height];
		
		for (int k = 0; k < height; ++k)
		{
			real[i][k] = (bool)(rand() & 1);
			stub[i][k] = real[i][k];
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
	int neighbours;
	
	for (int i = 0; i < width; ++i)
	{
		for (int k = 0; k < height; ++k)
		{
			neighbours = adjAndAlive(i, k);
			
			if (real[i][k])
			{ // if alive
				if (neighbours < 2)
				{
					stub[i][k] = false;
				}
				else if (neighbours < 4)
				{
					stub[i][k] = true;
				}
				else
				{
					stub[i][k] = false;
				}
			}
			else if (neighbours == 3)
			{
				stub[i][k] = true;
			}
		}
	}
	
	copy();
}

void Grid::display()
{
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
	for (int x = 0; x < width; ++x)
	{
		for (int y = 0; y < height; ++y)
		{
			real[x][y] = stub[x][y];
		}
	}
}

bool Grid::inBounds(int x, int y)
{
	return (x >= 0) && (x < width) && (y >= 0) && (y < height);
}

int Grid::adjAndAlive(int x, int y)
{
	bool was_alive = real[x][y];
	int count = 0;
	--x;
	--y;
	
	for (int i = 0; i < 3; ++i)
	{
		for (int k = 0; k < 3; ++k)
		{
			if (inBounds(x + i, y + k) && real[x + i][y + k])
			{
				++count;
			}
		}
	}
	
	if (was_alive)
	{
		return count - 1;
	}
	else
	{
		return count;
	}
}
