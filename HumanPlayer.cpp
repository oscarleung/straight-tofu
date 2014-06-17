#include "HumanPlayer.h"

namespace{
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
HumanPlayer::HumanPlayer(int playerNo) :Player(playerNo){
    
}

Command HumanPlayer::turn(vector<Card> &table)
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
	vector<Card> legalPlays = getPlays(table);
	for (Card c : legalPlays)
	{
		cout << " " << c;
	}
	cout << endl;
	Command cmd;
	bool successfulPlay = false;
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
				//play(cmd.card, table);
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
				//discard(cmd.card);
				successfulPlay = true;
			}
			break;
		case DECK:
			successfulPlay = true;
            // this is not printing.. needs a deck object,
            // i guess u could do a throw.. and exception...
            //Deck::printDeck();
            break;
		case QUIT:
			exit(0);
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