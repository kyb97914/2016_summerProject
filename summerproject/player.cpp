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
	}//�ʱ�ȭ �Ѵ�.
	cout << "\t���̽ð� �� �и� ������ �ֽʽÿ�" << endl;
	cout << "\t1 2 3�� �Է��ϽÿɼҼ�" << endl;
	int selectcard;//���̰� �� �� �Է�
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
			cout << "\t�װ� �������� 1 2 3�� �Է� �϶�� ���ݾƿ� �峭 ġ�ô� �̴ϱ� �ѹ��� ������ �ٽ��ѹ� �غ�����" << endl;
			sorrycount++;
		}
		else
		{
			cout << "\t�ѹ��� �뼭���شٰ� ���� �̳�� �װ� ��� ơ�� ���� ������ �ϳ� �̻߻� ������ ���� ���� 100���̴� �̳��" << endl;
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
	int battingcount = 0;//���� ��ɾ�
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
			cout << "\thit�� �������� �Ҽ� �����ϴ�." << endl;
			cout << "\tcall�� �����Ű�ڽ��ϴ�." << endl;
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
