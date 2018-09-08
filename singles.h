#ifndef SINGLES_H
#define SINGLES_H

#include "minion.h"
#include <iostream>
#include "triggerminion.h"
#include "activeminion.h"
class AirElemental final: public Minion {
	public: 
	AirElemental(Player * o, Player * e); 
};

class CSTA final : public Minion {
	public:
	CSTA(Player * o, Player * e);
};

class EarthElemental final: public Minion {
	public: 
	EarthElemental(Player * o, Player * e);
};

class BoneGolem final : public TriggerMinion {	
	public:
	BoneGolem(Player * o, Player * e);
	void leaveTrigger(int pNum, std::shared_ptr<AbsMinion> m) override;
};

class FireElemental final : public TriggerMinion {
        public:
	FireElemental(Player * o, Player * e);
	void enterTrigger(int pNum, std::shared_ptr<AbsMinion> m) override;
};

class PotionSeller final : public TriggerMinion {
	public:
	PotionSeller(Player * o, Player * e);
	void edTrigger(int pNum) override;
};

class Nomair final : public TriggerMinion {
	public: 
	Nomair(Player * o, Player * e);
	void stTrigger(int pNum) override;
};

class NovicePyromancer final: public ActiveMinion {
	public: 
	NovicePyromancer(Player * o, Player * e);
	void use(int i,int extra = 0) override;
};

class ApprenticeSummoner final : public ActiveMinion {
	public:
	ApprenticeSummoner(Player * o, Player * e);
	void use(int extra = 0) override;
};

class MasterSummoner final : public ActiveMinion {
	public: 
	MasterSummoner(Player * o, Player * e);
	void use(int extra = 0) override;
};


#endif























