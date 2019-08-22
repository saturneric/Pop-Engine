#pragma once

#include <memory>

#include "Production.h"
#include "Need.h"

using namespace std;

class Career
{
public:
    shared_ptr<Production> get_production(void);

private:
	// The prodution which this career makes.
	shared_ptr<Production> pdt;
	// Produtions which this career needed.
	shared_ptr<Need> ned;

};

