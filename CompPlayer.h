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
	int getScore() const;                   // accessor
	vector<Card> getHand() const;           // accessor
    bool hasCard(Card) const;
	void addCard(Card);                     // mutator
    void addHand(vector<Card>);             // mutator
	void addScore(int);                     // mutator
	void reset();
	void turn(vector<Card> &);
private:
	int score_ = 0;
	vector<Card> hand_;
};


#endif /* defined(__straight_tofu__CompPlayer__) */
