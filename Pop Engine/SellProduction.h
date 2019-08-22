#pragma once
#include "Production.h"
#include "Market.h"

#include <map>

using std::pair;
using std::map;

class SellProduction
{
public:
	using Amount = float;
	using Price = float;
	using PriceList = pair<Price, Amount>;
	using PriceMap = pair<Price, PriceList>;

	SellProduction(shared_ptr<Production> pt_pdt) : p_pdt(pt_pdt) {}

	// 委托请求接口
	void new_request(shared_ptr<Request> pn_req);
	bool cancel_request(shared_ptr<Request> pn_req);

	const float get_average_price();
	const float get_selling_amount();
	const float get_buying_amount();
	
	
private:
	// 价位表
	map<Price, PriceList> pce_s_lst, pce_b_lst;
	// 产品指针
	shared_ptr<Production> p_pdt;
	// 销售交易委托
	vector<shared_ptr<Request>> reqs_sl;
	// 购买交易委托
	vector<shared_ptr<Request>> reqs_by;
	// 交易统计
	float buy_amt = 0.0, sell_amt = 0.0;
	// 平均价格
	float price_avg = 0.0;

	// 更新价位表接口
	void update_buying_map(Price price, Amount amount);
	void update_selling_map(Price price, Amount amount);
	void update_map(map<Price, PriceList>& pce_map, Price price, Amount amount);

	


};

