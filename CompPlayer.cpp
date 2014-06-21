#include "CompPlayer.h"
#include "Command.h"

CompPlayer::CompPlayer(int playerNo): Player(playerNo) {
    
}
CompPlayer::CompPlayer(const Player &x) : Player(x){}

Command CompPlayer::turn(vector<Card> &table,bool print)
{
	Command cmd;
	vector<Card> validPlays = getPlays(table);
	if (validPlays.size() == 0)
	{
		cmd.type = DISCARD;
		cmd.card = hand_.at(0);
	}
	else{
		cmd.type = PLAY;
		cmd.card = validPlays.at(0);
	}
	return cmd;
}