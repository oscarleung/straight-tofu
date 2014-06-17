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

using namespace std;

class HumanPlayer: public Player{
public:
	HumanPlayer(int);
	Command turn(vector<Card> &);
private:
};


#endif /* defined(__straight_tofu__HumanPlayer__) */
