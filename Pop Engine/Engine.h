#pragma once

#include <vector>
#include <memory>

#include "Market.h"

using namespace std;

class Engine
{
public:

private:
	vector<shared_ptr<Market>> mkts;
};

