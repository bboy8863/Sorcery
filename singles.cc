#include "singles.h"
#include <memory>
#include "player.h"
using namespace std;
AirElemental::AirElemental(Player * o, Player * e)
          : Minion{"Air Elemental", 0, o, e,1, 1} {}

CSTA::CSTA(Player * o, Player * e)
          : Minion{"CS246 TA", 0, o, e,1, 1} {}

        
EarthElemental::EarthElemental(Player * o, Player * e)
          : Minion{"Earth Elemental", 3, o, e,4, 4} {}

BoneGolem::BoneGolem(Player * o, Player * e) : 
  TriggerMinion{"Bone Golem", 2, o, e, 1, 3, 
  "Gain +1/+1 whenever a minion leaves play"}{}

void BoneGolem::leaveTrigger(int pNum, shared_ptr<AbsMinion> m) {
	this->gainStat(1,1);
}

FireElemental::FireElemental(Player * o, Player * e) :
  TriggerMinion{"Fire Elemental", 2,o,e,2,2
  , "Whenever an opponent's minion enters play, deal 1 damage to it"} {}


void FireElemental::enterTrigger(int pNum, shared_ptr<AbsMinion> m) {
	if (pNum != o->pNum) {
		m->takeDam(1);
	}
}

PotionSeller::PotionSeller(Player * o, Player * e) :
  TriggerMinion{"Potion Seller", 2, o,e,1,3,
  "At the end of your turn, all your minions gain +0/+1"} {}

void PotionSeller::edTrigger(int pNum) {
	if (o->pNum == pNum) {
		for (auto &a : o->field) {a->gainStat(0,1);}
	}
}

NovicePyromancer::NovicePyromancer(Player * o, Player * e):
  ActiveMinion{"Novice Pyromancer", 1, o,e,0,1,1, 
 "Deal 1 damage to target minion"}{}

void NovicePyromancer::use(int i,int extra) {
	if (o->magic < (abCost+extra) && !o->testing) {
		cout << "Not enough Magic" << endl;
		return;
	} 
	if (getAct() < 1) {
		cout << "Not enough action point" << endl;
		return;
	}
	loseAct();
	o->magic -= (abCost+extra);
	if (o->testing && o->magic < 0) {o->magic = 0;}
	Player * p;
        if (i > 0) {
                if (o->pNum == 1) {p = o;}
                else {p = e;}
        } else {
                if (o->pNum == 2) {p = o;}
                else {p = e;}
        }

        i = abs(i) - 1;
        const int fs = p->field.size();
        if (i >= fs) {
                cout << "Invalid Command" << endl;
        }
	p->field[i]->takeDam(1);
}
	
Nomair::Nomair(Player * o, Player * e): 
  TriggerMinion{"Nomair, the TA Creator", 0, o,e,0,999,
  "At the start of your turn, summon 1 CS246 TA"} {}
	
void Nomair::stTrigger(int pNum) {
	o->addField(make_shared<CSTA>(o,e));
}
ApprenticeSummoner::ApprenticeSummoner(Player * o, Player * e):
  ActiveMinion{"Apprentice Summoner", 1,o,e, 1,1,1,
  "Summon a 1/1 air elemental"}{}

void ApprenticeSummoner::use(int extra) {
	if (o->magic < (abCost+extra) && !o->testing) {
                cout << "Not enough Magic" << endl;
                return;
        }
	if (getAct() < 1) {
                cout << "Not enough action point" << endl;
                return;
        }
        loseAct();
        o->magic -= (abCost+extra);
	if (o->testing && o->magic < 0) {o->magic = 0;}
	o->addField(make_shared<AirElemental>(o,e));
}


MasterSummoner::MasterSummoner(Player * o, Player * e):
  ActiveMinion{"Master Summonmer", 3, o,e, 2,3,2,
   "Summon up to three air elementals"} {}


void MasterSummoner::use(int extra) {
        if (o->magic < (abCost+extra) && !o->testing) {
                cout << "Not enough Magic" << endl;
                return;
        }
	if (getAct() < 1) {
                cout << "Not enough action point" << endl;
                return;
        }
        loseAct();
        o->magic -= (abCost+extra);
        if (o->testing && o->magic < 0) {o->magic = 0;}

        for (int i = 0; i < 3; ++i) {
                o->addField(make_shared<AirElemental>(o,e));
        }
}



















