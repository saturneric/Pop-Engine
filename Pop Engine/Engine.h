#pragma once

#include <vector>
#include <memory>

#include "Market.h"
#include "Land.h"

using namespace std;

class Engine
{
public:
	
private:
	// Manage all the markets.
	vector<shared_ptr<Market>> mkts;
	// Manage all the lands in the world.
	vector<shared_ptr<Land>> lands;
};

