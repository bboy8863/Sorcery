#ifndef DECK_H
#define DECK_H 

#include "card.h"
#include <vector>
class Deck {
	std::vector <Card*> theDeck;
	public: 
	Card * top();
	//void shuffle();
	~Deck();
#endif
