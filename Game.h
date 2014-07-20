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
    //void start(int seed=0);                         // (OLD) begin a new game
    void turn(Card c);
	void reset();
	void seed(int s);
	vector<Card> getActiveHand() const;
	vector<Card> getActiveValid() const;
	vector<Card> getCardsInPlay() const;
	vector<int> getPlayerScores() const;
	vector<int> getPlayerDiscards() const;
    vector<Card> getDiscard(int) const;
    int getScore(int) const;
	int getActivePlayerNo() const;
    int calcScore(int);
    void initPlayers(char list[]);               // create a list of player
    void initRound();               // create a list of player
    void progressUntilHuman();
    bool playersHaveCards() const;    // check players hand for end game
    bool isActivePlayerHuman() const;
    int winner();
    void convert();
private:
    void printDeck();
    vector<Card> table_;
    Deck gameDeck;
    Player* playerList[4];							//List of players
    int activePlayer;							//Active  player
    
};
