#include "CompPlayer.h"


CompPlayer::CompPlayer(int playerNo): Player(playerNo) {
    
}

CompPlayer::CompPlayer(int playerNo, vector<Card> hand, vector<Card> discard, int score) : Player(playerNo)
{
	hand_ = hand;
	discardPile_ = discard;
	score_ = score;
}
void CompPlayer::turn(vector<Card> &table)
{
	vector<Card> validPlays = getPlays(table);
	if (validPlays.size() == 0)
	{
		discard(hand_.at(0));
	}
	else{
		play(validPlays[0],table);
	}
}