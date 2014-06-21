#include "Game.h"
using namespace std;

int main(int argc, char* argv[])
{
    Game x;
    if (argc == 2) {
        x.start((atoi(argv[1])));
    }
    else {
        x.start(0);
    }
    
	return 0;
}
