#include "esingles.h"
#include <iostream>
using namespace std;
GiantStrength::GiantStrength(Player * o, Player * e) :
  ADEnchant{"Giant Strength", 1, o,e,2,2,"+2","+2"}{}

int GiantStrength::getAtt() {
	return component->getAtt()+2;
}

int GiantStrength::getDef() {
        return component->getDef()+2;
}


Enrage::Enrage(Player * o, Player * e) :
  ADEnchant{"Enrage", 2, o,e,2,2,"*2","*2"}{}

int Enrage::getAtt() {
        return component->getAtt()*2;
}

int Enrage::getDef() {
	return component->getDef()*2;
}

Haste::Haste(Player * o, Player * e) : 
  NormalEnchant{"Haste", 1, o,e,"Enchanted minion gain +1 action each turn"},
    used{} {}
int Haste::getAct() {
	if (!used) {
		return 1;//there is action
	} else { 
		return component->getAct(); 
	}
}

void Haste::gainAct() {
	used = false;
	component->gainAct();
}

void Haste::use(int extra) {
	if (!used) {
		used = true;
		component->gainAct();
	} 
	component->use(extra);
}

void Haste::use(int i,int extra) {
        if (!used) {
                used = true;
                component->gainAct();
        }
        component->use(i,extra);
}

		
MagicFatigue::MagicFatigue(Player * o, Player * e) : 
  NormalEnchant{"Magic Fatigue", 0 , o,e,
   "Enchanted minion's activated ability costs 2 more"} {}

	
void MagicFatigue::use(int i, int extra) {
	component->use(i, extra + 2);
}

void MagicFatigue::use(int extra) {
        component->use(extra + 2);
}

Silence::Silence(Player * o, Player * e) :
  NormalEnchant{"Silence", 1, o ,e,
   "Enchanted minion cannot use abilities"} {}


void Silence::use(int extra) {
	cout << "This target cannot use abilities" << endl;
}

void Silence::use(int i,int extra) {
        cout << "This target cannot use abilities" << endl;
}































