#pragma once

#include "CommonDec.h"

class Seller //업주
{
private:
	int Income; //수입
	int Balance; //잔고
public:
	Seller() {};
	Seller(int _balance) : Balance(_balance), Income(0) {}
	void AddMoney(int _money); //수입
	void PrintSales(); //매출확인
};

void Seller::AddMoney(int money)
{
	Income += money;
	Balance += Income;
}

void Seller::PrintSales()
{
	cout << "[settlement of accounts]" << endl;
	cout << "income: " << Income << endl;
	cout << "Total holdings: " << Balance << endl;
}
