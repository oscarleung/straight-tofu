#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <set>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "CompPlayer.h"
#include "Command.h"

using namespace std;

class Game{
    public:
        void start();
    private:
		bool playersHaveCards(Player* playerList[]);
        void initPlayers(Player* list[]);
        vector<Card> table_;
		Deck gameDeck;
		void printDeck();

};
