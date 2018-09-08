#include "activeminion.h"

ActiveMinion::ActiveMinion(std::string name, int cost, Player * o, Player * e
           ,int att, int def, int abCost, std::string desc) :
	Minion{name,cost,o,e,att,def}, abCost{abCost}, desc{desc} {}

card_template_t ActiveMinion::makeTemplate(int newAtt, int newDef) {
	return display_minion_activated_ability(name, cost,newAtt,newDef,abCost,desc);
}

card_template_t ActiveMinion::makeTemplate() {
	return display_minion_activated_ability(name, cost,att,def,abCost,desc);
}

ActiveMinion::~ActiveMinion() {}
