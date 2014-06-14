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
	int getScore() const;                   // accessor
	vector<Card> getHand() const;           // accessor
    bool hasCard(Card) const;
	void addCard(Card);                     // mutator
    void discard(Card);                     // mutator
    void addHand(vector<Card>);             // mutator
	void addScore(int);                     // mutator
	void reset();
private:
	int score_ = 0;
	vector<Card> hand_;
};


#endif /* defined(__straight_tofu__HumanPlayer__) */
