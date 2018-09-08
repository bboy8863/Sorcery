#ifndef MINION_H
#define MINION_H
#include "enchantment.h"
#include <string>
#include "card.h"
#include "absminion.h"
class Player;
class Minion : public AbsMinion {
	protected:
	int att;
	int def;
	int act;
	public:
	Minion(std::string name, int cost, Player * o, Player * e
	   ,int att, int def);
	void play(std::shared_ptr<Card> self) override;
	void play(int i,std::shared_ptr<Card> self) override;
	void takeDam(int d) override;
	void disenchant(int i) override;
	virtual card_template_t makeTemplate() override;
	bool isDead() override ;
	void attack() override;
	void attack(int j) override;
	void gainAct() override;
	void loseAct() override;
	void die() override;
	void gainStat(int addAtt, int addDef) override;
	virtual void stTrigger(int pNum) override;
        virtual void edTrigger(int pNum) override;
        virtual void enterTrigger(int pNum, std::shared_ptr<AbsMinion> m) override;
        virtual void leaveTrigger(int pNum, std::shared_ptr<AbsMinion> m) override;
	virtual void use(int extra = 0) override;
	virtual card_template_t makeTemplate(int newAtt, int newDef) override;
	virtual void use(int i, int extra = 0) override;
	std::string getName();
	int getAtt() override;
	int getDef() override;
	int getAct() override;
	void setDef(int i) override;
 	std::vector<std::shared_ptr<Enchantment>> inspect(std::shared_ptr<AbsMinion> self) override;
	friend class TriggerMinion;
	friend class ActiveMinion;
	virtual ~Minion()=0;
	
};
#endif
	
	
