#pragma once

#include <memory>

#include "Career.h"
#include "Market.h"

using namespace std;

class Population
{
public:
	// Population group working to get production.
	void work(void);
	// Sell production to get money.
	void sell(void);
	// Give part of the money to nation.
	void tax(void);
	// Buy the production the population needed from the market.
	void buy(void);
	// Part of the population move to another land
	void move(void);
	//Part of the population changes the career
	void increase(void);
private:
	// Career of this population group.
	shared_ptr<Career> career;

	// The number of people of this population group.
	float pop;
	// Money rest from all recycle.
	float money;

};