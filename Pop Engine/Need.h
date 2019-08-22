#pragma once

#include <memory>
#include <vector>

#include "Production.h"

using namespace std;

class Need
{
public:
    

private:
	// Certain kinds of production which one of those careers need to matain their lives.
	vector<pair<shared_ptr<Production>, float>> base_pdts;
	// Certain kinds of production to improve their lives. 
	vector<pair<shared_ptr<Production>, float>> improve_pdts;
	// Certain kinds of production to satisfy their lives.
	vector<pair<shared_ptr<Production>, float>> high_pdts;
};

