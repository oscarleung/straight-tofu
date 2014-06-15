#include "HumanPlayer.h"
#include "Card.h"
#include "Command.h"


HumanPlayer::HumanPlayer() :Player(){
    
}

void HumanPlayer::turn(vector<Card> &table)
{
	Command cmd;
	bool successfulPlay = false;
	vector<Card> legalPlays = getPlays(table);
	while (!successfulPlay)
	{
		cin >> cmd;
		switch (cmd.type)
		{
		case PLAY:
			if (find(legalPlays.begin(), legalPlays.end(), cmd.card) == legalPlays.end())
			{
				cout << "This is not a legal play." << endl;
			}
			else
			{
				play(cmd.card, table);
				successfulPlay = true;
			}
			break;
		case DISCARD:
			if (legalPlays.size() != 0)
			{
				cout << "You have a legal play. You may not discard." << endl;
			}
			else
			{
				discard(cmd.card);
				successfulPlay = true;
			}
			break;
		case DECK:
		case QUIT:
		case RAGEQUIT:
		case BAD_COMMAND:
		default:
			break;
		}
	}

}