#include "Game.h"
#include <vector>
#include <iostream>
#include <string>
#include <cassert>

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
    // TODO shuffling the deck
	
    
}

void Game::initPlayer(Player* list[]) {
    for (int i = 1; i<=4; i++) {
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
    Player* playerList [4];
    initPlayer(playerList);       // init all player once
    
	initDeck();             // init the deck and shuffle
    
    // deal the deck
    for (int i = 1; i<=4; i++) {
        vector<Card> temp (deck_.begin()+ (i-1)*13, deck_.begin()+ i*13);
        playerList[i]->addHand(temp);
        
        for( int j=0; j<13; j++) {
            cout << playerList[i]->getHand().at(j) << ' ';
        }
        cout << endl;
    }
    Card startCard(SPADE, SEVEN);
    for (int i = 1; i<=4; i++) {
        if(playerList[i]->findCard(startCard)) {
            cout << "A new round begins. It's player " << i << "'s turn to play." << endl;
            break;
        }
    }
	
}