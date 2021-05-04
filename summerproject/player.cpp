#include "player.h"



player::player()
{
}


player::~player()
{
}
void player::selectfirstcard()
{
	for (int i = 0; i < 4; i++)
	{
		visiblecard[i].cardcardnumber = 0;
		visiblecard[i].cardNumber = '\0';
		visiblecard[i].cardshape = '\0';
	}//초기화 한다.
	cout << "\t보이시게 할 패를 말씀해 주십시오" << endl;
	cout << "\t1 2 3을 입력하시옵소서" << endl;
	int selectcard;//보이게 할 수 입력
	int sorrycount = 0;
	while (1)
	{
		cin >> selectcard;
		if (selectcard == 1 || selectcard == 2 || selectcard == 3)
		{
			break;
		}
		else if (sorrycount == 0)
		{
			cout << "\t죽고 싶으세요 1 2 3을 입력 하라고 했잖아요 장난 치시는 겁니까 한번은 바주죠 다시한번 해보세요" << endl;
			sorrycount++;
		}
		else
		{
			cout << "\t한번만 용서해준다고 했지 이놈아 죽고 잡냐 퉤엣 성질 나오게 하네 이삐삐 새끼가 너의 돈은 100원이다 이놈아" << endl;
			money = 100;
		}
	}
	visiblecard[0] = firstcard[selectcard - 1];
	if (selectcard == 1)
	{
		unvisiblecard[0] = firstcard[1];
		unvisiblecard[1] = firstcard[2];
	}
	else if (selectcard == 2)
	{
		unvisiblecard[0] = firstcard[0];
		unvisiblecard[1] = firstcard[2];
	}
	else if (selectcard == 3)
	{
		unvisiblecard[0] = firstcard[0];
		unvisiblecard[1] = firstcard[1];
	}
}
void player::print_card(int a)
{
	cout << unvisiblecard[0].cardshape << " " << unvisiblecard[0].cardNumber << " " << unvisiblecard[1].cardshape << " " << unvisiblecard[1].cardNumber;
	for (int i = 0; i <= a; i++)
	{
		cout << " " << visiblecard[i].cardshape << " " << visiblecard[i].cardNumber;
	}
}
void player::playerbatting(batting &a, int gameturn)
{
	int battingcount = 0;//배팅 명령어
	cout << "\tmy batting:";
	cin >> battingcount;
	switch (battingcount)
	{
	case 1:

		if (check_double == 0)
		{
			a.check();
			check_double = 1;
		}
		else
		{
			cout << "\thit는 연속으로 할수 없습니다." << endl;
			cout << "\tcall을 실행시키겠습니다." << endl;
			a.call(money);
			check_double = 0;
		}
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
		dienumber = 1;
		if (gameturn == 2)
		{
			visiblecard[3].numberofcard = 0;
			visiblecard[3].numberofshape = 0;
		}
		break;
	}
}
void player::jokbocarding()
{
	for (int i = 0; i < 3; i++)
	{
		jokbocard[i] = unvisiblecard[i];
	}
	for (int i = 3, b = 0; i < 7; i++, b++)
	{
		jokbocard[i] = visiblecard[b];
	}
}
