#ifndef __straight_tofu__CompPlayer__
#define __straight_tofu__CompPlayer__

#include <vector>
#include "Card.h"
#include "Player.h"

using namespace std;

class CompPlayer: public Player{
public:
	CompPlayer(int);
	CompPlayer(int,vector<Card>, vector<Card>, int);
	void turn(vector<Card> &);
private:
};


#endif /* defined(__straight_tofu__CompPlayer__) */
