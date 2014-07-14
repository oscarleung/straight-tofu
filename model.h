#ifndef MVC_MODEL_H
#define MVC_MODEL_H

#include "subject.h"

enum Suit { CLUB, DIAMOND, HEART, SPADE, SUIT_COUNT };
enum Rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
			EIGHT, NINE, TEN, JACK, QUEEN, KING, RANK_COUNT };

class Model : public Subject {
public:
    Model();
private:
    int topCard_;
}; // Model


#endif
