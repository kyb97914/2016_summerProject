#pragma once
#include "player.h"
#include "AIplayer.h"
class AIprogram
{
private:
	int batting_score = 0;
	int check_temp = 0;
	int call_temp = 0;
public:
	AIprogram();
	~AIprogram();
	void AI_distinction_card1(int a, AIplayer &myAI, batting bat);
	void AI_distinction_card2(int a, player A, AIplayer &myAI, AIplayer B, AIplayer C, AIplayer D, batting bat);
	void AI_distinction_card3(int a, player A, AIplayer &myAI, AIplayer B, AIplayer C, AIplayer D, batting bat);
	void AI_distinction_card4(int a, player A, AIplayer &myAI, AIplayer B, AIplayer C, AIplayer D, batting bat);
};

