#ifndef NORMALENCHAT_H
#define NORMALENCHAT_H
#include "enchantment.h"
class NormalEnchant : public Enchantment {
        protected:
        std::string desc;
        public:
        NormalEnchant(std::string name, int cost, Player * o, Player * e,
          std::string desc);
        card_template_t makeTemplate() override;
        card_template_t makeTemplate(int newAtt, int newDef) override;
	card_template_t displaySelf() override;	
};



#endif

