#pragma once
#include "card.h"
#include "blackjackplayer.h"
#include <ctime>
#include <cstdlib>
class blackbatting
{
public:
	blackbatting();
	~blackbatting();

	void hit(blackjackplayer &a, card b, int &gameturn, int &game_cardnumber);
	void stay(blackjackplayer &a);
	void doubledown(blackjackplayer &a, card b, int &gameturn, int &game_cardnumber, int &batting_money);
	void surrender(blackjackplayer &a, int &batting_money);
	int current_batting_money;
	void batting_program(blackjackplayer &a, card b, int &gameturn, int &game_cardnumber, int &batting_money, int batting_turn);
};

