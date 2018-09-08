#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <fstream>
#include <vector>
#include "card.h"
#include "board.h"
#include "singles.h"
#include "ssingles.h"
#include "esingles.h"
#include "rsingles.h"
#include <memory>
#include "ritual.h"
#include "enchantment.h"
class Player {
	const std::string name;
	int life,magic;
	std::vector <std::shared_ptr<Card>> deck;
	std::vector <std::shared_ptr <Card>> hand;
	std::vector <std::shared_ptr<AbsMinion>> field;
	std::vector <std::shared_ptr<AbsMinion>> grave;
	std::shared_ptr<Ritual> ritual;
	Player * e; // ememy 
	int pNum;
	bool testing; // test mode
	public:
	Player(std::string name, int pNum, bool testing);
	void draw();
	void discard(int i);
	void setDeck(std::ifstream & file); 
	void startTurn();
	void endTurn();
	bool isLose();
	void playCard(int i);
	void playCard(int i, int p, int t);
	void playCard(int i, int p, char t);
	void useCard(int i);
        void useCard(int i, int p, int t);
        void useCard(int i, int p, char t);
	void att(int i);
	void att(int i, int j);
	void checkDead();
	void addHand(std::shared_ptr<Card> c);
	void addField(std::shared_ptr<AbsMinion> c);
	void addRitual(std::shared_ptr<Ritual> c);
	void setEm(Player * e,std::ifstream & deckFile);
	friend class Board;
	friend class Minion;
	friend class Unsummon;
	friend class Blizzard;
	friend class DarkRitual;
	friend class AuraOfPower;
	friend class Standstill;
	friend class FireElemental;
	friend class PotionSeller;
	friend class Banish;
	friend class Recharge;
	friend class RaiseDead;
	friend class Enchantment;
	friend class ADEnchant;
	friend class NovicePyromancer;
	friend class ApprenticeSummoner;
	friend class MasterSummoner;
	friend class Disenchant;
};

#endif
