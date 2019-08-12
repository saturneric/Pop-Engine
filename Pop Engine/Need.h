#pragma once

#include <memory>
#include <vector>

#include "Production.h"

using namespace std;

class Need
{
public:

private:
	vector<shared_ptr<Production>> base_pdts;
	vector<shared_ptr<Production>> improve_pdts;
	vector<shared_ptr<Production>> high_pdts;
};

