#include "triggerminion.h"
using namespace std;
TriggerMinion::TriggerMinion(std::string name, int cost, Player * o, 
  Player * e, int att, int def, std::string desc) :
    Minion{name,cost,o,e,att,def}, desc{desc}{}


card_template_t TriggerMinion::makeTemplate() {
	return display_minion_triggered_ability(name,cost,att,def,desc);
}

card_template_t TriggerMinion::makeTemplate(int newAtt, int newDef ) {
        return display_minion_triggered_ability(name,cost,newAtt,newDef,desc);
}

TriggerMinion::~TriggerMinion(){}
