#include "Game.h"

bool Game::playersHaveCards(Player* playerList[])               // check for end game where player is out of cards
{
    for (int i=0; i<4; i++) {
        if (playerList[i]->getHand().size() != 0) return true;
    }
	return false;
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

void Game::start(int seed)
{
    srand48(seed);
	int activePlayer = 0;
    Player* playerList [4];
    initPlayers(playerList);         // init all player once
    while (!cin.eof()) {
        gameDeck.shuffle();             // shuffle card at beginning of each round
        table_.clear();
        // deal the deck
        for (int i = 0; i<4; i++) {
            vector<Card> temp = gameDeck.getDeck();
            vector<Card> sub (temp.begin()+i*13, temp.begin()+(i+1)*13);
            playerList[i]->addHand(sub);
            
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
		bool print=true;
		while (playersHaveCards(playerList))
		{
			Command cmd =	playerList[activePlayer]->turn(table_,print);
			vector<Card> legalPlays = playerList[activePlayer]->getPlays(table_);
			print = true;
				switch (cmd.type)
				{
				case PLAY:
						playerList[activePlayer]->play(cmd.card, table_);
					break;
				case DISCARD:
						playerList[activePlayer]->discard(cmd.card);
					break;
				case DECK:
					gameDeck.printDeck();
					print = false;
					break;
				case QUIT:
                    for (int i=0; i<4; i++) {
                        delete playerList[i];
                    }
					exit(0);
					break;
				case RAGEQUIT:
				{
					Player* replaceHuman = new CompPlayer(*playerList[activePlayer]);
					delete playerList[activePlayer];
					playerList[activePlayer] = replaceHuman;
					playerList[activePlayer]->turn(table_);
					break;
				}
				case BAD_COMMAND:
				default:
					break;
				}
		
				if (cmd.type != RAGEQUIT && cmd.type != DECK)
				{
					if (activePlayer == 3)
						activePlayer = 0;
					else
						activePlayer++;
				}
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
                    // output winners
                    if (playerList[j]->getScore() == lowest) cout << "Player " << j + 1 << " wins!" << endl;
					delete playerList[j];
                }
                return;
            }
        }
    }
}