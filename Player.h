#ifndef __straight_tofu__Player__
#define __straight_tofu__Player__

#include <vector>
#include "Card.h"
#include "Command.h"
#include <iostream>
using namespace std;

class Player{
public:
	Player(int);							//contructor sets player player number
    virtual ~Player() {}					//detructor
    int getScore() const;                   //accessor
    void doScoring() ;						//prints scores and discard pile for end of round
	vector<Card> getHand() const;           // accessor
    bool hasCard(Card) const;				// checks for valid plays
    void discard(Card);                     // mutator
    void addHand(vector<Card>);             // mutator
	virtual Command turn(vector<Card> &,bool print=true) = 0;	//begins a players turn. Implementation depends on type of derived class
	void play(Card&, vector<Card> &);		// mutator, removes card from hand, adds it to set of cards in play
	vector<Card> getPlays(vector<Card>) const;	// return valid plays
private:
	vector<Card> hand_;						// stores all cards in a players hand
	vector<Card> discardPile_;				// keeps track of the discards for a player in a given round
	int score_ ;							// keeps track of score
	int playerNumber_;						
protected:
	int cardPos(Card) const;
	
};

#endif /* defined(__straight_tofu__Player__) */
