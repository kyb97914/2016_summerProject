#pragma once
#include "card.h"
#include "batting.h"
#include <iostream> 
class player
{
public:
	player();
	~player();
	int playerfirstmoney = 10000;
	int highcard = 0;//���࿡ ���� ���� ���´ٸ� ���ſ���
	int money = 10000;//�⺻ ��
	float value_jokbo = 0;
	caRD unvisiblecard[3];//�������� �Ⱥ��̴� ī���
	caRD visiblecard[4];//�����ִ� ī���
	caRD firstcard[3];//ó�� �޴� ī���
	caRD jokbocard[7];//������ �� ����� ī��
	void selectfirstcard();
	void print_card(int a);
	void playerbatting(batting &a, int gameturn);
	int check_double = 0;
	void jokbocarding();
	int dienumber = 0;
};

