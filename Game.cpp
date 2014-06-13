#include "Game.h"
#include <vector>
#include <iostream>
#include <string>
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
	cout << "test" ;
}

void Game::start()
{
	init();
	cout << "test";
}