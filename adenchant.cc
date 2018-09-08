#include "adenchant.h"
#include <iostream>
#include "player.h"
#include "gameover.h"
using namespace std;


ADEnchant::ADEnchant(std::string name, int cost, Player * o, Player * e,
  int gainAtt, int gainDef, std::string dAtt, std::string dDef) :
	Enchantment{name,cost,o,e}, gainAtt{gainAtt}, gainDef{gainDef},
	dAtt{dAtt}, dDef{dDef}{}

card_template_t ADEnchant::makeTemplate() {
	if (component) {
		return component->makeTemplate(getAtt(),getDef());
	} else {
		return display_enchantment_attack_defence(name,cost,"",dAtt,dDef);
	}
}

card_template_t ADEnchant::makeTemplate(int newAtt, int newDef) {
	return component->makeTemplate(newAtt,newDef);
}


card_template_t ADEnchant::displaySelf() {
	return display_enchantment_attack_defence(name,cost,"",dAtt,dDef);
}

