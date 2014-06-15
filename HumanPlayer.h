#ifndef __straight_tofu__HumanPlayer__
#define __straight_tofu__HumanPlayer__

#include <vector>
#include <set>
#include "Card.h"
#include "Player.h"
#include "Deck.h"
#include "Command.h"

using namespace std;

class HumanPlayer: public Player{
public:
	HumanPlayer(int);
	void turn(vector<Card> &);
private:
};


#endif /* defined(__straight_tofu__HumanPlayer__) */
