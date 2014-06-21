#ifndef __straight_tofu__CompPlayer__
#define __straight_tofu__CompPlayer__

#include <vector>
#include "Card.h"
#include "Player.h"
using namespace std;

class CompPlayer: public Player{
public:
	CompPlayer(int);								//Constructor sets player number
	explicit CompPlayer(const Player &);			//Copy constructor to allow conversion from human to computer player
	Command turn(vector<Card> &,bool print=false);	//Computer player turn implementation
private:
	vector<Card> getPlays(vector<Card>) const;	// return valid plays
	vector<Card> hand_;						// stores all cards in a players hand
	vector<Card> discardPile_;				// keeps track of the discards for a player in a given round
	int score_ = 0;							// keeps track of score
	int playerNumber_;
};


#endif /* defined(__straight_tofu__CompPlayer__) */
