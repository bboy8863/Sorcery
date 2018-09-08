#include "enchantment.h"
#include "player.h"
#include "gameover.h"
using namespace std;

int ab(int x) {
        return x>=0? x : -x;
}


Enchantment::Enchantment(std::string name, int cost, Player * o, Player * e) 
:Decorator{name,cost,o,e,nullptr}{}

Enchantment::~Enchantment() {}

void Enchantment::play(std::shared_ptr<Card> self){
	cout << "Invalid command" << endl;
}
bool Enchantment::isDead() {
	return getDef()<=0;
}
void Enchantment::takeDam(int d) {
	component->takeDam(d);
}

void Enchantment::play(int i,std::shared_ptr<Card> self) {
	Player * p;
        if (i > 0) {
		if (o->pNum == 1) {p = o;}
		else {p = e;}
	} else {
		if (o->pNum == 2) {p = o;}
		else {p = e;}
	}
        i = ab(i) - 1;
        const int fs = p->field.size();
        if (i >= fs) {
                cout << "Invalid Command" << endl;
		return;
        }
	if (o!= p) { e = o; o = p;} //ememy owns the card now
	component = p->field[i];//attach minion to enchatment
	shared_ptr<AbsMinion> temp = static_pointer_cast<AbsMinion>(self);//change AbsMinion
	p->field[i] = temp;
}
void Enchantment::disenchant(int i) {
	if (component) {
		o->field[i]=component;
	//	component = nullptr;
	}
}
	
void Enchantment::attack(){
        if (getAct()>=1) {
                cout <<getName() <<" attacked directly" << endl;
                e->life-=getAtt();
                loseAct();
                if (e->life <=0) {
                        throw (Gameover{o->name});
                }
        } else {
                cout << "Action point required" <<endl;
        }
}

void Enchantment::attack(int j) {
	if (getAct()>=1) {
                cout <<getName() <<" attacked "<<
	   	  e->field[j]->getName() << endl;
		int temp = e->field[j]->getAtt(); //in case it dies
                e->field[j]->takeDam(getAtt());
                takeDam(temp);
        }
}



void Enchantment::loseAct() {
        component->loseAct();
}

void Enchantment::gainAct() {component->gainAct();}
void Enchantment::gainStat(int addAtt, int addDef){component->gainStat(addAtt, addDef);}

void Enchantment::die() {
        component->die();
        component = nullptr;
}
int Enchantment::getAct() {return component->getAct();}
void Enchantment::stTrigger(int pNum) {component->stTrigger(pNum);}
void Enchantment::edTrigger(int pNum) {component->edTrigger(pNum);}
void Enchantment::enterTrigger(int pNum, std::shared_ptr<AbsMinion> m){
        component->enterTrigger(pNum, m);
}
void Enchantment::leaveTrigger(int pNum, std::shared_ptr<AbsMinion> m){
        component->leaveTrigger(pNum,m);
}
void Enchantment::use(int extra) {component->use(extra);}
void Enchantment::use(int i, int extra) {component->use(i,extra);}
int Enchantment::getAtt() { return component->getAtt();
}

int Enchantment::getDef() {
        return component->getDef();
}
vector<shared_ptr<Enchantment>> Enchantment::inspect(std::shared_ptr<AbsMinion> self) {
	vector<shared_ptr<Enchantment>> v;
	if (component) {
		v =  component->inspect(component);
	}
	shared_ptr<Enchantment> temp = static_pointer_cast<Enchantment>(self);
	v.emplace_back(temp);
	return v;
}		

string Enchantment::getName() {return component->getName();}

void Enchantment::setDef(int i) {component->setDef(i);}


