#include "Card.h"
#include "Game.h"
#include "Command.h"
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    if (argc == 2) {
        srand48(atoi(argv[1]));
    }
    else {
        srand48(0);
    }
	Game x;
	x.start();
	int t;
	cin >> t;
	return 0;
}