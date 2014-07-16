#include "model.h"

Model::Model() {
	game_=new Game();
}
vector<Card> Model::getCardsInPlay()
{
	return game_->getCardsInPlay();
}
vector<Card> Model::getActivePlayerHand()
{
	return game_->getActiveHand();
}
void Model::start(int x)
{
	game_->start();
	notify();
}
void Model::end()
{
}
void Model::rageCurrentPlayer()
{
}
vector<Card> getActiveHand()
{
vector<Card> x;
return x;
}
