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
	cout << "����� �̹��� ���� ī��� " << a.pluscard[gameturn].cardshape << a.pluscard[gameturn].cardNumber << endl;
	gameturn++;
	game_cardnumber++;
}
void blackbatting::stay(blackjackplayer &a)
{
	cout << "stay�� ���� �ϼ̽��ϴ�.." << endl;
	a.stay_number = 1;
}
void blackbatting::doubledown(blackjackplayer &a, card b, int &gameturn, int &game_cardnumber, int &batting_money)
{
	a.pluscard[gameturn] = b.cardcard[game_cardnumber];
	cout << "����� �̹��� ���� ī��� " << a.pluscard[gameturn].cardshape << a.pluscard[gameturn].cardNumber << endl;
	cout << "�׸��� ����� �̹���⿡�� �̱�� �޴� �ݾ���" << (batting_money / 2) * 3 << "�Դϴ�." << endl;
	a.money = a.money - (batting_money / 2);
	batting_money = (batting_money / 2) * 3;
	gameturn++;
	game_cardnumber++;
}
void blackbatting::surrender(blackjackplayer &a, int &batting_money)
{
	cout << "�׺��� �����ϼ̱���" << endl;
	srand((unsigned int)time(NULL));
	int probability = rand() % 100 + 1;
	if (probability < 5)//5%�� Ȯ����
	{
		cout << "�ᱹ ���� �¸� �̱��� ���� ����� ���� �� �˾Ҿ�� " << endl;
		cout << "���� ����� ���� �߳����� ����ġ�� ����" << endl;
	}
	else
	{

	}
	a.money = a.money + (batting_money / 2);
	cout << "����� ����� ���� �ݾ��� ������ �������� �� ������ �����ϴ� �̴ϴ�." << endl;
	cout << "�׷� �����ǿ� ����� �й��Ͽ� ���ñ⸦ " << endl;
	a.stay_number = 1;
}
void blackbatting::batting_program(blackjackplayer &a, card b, int &gameturn, int &game_cardnumber, int &batting_money, int batting_turn)
{
	cout << "1.hit" << endl;
	cout << "2.stay" << endl;
	cout << "3.doubledown" << endl;
	cout << "4.surrender" << endl;
	cout << "�� �̿��� ���ڴ� ��Ʈ�� ���� �˴ϴ�." << endl;
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
			cout << "�峭 ġ�� ���ð�� ��Ʈ ������ �׺��� �ȵ˴ϴ�." << endl;
			cout << "stay ��  ó���ϰڽ��ϴ�." << endl;
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
