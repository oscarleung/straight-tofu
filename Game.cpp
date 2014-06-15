#include "Game.h"
#include "Command.h"
#include <set>

void Game::printTable()
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
		cout << " " << i.getRank();
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
void Game::initDeck()
{
    // init the deck
	deck_.clear();
	for (int i = 0; i<=3;i++)
	{
		for (int j = 0; j <= 12; j++)
		{
			Card tempCard((Suit)i, (Rank)j);
			deck_.push_back(tempCard);
		}
	}
    
}

void Game::shuffleDeck() {
    // TODO shuffling
}

void Game::initPlayer(Player* list[]) {
    for (int i = 0; i<4; i++) {
        cout << "Is player " << i << " a human(h) or a computer(c)?" << endl;
        char playerType;
        cin >> playerType;
        assert( playerType == 'h' || playerType == 'H' || playerType == 'c' || playerType == 'C' );
        if (playerType == 'h' || playerType == 'H') {
            // make human player
            Player* p = new HumanPlayer();
            list[i] = p;
        }
        if (playerType == 'c' || playerType == 'C') {
            // make computer player
            Player* p = new CompPlayer();
            list[i] = p;
        }
        
    }
}

void Game::start()
{
	int activePlayer;
    Player* playerList [4];
    initPlayer(playerList);         // init all player once
    initDeck();                     // init the deck
    while (!cin.eof()) {
        shuffleDeck();
        
        // deal the deck
        for (int i = 0; i<4; i++) {
            vector<Card> temp (deck_.begin()+ (i)*13, deck_.begin()+ (i+1)*13);
            playerList[i]->addHand(temp);
            
        }
        // find starting person
        Card startCard(SPADE, SEVEN);
        for (int i = 0; i<4; i++) {
            if(playerList[i]->hasCard(startCard)) {
				activePlayer = i;
                cout << "A new round begins. It's player " << i+1 << "'s turn to play." << endl;
                break;
            }
        }
        // TODO play the game
		cout << "Cards on the table:"<<endl;
		printTable();
		cout << "Your hand:";
		for (Card c : playerList[activePlayer]->getHand())
		{
			cout <<" "<< c;
		}
		cout << endl;
		cout << "Legal Plays:";
		vector<Card> legalPlays = playerList[activePlayer]->getPlays(table_);
		for (Card c : legalPlays)
		{
			cout <<" "<< c;
		}
		cout << endl;
		playerList[activePlayer]->turn(table_);
	
        
        
        
        
        
        // temporary thing to add score so that it ends after 4 round.
        playerList[0]->addScore(20);
        
        // check if 80 point is reached
        for (int i = 0; i<4; i++) {
            if (playerList[i]->getScore() >= 80) {
                // game is over, find winner and print winner message
                int lowest = playerList[1]->getScore();
                for (int j=1; j<4; j++) {
                    if (playerList[j]->getScore() < lowest) lowest = playerList[j]->getScore();
                }
                for (int j=0; j<4; j++) {
                    if (playerList[j]->getScore() == lowest) cout << "Player " << j+1 << " wins!" << endl;
                }
                return;
            }
        }
    }
}