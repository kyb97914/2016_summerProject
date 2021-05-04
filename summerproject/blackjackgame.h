#pragma once
#include "card.h"
#include "blackbatting.h"
#include "blackjackplayer.h"
#include <Windows.h>
class blackjackgame
{
public:
	blackjackgame();
	~blackjackgame();
	void balckjackgamestart();
	blackjackplayer my;
	blackjackplayer dealer;
	card game;
	blackbatting battingdirector;
	int game_cardnumber = 0;
	int player_plus = 0;
};

