#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Production.h"

class Market;

class Population;

using namespace std;

class Land
{
public:
    shared_ptr<Market> get_market(void);

private:
	vector<unique_ptr<Population>> pops;
	shared_ptr<Market> mkt;
	vector<shared_ptr<Production>> pdts;
	float max_pop;
	string name;
};

