#pragma once
#include <iostream>
using namespace std;
class batting
{

public:
	batting();
	~batting();
	void call(int &a);//������� �� �� �״�� ����
	void doublebatting(int &a);//������� ���� 2��� ����
	void half(int &a);//���� �ɷ��� �ִ� �ǵ��� �� �� ����
	void check();
	void battingMoney(int a);
	void die();
	int callnumber = 0;
	int checknumber = 0;
	int batting_money = 0;//���� �ɷ��ִ� ������ �� �׼�
	int current_batting_money = 0;//���� ������ ��
	void all_in();

};


