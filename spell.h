#ifndef SPELL_H
#define SPELL_H

#include "card.h"
class Player;
class Spell : public Card {
	protected:
	std::string desc;
	public:
	Spell(std::string name, int cost,Player *o, Player * e, 
		std::string desc);
	card_template_t makeTemplate() override;
	virtual ~Spell()=0;
};
#endif
