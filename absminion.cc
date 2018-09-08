#include "absminion.h"
#include "player.h"

AbsMinion:: AbsMinion(std::string name, int cost, Player * o, Player * e) :
  Card{name,cost,o,e} {}

AbsMinion::~AbsMinion(){}
