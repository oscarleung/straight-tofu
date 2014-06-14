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
    bool findCard(Card) const;
	void addCard(Card);
    void addHand(vector<Card>);
	void addScore(int);
	void reset();
private:
	int score_ = 0;
    vector<Card> hand_;
	
};

#endif /* defined(__straight_tofu__Player__) */
