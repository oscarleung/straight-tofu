#include "Player.h"

using namespace std;

Player::Player() {
    
}
vector<Card> Player::getHand() const {
	return hand_;
}
int Player::getScore() const {
    return score_;
}

bool Player::hasCard(Card target) const {
    for (int i=0; i < hand_.size(); i++) {
        if (hand_.at(i) == target) {
            return true;
        }
    }
    return false;
}
void Player::addCard(Card newCard) {
	hand_.push_back(newCard);
}
void Player::discard(Card target) {
    // TODO the following two lines are repeating hasCard
    for (int i=0; i < hand_.size(); i++) {
        if (hand_.at(i) == target) {
            hand_.erase(hand_.begin()+i);
            discardPile_.push_back(target);
            return;
        }
    }
}
void Player::addHand(vector<Card> newHand) {
    hand_ = newHand;
}
void Player::addScore(int x) {
	score_ += x;
}
void Player::reset() {
    
}