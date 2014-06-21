#include "Game.h"
using namespace std;

int main(int argc, char* argv[])
{
    Game straightsgame;
    if (argc == 2) {
        straightsgame.start((atoi(argv[1])));
    }
    else {
        straightsgame.start();
    }
    
	return 0;
}
