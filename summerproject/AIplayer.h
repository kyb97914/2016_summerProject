#pragma once
#include "card.h"
#include "batting.h"
#include <iostream> 
class AIplayer
{
public:
	AIplayer();
	~AIplayer();
	int battingcount = 0;
	int firstmoney = 10000;
	int money = 10000;//�⺻ ��
	float value_jokbo = 0;
	int highcard = 0;//���࿡ ���� ���� ���´ٸ� ���ſ���
	caRD unvisiblecard[3];//�������� �Ⱥ��̴� ī���
	caRD visiblecard[4];//�����ִ� ī���
	caRD firstcard[3];//ó�� �޴� ī���
	caRD jokbocard[7];//������ �� ����� ī��
	void AIbatting(batting &a, int gameturn);
	void AIselectfirstcard();
	void AIprint_card(int a);
	void jokbocarding();
	void AIFinalcard();
	int dienumber = 0;
};

