#ifndef ACTIVEMINION_H
#define ACTIVEMINION_H
#include "minion.h"

class ActiveMinion : public Minion {
	protected:
	int abCost;
	std::string desc;
	public:
	ActiveMinion(std::string name, int cost, Player * o, Player * e
           ,int att, int def, int abCost, std::string desc);
	card_template_t makeTemplate(int newAtt, int newDef) override;
	card_template_t makeTemplate() override;
	virtual ~ActiveMinion()=0;

};
#endif
