#pragma once

#include <memory>

#include "Career.h"
#include "Market.h"

using namespace std;

class Population
{
public:
	void work(void);
	void sell(void);
	void tax(void);
	void buy(void);
	void move(void);
	void increase(void);

private:
	shared_ptr<Career> career;
	shared_ptr<Market> market;

	float pop;
	float money;

};