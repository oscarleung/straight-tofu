#ifndef __straight_tofu__HumanPlayer__
#define __straight_tofu__HumanPlayer__

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "Card.h"
#include "Player.h"
#include "Deck.h"
#include "Command.h"
#include <stdexcept>

using namespace std;

class HumanPlayer: public Player{
public:
	HumanPlayer(int);
	Command turn(vector<Card> &,bool print=true);
private:
	vector<Card> getPlays(vector<Card>) const;	// return valid plays
	vector<Card> hand_;						// stores all cards in a players hand
	vector<Card> discardPile_;				// keeps track of the discards for a player in a given round
	int score_ = 0;							// keeps track of score
	int playerNumber_;
};


#endif /* defined(__straight_tofu__HumanPlayer__) */
