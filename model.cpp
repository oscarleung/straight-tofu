#include "model.h"

Model::Model() {
	game_=new Game();
}
vector<Card> Model::getCardsInPlay() const
{
	return game_->getCardsInPlay();
}
vector<Card> Model::getActivePlayerValid() const
{
	return game_->getActiveValid();
}
vector<Card> Model::getActivePlayerHand() const
{
	return game_->getActiveHand();
}
void Model::progressUntilHuman()
{
    // process all following computer moves until a human player is reach
	game_->progressUntilHuman();
	notify();
}
bool Model::isActivePlayerHuman() const
{
	return game_->isActivePlayerHuman();
}
int Model::getActivePlayer() const
{
	return game_->getActivePlayerNo();
}
int Model::calcScore(int player)
{
    //calculate score and return the new score
    return game_->calcScore(player);
}
int Model::getScore(int player) const
{
    // accessor for player score
    return game_->getScore(player);
}
vector<Card> Model::getDiscard(int player) const
{
    return game_->getDiscard(player);
}
bool Model::roundOver()
{
    // check if round is over
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
    game_->convert();
}
vector<int> Model::getScores() const
{
    return game_->getPlayerScores();
}

vector<int> Model::getDiscards() const
{
    return game_->getPlayerDiscards();
}
