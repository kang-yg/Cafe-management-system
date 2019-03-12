#pragma once

#include "Table.h"

class Store
{
private:
	Table towTable[10]; //2인석 10개
	Table fourTable[5]; //4인석 5개
	int towTableNum = 10;
	int fourTableNum = 5;
public:
	Store() {}
	void provideTowTable(char* _name, string _order);
	void provideFourTable(char* _name, string _order);
	void recoveryTowTable(char* _name);
	void recoveryFourTable(char* _name);
	void showTableInfo();
};

void Store::provideTowTable(char* _name, string _order)
{
	for (int i = 0 ; i < towTableNum; i++)
	{
		if (towTable[i].getUser() == _name)
		{
			towTable[i].addOrder(_order);
			break;
		}

		else if (towTable[i].getAvailability() == true)
		{
			towTable[i].setAvailability(false);
			towTable[i].setUser(_name);
			towTable[i].setOrder(_order);
			break;
		}
	}
}

void Store::provideFourTable(char* _name, string _order)
{
	for (int i = 0; i < fourTableNum ; i++)
	{
		if (fourTable[i].getUser() == _name)
		{
			fourTable[i].addOrder(_order);
			break;
		}

		else if (fourTable[i].getAvailability() == true)
		{
			fourTable[i].setAvailability(false);
			fourTable[i].setUser(_name);
			fourTable[i].setOrder(_order);
			break;
		}
	}
}

void Store::recoveryTowTable(char* _name)
{
	for (int i = 0; i < towTableNum; i++)
	{
		if (towTable[i].getUser() == _name)
		{
			towTable[i].setAvailability(true);
			towTable[i].setUser("NULL");
			towTable[i].setOrder("No Order");
			cout << "**********Your use has ended.**********" << endl;
			break;
		}
	}
}

void Store::recoveryFourTable(char* _name)
{
	for (int i = 0; i < fourTableNum; i++)
	{
		if (fourTable[i].getUser() == _name)
		{
			fourTable[i].setAvailability(true);
			fourTable[i].setUser("NULL");
			fourTable[i].setOrder("No Order");
			cout << "**********Your use has ended.**********" << endl;
			break;
		}
	}
}

void Store::showTableInfo()
{
	cout << "----------Two-seater information----------" << endl;
	for (int i = 0; i < towTableNum; i++)
	{
		cout << "User: " << towTable[i].GetUser() << endl;
		cout << "Order History: " << towTable[i].getOrder() << endl;
	}
	
	cout << "----------4 Seating Information----------" << endl;
	for (int j = 0; j < fourTableNum; j++)
	{	
		cout << "User: " << fourTable[j].GetUser() << endl;
		cout << "Order History: " << fourTable[j].getOrder() << endl;
	}
}