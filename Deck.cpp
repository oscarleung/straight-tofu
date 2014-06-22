#include "Deck.h"


Deck::Deck() :CARD_COUNT(52)
{
    // give deck 52 cards
	for (int i = 0; i<=3;i++)
	{
		for (int j = 0; j <= 12; j++)
		{
			Card tempCard((Suit)i, (Rank)j);
            deck_.push_back(tempCard);
		}
	}
    
}

void Deck::shuffle() {
    // shuffling
    int n = CARD_COUNT;
    
	while ( n > 1 ) {
		int k = (int)(lrand48() % n);
		--n;
		Card c = deck_[n];
		deck_[n] = deck_[k];
		deck_[k] = c;
	}
    
}

void Deck::printDeck() const {
    for (int j=0; j<4; j++) {
        for (int i=0; i<13; i++) {
            cout << deck_[i+(13*j)] << " ";
        }
        cout << endl;
    }
}

vector<Card> Deck::getDeck() const {
    return deck_;
}