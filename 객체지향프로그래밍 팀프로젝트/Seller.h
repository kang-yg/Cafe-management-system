#pragma once

#include "CommonDec.h"

class Seller //����
{
private:
	int Income; //����
	int Balance; //�ܰ�
public:
	Seller() {};
	Seller(int _balance) : Balance(_balance), Income(0) {}
	void AddMoney(int _money); //����
	void PrintSales(); //����Ȯ��
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
