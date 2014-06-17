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
	vector<Card> getHand() const;           // accessor
    bool hasCard(Card) const;
	void addCard(Card);                     // mutator
    void addHand(vector<Card>);             // mutator
	void addScore(int);                     // mutator
	void reset();
	void turn(vector<Card> &);
private:
};


#endif /* defined(__straight_tofu__HumanPlayer__) */
