#include "player.h"
#include <iostream>
#include "ssingles.h"
#include <algorithm>
#include <ctime>   
#include <cstdlib>
using namespace std;

shared_ptr<Card>  strToCard(string name, Player * o, Player * e) {
	if (name == "Air Elemental") {
		return make_shared<AirElemental>(o,e);
	} else if (name == "Earth Elemental") {
		return make_shared<EarthElemental>(o,e);
	} else if (name == "Unsummon") {
		return make_shared<Unsummon>(o,e);
	} else if (name == "Blizzard") {
		return make_shared <Blizzard>(o,e);
	} else if (name == "Dark Ritual") {
		return make_shared<DarkRitual>(o,e);
	} else if (name == "Aura of Power") {
		return make_shared<AuraOfPower>(o,e);
	} else if (name == "Standstill") {
		return make_shared<Standstill>(o,e);
	} else if (name == "Bone Golem") {
		return make_shared<BoneGolem>(o,e);
	} else if (name == "Fire Elemental") {
		return make_shared<FireElemental>(o,e);
	} else if (name == "Potion Seller") {
		return make_shared<PotionSeller>(o,e);
	} else if (name == "Banish") {
                return make_shared<Banish>(o,e);
        } else if (name == "Recharge") {
                return make_shared<Recharge>(o,e);
	} else if (name == "Raise Dead") {
                return make_shared<RaiseDead>(o,e);
	} else if (name == "Giant Strength") {
		return make_shared<GiantStrength>(o,e);
	} else if (name == "Enrage") {
		return make_shared<Enrage>(o,e);
	} else if (name == "Novice Pyromancer") {
		return make_shared<NovicePyromancer>(o,e);
	} else if (name == "Apprentice Summoner") {
		return make_shared<ApprenticeSummoner>(o,e);
	} else if (name == "Master Summoner") {
		return make_shared<MasterSummoner>(o,e);
	} else if (name == "Disenchant") {
		return make_shared<Disenchant>(o,e);
	} else if (name == "Haste") {
		 return make_shared<Haste>(o,e);
	} else if (name == "Magic Fatigue") {
		return make_shared<MagicFatigue>(o,e);
	} else if (name == "Silence") {
		return make_shared<Silence>(o,e);
	} else if (name == "Nomair") {
		return make_shared<Nomair>(o,e);
	} else if (name == "CS246 TA") {
		return make_shared<CSTA>(o,e);
	} else {cout << name << " no SuchCard" << endl;
		throw;
	}
	return nullptr;
}

Player::Player(string name, int pNum, bool testing): 
  name{name}, life{20},magic{3}, deck{}, hand{}, field{},grave{},
    ritual{nullptr} , pNum{pNum}, testing{testing} {}


void Player::setEm(Player * e, ifstream & deckFile) {
	this->e = e;
	setDeck(deckFile);
        for (int i = 0; i < 5; ++i) { draw(); }

}

int myRand(int i) {
  return rand()%i;
}


void Player::setDeck(ifstream & file) {
	string s;

	while (!file.eof()) {
		getline(file, s);
		if (s!="") {//not enf of file
			deck.emplace_back(strToCard(s, this, e));
		}
	}
	if (!testing) {
		srand(time(0));
		random_shuffle(deck.begin(),deck.end(),myRand);
	}
	
}	

void Player::draw() {
	if (deck.size()!=0 && hand.size() < 5) { 
		hand.emplace_back(deck.back());
		deck.pop_back();
	}
}

void Player::discard(int i) {
	hand.erase (hand.begin()+i-1);
}

void Player::playCard(int i) {
	int s = hand.size();
	if (i <= 0 || i > s) {
		cout <<"Invalid command" << endl;
		return;
	}
	if (magic < hand[i-1]->getCost()) { // cost for the card
		if (testing) {
			hand[i-1]->play(hand[i-1]);
                	discard(i);
			return;
		}
                cout <<"Not enough magic" << endl;
        } else {
                magic -= hand[i-1]->getCost();
		hand[i-1]->play(hand[i-1]);
        	discard(i);
        }

}
void Player::useCard(int i) {
        int s = field.size();
        if (i <= 0 || i > s) {
                cout <<"Invalid command" << endl;
        } else {
                field[i-1]->use(0);
        }

}

void Player::playCard(int i, int p, int t) {
	if (i <= 0|| i >hand.size() || (p != 1 && p!=2) || t <=0) {
		cout <<"Invalid command" << endl;
                return;
	}
	if (magic < hand[i-1]->getCost()&& !testing) { // cost for the card
		cout <<"Not enough magic" << endl;
	} else {
		magic -= hand[i-1]->getCost();
		if (testing && magic < 0) {magic = 0;}
		if (p == 1) {
                	hand[i-1]->play(t,hand[i-1]);
        	} else {
                	hand[i-1]->play(-t,hand[i-1]); // player 2 is negative number
        	}
		discard(i);

	}
}
void Player::useCard(int i, int p, int t) {
        if (i <= 0|| i >field.size() || (p != 1 && p!=2) || t <=0) {
                cout <<"Invalid command" << endl;
                return;
        } else {
                if (p == 1) {
                        field[i-1]->use(t,0);
                } else {
                        field[i-1]->use(-t,0); // player 2 is negative number
                }

        }
}



void Player::playCard(int i, int p, char t) {
	if (i <= 0|| i >=hand.size() || (p != 1 && p!=2)) {
                cout <<"Invalid command" << endl;
                return;
	}
	if (magic < hand[i-1]->getCost() && !testing) { // cost for the card
                cout <<"Not enough magic" << endl;
        } else {
		magic -= hand[i-1]->getCost();
                if (testing && magic < 0) {magic = 0;}
        

		if (p == 1) {
			hand[i-1]->play(6,hand[i-1]); // 6 is ritual
		} else {
			hand[i-1]->play(-6,hand[i-1]);
		}
		discard(i);
	}
} 

 
void Player::att(int i) {
	field[i-1]->attack();
}

void Player::att(int i, int j) {
	field[i-1]->attack(j-1);
}

void Player::startTurn() {
	++magic;
	draw();
	const int fs = (field.size());
	for (int i = 0; i < fs; ++i) {field[i]->stTrigger(pNum);}
	if (ritual) {ritual->stTrigger(pNum);}//ritual triger

	int l = field.size();
	for (int i = 0; i < l; ++i) {
		field[i]->gainAct();
	}
	
}
void Player::endTurn() {
	for (auto &a : field) {a->edTrigger(pNum);};
	if (ritual) {ritual->edTrigger(pNum);}
}

void Player::checkDead() {
	for (int i = 0; i < field.size();){
		if (field[i]->isDead()) {
			grave.emplace_back(field[i]);
			shared_ptr<AbsMinion> temp = field[i];
			field.erase(field.begin()+i);
			//minion trigger
			for(auto &a : field) {a->leaveTrigger(pNum, temp);}
			if (ritual) {ritual->leaveTrigger(pNum, temp);}
			for(auto &a : e->field) {a->leaveTrigger(pNum, temp);}
			if (e->ritual) {e->ritual->leaveTrigger(pNum, temp);}
		} else {
			++i;
		}
	}
}


bool Player::isLose() {return life <= 0;}

void Player::addHand(shared_ptr<Card> c) {
	int hs = hand.size();
	if (hs < 5) {
		hand.emplace_back(c);
	}
}

void Player::addField(shared_ptr<AbsMinion> m) {
	if (field.size() < 5) {
		field.emplace_back(m);
		shared_ptr<AbsMinion> temp = field.back();
		for (auto &a : field) {a->enterTrigger(pNum,temp);}
		if (ritual) {ritual->enterTrigger(pNum, temp);}
		for (auto &a : e->field) {a->enterTrigger(pNum,temp);}
		if(e->ritual) {e->ritual->enterTrigger(pNum, temp);}
	}
}
void Player::addRitual(shared_ptr<Ritual> c) {
	ritual = c;
}	 	



















