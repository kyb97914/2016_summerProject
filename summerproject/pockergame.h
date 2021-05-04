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
	void pockergamestart();//포커게임을 하는 전반적인 함수이다.
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
	void enemy4_cardDividing(int a);//enemy4나눠주기
	int distinction_card(int a);//우선순위
	void Dividing(int a, int b);//카드 나눠주기
	void distinction_winner();//위너  판단
	void batting_ing();
	void batting_first();//처음 배팅 초기금액 을 설정
	int distinction = 0;
};

