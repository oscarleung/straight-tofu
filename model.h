#ifndef MVC_MODEL_H
#define MVC_MODEL_H

#include "subject.h"
#include "Game.h"

class Model : public Subject {
public:
    Model();
	vector<Card> getCardsInPlay() const;            // return all cards in play
	vector<Card> getActivePlayerHand() const;
	vector<Card> getActivePlayerValid() const;
    vector<int> getScores() const;                // return score of all player
	vector<int> getDiscards() const;              // return discard count of all player
    vector<Card> getDiscard(int) const;     // return the all discarded cards for a specific player
	bool isActivePlayerHuman() const;
	int getActivePlayer() const;
    int getScore(int) const;
    bool roundOver();                   // check if round is over
    int winnerFound();                  // return winner number
    int calcScore(int);                 // calculate score and return new score
    void initPlayers(char[]);
	void refreshRound();                // start a new round
	void progressUntilHuman();          // process all computer player until human player is reach
	void play(Card c);
	void end();
	void seed(int s);
	void rageCurrentPlayer();
private:
	Game* game_;
}; // Model


#endif
