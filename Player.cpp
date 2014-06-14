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

int Player::cardPos(Card target) const {
    for (int i=0; i < hand_.size(); i++) {
        if (hand_.at(i) == target) {
            return i;
        }
    }
    // not founds
    return (int)hand_.size();
}

bool Player::hasCard(Card target) const {
    if (cardPos(target) < hand_.size()) return true;
    return false;
}
void Player::addCard(Card newCard) {
	hand_.push_back(newCard);
}
void Player::discard(Card target) {
    int pos = cardPos(target);                  // get position of discard target
    hand_.erase(hand_.begin() + pos);
    discardPile_.push_back(target);
    return;
}
void Player::addHand(vector<Card> newHand) {
    hand_ = newHand;
}
void Player::addScore(int x) {
	score_ += x;
}
void Player::reset() {
    
}