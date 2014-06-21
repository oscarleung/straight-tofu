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
	Command turn(vector<Card> &,bool print=false);
private:
};


#endif /* defined(__straight_tofu__CompPlayer__) */
