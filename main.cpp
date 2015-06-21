#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <time.h>
#include "Grid.h"

using namespace std;

bool equals(const char* const first, const char* const last);

int main() {
	time_t then;
	time_t now;
	time(&then);
	srand(then);
	
	Grid game(20, 10);
	
	// first iteration
	game.display();
	cout << endl;
	
	time(&now);
	
	while (true)
	{
		if (difftime(now, then) > 1.0)
		{
			time(&then);
			game.process();
			game.display();
			cout << endl;
		}
		//cin.getline(input, 256);
		time(&now);
	}

	return EXIT_SUCCESS;
}

bool equals(const char* const first, const char* const last)
{
	unsigned int length1 = strlen(first);

	if (length1 != strlen(last))
	{
		return false;
	}
	for (unsigned int x = 0; x < length1; ++x)
	{
		if (first[x] != last[x])
		{
			return false;
		}
	}

	return true;
}
