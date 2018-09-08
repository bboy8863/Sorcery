#include "minion.h"
#include "player.h"
#include <iostream>
#include "gameover.h"

using namespace std;

Minion::Minion(string name, int cost,Player * o,Player * e
  , int att, int def): AbsMinion{name, cost, o, e}, att{att}, def{def}, act{0}{}

void Minion::disenchant(int i) {}

void Minion::play(shared_ptr<Card> self) {
	shared_ptr<AbsMinion> p = static_pointer_cast<AbsMinion>(self);
	o->addField(p);
}

void Minion::play(int i,std::shared_ptr<Card> self) {
	cout << "Invalid command" << endl;
}

card_template_t Minion::makeTemplate() {
	return display_minion_no_ability(name,cost, att, def);
}

card_template_t Minion::makeTemplate(const int newAtt, const int newDef) {
	return display_minion_no_ability(name,cost, newAtt, newDef);
}


void Minion::gainAct() { 
	act = 1;
} 

bool Minion::isDead() {
	return def<=0;
}

void Minion::takeDam(int d) {
	def-=d;
	if (def<=0) {
		cout << name <<" has died" << endl;
		o->checkDead();
		
	}	
}

int Minion::getAct() { return act;}

void Minion::loseAct() {
	if (act == 1) { act = 0;}
}

string Minion::getName() {return name;}


void Minion::attack() {
	if (act==1) {
		cout <<name <<" attacked directly" << endl;
		e->life-=att;
		act = 0;
		if (e->life <=0) {
			throw (Gameover{o->name});
		}
	} else {
		cout << "Action point required" <<endl; 
	} 	
}
void Minion::setDef(int i) {def = i;}

int Minion::getAtt() {return att;}
int Minion::getDef() {return def;}

void Minion::attack(int j) {
	if (act == 1) {
		cout << name << " attacked " <<e->field[j]->name << endl;
		int temp = e->field[j]->getAtt(); //in case it dies 
		e->field[j]->takeDam(att);
		takeDam(temp);
	}
}	

void Minion::die() {
	def = 0;
	cout << name <<" has died" << endl;
	o->checkDead();
}
	

void Minion::gainStat(int addAtt, int addDef) {
	att+=addAtt; def+=addDef;
}

void Minion::stTrigger(int pNum){}

void Minion::edTrigger(int pNum){}

void Minion::enterTrigger(int pNum, std::shared_ptr<AbsMinion> m){}

void Minion::leaveTrigger(int pNum, std::shared_ptr<AbsMinion> m){}

void Minion::use(int extra) {}

void Minion::use(int i, int extra) {}


vector<shared_ptr<Enchantment>> Minion::inspect(std::shared_ptr<AbsMinion> self) {
	vector<shared_ptr<Enchantment>> v;
	return v;
}

Minion::~Minion(){}














 
