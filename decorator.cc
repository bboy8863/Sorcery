#include "decorator.h"

Decorator::Decorator(std::string name, int cost, Player * o, 
	Player * e, std::shared_ptr<AbsMinion> component): 
	 AbsMinion{name,cost,o,e}, component{component} {}

Decorator::~Decorator() {}

