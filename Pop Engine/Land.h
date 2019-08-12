#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Population.h"
#include "Production.h"

using namespace std;

class Land
{
public:

private:
	vector<unique_ptr<Population>> pops;
	shared_ptr<Market> mkt;
	vector<shared_ptr<Production>> pdts;
	float max_pop;
	string name;
};

