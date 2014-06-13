#include <vector>
#include <string>
#include "Card.h"

using namespace std;

class Game{
    public:
        void start();
    private:
		void init();
        void initPlayer();
        vector<Card> deck;



};
