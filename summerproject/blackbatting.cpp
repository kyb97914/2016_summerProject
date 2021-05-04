#include "blackbatting.h"



blackbatting::blackbatting()
{
}


blackbatting::~blackbatting()
{
}
void blackbatting::hit(blackjackplayer &a, card b, int &gameturn, int &game_cardnumber)
{
	a.pluscard[gameturn] = b.cardcard[game_cardnumber];
	cout << "당신이 이번에 받을 카드는 " << a.pluscard[gameturn].cardshape << a.pluscard[gameturn].cardNumber << endl;
	gameturn++;
	game_cardnumber++;
}
void blackbatting::stay(blackjackplayer &a)
{
	cout << "stay를 선언 하셨습니다.." << endl;
	a.stay_number = 1;
}
void blackbatting::doubledown(blackjackplayer &a, card b, int &gameturn, int &game_cardnumber, int &batting_money)
{
	a.pluscard[gameturn] = b.cardcard[game_cardnumber];
	cout << "당신이 이번에 받을 카드는 " << a.pluscard[gameturn].cardshape << a.pluscard[gameturn].cardNumber << endl;
	cout << "그리고 당신이 이번경기에서 이길시 받는 금액은" << (batting_money / 2) * 3 << "입니다." << endl;
	a.money = a.money - (batting_money / 2);
	batting_money = (batting_money / 2) * 3;
	gameturn++;
	game_cardnumber++;
}
void blackbatting::surrender(blackjackplayer &a, int &batting_money)
{
	cout << "항복을 선택하셨군요" << endl;
	srand((unsigned int)time(NULL));
	int probability = rand() % 100 + 1;
	if (probability < 5)//5%의 확률로
	{
		cout << "결국 저의 승리 이군요 역시 당신은 못할 줄 알았어요 " << endl;
		cout << "역시 당신의 저의 발끝에도 못미치는 군요" << endl;
	}
	else
	{

	}
	a.money = a.money + (batting_money / 2);
	cout << "당신은 당신의 배팅 금액의 절반을 가져가고 이 게임을 포기하는 겁니다." << endl;
	cout << "그럼 다음판에 더욱더 분발하여 보시기를 " << endl;
	a.stay_number = 1;
}
void blackbatting::batting_program(blackjackplayer &a, card b, int &gameturn, int &game_cardnumber, int &batting_money, int batting_turn)
{
	cout << "1.hit" << endl;
	cout << "2.stay" << endl;
	cout << "3.doubledown" << endl;
	cout << "4.surrender" << endl;
	cout << "그 이외의 숫자는 히트로 설정 됩니다." << endl;
	int battingcount = 0;
	cin >> battingcount;
	switch (battingcount)
	{
	case 1:
		hit(a, b, gameturn, game_cardnumber);
		break;
	case 2:
		stay(a);
		break;
	case 3:
		doubledown(a, b, gameturn, game_cardnumber, batting_money);
		break;
	case 4:
		if (batting_turn > 0)
		{
			cout << "장난 치지 마시고요 히트 했으면 항복이 안됩니다." << endl;
			cout << "stay 로  처리하겠습니다." << endl;
			stay(a);
		}
		else
		{
			surrender(a, batting_money);
		}
		break;
	default:
		hit(a, b, gameturn, game_cardnumber);
		break;
	}
}
