#include "blackjackgame.h"



blackjackgame::blackjackgame()
{
}


blackjackgame::~blackjackgame()
{
}
void blackjackgame::balckjackgamestart()
{
	cout << "blackjack game start" << endl;
	cout << "패가 도착하였습니다." << endl;
	game.cardmade();//카드를 만듭니다.
	cout << "패를 섞고 있습니다." << endl;
	game.shufflecard();//카드를 섞습니다.
	int player_gameturn = 0;//gameturn을 기록할 변수 입니다.
	int dealer_gameturn = 0;
	game_cardnumber = 0;//game 중 카드를 나눠줄 변수입니다.
	int batting_money = 0;
	cout << "당신의 현재 돈은 " << my.money << "입니다." << endl;
	Sleep(1000);
	cout << "배팅 금액을 말하세요" << endl;
	cout << "잘 생각 하셔야 합니다 블랙잭은 자신이 배팅한 금액 그대로 가져 가야 합니다. " << endl;
	Sleep(500);
	cin >> batting_money;
	if (my.money < batting_money)
	{
		cout << "장난 치다 걸리면 손모가지 날라간다 어디서 개수작이여" << endl;
		cout << "그냥 올인으로 알아 듣는다임" << endl;
		cout << "아 안그래도 어제 못자서 성질 나있는데" << endl;
		batting_money = my.money;
		my.money = 0;
	}
	else
	{
		if (batting_money < (my.money / 10))
		{
			cout << "에이 손님 너무 조금 걸었다 " << endl;
			cout << "이러다 둘다 집 못가 손님 조금만 더 걸자 어때 조금만 더 걸자고 너의 운을 믿어봐" << endl;
			int plus_money = 0;
			cout << "에어 돈 적어봐 더 배팅해봐 0적어도 되긴하는데 손님 너무 통이 작다 " << endl;
			cin >> plus_money;
			batting_money = batting_money + plus_money;
			my.money = my.money - batting_money;
		}
		else
		{
			cout << "한번 즐겨 봅세다" << endl;
			my.money = my.money - batting_money;
		}
	}
	cout << "당신이 이번 게임에 배팅한  금액은 " << batting_money << "입니다." << endl;
	cout << "지금 부터 블랙잭 배팅 규칙에 대해 말씀 해 드리겠습니다." << endl;
	cout << "누가 먼저 패를 받고 싶은지 결정 하십시오(1은 플레이어 당신 1을 제외하면 제가 받습니다.)" << endl;
	int first;
	cin >> first;
	if (first == 1)
	{
		cout << "당신의 첫번째 카드 입니다." << endl;
		my.visiblecard[0] = game.cardcard[game_cardnumber];
		cout << my.visiblecard[0].cardshape << " " << my.visiblecard[0].cardNumber << endl;
		game_cardnumber++;
		cout << "저도 한장을 뽑겠습니다.." << endl;
		dealer.visiblecard[0] = game.cardcard[game_cardnumber];
		game_cardnumber++;
		cout << "당신의 두번째 카드 입니다." << endl;
		my.visiblecard[1] = game.cardcard[game_cardnumber];
		cout << my.visiblecard[0].cardshape << " " << my.visiblecard[0].cardNumber << "" << my.visiblecard[1].cardshape << " " << my.visiblecard[1].cardNumber << endl;
		game_cardnumber++;
		cout << "저도 한장을 뽑도록 하죠." << endl;
		dealer.visiblecard[1] = game.cardcard[game_cardnumber];
		game_cardnumber++;
	}
	else
	{
		cout << "제가 먼저 한장을 가져가겠습니다.." << endl;
		dealer.visiblecard[0] = game.cardcard[game_cardnumber];
		game_cardnumber++;
		cout << "당신의 첫번째 카드 입니다." << endl;
		my.visiblecard[0] = game.cardcard[game_cardnumber];
		cout << my.visiblecard[0].cardshape << " " << my.visiblecard[0].cardNumber << endl;
		game_cardnumber++;
		cout << "저의  두번째 카드를 가져가도록 하죠" << endl;
		dealer.visiblecard[1] = game.cardcard[game_cardnumber];
		game_cardnumber++;
		cout << "당신의 두번째 카드 입니다." << endl;
		my.visiblecard[1] = game.cardcard[game_cardnumber];
		cout << my.visiblecard[0].cardshape << " " << my.visiblecard[0].cardNumber << "" << my.visiblecard[1].cardshape << " " << my.visiblecard[1].cardNumber << endl;
		game_cardnumber++;
	}
	system("pause");
	system("cls");
	cout << "우선 카드를 한번 더 받고 싶으면 hit를 말해 주십시오" << endl;
	Sleep(1000);
	cout << "그리고 카드를 받지 않고 넘기실려면 stay를 말해 주십시오" << endl;
	Sleep(1000);
	cout << " [A 10],[A j],[A K],[A Q] 이 두장을 받으신다면 1.5배의 배당을 받게 됩니다." << endl << endl;
	Sleep(1000);
	cout << "만약 한장을 받을때 돈을 올리고싶다 더블다운을 하시면 합니다 더블 다운은 처음 낸 돈만큼 추가 베팅을 하고 1장의 카드를 더 받는 것입니다." << endl;
	Sleep(1000);
	cout << endl << "그리고 저의 패가 이길 가능성이 크다고 생각하시면 surrender을 하시면 되는데 배팅금액의 절반만 받고 죽을수 있습니다." << endl;
	Sleep(1000);
	cout << "저를 이기신다면 2배의 배당금을 얻게 됩니다." << endl;
	Sleep(1000);
	cout << "그리고 같은 숫자가 나왔다 면 그냥 당신은 당신 그대로의 카드를 가지게 됩니다" << endl;
	cout << "잠시 생각할 시간을 주겠습니다." << endl;
	Sleep(1000);
	cout << "잊으셨을 까봐 저의 카드를 보여 주겠습니다." << endl;
	cout << "당신의 패는" << my.visiblecard[0].cardshape << " " << my.visiblecard[0].cardNumber << "" << my.visiblecard[1].cardshape << " " << my.visiblecard[1].cardNumber << endl;
	cout << "dealer 의 패" << dealer.visiblecard[0].cardshape << dealer.visiblecard[0].cardNumber << endl;
	for (int i = 0; i < 2; i++)
	{
		if (my.visiblecard[i].numberofcard == 14)
		{
			my.visiblecard[i].numberofcard = 11;
		}
		else if (my.visiblecard[i].numberofcard > 10)
		{
			my.visiblecard[i].numberofcard = 10;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (dealer.visiblecard[i].numberofcard == 14)
		{
			dealer.visiblecard[i].numberofcard = 11;
		}
		else if (dealer.visiblecard[i].numberofcard > 10)
		{
			dealer.visiblecard[i].numberofcard = 10;
		}
	}
	int blackjack_correct = 0;
	if (my.visiblecard[0].numberofcard + my.visiblecard[1].numberofcard == 21)
	{
		if (dealer.visiblecard[0].numberofcard + dealer.visiblecard[1].numberofcard == 21)
		{
			blackjack_correct = 1;
			cout << "축하합니다 고객님 블랙잭이시군요" << endl;
			Sleep(2000);
			cout << "혹시 저의 패가 궁금하시지 않으신가요????????????" << endl << "저의 패는";
			cout << dealer.visiblecard[0].cardshape << " " << dealer.visiblecard[0].cardNumber << " " << dealer.visiblecard[1].cardshape << " " << dealer.visiblecard[1].cardNumber << endl;
			cout << "고객님 기분 좋으셨죠 ??" << endl;
			cout << "많이 당황 스러웠죠 고객님 저도 블랙잭 입니다 고객님 따라서 고객님은 단돈 " << batting_money << "을 갖게 됩니다 아 아쉬 워라" << endl;
			cout << "고객님이 많이 즐거워 하셨는데 " << endl;
			cout << "조금 머리 식힐 시간 드릴게요 다음 에도 한번 잘해 보죠 깔깔깔" << endl;
			my.money = my.money + batting_money;
			Sleep(3000);
			system("cls");
		}
		else
		{
			blackjack_correct = 1;
			cout << "축하합니다 블랙잭이군요 당신은 당신이 건 금액의 절반 을 얻습니다. " << endl;
			cout << "저의 패는";
			cout << dealer.visiblecard[0].cardshape << " " << dealer.visiblecard[0].cardNumber << " " << dealer.visiblecard[1].cardshape << " " << dealer.visiblecard[1].cardNumber << endl;
			cout << "당신이 받으실 돈은" << (batting_money / 2) * 3 << "입니다." << endl;
			my.money = my.money + (batting_money / 2) * 3;
		}
	}
	my.stay_number = 0;
	my.die_number = 0;
	if (blackjack_correct == 1)
	{
	}
	else
	{
		int batting_turn = 0;
		while (my.stay_number != 1)
		{
			battingdirector.batting_program(my, game, player_gameturn, game_cardnumber, batting_money, batting_turn);
			batting_turn++;
		}
		if (my.die_number == 1)
		{
			cout << "저의 패를 공개 하겠습니다." << endl;
			cout << dealer.visiblecard[0].cardshape << " " << dealer.visiblecard[0].cardNumber << " " << dealer.visiblecard[1].cardshape << " " << dealer.visiblecard[1].cardNumber;
			cout << "그럼 다음 판으로 진행 하겠습니다." << endl;
		}
		else
		{
			int dealer_cardmax = 0;
			dealer_cardmax = dealer.visiblecard[0].numberofcard + dealer.visiblecard[1].numberofcard;
			while (dealer_cardmax < 17)
			{
				dealer.pluscard[dealer_gameturn] = game.cardcard[game_cardnumber];
				if (dealer.pluscard[dealer_gameturn].numberofcard == 14)
				{
					dealer.pluscard[dealer_gameturn].numberofcard = 11;
				}
				else if (dealer.pluscard[dealer_gameturn].numberofcard > 10)
				{
					dealer.pluscard[dealer_gameturn].numberofcard = 10;
				}
				dealer_cardmax = dealer_cardmax + dealer.pluscard[dealer_gameturn].numberofcard;
				dealer_gameturn++;
				game_cardnumber++;
			}
			int my_cardmax = 0;
			for (int i = 0; i < 2; i++)
			{
				if (my.visiblecard[i].numberofcard == 11)
				{
					cout << "A를 1 or 11로 선택하여 주십시오" << endl;
					int temp;
					cin >> temp;
					if (temp == 1)
					{
						my_cardmax = my_cardmax + 1;
					}
					else
					{
						my_cardmax = my_cardmax + 11;
					}
				}
				else
				{
					my_cardmax = my_cardmax + my.visiblecard[i].numberofcard;
				}
			}
			for (int i = 0; i < player_gameturn; i++)
			{
				if (my.pluscard[i].numberofcard == 14)
				{
					my.pluscard[i].numberofcard = 11;
				}
				else if (my.pluscard[i].numberofcard > 10)
				{
					my.pluscard[i].numberofcard = 10;
				}

				if (my.pluscard[i].numberofcard == 11)
				{
					cout << "A를 1 or 11로 선택하여 주십시오" << endl;
					int temp;
					cin >> temp;
					if (temp == 1)
					{
						my_cardmax = my_cardmax + 1;
					}
					else
					{
						my_cardmax = my_cardmax + 11;
					}
				}
				else
				{
					my_cardmax = my_cardmax + my.pluscard[i].numberofcard;
				}
			}
			if (my_cardmax > 21)
			{
				cout << "dealer의 카드들은";
				for (int i = 0; i < 2; i++)
				{
					cout << dealer.visiblecard[i].cardshape << " " << dealer.visiblecard[i].cardNumber;
				}
				cout << " ";
				for (int i = 0; i < dealer_gameturn; i++)
				{
					cout << dealer.pluscard[i].cardshape << " " << dealer.pluscard[i].cardNumber;
				}
				cout << endl << "당신의 패들은";
				for (int i = 0; i < 2; i++)
				{
					cout << my.visiblecard[i].cardshape << " " << my.visiblecard[i].cardNumber;
				}
				cout << " ";
				for (int i = 0; i < player_gameturn; i++)
				{
					cout << my.pluscard[i].cardshape << " " << my.pluscard[i].cardNumber;
				}
				cout << "플레이어가 21을 넘겼으므로" << endl;
				cout << "dealer 의 승리 입니다." << endl;

			}
			else if (dealer_cardmax > 21)
			{
				cout << "dealer의 카드들은";
				for (int i = 0; i < 2; i++)
				{
					cout << dealer.visiblecard[i].cardshape << " " << dealer.visiblecard[i].cardNumber;
				}
				cout << " ";
				for (int i = 0; i < dealer_gameturn; i++)
				{
					cout << dealer.pluscard[i].cardshape << " " << dealer.pluscard[i].cardNumber;
				}
				cout << endl << "당신의 패들은";
				for (int i = 0; i < 2; i++)
				{
					cout << my.visiblecard[i].cardshape << " " << my.visiblecard[i].cardNumber;
				}
				cout << " ";
				for (int i = 0; i < player_gameturn; i++)
				{
					cout << my.pluscard[i].cardshape << " " << my.pluscard[i].cardNumber;
				}
				cout << "딜러가 21을 넘겼으므로" << endl;
				cout << "플레이어의 승리 입니다." << endl;
				my.money = (batting_money * 2) + my.money;
			}
			else if (my_cardmax > dealer_cardmax)
			{
				cout << "dealer의 카드들은";
				for (int i = 0; i < 2; i++)
				{
					cout << dealer.visiblecard[i].cardshape << " " << dealer.visiblecard[i].cardNumber;
				}
				cout << " ";
				for (int i = 0; i < dealer_gameturn; i++)
				{
					cout << dealer.pluscard[i].cardshape << " " << dealer.pluscard[i].cardNumber;
				}
				cout << endl << "당신의 패들은";
				for (int i = 0; i < 2; i++)
				{
					cout << my.visiblecard[i].cardshape << " " << my.visiblecard[i].cardNumber;
				}
				cout << " ";
				for (int i = 0; i < player_gameturn; i++)
				{
					cout << my.pluscard[i].cardshape << " " << my.pluscard[i].cardNumber;
				}
				cout << "딜러의 카드합 " << dealer_cardmax << "이 플레이어의 카드 합" << my_cardmax << "보다 적으므로";
				cout << "player의 승리 입니다." << endl;
				my.money = (batting_money * 2) + my.money;
			}
			else if (my_cardmax < dealer_cardmax)
			{
				cout << "dealer의 카드들은";
				for (int i = 0; i < 2; i++)
				{
					cout << dealer.visiblecard[i].cardshape << " " << dealer.visiblecard[i].cardNumber;
				}
				cout << " ";
				for (int i = 0; i < dealer_gameturn; i++)
				{
					cout << dealer.pluscard[i].cardshape << " " << dealer.pluscard[i].cardNumber;
				}
				cout << endl << "당신의 패들은";
				for (int i = 0; i < 2; i++)
				{
					cout << my.visiblecard[i].cardshape << " " << my.visiblecard[i].cardNumber;
				}
				cout << " ";
				for (int i = 0; i < player_gameturn; i++)
				{
					cout << my.pluscard[i].cardshape << " " << my.pluscard[i].cardNumber;
				}
				cout << "딜러의 카드합 " << dealer_cardmax << "이 플레이어의 카드 합" << my_cardmax << "보다 많으므로";
				cout << "dealer의 승리 입니다." << endl;
			}
			else
			{
				cout << "dealer의 카드들은";
				for (int i = 0; i < 2; i++)
				{
					cout << dealer.visiblecard[i].cardshape << " " << dealer.visiblecard[i].cardNumber;
				}
				cout << " ";
				for (int i = 0; i < dealer_gameturn; i++)
				{
					cout << dealer.pluscard[i].cardshape << " " << dealer.pluscard[i].cardNumber;
				}
				cout << endl << "당신의 패들은";
				for (int i = 0; i < 2; i++)
				{
					cout << my.visiblecard[i].cardshape << " " << my.visiblecard[i].cardNumber;
				}
				cout << " ";
				for (int i = 0; i < player_gameturn; i++)
				{
					cout << my.pluscard[i].cardshape << " " << my.pluscard[i].cardNumber;
				}
				cout << "무승부 입니다." << endl;
				cout << "배팅한 금액을 다시 가져갑니다." << endl;
				my.money = batting_money + my.money;
			}
		}
	}

}