#include "CompPlayer.h"
#include "Command.h"

CompPlayer::CompPlayer(int playerNo): Player(playerNo) {
}

//copy constructor to allow conversion from Human to computer player easily
CompPlayer::CompPlayer(const Player &x) : Player(x){
}
bool CompPlayer::isHuman()
{
	return false;
}
//Computer player turn implementation, AI just plays first possible play or discards first possible card if it has no plays
Command CompPlayer::turn(vector<Card> &table,bool print)
{
	Command cmd;
	vector<Card> validPlays = Player::getPlays(table);
	vector<Card> hand_= getHand();
	if (validPlays.size() == 0)
	{
		cmd.type = DISCARD;
		cmd.card = hand_.at(0);
        for (int i=1; i < hand_.size(); i++) {
            if (hand_.at(i).getRank() < cmd.card.getRank()) {
                cmd.card = hand_.at(i);
            }
        }
	}
	else{
		cmd.type = PLAY;
		cmd.card = validPlays.at(0);
        for (int i=0; i < validPlays.size(); i++) {
            if (cmd.card.getRank() < validPlays.at(i).getRank()) {
                cmd.card = validPlays.at(i);
            }
        }
	}
	return cmd;
}
