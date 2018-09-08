#ifndef BOARD_H
#define BOARD_H
#include "player.h"
class Board {
	Player * p1;
	Player * p2;
	public:
	Board(Player * p1, Player * p2); 
	void display();
	void displayHand(Player * actp);
	void inspectMinion(Player * actp, int i);
};
#endif
