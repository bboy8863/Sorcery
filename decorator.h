#ifndef _DECORATOR_H_
#define _DECORATOR_H_
#include "absminion.h"

class Decorator: public AbsMinion {
 protected:
  std::shared_ptr<AbsMinion> component;
 public:
  Decorator(std::string name, int cost, Player * o, Player * e , 
	std::shared_ptr<AbsMinion> component);
  virtual ~Decorator();
};

#endif

