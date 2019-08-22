#include "SellProduction.h"

void SellProduction::new_request(shared_ptr<Request> pn_req) {
	if (pn_req->type == SELL_DEFINE) {
		reqs_sl.push_back(pn_req);
		update_selling_map(pn_req->price, pn_req->amount);
	}
	else
	{
		reqs_by.push_back(pn_req);
		update_buying_map(pn_req->price, pn_req->amount);
	}
}

inline void SellProduction::update_buying_map(Price price, Amount amount)
{
	update_map(pce_b_lst, price, amount);
}

inline void SellProduction::update_selling_map(Price price, Amount amount)
{
	update_map(pce_s_lst, price, amount);
}

void SellProduction::update_map(map<Price, PriceList>& pce_map, Price price, Amount amount)
{
	auto pcemp_i = pce_s_lst.find(price);
	if (pcemp_i == pce_s_lst.end()) {
		pce_s_lst.insert(PriceMap(price, PriceList(price, amount)));
	}
	else {
		pcemp_i->second.second += amount;
	}
}


