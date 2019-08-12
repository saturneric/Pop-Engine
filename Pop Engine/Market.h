#pragma once

#include <memory>
#include <vector>

#include "Population.h"
#include "SellProduction.h"

using namespace std;

class Market
{
public:

private:
	// Selling productions in the market.
	vector<unique_ptr<SellProduction>> sl_pdts;
	// Children markets.
	vector<shared_ptr<Market>> sub_mkts;
	// Parent market.
	shared_ptr<Market> pae_mkts;
};

