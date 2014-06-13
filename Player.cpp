#include <vector>
#include <string>
#include "Card.h"
#include "Player.h"

Player::Player()
{

}

void Player::addCard(Card newCard)
{
	hand.push_back(newCard);
}
vector<Card> Player::getHand() const
{
	return hand;
}
void Player::addScore(int x)
{
	score += x;
}
void Player::reset()
{

}