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
	CompPlayer(int);
	CompPlayer(int,vector<Card>, vector<Card>, int);
	vector<Card> getHand() const;           // accessor
    bool hasCard(Card) const;
	void addCard(Card);                     // mutator
    void addHand(vector<Card>);             // mutator
	void addScore(int);                     // mutator
	void reset();
	void turn(vector<Card> &);
private:
};


#endif /* defined(__straight_tofu__CompPlayer__) */
