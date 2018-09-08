#ifndef RSINGLES_H
#define RSINGLES_H

#include "ritual.h"

class DarkRitual final : public Ritual {
	public:
	DarkRitual(Player * o,Player * e);
	void stTrigger(int pNum) override;
};

class AuraOfPower final : public Ritual {
	public:
	AuraOfPower(Player * o, Player * e);
	void enterTrigger(int pNum, std::shared_ptr<AbsMinion> m) override;
};

class Standstill final : public Ritual {
	public:
	Standstill(Player * o, Player * e);
	void enterTrigger(int pNum, std::shared_ptr<AbsMinion> m) override;
};


#endif
