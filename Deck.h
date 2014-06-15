#ifndef __straight_tofu__Deck__
#define __straight_tofu__Deck__

#include <iostream>
#include <vector>
#include "Card.h"
using namespace std;

class Deck{
public:
	Deck();
    void shuffle();
    void printDeck() const;
    vector<Card> getDeck() const;
	
private:
	vector<Card> deck_;
    const int CARD_COUNT = 52;
};

#endif /* defined(__straight_tofu__Deck__) */
