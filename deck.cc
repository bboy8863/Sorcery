#include "deck.h"

Card * Deck::top() {
	Card * cp = theDeck.back();
	theDeck.pop_back();
	return cp;
}

Deck::~Deck() {
	for (auto &cp : theDeck) {delete cp;}
}

bool Deck::isEmpty() {return theDeck.size == 0} 
