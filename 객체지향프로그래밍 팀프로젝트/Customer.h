#pragma once

#include "CommonDec.h"

class Customer //소비자
{
private:
	char* Name;
	int Times; //남은시간
	int Balance; //잔고
	char* grade; //등급
	double point; //적립금
	double ratio; //할인율
public:
	Customer(char *_name, int _balance, char* _grade);
	string GetName();
	char* getName();
	void PayMoney(int money);
	void AddTime(int money);
	void PrintSpare();
	void setPoint(double _point);
	void setRatio(double _ratio);
	void setGrade(char* _grade);
	void outTime();
	char* getGrade();
	double getPoint();
	double getRatio();
	int getBalance();
};

Customer::Customer(char *_name, int _balance, char* _grade) : ratio(NORMAL_RATIO) , Times(0), point(0)
{
	Name = new char[strlen(_name) + 1];
	strcpy_s(Name, strlen(_name) + 1, _name);
	
	Balance = _balance;

	grade = new char[strlen(_grade) + 1];
	strcpy_s(grade, strlen(_grade) + 1, _grade);
}

string Customer::GetName()
{
	return Name;
}

char* Customer::getName()
{
	return Name;
}

void Customer::PayMoney(int money)
{
	Balance = Balance - (money * ratio);
}

void Customer::AddTime(int money)
{
	Times = Times + (money / 1000);
	cout << "------<Payment completed>------" << endl;
}


void Customer::PrintSpare()
{
	cout << "Time remaining: " << Times << endl;
}

void Customer::setPoint(double _point)
{
	point += _point;
}

void Customer::setRatio(double _ratio)
{
	ratio = _ratio;
}

void Customer::setGrade(char* _grade)
{
	strcpy_s(grade, strlen(_grade) + 1, _grade);
}

char* Customer::getGrade()
{
	return grade;
}

double Customer::getPoint()
{
	return point;
}

double Customer::getRatio()
{
	return ratio;
}

int Customer::getBalance()
{
	return Balance;
}

void Customer::outTime()
{
	Times = 0;
}