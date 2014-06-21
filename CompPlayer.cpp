#include "CompPlayer.h"
#include "Command.h"

CompPlayer::CompPlayer(int playerNo): Player(playerNo) {}

//copy constructor to allow conversion from Human to computer player easily
CompPlayer::CompPlayer(const Player &x) : Player(x){}

//Computer player turn implementation, AI just plays first possible play or discards first possible card if it has no plays
Command CompPlayer::turn(vector<Card> &table,bool print)
{
	Command cmd;
	vector<Card> validPlays = Player::getPlays(table);
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