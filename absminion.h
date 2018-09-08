#ifndef ABSMINION_H
#define ABSMINION_H
#include "card.h"
class Enchantment;
class Player;
class AbsMinion : public Card {
	public:
	AbsMinion(std::string name, int cost, Player * o, Player * e);
	virtual void disenchant(int i)=0;
        virtual void takeDam(int d)=0;
        virtual bool isDead()=0;
        virtual void attack()=0;
        virtual void attack(int j)=0;
        virtual void gainAct()=0;
	virtual void loseAct()=0;
        virtual ~AbsMinion()=0;
	virtual void gainStat(int addAtt, int addDef)=0;
	virtual void die()=0;
	virtual void stTrigger(int pNum)=0;
        virtual void edTrigger(int pNum)=0;
        virtual void enterTrigger(int pNum, std::shared_ptr<AbsMinion> m)=0;
        virtual void leaveTrigger(int pNum, std::shared_ptr<AbsMinion> m)=0;
	virtual void use(int extra)=0;
	virtual void use(int i, int extra)=0;
	virtual std::string getName()=0;
	virtual int getAtt()=0;
	virtual int getDef()=0;
	virtual card_template_t makeTemplate()=0;
	virtual std::vector<std::shared_ptr<Enchantment>> inspect(std::shared_ptr<AbsMinion> self)=0;
	virtual card_template_t makeTemplate(int newAtt, int newDef)=0;
	virtual int getAct()=0;
	virtual void setDef(int i)=0;
	friend class Minion;
	friend class Enchantment;
	friend class ADEnchant;
};
#endif
