/*
버전 : Ver04 (할인율, 가게, 테이블 사용, 일행, 메뉴 선택)
마지막 수정일 : 2017년 11월 17일
프로젝트 시작일 : 2017년 09월 07일
코드 작성 시작일 : 2017년 10월 3일
참여 : 14100003강영규 / 14100050 유승종 / 14100074 전제형 / 14100082 조용범
*/

#include "Handler.h"

int main()
{
	Handler manager;
	int choice;

	while (1)
	{
		cout << endl;
		manager.ShowMenu();
		cout << "Selection: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MakeSel:
			manager.MakeSller();
			break;
		case Sales:
			manager.PrintSaleResult();
			break;
		case TABLE:
			manager.showTable();
			break;
		case MakeCus:
			manager.MakeCustomer();
			break;
		case PayM:
			manager.setGrade();
			manager.CustomerBuyFood();
			break;
		case Spare:
			manager.CustomerSpareTime();
			break;
		case CusOut:
			manager.cusOut();
			break;
		case End:
			return 0;
		default:
			break;
		case 9:
			manager.showCustomer();
			break;
		}
	}
}