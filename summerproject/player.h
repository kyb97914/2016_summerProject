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
	int highcard = 0;//만약에 같은 수가 나온다면 쓸거예요
	int money = 10000;//기본 돈
	float value_jokbo = 0;
	caRD unvisiblecard[3];//마지막에 안보이는 카드들
	caRD visiblecard[4];//보여주는 카드들
	caRD firstcard[3];//처음 받는 카드들
	caRD jokbocard[7];//마지막 을 사용할 카드
	void selectfirstcard();
	void print_card(int a);
	void playerbatting(batting &a, int gameturn);
	int check_double = 0;
	void jokbocarding();
	int dienumber = 0;
};

