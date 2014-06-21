#include "Player.h"

using namespace std;
namespace{
	//helper function to check if a card is a valid play
	bool isPlayable(Card inPlay, Card inHand)
	{
		if (inHand.getRank() == SEVEN)
		{
			return true;
		}
		if (inHand.getSuit() == inPlay.getSuit())
		{
			if (inHand.getRank() == (Rank)(inPlay.getRank() + 1) || (inHand.getRank() == (Rank)(inPlay.getRank() - 1)))
			{
				return true;
			}
		}
		return false;
	}
}
//contructor to set a player number on construction
Player::Player(int num) {
	playerNumber_ = num;
}
//Accessor
vector<Card> Player::getHand() const {
	return hand_;
}
//Accessor
vector<Card> Player::getDiscards() const {
	return discardPile_;
}
//Accessor
int Player::getScore() const {
    return score_;
}
//prints scores and discard pile for end of round
void Player::doScoring() {
    int roundScore = 0;
    cout << "Player " << playerNumber_ << "'s discards:";
    for (int i=0; i < discardPile_.size(); i++) {
        cout << " " << discardPile_.at(i);
        roundScore += discardPile_.at(i).getRank()+1;
    }
    cout << endl;
    int newScore = score_ + roundScore;
    cout << "Player " << playerNumber_ << "'s score: " << score_ << " + " << roundScore << " = " << newScore << endl;
    score_ = newScore;
    discardPile_.clear();
}
//get the 
int Player::cardPos(Card target) const {
    for (int i=0; i < hand_.size(); i++) {
        if (hand_.at(i) == target) {
            return i;
        }
    }
    // not found
    return (int)hand_.size();
}

bool Player::hasCard(Card target) const {
    if (cardPos(target) < hand_.size()) return true;
    return false;
}
//Mutator adds card to hand
void Player::addCard(Card newCard) {
	hand_.push_back(newCard);
}
//Mutator removes card from hand, adds it to discard, prints message
void Player::discard(Card target) {
    int pos = cardPos(target);                  // get position of discard target
    hand_.erase(hand_.begin() + pos);
    discardPile_.push_back(target);
	cout << "Player " << playerNumber_ << " discards " << target << "." << endl;
}
//Mutator for hand
void Player::addHand(vector<Card> newHand) {
    hand_ = newHand;
}
//Mutator for score
void Player::addScore(int amountToAdd) {
	score_ += amountToAdd;
}

//returns a list of valid plays 
vector<Card> Player::getPlays(vector<Card> inPlay) const
{
	vector<Card> plays;
    if (inPlay.size()== 0)
	{
		plays.push_back(Card(SPADE,SEVEN));
		return plays;
	}

	for (int i = 0; i < hand_.size(); i++)
	{
		for (int j = 0; j < inPlay.size(); j++)
		{
			if (isPlayable(inPlay[j], hand_[i]))
			{
				plays.push_back(hand_[i]);
                break;
			}
		}
	}

	return plays;
}
//Mutator, removes card from hand, adds it to set of cards in play, prints message
void Player::play(Card &c, vector<Card> &table)
{
    table.push_back(c);
	hand_.erase(find(hand_.begin(),hand_.end(),c));
	cout << "Player " << playerNumber_ << " plays " << c << "." << endl;

}
