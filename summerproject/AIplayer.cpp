#include "AIplayer.h"



AIplayer::AIplayer()
{
}


AIplayer::~AIplayer()
{
}
void AIplayer::AIselectfirstcard()
{
	for (int i = 0; i < 4; i++)
	{
		visiblecard[i].cardcardnumber = 0;
		visiblecard[i].cardNumber = '\0';
		visiblecard[i].cardshape = '\0';
	}//초기화
	cout << "\t패 보는중 " << endl;
	int selectCard = 1;
	visiblecard[0] = firstcard[selectCard - 1];
	if (selectCard == 1)
	{
		unvisiblecard[0] = firstcard[1];
		unvisiblecard[1] = firstcard[2];
	}
	else if (selectCard == 2)
	{
		unvisiblecard[0] = firstcard[0];
		unvisiblecard[1] = firstcard[2];
	}
	else if (selectCard == 3)
	{
		unvisiblecard[0] = firstcard[0];
		unvisiblecard[1] = firstcard[1];
	}
	cout <<"\t"<< visiblecard[0].cardshape << "  " << visiblecard[0].cardNumber << "     ?      ?" << endl;
}
void AIplayer::AIprint_card(int a)
{
	cout << "\t";
	for (int i = 0; i <= a; i++)
	{
		cout << " " << visiblecard[i].cardshape << " " << visiblecard[i].cardNumber;
	}
}
void AIplayer::AIFinalcard()
{
	cout << "\t";
	for (int i = 0; i < 4; i++)
	{
		cout << " " << visiblecard[i].cardshape << " " << visiblecard[i].cardNumber;
	}
	for (int i = 0; i < 3; i++)
	{
		cout << " " << unvisiblecard[i].cardshape << " " << unvisiblecard[i].cardNumber;
	}
}
void AIplayer::jokbocarding()
{
	cout << "\t";
	for (int i = 0; i < 3; i++)
	{
		jokbocard[i] = unvisiblecard[i];
	}
	for (int i = 3, b = 0; i < 7; i++, b++)
	{
		jokbocard[i] = visiblecard[b];
	}
}
void AIplayer::AIbatting(batting &a, int gameturn)
{

	switch (battingcount)
	{
	case 1:
		a.check();
		break;
	case 2:

		a.call(money);
		break;
	case 3:
		a.doublebatting(money);
		break;
	case 4:
		a.half(money);
		break;
	case 5:
		a.die();
		if (gameturn == 2)
		{
			visiblecard[3].numberofcard = 0;
			visiblecard[3].numberofshape = 0;
		}
		dienumber = 1;

		break;
	}
}
