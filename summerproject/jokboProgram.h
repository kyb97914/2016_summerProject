#pragma once
#include "player.h"
#include "AIplayer.h"
class jokboProgram
{
private:
	int plush = 0;
	int  mountain = 0;
	int straight = 0;
	int Pair = 0;
	int tripple = 0;
	int fourcard = 0;
	int twoPair = 0;
	int backstraight = 0;
	int fullhouse = 0;
public:
	jokboProgram();
	~jokboProgram();
	int jokbo_arr[7];
	void plush_distinction(player &a);
	void straight_distinction(player &a);
	void pair_distinction(player &a);
	void distinction_jokbo(player &a);
	void AIdistinction_jokbo(AIplayer &a);
	void AIpair_distinction(AIplayer &a);
	void AIplush_distinction(AIplayer &a);
	void AIstraight_distinction(AIplayer &a);
	void jokbo_reset();
	int value_jokbo = 0;
	int pair_count = 0;
};
