#include "model.h"

Model::Model() {
	game_=new Game();
}
vector<Card> Model::getCardsInPlay()
{
	return game_->getCardsInPlay();
}
vector<Card> Model::getActivePlayerValid()
{
	return game_->getActiveValid();
}
vector<Card> Model::getActivePlayerHand()
{
	return game_->getActiveHand();
}
int Model::getActivePlayer()
{
	return game_->getActivePlayerNo();
}
bool Mode::roundOver()
{
    //return game_->();
}

void Model::play(Card c)
{
	game_->turn(c);
	notify();
}
void Model::initPlayers(char playerType[])
{
	game_->initPlayers(playerType);
	game_->initRound();
	notify();
}
void Model::rageCurrentPlayer()
{
    
}
vector<Card> getActiveHand()
{
    vector<Card> x;
    return x;
}
