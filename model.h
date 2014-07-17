#ifndef MVC_MODEL_H
#define MVC_MODEL_H

#include "subject.h"
#include "Game.h"

class Model : public Subject {
public:
    Model();
	vector<Card> getCardsInPlay();
	vector<Card> getActivePlayerHand();
	vector<Card> getActivePlayerValid();
	vector<int> getScores();
	vector<int> getDiscards();
	int getActivePlayer();
	void initPlayers(char[]);
	void play(Card c);
	void rageCurrentPlayer();
	vector<Card> getActiveHand();
    bool roundOver();
    int calcScore(int);
    int getScore(int) const;
    vector<Card> getDiscard(int) const;
private:
	Game* game_;
}; // Model


#endif
