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

	cout << endl << endl << endl << endl << endl << "                         7포커 게임을 실행중입니다." << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "기본금액은 ";
	textcolor(14);
	cout << "10000입니다." << endl;
	textcolor(15);
	cout << " 플레이어와 AI플레이어 총 5명이서 게임을 진행하며" << endl;
	cout << "총 15판을 진행하며 최종적인 돈을 랭킹에 들어가게 됩니다. top20위 안에 들어야 이름을 집어넣을수 있습니다.. " << endl << endl << endl << endl << endl;
	textcolor(12);
	cout << "                그럼 행운을 빕니다. 행운이 함께 하기를 " << endl << endl << endl << endl << endl << endl << endl;
	textcolor(15);
	cout << "1을 입력하세요 그럼 게임 시작합니다." << endl;
	int gamestart;
	cin >> gamestart;
	system("cls");

}

void gamestart_blackjack()
{
	cout << endl << endl << endl << endl << endl << "                         black jack 게임을 실행중입니다." << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "       기본금액은 ";
	textcolor(14);
	cout << "10000입니다." << endl;
	textcolor(15);
	cout << "플레이어와 딜러와의 단판 싸움입니다." << endl;
	cout << "총 10판 을 진행하게 될것입니다. 물론 그전에 돈을 다 쓴다면 그대로 게임이 끝나게 됩니다. " << endl;
	cout << "10판을 진행하고 난 후의 최종금액이 플레이어의 점수가 될것입니다." << endl;
	cout << "총 top 20의 랭킹만이 기록되게 됩니다 한번 랭킹 20위에 도전을 해보시기 바랍니다." << endl << endl << endl << endl;
	textcolor(12);
	cout << "                그럼 행운을 빕니다. 행운이 함께 하기를 " << endl << endl << endl << endl << endl << endl << endl;
	textcolor(15);
	cout << "1을 입력하세요 그럼 게임 시작합니다." << endl;
	int gamestart;
	cin >> gamestart;
	system("cls");
}
int main()
{
	rank_game ranking_score[20];
	system("mode con:cols=80 lines=30");//한글로 40자
	cout << endl << endl << endl << endl << endl << endl << endl;
	textcolor(15);
	cout << "                 지금부터 카드게임 프로그램을 시작하겠습니다." << endl;
	cout << endl << endl << endl << endl << endl << endl << endl;
	textcolor(12);
	cout << "                         Welcome to the 카지노 program" << endl;

	textcolor(15);
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "제작자 :kyb" << endl;
	system("pause");
	system("cls");
	textcolor(12);
	cout << endl << endl << endl << endl;
	cout << "                        게임 종류를 설정하여 주십시오" << endl;

	cout << endl << endl << endl;
	textcolor(14);
	cout << "1:7포커" << endl << endl << endl << endl;
	cout << "2:블랙잭" << endl << endl << endl << endl;
	cout << "게임 종류를 입력해 주십시오:";
	int gametype;
	cin >> gametype;
	int check;
	system("cls");
	if (gametype == 1)
	{
		textcolor(11);
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "                         7포커 게임을 선택하셨습니다." << endl << endl << endl << "                  확실합니까?? 확실하시면 1을 눌러 주십시오" << endl;
		cin >> check;
	}
	else if (gametype == 2)
	{
		textcolor(11);
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "                        블랙잭 게임을 선택하셨습니다. " << endl << endl << endl << endl << "                  확실합니까?? 확실하시면 1을 눌러 주십시오" << endl;
		cin >> check;
	}
	else
	{
		textcolor(12);
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "                 손목아지 날라가고 싶나 프로그램 다시 실행해라" << endl;
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
			cout << "남은 판의 수:" << pocker_gameturn << endl;
			cout << "패를 생성 중입니다." << endl;
			card game;
			gamedirector.pockergamestart();//시작 프로그램
			if (gamedirector.my.money <= 0)
			{
				break;
			}
			pocker_gameturn--;
		}
		if (gamedirector.my.money <= 0)
		{
			cout << "올인 하셨습니다. 수고하세요" << endl;
			break;
		}
		else
		{

			cout << "5턴이 끝났습니다." << endl;
			cout << "랭킹은 다음화면에서 공개 됩니다 뚜둥뚜둥뚜둥" << endl;
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
				cout << "당신의 이름을 입력하십시오" << endl;
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
				cout << "당신의 순위는 " << player_ranking + 1 << "위 입니다." << endl;
				for (int i = 0; i < 20; i++)
				{
					ranking_record << ranking_score[i].name << " " << ranking_score[i].money << endl;
				}
				ranking_record.close();
			}
			else
			{
				cout << "아쉽지만 당신은 순위안에 들지 못하였습니다." << endl;
			}
		}
		break;
	case 2:
		gamestart_blackjack();
		while (blackjack_gameturn > 0)
		{
			Sleep(1000);
			system("cls");
			cout << "남은 판의 수:" << blackjack_gameturn << endl;
			jackgamedirector.balckjackgamestart();
			if (jackgamedirector.my.money <= 0)
			{
				cout << "올인 하셨습니다. 수고하세요" << endl;
				break;
			}
			cout << "다음 턴으로 넘어갑니다." << endl;
			Sleep(1500);
			blackjack_gameturn--;
		}
		if (jackgamedirector.my.money <= 0)
		{
			system("cls");
			cout << "올인 하셨습니다. 수고하세요" << endl;
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
				cout << "당신의 이름을 입력하십시오" << endl;
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
				cout << "당신의 순위는 " << player_ranking + 1 << "입니다." << endl;
				for (int i = 0; i < 20; i++)
				{
					ranking_record << ranking_score[i].name << " " << ranking_score[i].money << endl;
				}
				ranking_record.close();
			}
			else
			{
				cout << "아쉽지만 당신은 순위안에 들지 못하였습니다." << endl;
			}
		}
		break;

	}
	cout << "게임 이 끝났습니다 수고하셨습니다." << endl;
	return 0;

}