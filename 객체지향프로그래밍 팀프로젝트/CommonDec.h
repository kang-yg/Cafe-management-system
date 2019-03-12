#pragma once
#include <string>
#include <iostream>
using namespace std;

//등급별 할인율
#define NORMAL_RATIO 1//할인율 0%
#define BRONZE_RATIO 0.95//할인율 5%
#define SILVER_RATIO 0.9//할인율 10%
#define GOLD_RATIO 0.8//할인율 20%
#define VIP_RATIO 0.7//할인율 30%

enum 메뉴{ MakeSel = 1, Sales, TABLE, MakeCus, PayM, Spare, CusOut, End };

enum 등급별포인트 { VIP_POINT = 10000,  GOLD_POINT = 7000, SILVER_POINT = 4000, BRONZE_POINT = 1000, NORMAL_POINT = 200 };