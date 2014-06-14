#ifndef __straight_tofu__CompPlayer__
#define __straight_tofu__CompPlayer__

#include <iostream>
#include <vector>
#include <string>
#include "Card.h"
#include "Player.h"

using namespace std;

class CompPlayer: public Player{
public:
	CompPlayer();
	int getScore() const;
	vector<Card> getHand() const;
	void addCard(Card);
    void addHand(vector<Card>);
	void addScore(int);
	void reset();
private:
	int score_ = 0;
	vector<Card> hand_;
};


#endif /* defined(__straight_tofu__CompPlayer__) */
