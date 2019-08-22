#include "Population.h"
#include "Production.h"
#include "Market.h"


void Population::work(){
    goods = pop * ability / career->get_production()->get_value();
}
