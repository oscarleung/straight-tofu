#ifndef __straight_tofu__HumanPlayer__
#define __straight_tofu__HumanPlayer__

#include <iostream>
#include <vector>
#include <string>
#include "Card.h"
#include "Player.h"

using namespace std;

class HumanPlayer: public Player{
public:
	HumanPlayer();
	void addCard(Card);
	vector<Card> getHand() const;
	void addScore(int);
	void reset();
private:
	int score=0;
	vector<Card> hand;
};


#endif /* defined(__straight_tofu__HumanPlayer__) */
