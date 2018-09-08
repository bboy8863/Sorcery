#ifndef TRIGGERMINION_H
#define TRIGGERMINION_H
#include "minion.h"
class Player;
class TriggerMinion : public Minion {
	std::string desc;
	public:
	TriggerMinion(std::string name, int cost, Player * o, Player * e,
	  int att, int def, std::string desc); 
	card_template_t makeTemplate() override;  	
	card_template_t makeTemplate(int newAtt, int newDef) override;
	virtual ~TriggerMinion()=0;
};
#endif
