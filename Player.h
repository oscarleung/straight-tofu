#ifndef __straight_tofu__Player__
#define __straight_tofu__Player__

#include <vector>
#include <string>
#include "Card.h"
#include <iostream>
using namespace std;

class Player{
public:
	Player();
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
	vector<Card> discardPile_;
    int cardPos(Card) const;                // helper to find position of card
};

#endif /* defined(__straight_tofu__Player__) */
