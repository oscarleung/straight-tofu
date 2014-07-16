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
	int getActivePlayer();
	void initPlayers(char[]);
	void play(Card c);
	void rageCurrentPlayer();
	void end();
	vector<Card> getActiveHand();
private:
	Game* game_;
}; // Model


#endif
