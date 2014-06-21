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
};


#endif /* defined(__straight_tofu__CompPlayer__) */
