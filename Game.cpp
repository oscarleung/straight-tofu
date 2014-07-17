#include "Game.h"
namespace{
	void isInHand(Player* p,Card c){
		if (!p->hasCard(c))
		{
			throw runtime_error("This is not a legal play.");
		}
	}
}
bool Game::playersHaveCards()               // check for end game where player is out of cards
{
    for (int i=0; i<4; i++) {
        if (playerList[i]->getHand().size() != 0) return true;
    }
	return false;
}
vector<int> Game::getPlayerScores()             
{
	vector<int> scores;
    for (int i=0; i<4; i++) {
        scores.push_back(playerList[i]->getScore());
    }
	return scores;
}
vector<int> Game::getPlayerDiscards()              
{
	vector<int> discards;
    for (int i=0; i<4; i++) {
	  discards.push_back(playerList[i]->getNumDiscards());
    }
	return discards;
}
void Game::reset()
{
	for (int i = 0; i < 4; i++) {
		delete playerList[i];
	}
	activePlayer=-1;
    gameDeck.shuffle();  
	table_.clear();

}
vector<Card> Game::getActiveHand()
{
	return playerList[activePlayer]->getHand();
}
vector<Card> Game::getActiveValid()
{
	return playerList[activePlayer]->getPlays(table_);
}
vector<Card> Game::getCardsInPlay()
{
	return table_;
}
int Game::calcScore(int player)
{
    return playerList[player]->calcScore();
}
int Game::getScore(int player) const
{
    return playerList[player]->calcScore();
}
vector<Card> Game::getDiscard(int player) const
{
    return playerList[player]->getDiscard();
}
void Game::seed(int s)
{
	srand48(s);
}
void Game::initPlayers(char list[]) {
    
	gameDeck.reinit();
    for (int i = 0; i<4; i++) {
        if (list[i] == 'h'){
            // make human player
            Player* p = new HumanPlayer(i+1);
            playerList[i] = p;
        }
        if (list[i] == 'c'){
            // make computer player
            Player* p = new CompPlayer(i+1);
            playerList[i] = p;
        }
        
    }
}

void Game::initRound(){
    
    gameDeck.shuffle();             // shuffle card at beginning of each round
    table_.clear();
    for (int i = 0; i<4; i++) {
        vector<Card> temp = gameDeck.getDeck();
        vector<Card> sub (temp.begin()+i*13, temp.begin()+(i+1)*13);
        playerList[i]->addHand(sub);
    }
    Card startCard(SPADE, SEVEN);
    for (int i = 0; i<4; i++) {
        if(playerList[i]->hasCard(startCard)) {
            activePlayer = i;
            cout << "A new round begins. It's player " << i+1 << "'s turn to play." << endl;
            break;
        }
    }
}

void Game::turn(Card c)
{
	vector<Card> validPlays=playerList[activePlayer]->getPlays(table_);
	if(validPlays.size()==0)
	{
		playerList[activePlayer]->discard(c);
	}
	else
	{
		playerList[activePlayer]->play(c, table_);
	}
	if (activePlayer == 3)
		activePlayer = 0;
	else
		activePlayer++;
}
int Game::getActivePlayerNo()
{
	return activePlayer;
}
void Game::start(int seed)
{
    while (!cin.eof()) {
        // deal the deck
        // find starting person
        // play the game
		bool print=true;
		bool incPlayer=true;
		Command cmd;
		while (playersHaveCards())
		{
			try
			{
                cmd = playerList[activePlayer]->turn(table_, print);
                print = true;
                switch (cmd.type)
                {
					case PLAY:
						isInHand(playerList[activePlayer], cmd.card);
						playerList[activePlayer]->play(cmd.card, table_);
						incPlayer = true;
						break;
					case DISCARD:
						isInHand(playerList[activePlayer], cmd.card);
						playerList[activePlayer]->discard(cmd.card);
						incPlayer = true;
						break;
					case DECK:
						gameDeck.printDeck();
						print = false;
						incPlayer = false;
						break;
					case QUIT:
						for (int i = 0; i < 4; i++) {
							delete playerList[i];
						}
						exit(0);
						break;
					case RAGEQUIT:
					{
                        Player* replaceHuman = new CompPlayer(*playerList[activePlayer]);
                        delete playerList[activePlayer];
                        playerList[activePlayer] = replaceHuman;
                        cout << "Player " << activePlayer + 1 << " ragequits. A computer will now take over." << endl;
                        playerList[activePlayer]->turn(table_);
                        break;
					}
					case BAD_COMMAND:
					default:
						break;
                }
                if ((cmd.type != RAGEQUIT && cmd.type != DECK)||(!print && cmd.type==PLAY)||(!print && cmd.type==DISCARD))
                {
                    if (activePlayer == 3)
                        activePlayer = 0;
                    else
                        activePlayer++;
                }
            }
            catch (runtime_error e)
            {
                cout << e.what() << endl;
                print = false;
                incPlayer = false;
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
