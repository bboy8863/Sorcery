#include "card.h"

using namespace std;

Card::Card(string name, int cost, Player * o, Player * e): 
  name{name}, cost{cost}, o{o}, e{e} {}

int Card::getCost() {return cost;}

Card::~Card(){}
