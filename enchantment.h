#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include "card.h"
#include "decorator.h"
class Player;
class Enchantment : public Decorator {
	public:
	Enchantment(std::string name, int cost, Player * o, Player * e);
	void play(std::shared_ptr<Card> self) override;
	void play(int i,std::shared_ptr<Card> self) override;
	void disenchant(int i) override;
	friend class ADEnchant;
	virtual void takeDam(int d) override;
        virtual bool isDead() override;
        virtual void attack()override;
        virtual  void attack(int j) override;
        virtual void gainAct() override;
        virtual void loseAct() override;
        virtual int getAct() override;
        virtual void gainStat(int addAtt, int addDef) override;
        virtual void die() override;
        virtual void stTrigger(int pNum) override;
        virtual void edTrigger(int pNum) override;
        virtual void enterTrigger(int pNum, std::shared_ptr<AbsMinion> m)override;
        virtual void leaveTrigger(int pNum, std::shared_ptr<AbsMinion> m)override;
        virtual void use(int extra = 0) override;
        virtual void use(int i, int extra = 0) override;
        virtual std::string getName() override;
        virtual int getAtt() override;
        virtual int getDef() override;
        virtual void setDef(int i) override;
	virtual card_template_t displaySelf()=0;
	std::vector<std::shared_ptr<Enchantment>> inspect(std::shared_ptr<AbsMinion> self) override;
	virtual ~Enchantment();

};
	


#endif
