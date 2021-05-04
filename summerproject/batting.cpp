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
		current_batting_money = 100000;//설마 여기 까지 오는 사람은 없겟죠?? 돈을 100억이상 따면 이 프로그램은 터집니다.
	}
	else
	{
		current_batting_money = 1000000;
	}
	cout << "\t지금의 판돈은" << current_batting_money << "입니다." << endl;
}
void batting::all_in()
{
	cout << "\t올인상태 " << endl;
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
			cout << "\tcall을 하셨습니다." << endl;
			callnumber++;//call을 실행한 사람의 수를 증가 시킨다.
			batting_money = batting_money + a;
			cout << "\t올인합니다." << endl;
			a = 0;
		}

	}
	else
	{
		cout << "\tcall을 하셨습니다." << endl;
		callnumber++;//call을 실행한 사람의 수를 증가 시킨다.
		batting_money = batting_money + current_batting_money;
		a = a - current_batting_money;
	}
	cout << "\t현재 판돈 :" << batting_money << "현재 낸 돈" << current_batting_money << endl;//그래픽 디자인 해야함
	cout << "\t현재 콜과 체크를 외친 사람의 수는 " << callnumber + checknumber << "입니다." << endl;
}
void batting::doublebatting(int& a)
{

	if (a - current_batting_money < 0)
	{
		cout << "\t올인 합니다" << endl;
		batting_money = batting_money + a;
		a = 0;
		if (a == 0)
		{
			cout << "\t올 인 상 태" << endl;
			callnumber++;
		}
		else
		{
			cout << "\t올인 합니다" << endl;
			batting_money = batting_money + a;
			a = 0;
		}
	}
	else
	{
		cout << "\tdouble을 하셨습니다." << endl;
		callnumber = 0; checknumber = 0;
		current_batting_money = current_batting_money * 2;
		batting_money = batting_money + current_batting_money;
		a = a - current_batting_money;
	}
	cout << "\t현재 판돈 :" << batting_money << "현재 낸 돈" << current_batting_money << endl;
	cout << "\t현재 콜과 체크를 외친 사람의 수는 " << callnumber + checknumber << "명 입니다." << endl;
}
void batting::die()
{
	cout << "\tdie를 하였습니다." << endl;
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
			cout << "\thalf을 하였습니다." << endl;
			callnumber = 0; checknumber = 0;
			cout << "\t올인 합니다." << endl;
			batting_money = batting_money + a;
			a = 0;
		}
	}
	else
	{
		cout << "\thalf을 하였습니다." << endl;
		callnumber = 0; checknumber = 0;
		batting_money = batting_money + current_batting_money;
		a = a - current_batting_money;
	}

	cout << "\t현재 판돈 :" << batting_money << "현재 낸 돈" << current_batting_money << endl;//그래픽 디자인 해야함
	cout << "\t현재 콜과 체크를 외친 사람의 수는 " << callnumber + checknumber << "입니다." << endl;
}
void batting::check()
{
	cout << "\tcheck 를 하였습니다." << endl;
	checknumber++;
	cout << "\t현재 콜과 체크를 외친 사람의 수는 " << callnumber + checknumber << "입니다." << endl;
}
