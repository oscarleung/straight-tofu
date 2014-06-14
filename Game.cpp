#include "Game.h"

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
    Player* playerList [4];
    initPlayer(playerList);       // init all player once
    while (!cin.eof()) {
        initDeck();             // init the deck and shuffle
        
        // deal the deck
        for (int i = 0; i<4; i++) {
            vector<Card> temp (deck_.begin()+ (i)*13, deck_.begin()+ (i+1)*13);
            playerList[i]->addHand(temp);
            
            for( int j=0; j<13; j++) {
                cout << playerList[i]->getHand().at(j) << ' ';
            }
            cout << endl;
        }
        // find starting person
        Card startCard(SPADE, SEVEN);
        for (int i = 0; i<4; i++) {
            if(playerList[i]->findCard(startCard)) {
                cout << "A new round begins. It's player " << i+1 << "'s turn to play." << endl;
                break;
            }
        }
        
        // TODO play the game
        
        
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