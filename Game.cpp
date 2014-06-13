#include "Game.h"
#include <vector>
#include <iostream>
#include <string>
#include <cassert>
#include "Card.h"

void Game::init()
{
	deck.clear();
	for (int i = 0; i<=3;i++)
	{
		for (int j = 0; j <= 12; j++)
		{
			Card tempCard((Suit)i, (Rank)j);
			deck.push_back(tempCard);
		}
	}
	cout << "test - int" ;
    initPlayer();
}

void Game::initPlayer() {
    for (int i = 1; i<=4; i++) {
        cout << "Is player " << i << " a human(h) or a computer(c)?" << endl;
        char playerType;
        cin >> playerType;
        assert( playerType == 'h' || playerType == 'H' || playerType == 'c' || playerType == 'C' );
        if (playerType == 'h') {
            // make human player
        }
        if (playerType == 'c') {
            // make computer player
        }

    }
}

void Game::start()
{
	init();
	cout << "test - start";
}