#pragma once
#include <iostream>
#include "AIprogram.h";
#include"jokboProgram.h"
#include <windows.h>
class pockergame
{
private:
	int gameturn;
	float winner_value[5];
	int current_winner;
	float winnervaluejokbo = 0;
	int nagari = 0;
	int nagari_number = 0;
public:
	void reset();
	pockergame();
	~pockergame();
	int gamenumber = 0;
	void pockergamestart();//��Ŀ������ �ϴ� �������� �Լ��̴�.
	card game;
	player my;
	AIplayer enemy1;
	AIplayer enemy2;
	AIplayer enemy3;
	AIplayer enemy4;
	batting gamebatting;
	AIprogram Alpago;
	jokboProgram jokbo;
	int battingcount = 0;
	void my_cardDividing(int a);
	void enemy1_cardDividing(int a);
	void enemy2_cardDividing(int a);
	void enemy3_cardDividing(int a);
	void enemy4_cardDividing(int a);//enemy4�����ֱ�
	int distinction_card(int a);//�켱����
	void Dividing(int a, int b);//ī�� �����ֱ�
	void distinction_winner();//����  �Ǵ�
	void batting_ing();
	void batting_first();//ó�� ���� �ʱ�ݾ� �� ����
	int distinction = 0;
};

