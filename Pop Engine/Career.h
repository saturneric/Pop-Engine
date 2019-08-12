#pragma once

#include <memory>

#include "Production.h"
#include "Need.h"

using namespace std;

class Career
{
public:

private:
	shared_ptr<Production> pdt;
	shared_ptr<Need> ned;

};

