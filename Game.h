#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "CompPlayer.h"
#include "Command.h"

using namespace std;

class Game{
public:
    void start(int seed=0);                         // begin a new game
	void turn(Card c);
	void reset();
	vector<Card> getActiveHand();
	vector<Card> getActiveValid();
	vector<Card> getCardsInPlay();
	vector<int> getPlayerScores();
	vector<int> getPlayerDiscards();
    int calcScore(int);
    int getScore(int) const;
    vector<Card> getDiscard(int) const;
    void initPlayers(char list[]);               // create a list of player
    void initRound();               // create a list of player
	int getActivePlayerNo();
    bool playersHaveCards();    // check players hand for end game
private:
    void printDeck();
    vector<Card> table_;
    Deck gameDeck;
    Player* playerList[4];							//List of players
    int activePlayer;							//Active  player
    
};
