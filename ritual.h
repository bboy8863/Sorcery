#ifndef RITUAL_H
#define RITUAL_H

#include "card.h"
class AbsMinion;


class Ritual : public Card{
	protected:
	int charge, actCost;
	std::string desc;
	public: 
	Ritual(std::string name, int cost, Player * o, Player * e
		, int charge,int actCost, std::string desc);
	void play(std::shared_ptr<Card> self) override;
	void play(int i,std::shared_ptr<Card> self) override;
	card_template_t makeTemplate() override;
	void gainCharge(int i);
	virtual void stTrigger(int pNum);
	virtual void edTrigger(int pNum);
	virtual void enterTrigger(int pNum, std::shared_ptr<AbsMinion> m);
	virtual void leaveTrigger(int pNum, std::shared_ptr<AbsMinion> m);
	virtual	~Ritual()=0;
};
	
	
	
	

#endif
