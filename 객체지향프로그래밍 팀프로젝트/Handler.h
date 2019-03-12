#pragma once
#include <fstream>

#include "Seller.h"
#include "Customer.h"
#include "Store.h"
#include "Food.h"

ifstream cus("Customer.txt");
ifstream sell("Seller.txt");
ifstream foodList("Food.txt");

class Handler
{
private:
	Customer *cusArr[100];
	Seller Owner;
	Store shop;
	Food *foodMenu[100];
	int cusNum;
	int foodNum;
public:
	Handler();
	void ShowMenu(); //�޴� ���
	void MakeCustomer(); //�մ� ����
	void MakeSller(); //���� ����
	void CustomerBuyFood(); //���� ����
	void CustomerSpareTime(); //�մ� �ܿ��ð� Ȯ��
	void PrintSaleResult(); //���� ���� Ȯ��
	void setGrade(); //�մ� ��޼���
	void cusOut(); //�մ� ����
	void addFood(); //���ĸ޴� �߰�
	void showTable(); //���̺� ���� ���
	void showCustomer(); //�մ����� for test
};

Handler::Handler() : cusNum(0), foodNum(0) {}

void Handler::ShowMenu()
{
	cout << "----------OwnerMenu----------" << endl;
	cout << "1. Add seller" << endl;
	cout << "2. Revenue verification" << endl;
	cout << "3. Seat information" << endl;
	cout << "----------CustomerMenu----------" << endl;
	cout << "4. Membership Registration" << endl;
	cout << "5. Food purchase" << endl;
	cout << "6. Check remaining time" << endl;
	cout << "7. End of use" << endl;
	cout << "8. End" << endl;
	cout << "----------------------------" << endl;
}

void Handler::MakeCustomer()
{
	while (cus.tellg() > -1)
	{
		char name[20];
		int balance;

		cus >> name;
		cus >> balance;

		cusArr[cusNum++] = new Customer(name, balance, "NORMAL");
	}
	cus.close();
	cout << "******[Total " << cusNum << "Added guests information]******" << endl;
}

void Handler::MakeSller()
{
	while (sell.tellg() > -1)
	{
		int balance;

		sell >> balance;

		Owner = Seller(balance);
	}
	sell.close();
	cout << "******Owner Completed registration******" << endl;
	addFood();
}

void Handler::CustomerBuyFood()
{
	char name[20]; //�մ� �̸�
	int selectfood[10]; //���� ���� �ִ� 10��
	int selectfoodNum = 0; //������ ������ ��
	int totalPrice = 0; //������ ������ ���� �ݾ�
	string totalFoodName;
	string blank = " ";
	int party; //���� ��

	cout << "[Buy food]" << endl;
	
	for (int i = 0; i < foodNum; i++)
	{
		cout << i+1 << '.';
		foodMenu[i]->showFoodMenu();
	}
	
	cout << "Enter buyer name: ";
	cin >> name;
	
	for (int j = 0 ; ; j++)
	{
		cout << "Food selection (Please enter 0 if you want to quit / You can order up to 10): ";
		cin >> selectfood[j];

		if (selectfood[j] <= foodNum && selectfood[j] > 0)
		{
			selectfoodNum++;
			continue;
		}
		else
		{
			break;
		}
	}

	for (int z = 0 ; z < selectfoodNum+1 ; z++)
	{
		if (selectfood[z] > 0 && selectfood[z] < foodNum+1)
		{
			totalPrice += foodMenu[selectfood[z] - 1]->getFoodPrice();
			totalFoodName += (foodMenu[selectfood[z] - 1]->getFoodName() + blank);
		}
		else
		{
			break;
		}
	}

	cout << "Number of people: ";
	cin >> party;

	for (int i = 0; i < cusNum; i++)
	{
		for (int j = 0; j < selectfoodNum + 1; j++)
		{
			if (selectfood[j] > 0 && selectfood[j] < foodNum + 1)
			{
				if (cusArr[i]->GetName() == name)
				{
					if (party > 0 && party <= 2)
					{
						shop.provideTowTable(name, totalFoodName);
					}
					else
					{
						shop.provideFourTable(name, totalFoodName);
					}
					cusArr[i]->PayMoney(totalPrice);
					cusArr[i]->AddTime(totalPrice);
					cusArr[i]->setPoint(totalPrice * 0.2);
					Owner.AddMoney(totalPrice);
					break;
				}
			}
		}
	}
}

void Handler::CustomerSpareTime()
{
	char name[20];

	cout << "[Check remaining time]" << endl;
	cout << "Enter name: ";
	cin >> name;

	for (int i = 0; i < cusNum; i++)
	{
		if (cusArr[i]->GetName() == name)
		{
			cusArr[i]->PrintSpare();
		}		
	}
}

void Handler::PrintSaleResult()
{
	Owner.PrintSales();
}

void Handler::setGrade()
{
	for (int i = 0; i < cusNum ; i++)
	{
		if (cusArr[i]->getPoint() > VIP_POINT)
		{
			cusArr[i]->setGrade("VIP");
			cusArr[i]->setRatio(VIP_RATIO);
		}
		else if (cusArr[i]->getPoint() > GOLD_POINT)
		{
			cusArr[i]->setGrade("GOLD");
			cusArr[i]->setRatio(GOLD_RATIO);
		}
		else if (cusArr[i]->getPoint() > SILVER_POINT)
		{
			cusArr[i]->setGrade("SILVER");
			cusArr[i]->setRatio(SILVER_RATIO);
		}
		else if (cusArr[i]->getPoint() > BRONZE_POINT)
		{
			cusArr[i]->setGrade("BRONZE");
			cusArr[i]->setRatio(BRONZE_RATIO);
		}
		else
		{
			cusArr[i]->setGrade("NORMAL");
			cusArr[i]->setRatio(NORMAL_RATIO);
		}
	}
}

void Handler::cusOut()
{
	char name[20];

	cout << "Enter name for end of use: ";
	cin >> name;

	for (int i = 0; i < cusNum; i++)
	{
		if (cusArr[i]->GetName() == name)
		{
			cusArr[i]->outTime();
		}
	}

	shop.recoveryTowTable(name);
	shop.recoveryFourTable(name);
}

void Handler::addFood()
{
	while (foodList.tellg() > -1)
	{
		char foodname[20];
		int foodprice;

		foodList >> foodname;
		foodList >> foodprice;

		foodMenu[foodNum++] = new Food(foodname, foodprice);
	}
	foodList.close();
	cout << "******[Total " << foodNum << "Added food information]******" << endl;
}

void Handler::showTable()
{
	shop.showTableInfo();
}

void Handler::showCustomer()
{
	for (int i = 0; i < cusNum; i++)
	{
		cout << cusArr[i]->getName() << endl;
		cusArr[i]->PrintSpare();
		cout << "Grade: " << cusArr[i]->getGrade() << endl;
		cout << "Point: " << cusArr[i]->getPoint() << endl;
		cout << "Balance: " << cusArr[i]->getBalance() << endl;
		cout << "Discount rate: " << cusArr[i]->getRatio() << endl;
		cout << endl;
	}
}