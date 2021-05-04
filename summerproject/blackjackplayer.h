#pragma once
#include "card.h"
class blackjackplayer
{
public:
	blackjackplayer();
	~blackjackplayer();
	caRD visiblecard[2];
	caRD pluscard[3];
	int money = 10000;
	int stay_number = 0;
	int die_number = 0;
};

