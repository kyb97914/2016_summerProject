#include "card.h"



card::card()
{
}


card::~card()
{
}
void card::cardmade()//ī����� ���� ��ȣ�� ������ ���´�.
{
	for (int i = 0; i < 52; i++)
	{
		cardnumber[i] = i + 1;
	}
}
void card::shufflecard()//ī�带 ���� �ִ�.
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 52; i++)
	{
		shufflecardnumber[i] = rand() % 52 + 1;
		for (int j = 0; j < i; j++)
		{
			if (shufflecardnumber[i] == shufflecardnumber[j])
			{
				i--;

			}
		}
		cardpattern(shufflecardnumber[i], i);//������ ī�忡 ���ڿ� ��� ����
	}
}
void card::cardpattern(int a, int i)
{
	int shape = (a / 13) + 1;
	int number = (a % 13) + 1;
	if (shape == 1)
	{
		cardcard[i].cardshape = "��";
		cardcard[i].numberofshape = 1;
	}
	else if (shape == 2)
	{
		cardcard[i].cardshape = "��";
		cardcard[i].numberofshape = 2;
	}
	else if (shape == 3)
	{
		cardcard[i].cardshape = "��";
		cardcard[i].numberofshape = 3;
	}
	else
	{
		cardcard[i].cardshape = "��";
		cardcard[i].numberofshape = 5;
	}
	if (number == 1)
	{
		cardcard[i].cardNumber = "A";
		cardcard[i].numberofcard = 14;
	}
	else if (number == 2)
	{
		cardcard[i].cardNumber = "2";
		cardcard[i].numberofcard = 2;
	}
	else if (number == 3)
	{
		cardcard[i].cardNumber = "3";
		cardcard[i].numberofcard = 3;
	}
	else if (number == 4)
	{
		cardcard[i].cardNumber = "4";
		cardcard[i].numberofcard = 4;
	}
	else if (number == 5)
	{
		cardcard[i].cardNumber = "5";
		cardcard[i].numberofcard = 5;
	}
	else if (number == 6)
	{
		cardcard[i].cardNumber = "6";
		cardcard[i].numberofcard = 6;
	}
	else if (number == 7)
	{
		cardcard[i].cardNumber = "7";
		cardcard[i].numberofcard = 7;
	}
	else if (number == 8)
	{
		cardcard[i].cardNumber = "8";
		cardcard[i].numberofcard = 8;
	}
	else if (number == 9)
	{
		cardcard[i].cardNumber = "9";
		cardcard[i].numberofcard = 9;
	}
	else if (number == 10)
	{
		cardcard[i].cardNumber = "10";
		cardcard[i].numberofcard = 10;
	}
	else if (number == 11)
	{
		cardcard[i].cardNumber = "J";
		cardcard[i].numberofcard = 11;
	}
	else if (number == 12)
	{
		cardcard[i].cardNumber = "Q";
		cardcard[i].numberofcard = 12;
	}
	else if (number == 13)
	{
		cardcard[i].cardNumber = "K";
		cardcard[i].numberofcard = 13;
	}
	cardcard[i].cardcardnumber = a;
}
