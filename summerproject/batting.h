#pragma once
#include <iostream>
using namespace std;
class batting
{

public:
	batting();
	~batting();
	void call(int &a);//전사람이 낸 돈 그대로 배팅
	void doublebatting(int &a);//전사람이 낸돈 2배로 배팅
	void half(int &a);//지금 걸려져 있는 판돈의 절 반 배팅
	void check();
	void battingMoney(int a);
	void die();
	int callnumber = 0;
	int checknumber = 0;
	int batting_money = 0;//현재 걸려있는 배팅의 돈 액수
	int current_batting_money = 0;//현재 배팅할 돈
	void all_in();

};


