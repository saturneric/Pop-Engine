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

	// ί������ӿ�
	void new_request(shared_ptr<Request> pn_req);
	bool cancel_request(shared_ptr<Request> pn_req);

	const float get_average_price();
	const float get_selling_amount();
	const float get_buying_amount();
	
	
private:
	// ��λ��
	map<Price, PriceList> pce_s_lst, pce_b_lst;
	// ��Ʒָ��
	shared_ptr<Production> p_pdt;
	// ���۽���ί��
	vector<shared_ptr<Request>> reqs_sl;
	// ������ί��
	vector<shared_ptr<Request>> reqs_by;
	// ����ͳ��
	float buy_amt = 0.0, sell_amt = 0.0;
	// ƽ���۸�
	float price_avg = 0.0;

	// ���¼�λ��ӿ�
	void update_buying_map(Price price, Amount amount);
	void update_selling_map(Price price, Amount amount);
	void update_map(map<Price, PriceList>& pce_map, Price price, Amount amount);

	


};

