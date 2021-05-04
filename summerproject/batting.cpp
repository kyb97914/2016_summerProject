#include "batting.h"



batting::batting()
{
}


batting::~batting()
{
}
void batting::battingMoney(int a)
{
	if (a < 1000)
	{
		current_batting_money = 5;
	}
	else if (a < 100000)
	{
		current_batting_money = 10;
	}
	else if (a < 1000000)
	{
		current_batting_money = 100;
	}
	else if (a < 10000000)
	{
		current_batting_money = 1000;
	}
	else if (a < 100000000)
	{
		current_batting_money = 10000;
	}
	else if (a < 1000000000)
	{
		current_batting_money = 100000;//���� ���� ���� ���� ����� ������?? ���� 100���̻� ���� �� ���α׷��� �����ϴ�.
	}
	else
	{
		current_batting_money = 1000000;
	}
	cout << "\t������ �ǵ���" << current_batting_money << "�Դϴ�." << endl;
}
void batting::all_in()
{
	cout << "\t���λ��� " << endl;
	callnumber++;
}
void batting::call(int &a)
{
	if (a - current_batting_money <= 0)
	{
		if (a == 0)
		{
			all_in();
		}
		else
		{
			cout << "\tcall�� �ϼ̽��ϴ�." << endl;
			callnumber++;//call�� ������ ����� ���� ���� ��Ų��.
			batting_money = batting_money + a;
			cout << "\t�����մϴ�." << endl;
			a = 0;
		}

	}
	else
	{
		cout << "\tcall�� �ϼ̽��ϴ�." << endl;
		callnumber++;//call�� ������ ����� ���� ���� ��Ų��.
		batting_money = batting_money + current_batting_money;
		a = a - current_batting_money;
	}
	cout << "\t���� �ǵ� :" << batting_money << "���� �� ��" << current_batting_money << endl;//�׷��� ������ �ؾ���
	cout << "\t���� �ݰ� üũ�� ��ģ ����� ���� " << callnumber + checknumber << "�Դϴ�." << endl;
}
void batting::doublebatting(int& a)
{

	if (a - current_batting_money < 0)
	{
		cout << "\t���� �մϴ�" << endl;
		batting_money = batting_money + a;
		a = 0;
		if (a == 0)
		{
			cout << "\t�� �� �� ��" << endl;
			callnumber++;
		}
		else
		{
			cout << "\t���� �մϴ�" << endl;
			batting_money = batting_money + a;
			a = 0;
		}
	}
	else
	{
		cout << "\tdouble�� �ϼ̽��ϴ�." << endl;
		callnumber = 0; checknumber = 0;
		current_batting_money = current_batting_money * 2;
		batting_money = batting_money + current_batting_money;
		a = a - current_batting_money;
	}
	cout << "\t���� �ǵ� :" << batting_money << "���� �� ��" << current_batting_money << endl;
	cout << "\t���� �ݰ� üũ�� ��ģ ����� ���� " << callnumber + checknumber << "�� �Դϴ�." << endl;
}
void batting::die()
{
	cout << "\tdie�� �Ͽ����ϴ�." << endl;
	callnumber++;
}
void batting::half(int &a)
{
	current_batting_money = batting_money / 2;
	if (a - current_batting_money <= 0)
	{
		if (a == 0)
		{
			all_in();
		}
		else
		{
			cout << "\thalf�� �Ͽ����ϴ�." << endl;
			callnumber = 0; checknumber = 0;
			cout << "\t���� �մϴ�." << endl;
			batting_money = batting_money + a;
			a = 0;
		}
	}
	else
	{
		cout << "\thalf�� �Ͽ����ϴ�." << endl;
		callnumber = 0; checknumber = 0;
		batting_money = batting_money + current_batting_money;
		a = a - current_batting_money;
	}

	cout << "\t���� �ǵ� :" << batting_money << "���� �� ��" << current_batting_money << endl;//�׷��� ������ �ؾ���
	cout << "\t���� �ݰ� üũ�� ��ģ ����� ���� " << callnumber + checknumber << "�Դϴ�." << endl;
}
void batting::check()
{
	cout << "\tcheck �� �Ͽ����ϴ�." << endl;
	checknumber++;
	cout << "\t���� �ݰ� üũ�� ��ģ ����� ���� " << callnumber + checknumber << "�Դϴ�." << endl;
}
