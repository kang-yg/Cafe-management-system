#pragma once
#include <string>
#include <iostream>
using namespace std;

//��޺� ������
#define NORMAL_RATIO 1//������ 0%
#define BRONZE_RATIO 0.95//������ 5%
#define SILVER_RATIO 0.9//������ 10%
#define GOLD_RATIO 0.8//������ 20%
#define VIP_RATIO 0.7//������ 30%

enum �޴�{ MakeSel = 1, Sales, TABLE, MakeCus, PayM, Spare, CusOut, End };

enum ��޺�����Ʈ { VIP_POINT = 10000,  GOLD_POINT = 7000, SILVER_POINT = 4000, BRONZE_POINT = 1000, NORMAL_POINT = 200 };