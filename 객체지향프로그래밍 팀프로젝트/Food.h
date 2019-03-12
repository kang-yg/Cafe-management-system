#pragma once

#include "CommonDec.h"

class Food
{
private:
	char* foodName; //음식 이름
	int foodPrice; //음식 가격
public:
	Food() {}
	Food(char* _foodName, int _foodPrice);
	int getFoodPrice();
	char* getFoodName();
	void showFoodMenu();
};

Food::Food(char* _foodName, int _foodPrice) : foodPrice(_foodPrice)
{
	foodName = new char[strlen(_foodName) + 1];
	strcpy_s(foodName, strlen(_foodName) + 1, _foodName);
}

int Food::getFoodPrice()
{
	return foodPrice;
}

char* Food::getFoodName()
{
	return foodName;
}

void Food::showFoodMenu()
{
	cout << foodName << endl;
	cout << "Price: " << foodPrice << endl;
}