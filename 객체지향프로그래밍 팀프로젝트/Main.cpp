/*
���� : Ver04 (������, ����, ���̺� ���, ����, �޴� ����)
������ ������ : 2017�� 11�� 17��
������Ʈ ������ : 2017�� 09�� 07��
�ڵ� �ۼ� ������ : 2017�� 10�� 3��
���� : 14100003������ / 14100050 ������ / 14100074 ������ / 14100082 �����
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