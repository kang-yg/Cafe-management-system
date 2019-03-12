#pragma once

#include "CommonDec.h"

class Table
{
private:
	bool availability; //��� ���� (true: ��밡��, false: ���Ұ�)
	char* user; //�����
	string order; //�ֹ�
public :
	Table();
	bool getAvailability();
	string getUser();
	string getOrder();
	char* GetUser();
	void setAvailability(bool _availability);
	void setUser(char* _user);
	void setOrder(string _order);
	void addOrder(string _order);
};

Table::Table() : availability(true) 
{
	user = new char[20];
	strcpy_s(user, 20, "NULL");

	order = new char[100];
	order = "No Order";
}

bool Table::getAvailability()
{
	return availability;
}

string Table::getUser()
{
	return user;
}

string Table::getOrder()
{
	return order;
}

char* Table::GetUser()
{
	return user;
}

void Table::setAvailability(bool _availability)
{
	availability = _availability;
}

void Table::setUser(char* _user)
{
	strcpy_s(user, strlen(_user)+1, _user);
}

void Table::setOrder(string _order)
{
	order = _order;
}

void Table::addOrder(string _order)
{
	order += _order;
}