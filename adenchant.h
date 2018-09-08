#ifndef ADENCHANT_H
#define ADENCHANT_H

#include "enchantment.h" 
class Player;

class ADEnchant : public Enchantment {
	protected:
	int gainAtt, gainDef;
	std::string dAtt, dDef; //for display
	public: 
	ADEnchant(std::string name, int cost, Player * o, Player * e, 
	  int gainAtt, int gainDef, std::string dAtt, std::string dDef);
	card_template_t displaySelf() override;	
	card_template_t makeTemplate() override;
	card_template_t makeTemplate(int newAtt, int newDef) override;
	
};


#endif 
