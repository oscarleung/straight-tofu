#include <vector>
#include <string>
#include "Card.h"
#include "Player.h"

Player::Player() {
    
}
vector<Card> Player::getHand() const {
	return hand_;
}
int Player::getScore() const {
    return score_;
}
void Player::addCard(Card newCard) {
	hand_.push_back(newCard);
}
void Player::addHand(vector<Card> newHand) {
    hand_ = newHand;
}
void Player::addScore(int x) {
	score_ += x;
}
void Player::reset() {
    
}