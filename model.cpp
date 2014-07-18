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
void Model::progressUntilHuman()
{
	game_->progressUntilHuman();
	notify();
}
bool Model::isActivePlayerHuman()
{
	return game_->isActivePlayerHuman();
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
void Model::end()
{
	game_->reset();
	notify();
}
void Model::seed(int s)
{
	game_->seed(s);
}
void Model::play(Card c)
{
	game_->turn(c);
	notify();
}
int Model::winnerFound()
{
    return game_->winner();
}
void Model::initPlayers(char playerType[])
{
	game_->initPlayers(playerType);
	game_->initRound();
	notify();
}
void Model::refreshRound()
{
	game_->initRound();
}
void Model::rageCurrentPlayer()
{
    
}
vector<int> Model::getScores()
{
    return game_->getPlayerScores();
}

vector<int> Model::getDiscards()
{
    return game_->getPlayerDiscards();
}
