#pragma once

#include <memory>
#include <vector>
#include <string>

using namespace std;

class Production
{
public:

private:
	vector<shared_ptr<Production>> material;
	float value;
	string name;
};

