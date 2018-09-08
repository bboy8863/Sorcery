#ifndef CARD_H
#define CARD_H
#include <memory>
#include <string>
#include "ascii_graphics.h"
class Player;

class Card {
	protected:
	std::string name;
	int cost;
	Player * o; // owner
	Player * e; // ememy
	public:
	Card(std::string name, int cost, Player * o, Player * e);
	int getCost();
	virtual void play(std::shared_ptr<Card> self)=0;
	virtual card_template_t makeTemplate()=0; 
	virtual void play(int i, std::shared_ptr<Card> self)=0;
	virtual	~Card()=0;
};


#endif
