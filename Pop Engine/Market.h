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
	vector<unique_ptr<SellProduction>> sl_pdts;
	vector<unique_ptr<Population>> pops;
	vector<shared_ptr<Market>> sub_mkts;
	shared_ptr<Market> pae_mkts;
};

