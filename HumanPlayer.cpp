#include "HumanPlayer.h"

namespace{
	//helper function to print the current cards in play, with the required formatting
	void printTable(vector<Card> table_)
	{
		set<Card> clubs;
		set<Card> diamonds;
		set<Card> hearts;
		set<Card> spades;
		for (int i = 0; i < table_.size(); i++)
		{
            if (table_[i].getSuit() == CLUB)
				clubs.insert(table_[i]);
			else if (table_[i].getSuit() == DIAMOND)
				diamonds.insert(table_[i]);
			else if (table_[i].getSuit() == HEART)
				hearts.insert(table_[i]);
			else
				spades.insert(table_[i]);
		}
		cout << "Clubs:";
		for (Card i : clubs)
		{
			cout << " " << i.getStrRank();
		}
		cout << endl;
		cout << "Diamonds:";
		for (Card i : diamonds)
		{
			cout << " " << i.getStrRank();
		}
		cout << endl;
		cout << "Hearts:";
		for (Card i : hearts)
		{
			cout << " " << i.getStrRank();
		}
		cout << endl;
		cout << "Spades:";
		for (Card i : spades)
		{
			cout << " " << i.getStrRank();
		}
		cout << endl;
	}
}
//Human player constructor uses base constructor(just sets player  number)
HumanPlayer::HumanPlayer(int playerNo) :Player(playerNo){}

//Human plyer turn implementation
Command HumanPlayer::turn(vector<Card> &table,bool print)
{
	vector<Card> legalPlays = Player::getPlays(table);
	//conditional print required for when "DECK" command is called
	if (print)
	{
		cout << "Cards on the table:" << endl;
		printTable(table);
		cout << "Your hand:";
		for (Card c : hand_)
		{
			cout << " " << c;
		}
		cout << endl;
		cout << "Legal Plays:";
		for (Card c : legalPlays)
		{
			cout << " " << c;
		}
		cout << endl;
	}
	Command cmd;
	bool successfulPlay = false;
	//get Command from player input, loop until valid command is given
	while (!successfulPlay)
	{
		cin >> cmd;
		switch (cmd.type)
		{
		case PLAY:
			if (find(legalPlays.begin(), legalPlays.end(), cmd.card) == legalPlays.end())
			{
				throw runtime_error("This is not a legal play.");
			}
			else
			{
				successfulPlay = true;
			}
			break;
		case DISCARD:
			if (legalPlays.size() != 0)
			{
				throw runtime_error("You have a legal play. You may not discard.");
			}
			else
			{
				successfulPlay = true;
			}
			break;
		case DECK:
			successfulPlay = true;
            break;
		case QUIT:
			break;
		case RAGEQUIT:
			successfulPlay = true;
			break;
		case BAD_COMMAND:
		default:
			break;
		}
	}
	return cmd;
}