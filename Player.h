#include <vector>
#include <string>
#include "Card.h"

using namespace std;

class Player{
public:
	Player();
	void addCard(Card);
	vector<Card> getHand() const;
	void addScore(int);
	void reset();
private:
	int score=0;
	vector<Card> hand;
};
