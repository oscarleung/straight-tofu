#include "CompPlayer.h"
#include "Command.h"

CompPlayer::CompPlayer(int playerNo): Player(playerNo) {
    
}

CompPlayer::CompPlayer(int playerNo, vector<Card> hand, vector<Card> discard, int score) : Player(playerNo)
{
	hand_ = hand;
	discardPile_ = discard;
	score_ = score;
}
Command CompPlayer::turn(vector<Card> &table)
{
	Command cmd;
	vector<Card> validPlays = getPlays(table);
	if (validPlays.size() == 0)
	{
		cmd.type = DISCARD;
		cmd.card = hand_.at(0);
		//discard(hand_.at(0));
	}
	else{
		cmd.type = PLAY;
		cmd.card = validPlays.at(0);
		//play(validPlays[0],table);
	}
	return cmd;
}