#include <iostream>
#include <iomanip>
#include "card.h"
#include"pockergame.h"
#include "blackjackgame.h"
#include <fstream>
#include <cstring>
using namespace std;
struct rank_game
{
	string name;
	int money;
};
void textcolor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
void gamestart7Poker()
{

	cout << endl << endl << endl << endl << endl << "                         7��Ŀ ������ �������Դϴ�." << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "�⺻�ݾ��� ";
	textcolor(14);
	cout << "10000�Դϴ�." << endl;
	textcolor(15);
	cout << " �÷��̾�� AI�÷��̾� �� 5���̼� ������ �����ϸ�" << endl;
	cout << "�� 15���� �����ϸ� �������� ���� ��ŷ�� ���� �˴ϴ�. top20�� �ȿ� ���� �̸��� ��������� �ֽ��ϴ�.. " << endl << endl << endl << endl << endl;
	textcolor(12);
	cout << "                �׷� ����� ���ϴ�. ����� �Բ� �ϱ⸦ " << endl << endl << endl << endl << endl << endl << endl;
	textcolor(15);
	cout << "1�� �Է��ϼ��� �׷� ���� �����մϴ�." << endl;
	int gamestart;
	cin >> gamestart;
	system("cls");

}

void gamestart_blackjack()
{
	cout << endl << endl << endl << endl << endl << "                         black jack ������ �������Դϴ�." << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "       �⺻�ݾ��� ";
	textcolor(14);
	cout << "10000�Դϴ�." << endl;
	textcolor(15);
	cout << "�÷��̾�� �������� ���� �ο��Դϴ�." << endl;
	cout << "�� 10�� �� �����ϰ� �ɰ��Դϴ�. ���� ������ ���� �� ���ٸ� �״�� ������ ������ �˴ϴ�. " << endl;
	cout << "10���� �����ϰ� �� ���� �����ݾ��� �÷��̾��� ������ �ɰ��Դϴ�." << endl;
	cout << "�� top 20�� ��ŷ���� ��ϵǰ� �˴ϴ� �ѹ� ��ŷ 20���� ������ �غ��ñ� �ٶ��ϴ�." << endl << endl << endl << endl;
	textcolor(12);
	cout << "                �׷� ����� ���ϴ�. ����� �Բ� �ϱ⸦ " << endl << endl << endl << endl << endl << endl << endl;
	textcolor(15);
	cout << "1�� �Է��ϼ��� �׷� ���� �����մϴ�." << endl;
	int gamestart;
	cin >> gamestart;
	system("cls");
}
int main()
{
	rank_game ranking_score[20];
	system("mode con:cols=80 lines=30");//�ѱ۷� 40��
	cout << endl << endl << endl << endl << endl << endl << endl;
	textcolor(15);
	cout << "                 ���ݺ��� ī����� ���α׷��� �����ϰڽ��ϴ�." << endl;
	cout << endl << endl << endl << endl << endl << endl << endl;
	textcolor(12);
	cout << "                         Welcome to the ī���� program" << endl;

	textcolor(15);
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "������ :kyb" << endl;
	system("pause");
	system("cls");
	textcolor(12);
	cout << endl << endl << endl << endl;
	cout << "                        ���� ������ �����Ͽ� �ֽʽÿ�" << endl;

	cout << endl << endl << endl;
	textcolor(14);
	cout << "1:7��Ŀ" << endl << endl << endl << endl;
	cout << "2:����" << endl << endl << endl << endl;
	cout << "���� ������ �Է��� �ֽʽÿ�:";
	int gametype;
	cin >> gametype;
	int check;
	system("cls");
	if (gametype == 1)
	{
		textcolor(11);
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "                         7��Ŀ ������ �����ϼ̽��ϴ�." << endl << endl << endl << "                  Ȯ���մϱ�?? Ȯ���Ͻø� 1�� ���� �ֽʽÿ�" << endl;
		cin >> check;
	}
	else if (gametype == 2)
	{
		textcolor(11);
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "                        ���� ������ �����ϼ̽��ϴ�. " << endl << endl << endl << endl << "                  Ȯ���մϱ�?? Ȯ���Ͻø� 1�� ���� �ֽʽÿ�" << endl;
		cin >> check;
	}
	else
	{
		textcolor(12);
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "                 �ո���� ���󰡰� �ͳ� ���α׷� �ٽ� �����ض�" << endl;
	}

	textcolor(15);
	system("cls");

	pockergame gamedirector;
	blackjackgame jackgamedirector;
	int pocker_gameturn = 10;
	int blackjack_gameturn = 10;
	switch (gametype)
	{
	case 1:
		gamestart7Poker();
		while (pocker_gameturn>0)
		{
			system("cls");
			cout << "���� ���� ��:" << pocker_gameturn << endl;
			cout << "�и� ���� ���Դϴ�." << endl;
			card game;
			gamedirector.pockergamestart();//���� ���α׷�
			if (gamedirector.my.money <= 0)
			{
				break;
			}
			pocker_gameturn--;
		}
		if (gamedirector.my.money <= 0)
		{
			cout << "���� �ϼ̽��ϴ�. �����ϼ���" << endl;
			break;
		}
		else
		{

			cout << "5���� �������ϴ�." << endl;
			cout << "��ŷ�� ����ȭ�鿡�� ���� �˴ϴ� �ѵնѵնѵ�" << endl;
			Sleep(1500);
			system("cls");
			rank_game ranking_score[20];
			ifstream ranking;
			ranking.open("pocker_ranking.txt");
			for (int i = 0; i < 20; i++)
			{
				ranking >> ranking_score[i].name;
				ranking >> ranking_score[i].money;
			}
			ranking.close();
			if (ranking_score[19].money < gamedirector.my.money)
			{
				ofstream ranking_record;
				ranking_record.open("pocker_ranking.txt");
				int temp = 0;
				ranking_score[19].money = gamedirector.my.money;
				string name_temp = "d";
				string player_name;
				cout << "����� �̸��� �Է��Ͻʽÿ�" << endl;
				cin >> player_name;
				ranking_score[19].name = player_name;
				int player_ranking = 0;
				for (int i = 0; i < 19; i++)
				{
					for (int j = 0; j < 19 - i; j++)
					{
						if (ranking_score[j].money < ranking_score[j + 1].money)
						{
							temp = ranking_score[j].money;
							ranking_score[j].money = ranking_score[j + 1].money;
							ranking_score[j + 1].money = temp;
							name_temp = ranking_score[j].name;
							ranking_score[j].name = ranking_score[j + 1].name;
							ranking_score[j + 1].name = name_temp;
						}
					}
				}
				for (int i = 0; i < 20; i++)
				{
					cout << ranking_score[i].name << " " << ranking_score[i].money << endl;
				}
				for (int i = 0; i < 20; i++)
				{
					if (ranking_score[i].money == gamedirector.my.money)
					{
						player_ranking = i;
						break;
					}
				}
				cout << "����� ������ " << player_ranking + 1 << "�� �Դϴ�." << endl;
				for (int i = 0; i < 20; i++)
				{
					ranking_record << ranking_score[i].name << " " << ranking_score[i].money << endl;
				}
				ranking_record.close();
			}
			else
			{
				cout << "�ƽ����� ����� �����ȿ� ���� ���Ͽ����ϴ�." << endl;
			}
		}
		break;
	case 2:
		gamestart_blackjack();
		while (blackjack_gameturn > 0)
		{
			Sleep(1000);
			system("cls");
			cout << "���� ���� ��:" << blackjack_gameturn << endl;
			jackgamedirector.balckjackgamestart();
			if (jackgamedirector.my.money <= 0)
			{
				cout << "���� �ϼ̽��ϴ�. �����ϼ���" << endl;
				break;
			}
			cout << "���� ������ �Ѿ�ϴ�." << endl;
			Sleep(1500);
			blackjack_gameturn--;
		}
		if (jackgamedirector.my.money <= 0)
		{
			system("cls");
			cout << "���� �ϼ̽��ϴ�. �����ϼ���" << endl;
			break;
		}
		else
		{
			system("cls");
			rank_game ranking_score[20];
			ifstream ranking;
			ranking.open("blackjack_ranking.txt");
			for (int i = 0; i < 20; i++)
			{
				ranking >> ranking_score[i].name;
				ranking >> ranking_score[i].money;
			}
			for (int i = 0; i < 20; i++)
			{
				cout << ranking_score[i].name << " " << ranking_score[i].money << endl;
			}
			cout << endl;
			ranking.close();

			if (ranking_score[19].money < jackgamedirector.my.money)
			{
				ofstream ranking_record;
				ranking_record.open("blackjack_ranking.txt");
				int temp = 0;
				ranking_score[19].money = jackgamedirector.my.money;
				string name_temp = "d";
				cout << "����� �̸��� �Է��Ͻʽÿ�" << endl;
				string player_name;
				cin >> player_name;
				ranking_score[19].name = player_name;
				int player_ranking = 0;
				for (int i = 0; i < 19; i++)
				{
					for (int j = 0; j < 19 - i; j++)
					{
						if (ranking_score[j].money < ranking_score[j + 1].money)
						{
							temp = ranking_score[j].money;
							ranking_score[j].money = ranking_score[j + 1].money;
							ranking_score[j + 1].money = temp;
							name_temp = ranking_score[j].name;
							ranking_score[j].name = ranking_score[j + 1].name;
							ranking_score[j + 1].name = name_temp;
						}
					}
				}
				for (int i = 0; i < 20; i++)
				{
					if (ranking_score[i].money == jackgamedirector.my.money)
					{
						player_ranking = i;
						break;
					}
				}
				cout << "����� ������ " << player_ranking + 1 << "�Դϴ�." << endl;
				for (int i = 0; i < 20; i++)
				{
					ranking_record << ranking_score[i].name << " " << ranking_score[i].money << endl;
				}
				ranking_record.close();
			}
			else
			{
				cout << "�ƽ����� ����� �����ȿ� ���� ���Ͽ����ϴ�." << endl;
			}
		}
		break;

	}
	cout << "���� �� �������ϴ� �����ϼ̽��ϴ�." << endl;
	return 0;

}