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
	vector<Card> getPlays(vector<Card>);	// return valid plays
	void addScore(int);                     // mutator
	void reset();
	virtual void turn(vector<Card> &) = 0;
	void play(Card&, vector<Card> &);
private:
	int score_ = 0;
    vector<Card> hand_;
	vector<Card> discardPile_;
	bool active=true;
    int cardPos(Card) const;                // helper to find position of card
};

#endif /* defined(__straight_tofu__Player__) */
