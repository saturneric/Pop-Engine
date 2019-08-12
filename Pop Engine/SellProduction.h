#pragma once
#include "Production.h"
class SellProduction :
	public Production
{
public:

private:
	float num;
	float price;
	float need;
	shared_ptr<Production> type;
};

