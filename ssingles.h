#ifndef SSINGLES_H
#define SSINGLES_H
#include "spell.h"
#include <memory>
class Unsummon final : public Spell {
	public: 
	Unsummon(Player * o, Player * e);
	void play(std::shared_ptr<Card> self) override;
	void play(int i,std::shared_ptr<Card> self) override;
};

class Blizzard final : public Spell{
	public:	
	Blizzard(Player * o, Player * e);
	void play(std::shared_ptr<Card> self) override;
	void play(int i,std::shared_ptr<Card> self) override;
}; 

class Banish final : public Spell {
	public:
	Banish(Player * o, Player * e);
	void play(std::shared_ptr<Card> self) override;
        void play(int i,std::shared_ptr<Card> self) override;
};

class Recharge final : public Spell {
	public:
	Recharge(Player * o, Player * e);
        void play(std::shared_ptr<Card> self) override;
        void play(int i,std::shared_ptr<Card> self) override;
};

class RaiseDead final : public Spell {
	public:
	RaiseDead(Player * o, Player * e);
        void play(std::shared_ptr<Card> self) override;
        void play(int i,std::shared_ptr<Card> self) override;
};
 
class Disenchant final : public Spell {
	public: 
	Disenchant(Player * o, Player * e);
        void play(std::shared_ptr<Card> self) override;
        void play(int i,std::shared_ptr<Card> self) override;
};

#endif
