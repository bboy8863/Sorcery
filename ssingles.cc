#include "ssingles.h"
#include <iostream>
#include "player.h"
using namespace std;

int abs(int x) {
	if (x >= 0) return x;
	return -x;
}

Unsummon::Unsummon(Player * o, Player * e) : Spell{"Unsummon", 2, o, e, 
	"Return target minion to its owner's hand"} {}

void Unsummon::play(shared_ptr<Card> self) {
	cout << "Invalid command" << endl;
}

void Unsummon::play(int i,std::shared_ptr<Card> self) {
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

	p->addHand(p->field[i]);
	shared_ptr<AbsMinion> temp = p->field[i];
	p->field.erase(p->field.begin()+i);
	for(auto &a : p->field) {a->leaveTrigger(p->pNum, temp);}//check for trigger


        if (p->ritual) {p->ritual->leaveTrigger(p->pNum, temp);}
        for(auto &a : p->e->field) {a->leaveTrigger(p->pNum, temp);}
        if (p->e->ritual) {p->e->ritual->leaveTrigger(p->pNum, temp);}	
}

Blizzard::Blizzard(Player * o, Player * e) : Spell{"Blizzard", 3, o, e,
	"Deal 2 damange to all minions"} {}

void Blizzard::play(shared_ptr<Card> self) {
	int s = o->field.size();
	for (int i = 0; i < o->field.size();) {
		o->field[i]->takeDam(2);
		if (s ==o->field.size() ) { ++i;} // if a minion died
	}
	s = e->field.size();
        for (int i = 0; i < e->field.size(); ++i) {
                e->field[i]->takeDam(2);
		if (s ==e->field.size() ) { ++i;}
        }
}
void Blizzard::play(int i,std::shared_ptr<Card> self) {
	cout << "Invalid command" << endl;
}
 	
Banish::Banish(Player * o, Player * e) : Spell{"Banish",2,o,e,
  "Destroy target minion or ritual"}{}

void Banish::play(shared_ptr<Card> self) {
	cout << "Invalid command" << endl;
}

void Banish::play(int i,std::shared_ptr<Card> self) {
  	Player * p;
	if (i > 0) {
                if (o->pNum == 1) {p = o;}
                else {p = e;}
        } else {
                if (o->pNum == 2) {p = o;}
                else {p = e;}
        }

        i = abs(i) - 1;
        if (i > 6) {
		cout << "Invalid command" << endl;
		return;
	}
        if (i == 5) {//ritual
		p->ritual = nullptr;
		return;
	}
        shared_ptr<AbsMinion> temp = p->field[i];
        p->field.erase(p->field.begin()+i);
        for(auto &a : p->field) {a->leaveTrigger(p->pNum, temp);}//check for trigger
        if (p->ritual) {p->ritual->leaveTrigger(p->pNum, temp);}
        for(auto &a : p->e->field) {a->leaveTrigger(p->pNum, temp);}
	if (p->e->ritual) {p->e->ritual->leaveTrigger(p->pNum, temp);}
}


Recharge::Recharge(Player * o, Player * e) : 
  Spell{"Recharge", 1, o, e, "Your ritual gains 3 charges"} {}

void Recharge::play(int i,std::shared_ptr<Card> self) {
        cout << "Invalid command" << endl;
}

void Recharge::play(shared_ptr<Card> self) {
	o->ritual->gainCharge(3);
}


RaiseDead::RaiseDead(Player * o, Player * e) :
  Spell{"Raise Dead", 2,o,e,
  "Ressurect the top minion in your graveyard and set its defence to 1"}{}

void RaiseDead::play(int i,std::shared_ptr<Card> self) {
	cout << "Invalid command" << endl;
}


void RaiseDead::play(shared_ptr<Card> self) {
	if (o->grave.size()>0) {
		shared_ptr<AbsMinion> temp = o->grave.back();
		o->grave.pop_back();
		temp->setDef(1);
		o->addField(temp);
	}
}

Disenchant::Disenchant(Player * o, Player * e) :
  Spell{"Disenchant", 1, o,e, 
   "Destroy the top enhantment on target minion"} {}

void Disenchant::play(std::shared_ptr<Card> self) {
	cout << "Invalid command" << endl;
}
	
void Disenchant::play(int i,std::shared_ptr<Card> self) {
	Player * p;
        if (i > 0) {
                if (o->pNum == 1) {p = o;}
                else {p = e;}
        } else {
                if (o->pNum == 2) {p = o;}
                else {p = e;}
        }

        i = abs(i) - 1;
        if (i > 5) {
                cout << "Invalid command" << endl;
                return;
        }
        p->field[i]->disenchant(i);
}











  






