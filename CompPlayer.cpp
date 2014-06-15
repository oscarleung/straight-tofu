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
	cout << "computer turn" << endl;
}