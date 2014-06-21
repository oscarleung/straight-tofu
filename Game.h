#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "CompPlayer.h"
#include "Command.h"

using namespace std;

class Game{
    public:
        void start(int seed=0);                         // begin a new game
    private:
		bool playersHaveCards(Player* playerList[]);    // check players hand for end game
        void initPlayers(Player* list[]);               // create a list of player
        void printDeck();
        vector<Card> table_;
		Deck gameDeck;
		Player* playerList[4];							//List of players
		
};
