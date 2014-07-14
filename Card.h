#ifndef _CARD_
#define _CARD_

#include <ostream>
#include <istream>
#include <string>
#include "model.h"
class Card{
	friend std::istream &operator>>(std::istream &, Card &);

public:
	Card(Suit, Rank);
	Suit getSuit() const;
	Rank getRank() const;
	std::string getStrRank() const;
	
private:
	Suit suit_;
	Rank rank_;
};

bool operator==(const Card &, const Card &);
bool operator<(const Card &,const Card&);
//output/input Card in the format <rank><suit>
std::ostream &operator<<(std::ostream &, const Card &);
std::istream &operator>>(std::istream &, Card &);

#endif
