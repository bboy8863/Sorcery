#include "normalenchant.h"
using namespace std;

NormalEnchant::NormalEnchant(std::string name, int cost, Player * o, 
  Player * e, string desc) : Enchantment{name,cost,o,e}, desc{desc} {}

card_template_t NormalEnchant::makeTemplate() {
        if (component) {
                return component->makeTemplate(getAtt(),getDef());
        } else {
                return display_enchantment(name,cost,desc);
        }
}

card_template_t NormalEnchant::makeTemplate(int newAtt, int newDef) {
        return component->makeTemplate(newAtt,newDef);
}

card_template_t NormalEnchant::displaySelf() {
        return display_enchantment(name,cost,desc);
}

