#include "Command.h"
#include <cassert>
#include <sstream>
#include <vector>
using namespace std;

istream &operator>>(istream &in, Command &c){
	c.type = BAD_COMMAND;
	
	string cmd;
	in >> cmd;
	
	if (cmd == "play") {
		c.type = PLAY;
		in >> c.card;
	} else if (cmd == "discard") {
		c.type = DISCARD;
		in >> c.card;
	} else if (cmd == "deck") {
		c.type = DECK;
	} else if (cmd == "quit") {
		c.type = QUIT;
	} else if (cmd == "ragequit") {
		c.type = RAGEQUIT;
	}
	
	assert(!in.fail() && c.type != BAD_COMMAND);
	
	return in;
}

bool isValidCommand(Command cmd, vector<Card> x)
{
	switch (cmd.type)
	{
	case PLAY:
	default:
		break;
	}
	return true;
}