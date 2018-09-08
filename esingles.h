#ifndef ESINGLES_H
#define ESINGLES_H

#include "adenchant.h"
#include "normalenchant.h"
class GiantStrength final: public ADEnchant {
	public:
	GiantStrength(Player * o, Player * e);
	int getAtt() override;
	int getDef() override;
};

class Enrage final: public ADEnchant {
        public:
        Enrage(Player * o, Player * e);
	int getAtt()override;
        int getDef() override;
};

class Haste final: public NormalEnchant { 
	bool used=false; // if the point has been used
	public:
	Haste(Player * o, Player * e);
	int getAct() override;
	void gainAct() override;
	void use(int extra) override;
	void use(int i, int extra) override;
};	
	
class MagicFatigue final : public NormalEnchant {
	public: 
	MagicFatigue(Player * o, Player * e);
	void use(int extra) override;
	void use(int i, int extra) override;
};

class Silence final : public NormalEnchant {
        public:
	Silence(Player * o, Player * e);
	void use(int extra) override;
        void use(int i, int extra) override;
};

#endif
