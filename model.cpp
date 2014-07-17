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
int Model::calcScore(int player)
{
    return game_->calcScore(player);
}
int Model::getScore(int player) const
{
    return game_->getScore(player);
}
vector<Card> Model::getDiscard(int player) const
{
    return game_->getDiscard(player);
}
bool Model::roundOver()
{
    return !game_->playersHaveCards();
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
