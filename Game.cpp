#include "Game.h"
#include "Command.h"
#include <set>

bool Game::playersHaveCards(Player* playerList[])
{
    for (int i=0; i<4; i++) {
        if (playerList[i]->getHand().size() != 0) return true;
    }
	return false;
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
    // shuffling
    int n = 52;
    
	while ( n > 1 ) {
		int k = (int) (lrand48() % n);
		--n;
		Card c = deck_[n];
		deck_[n] = deck_[k];
		deck_[k] = c;
	}
}

void Game::initPlayers(Player* list[]) {
    for (int i = 0; i<4; i++) {
        cout << "Is player " << i+1 << " a human(h) or a computer(c)?" << endl;
        char playerType;
        cin >> playerType;
        assert( playerType == 'h' || playerType == 'H' || playerType == 'c' || playerType == 'C' );
        if (playerType == 'h' || playerType == 'H') {
            // make human player
            Player* p = new HumanPlayer(i+1);
            list[i] = p;
        }
        if (playerType == 'c' || playerType == 'C') {
            // make computer player
            Player* p = new CompPlayer(i+1);
            list[i] = p;
        }
        
    }
}

void Game::start()
{
	int activePlayer = 0;
    Player* playerList [4];
    initPlayers(playerList);         // init all player once
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
        // play the game
		while (playersHaveCards(playerList))
		{

			try{
				playerList[activePlayer]->turn(table_);
			}
			catch (ragequit_exception e)
			{
				delete playerList[activePlayer];
				playerList[activePlayer] = new CompPlayer(activePlayer,e.hand_, e.discard_, e.score_);
				playerList[activePlayer]->turn(table_);
			}
			
			if (activePlayer == 3)
				activePlayer = 0;
			else
				activePlayer++;
		}
        
        // round end, calculate score
        for (int i = 0; i < 4; i++) {
            playerList[i]->doScoring();
        }
        for (int i=0; i<4; i++) {               // check for end game
            if (playerList[i]->getScore() >= 80) {
                // game is over, find winner and print winner message
                int lowest = playerList[0]->getScore();
                for (int j = 1; j < 4; j++) {
                    if (playerList[j]->getScore() < lowest) lowest = playerList[j]->getScore();
                }
                for (int j = 0; j < 4; j++) {
                    if (playerList[j]->getScore() == lowest) cout << "Player " << j + 1 << " wins!" << endl;
                }
                return;
            }
        }
    }
}