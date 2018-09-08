#ifndef HAND_H
#define HAND_H

#include "card.h"
#include <vector>
class Hand {
	std::vector <Card*> theHand;
	int size;
	public:
	Hand(std::vector <Card *> vc);
	void play(int i);
	void play(int i, int j); // i for i th card in hand
				// j: positive cards are you cards,
				// negative for opponent, 6 for ritual
	void display();
	void add(Card * cp);
	bool isFull();
		
	
#endif
