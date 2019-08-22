#pragma once

#include <memory>
#include <cstdint>

#include "Career.h"
#include "Market.h"
#include "Land.h"

using namespace std;

// The number to identify certain population.
typedef uint32_t PopID;

class Population
{
public:
	// Population group working to get production.
	void work(void);
	// Sell production to get money.
	void sell_production(void);
	// Give part of the money to nation.
	void give_tax(void);
	// Buy the production the population needed from the market.
	void buy_needing(void);
	// Part of the population move to another land
	void move_away(void);
	//Part of the population changes the career
	void increase(void);
private:
	// Career of this population group.
	shared_ptr<Career> career;
    // The land which the population belongs to.
    shared_ptr<Land> land;
    
    // Ability to make production.
    float ability;
	// The number of people of this population group.
	float pop;
	// Money rest from all recycle.
	float money;
    // Goods which this population makes.
    float goods;
    
    PopID pop_id;

};
