#include "Market.h"
#include "Production.h"
#include "SellProduction.h"

#include <assert.h>
#include <algorithm>


shared_ptr<SellProduction> Market::get_sell_production(shared_ptr<Production> p_pdt){
	auto p_sl_pdt_i = sl_pdts.find(p_pdt);

    return p_sl_pdt_i->second;
}

shared_ptr<Market> Market::get_parent_market(){
    return pae_mkts;
}


shared_ptr<PermitManager> Market::ask_for_selling_right(shared_ptr<Population> p_pop, shared_ptr<Production> p_pdt) {
	shared_ptr<PermitManager> p_pm(new PermitManager(p_pop, p_pdt, this));
	pmt_mgrs_buying.push_back(p_pm);
	return p_pm;
}

shared_ptr<PermitManager> Market::ask_for_buying_right(shared_ptr<Population> p_pop) {
	shared_ptr<PermitManager> p_pm(new PermitManager(p_pop, this));
	pmt_mgrs_buying.push_back(p_pm);
	return p_pm;
}

shared_ptr<Request> Market::send_production_to_sell(shared_ptr<PermitManager> p_pm, float price, float amount) {
	shared_ptr<Request> pn_req(new Request(p_pm, price, amount));
	auto p_spt = get_sell_production(p_pm->p_dpt);
	p_spt->new_request(pn_req);
	return pn_req;
}