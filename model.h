#ifndef MVC_MODEL_H
#define MVC_MODEL_H

#include "subject.h"
#include "Game.h"

class Model : public Subject {
public:
    Model();
	void start(int x=0);
	void rageCurrentPlayer();
	void end();
	vector<Card> getActiveHand();
private:
	Game* game_;
}; // Model


#endif
