#include <iostream>
#include <cstdlib>
#include <cstring>
#include <time.h>
#include "Grid.h"

using namespace std;

bool equals(const char* const __restrict first, const char* const __restrict last);

int main() {
	time_t then, now;
	time(&then);
	Grid game = Grid(20, 10);
	char input[256] = "a";
	time(&now);
	srand(now);
	while (!(equals(input, "q") || equals(input, "quit")))
	{
		if (difftime(now, then) > 5.0)
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

bool equals(const char* const __restrict first, const char* const __restrict last)
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
