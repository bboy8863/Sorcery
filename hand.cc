#include "hand.h"

Hand::Hand(std::vector <Card *> vc): theHand{vc}, size{vc.size()} {}
void Hand::play(int i) {theHand[i]->play(); 
void Hand::play(int i, int j); {theHand[i]->play(j)};
void Hand::display() {} // code later 
void Hand::add(Card * cp) {
	if (size < 5) {
		theHand.emplace_back(cp)
	}
}
bool Hand::isFull() {return size == 5};
