#pragma once

#include <memory>
#include <vector>
#include <map>

#include "Population.h"
#include "SellProduction.h"
#include "Land.h"

using namespace std;

#define BUY_DEFINE 0
#define SELL_DEFINE 1

using Goods = float;
using Money = float;
// Money, Goods which the market returns to the seller or customer.
typedef pair<Money, Goods> MarketReturn;
// Information about price and need of a certain procuction in the market.
typedef pair<const Money, const Goods> MarketInfo;
// The Right to sell in this market.
typedef uint32_t SellingPermit;
// The Right to buy producrtion in this market.
typedef uint32_t BuyingPermit;

typedef uint32_t Permit;
// The number to identify certain population.
typedef uint32_t PopID;


// 市场准入证书
struct PermitManager {
	const uint16_t type;
	const shared_ptr<Population> p_pop;
	const shared_ptr<Production> p_dpt;
	const Market* p_mkt;

	using PPOP = shared_ptr<Population>;
	using PPDT = shared_ptr<Production>;

	// 市场购买许可
	PermitManager(PPOP pt_pop, PPDT pt_pdt, Market *pt_mkt) : type(BUY_DEFINE), p_pop(pt_pop), p_dpt(pt_pdt), p_mkt(pt_mkt) {}
	// 市场销售许可
	PermitManager(PPOP pt_pop, Market *pt_mkt) : type(SELL_DEFINE), p_pop(pt_pop), p_mkt(pt_mkt) {}
};

class SellProduction;

// 交易委托
struct Request {
	friend class SellProduction;

	const uint16_t type;
	const shared_ptr<PermitManager> p_pmt;
	const shared_ptr<Production> pdt;


	Request(shared_ptr<PermitManager> pt_pmt, float price, float amount) : type(pt_pmt->type), p_pmt(pt_pmt), pdt(pt_pmt->p_dpt) {
		this->price = price;
		this->amount = amount;
		this->active = true;
	}

	~Request() = default;

	// 销售者或者购买者查询交易委托所用接口
	const float show_money() { return money; }
	const float show_amount() { return amount; }

private:
	float money;
	float amount;
	float price;
	bool active;
	
	// 取消交易委托
	void cancel() {
		this->active = false;
	}

};

class Market
{
public:
    unique_ptr<MarketInfo> get_selling_production_info(shared_ptr<Production> p_pdt);
    
    shared_ptr<Request> send_production_to_sell(shared_ptr<PermitManager> p_pm, float price,float amount);
    MarketReturn get_money_from_selling(shared_ptr<Request> p_req);
    MarketReturn cancel_selling_request(SellingPermit spmt_id);
    
	// 获得市场销售准入证书
	shared_ptr<PermitManager> ask_for_selling_right(shared_ptr<Population> p_pop, shared_ptr<Production> p_pdt);
	// 获得市场购买准入证书
	shared_ptr<PermitManager> ask_for_buying_right(shared_ptr<Population> p_pop);
    
    void buy_production(BuyingPermit bpmt_id, string pdt_name, float money);
    shared_ptr<Market> get_parent_market(void);

	

    
private:
	// Selling productions in the market.
	map<shared_ptr<Production>, shared_ptr<SellProduction>> sl_pdts;
    // Lands in this market
    vector<shared_ptr<Land>> lands;
	// Children markets.
	vector<shared_ptr<Market>> sub_mkts;
	// Parent market.
	shared_ptr<Market> pae_mkts;

	vector<shared_ptr<PermitManager>> pmt_mgrs_selling, pmt_mgrs_buying;
    
    shared_ptr<SellProduction> get_sell_production(shared_ptr<Production> p_pdt);
	void process_request(void);
	void exchange_production(void);
	void transfer_production(void);
	
};

