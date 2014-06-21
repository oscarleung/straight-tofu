#ifndef __straight_tofu__Deck__
#define __straight_tofu__Deck__

#include <iostream>
#include <vector>
#include "Card.h"
using namespace std;

class Deck{
public:
	Deck();                         // constructor
    void shuffle();                 // shuffle function
    void printDeck() const;         // print entire deck
    vector<Card> getDeck() const;   // return deck as vector
	
private:
	vector<Card> deck_;
    const int CARD_COUNT = 52;      // constant card count at 52
};

#endif /* defined(__straight_tofu__Deck__) */
