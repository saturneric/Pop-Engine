#pragma once

#include <memory>
#include <vector>
#include <string>

using namespace std;

class Production
{
public:
    float get_value(void);
    string get_name(void);

private:
	// Raw material to make this production.
	vector<shared_ptr<Production>> material;
	// Base value of this prodution.
	float value;
	// Name of this production.
	string name;
};

