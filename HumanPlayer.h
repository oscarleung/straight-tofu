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
	int getScore() const;
	vector<Card> getHand() const;
    bool findCard(Card) const;
	void addCard(Card);
    void addHand(vector<Card>);
	void addScore(int);
	void reset();
private:
	int score_ = 0;
	vector<Card> hand_;
};


#endif /* defined(__straight_tofu__HumanPlayer__) */
