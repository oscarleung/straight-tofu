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
bool Player::findCard(Card target) const {
    for (int i=0; i < hand_.size(); i++) {
        if (hand_.at(i).getRank() == target.getRank() && hand_.at(i).getSuit() == target.getSuit()) {
            return true;
        }
    }
    return false;
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