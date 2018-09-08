#include "ritual.h"
#include <memory>
#include "player.h"
using namespace std;

Ritual::Ritual(string name, int cost, Player * o, Player * e
  , int charge,int actCost, string desc) : Card{name, cost, o, e}
  , charge{charge}, actCost{actCost}, desc{desc} {}

void Ritual::play(shared_ptr<Card> self) {
	o->addRitual(static_pointer_cast<Ritual>(self));
}
void Ritual::play(int i,std::shared_ptr<Card> self) {
	cout << "Invalid command" << endl;
}

card_template_t Ritual::makeTemplate() {
	return display_ritual(name,cost,actCost,desc,charge);
}

void Ritual::gainCharge(int i) {charge+=i;}

void Ritual::stTrigger(int pNum){}

void Ritual::edTrigger(int pNum){}

void Ritual::enterTrigger(int pNum, std::shared_ptr<AbsMinion> m){}

void Ritual::leaveTrigger(int pNum, std::shared_ptr<AbsMinion> m){}

Ritual::~Ritual(){}

