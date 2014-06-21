#include "Card.h"
#include "Game.h"
#include "Command.h"
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	Game x;
	x.start((int)argv[1]);
	return 0;
}