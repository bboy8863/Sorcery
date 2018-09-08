#include "rsingles.h"
#include "player.h"

DarkRitual::DarkRitual(Player * o, Player * e) : 
  Ritual{"Dark Ritual", 0, o, e, 5, 1
   , "At the start of your turn, gain 1 magic"}{}

void DarkRitual::stTrigger(int pNum) {
	if (pNum == o->pNum && charge >= actCost) {//owner's turn
		charge -= actCost;
		++o->magic;
	}
}

AuraOfPower::AuraOfPower(Player * o, Player * e) :
  Ritual{"Aura of Power", 1, o, e, 4, 1, 
  "Whenever a minion enters play under your control, it gains +1/+1"} {}

void AuraOfPower::enterTrigger(int pNum, std::shared_ptr<AbsMinion> m) {
	if (pNum == o->pNum && charge >= actCost) {
		charge-=actCost;
		m->gainStat(1,1);
	}
}

Standstill::Standstill(Player * o, Player * e) : 
  Ritual{"Standstill", 3, o, e, 4, 2
   , "Whenever a minion enters play, destroy it"} {}

void Standstill::enterTrigger(int pNum, std::shared_ptr<AbsMinion> m) {
	if (charge >= actCost) {
                charge -= actCost;
		m->die();
	}
}
