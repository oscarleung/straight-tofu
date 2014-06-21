#ifndef __straight_tofu__CompPlayer__
#define __straight_tofu__CompPlayer__

#include <vector>
#include "Card.h"
#include "Player.h"
using namespace std;

class CompPlayer: public Player{
public:
	CompPlayer(int);
	explicit CompPlayer(const Player &);
	Command turn(vector<Card> &,bool print=false);
private:
};


#endif /* defined(__straight_tofu__CompPlayer__) */
