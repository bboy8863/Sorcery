#include "spell.h"

Spell::Spell(std::string name, int cost,Player *o, Player * e,
                std::string desc): Card{name, cost, o, e}, desc{desc} {}

card_template_t Spell::makeTemplate(){
	return display_spell(name,cost,desc);
}

Spell::~Spell() {} 
