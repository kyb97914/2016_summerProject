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
	cout << "�а� �����Ͽ����ϴ�." << endl;
	game.cardmade();//ī�带 ����ϴ�.
	cout << "�и� ���� �ֽ��ϴ�." << endl;
	game.shufflecard();//ī�带 �����ϴ�.
	int player_gameturn = 0;//gameturn�� ����� ���� �Դϴ�.
	int dealer_gameturn = 0;
	game_cardnumber = 0;//game �� ī�带 ������ �����Դϴ�.
	int batting_money = 0;
	cout << "����� ���� ���� " << my.money << "�Դϴ�." << endl;
	Sleep(1000);
	cout << "���� �ݾ��� ���ϼ���" << endl;
	cout << "�� ���� �ϼž� �մϴ� ������ �ڽ��� ������ �ݾ� �״�� ���� ���� �մϴ�. " << endl;
	Sleep(500);
	cin >> batting_money;
	if (my.money < batting_money)
	{
		cout << "�峭 ġ�� �ɸ��� �ո��� ���󰣴� ��� �������̿�" << endl;
		cout << "�׳� �������� �˾� ��´���" << endl;
		cout << "�� �ȱ׷��� ���� ���ڼ� ���� ���ִµ�" << endl;
		batting_money = my.money;
		my.money = 0;
	}
	else
	{
		if (batting_money < (my.money / 10))
		{
			cout << "���� �մ� �ʹ� ���� �ɾ��� " << endl;
			cout << "�̷��� �Ѵ� �� ���� �մ� ���ݸ� �� ���� � ���ݸ� �� ���ڰ� ���� ���� �Ͼ��" << endl;
			int plus_money = 0;
			cout << "���� �� ����� �� �����غ� 0��� �Ǳ��ϴµ� �մ� �ʹ� ���� �۴� " << endl;
			cin >> plus_money;
			batting_money = batting_money + plus_money;
			my.money = my.money - batting_money;
		}
		else
		{
			cout << "�ѹ� ��� ������" << endl;
			my.money = my.money - batting_money;
		}
	}
	cout << "����� �̹� ���ӿ� ������  �ݾ��� " << batting_money << "�Դϴ�." << endl;
	cout << "���� ���� ���� ���� ��Ģ�� ���� ���� �� �帮�ڽ��ϴ�." << endl;
	cout << "���� ���� �и� �ް� ������ ���� �Ͻʽÿ�(1�� �÷��̾� ��� 1�� �����ϸ� ���� �޽��ϴ�.)" << endl;
	int first;
	cin >> first;
	if (first == 1)
	{
		cout << "����� ù��° ī�� �Դϴ�." << endl;
		my.visiblecard[0] = game.cardcard[game_cardnumber];
		cout << my.visiblecard[0].cardshape << " " << my.visiblecard[0].cardNumber << endl;
		game_cardnumber++;
		cout << "���� ������ �̰ڽ��ϴ�.." << endl;
		dealer.visiblecard[0] = game.cardcard[game_cardnumber];
		game_cardnumber++;
		cout << "����� �ι�° ī�� �Դϴ�." << endl;
		my.visiblecard[1] = game.cardcard[game_cardnumber];
		cout << my.visiblecard[0].cardshape << " " << my.visiblecard[0].cardNumber << "" << my.visiblecard[1].cardshape << " " << my.visiblecard[1].cardNumber << endl;
		game_cardnumber++;
		cout << "���� ������ �̵��� ����." << endl;
		dealer.visiblecard[1] = game.cardcard[game_cardnumber];
		game_cardnumber++;
	}
	else
	{
		cout << "���� ���� ������ �������ڽ��ϴ�.." << endl;
		dealer.visiblecard[0] = game.cardcard[game_cardnumber];
		game_cardnumber++;
		cout << "����� ù��° ī�� �Դϴ�." << endl;
		my.visiblecard[0] = game.cardcard[game_cardnumber];
		cout << my.visiblecard[0].cardshape << " " << my.visiblecard[0].cardNumber << endl;
		game_cardnumber++;
		cout << "����  �ι�° ī�带 ���������� ����" << endl;
		dealer.visiblecard[1] = game.cardcard[game_cardnumber];
		game_cardnumber++;
		cout << "����� �ι�° ī�� �Դϴ�." << endl;
		my.visiblecard[1] = game.cardcard[game_cardnumber];
		cout << my.visiblecard[0].cardshape << " " << my.visiblecard[0].cardNumber << "" << my.visiblecard[1].cardshape << " " << my.visiblecard[1].cardNumber << endl;
		game_cardnumber++;
	}
	system("pause");
	system("cls");
	cout << "�켱 ī�带 �ѹ� �� �ް� ������ hit�� ���� �ֽʽÿ�" << endl;
	Sleep(1000);
	cout << "�׸��� ī�带 ���� �ʰ� �ѱ�Ƿ��� stay�� ���� �ֽʽÿ�" << endl;
	Sleep(1000);
	cout << " [A 10],[A j],[A K],[A Q] �� ������ �����Ŵٸ� 1.5���� ����� �ް� �˴ϴ�." << endl << endl;
	Sleep(1000);
	cout << "���� ������ ������ ���� �ø���ʹ� ����ٿ��� �Ͻø� �մϴ� ���� �ٿ��� ó�� �� ����ŭ �߰� ������ �ϰ� 1���� ī�带 �� �޴� ���Դϴ�." << endl;
	Sleep(1000);
	cout << endl << "�׸��� ���� �а� �̱� ���ɼ��� ũ�ٰ� �����Ͻø� surrender�� �Ͻø� �Ǵµ� ���ñݾ��� ���ݸ� �ް� ������ �ֽ��ϴ�." << endl;
	Sleep(1000);
	cout << "���� �̱�Ŵٸ� 2���� ������ ��� �˴ϴ�." << endl;
	Sleep(1000);
	cout << "�׸��� ���� ���ڰ� ���Դ� �� �׳� ����� ��� �״���� ī�带 ������ �˴ϴ�" << endl;
	cout << "��� ������ �ð��� �ְڽ��ϴ�." << endl;
	Sleep(1000);
	cout << "�������� ��� ���� ī�带 ���� �ְڽ��ϴ�." << endl;
	cout << "����� �д�" << my.visiblecard[0].cardshape << " " << my.visiblecard[0].cardNumber << "" << my.visiblecard[1].cardshape << " " << my.visiblecard[1].cardNumber << endl;
	cout << "dealer �� ��" << dealer.visiblecard[0].cardshape << dealer.visiblecard[0].cardNumber << endl;
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
			cout << "�����մϴ� ���� �����̽ñ���" << endl;
			Sleep(2000);
			cout << "Ȥ�� ���� �а� �ñ��Ͻ��� �����Ű���????????????" << endl << "���� �д�";
			cout << dealer.visiblecard[0].cardshape << " " << dealer.visiblecard[0].cardNumber << " " << dealer.visiblecard[1].cardshape << " " << dealer.visiblecard[1].cardNumber << endl;
			cout << "���� ��� �������� ??" << endl;
			cout << "���� ��Ȳ �������� ���� ���� ���� �Դϴ� ���� ���� ������ �ܵ� " << batting_money << "�� ���� �˴ϴ� �� �ƽ� ����" << endl;
			cout << "������ ���� ��ſ� �ϼ̴µ� " << endl;
			cout << "���� �Ӹ� ���� �ð� �帱�Կ� ���� ���� �ѹ� ���� ���� ����" << endl;
			my.money = my.money + batting_money;
			Sleep(3000);
			system("cls");
		}
		else
		{
			blackjack_correct = 1;
			cout << "�����մϴ� �����̱��� ����� ����� �� �ݾ��� ���� �� ����ϴ�. " << endl;
			cout << "���� �д�";
			cout << dealer.visiblecard[0].cardshape << " " << dealer.visiblecard[0].cardNumber << " " << dealer.visiblecard[1].cardshape << " " << dealer.visiblecard[1].cardNumber << endl;
			cout << "����� ������ ����" << (batting_money / 2) * 3 << "�Դϴ�." << endl;
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
			cout << "���� �и� ���� �ϰڽ��ϴ�." << endl;
			cout << dealer.visiblecard[0].cardshape << " " << dealer.visiblecard[0].cardNumber << " " << dealer.visiblecard[1].cardshape << " " << dealer.visiblecard[1].cardNumber;
			cout << "�׷� ���� ������ ���� �ϰڽ��ϴ�." << endl;
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
					cout << "A�� 1 or 11�� �����Ͽ� �ֽʽÿ�" << endl;
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
					cout << "A�� 1 or 11�� �����Ͽ� �ֽʽÿ�" << endl;
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
				cout << "dealer�� ī�����";
				for (int i = 0; i < 2; i++)
				{
					cout << dealer.visiblecard[i].cardshape << " " << dealer.visiblecard[i].cardNumber;
				}
				cout << " ";
				for (int i = 0; i < dealer_gameturn; i++)
				{
					cout << dealer.pluscard[i].cardshape << " " << dealer.pluscard[i].cardNumber;
				}
				cout << endl << "����� �е���";
				for (int i = 0; i < 2; i++)
				{
					cout << my.visiblecard[i].cardshape << " " << my.visiblecard[i].cardNumber;
				}
				cout << " ";
				for (int i = 0; i < player_gameturn; i++)
				{
					cout << my.pluscard[i].cardshape << " " << my.pluscard[i].cardNumber;
				}
				cout << "�÷��̾ 21�� �Ѱ����Ƿ�" << endl;
				cout << "dealer �� �¸� �Դϴ�." << endl;

			}
			else if (dealer_cardmax > 21)
			{
				cout << "dealer�� ī�����";
				for (int i = 0; i < 2; i++)
				{
					cout << dealer.visiblecard[i].cardshape << " " << dealer.visiblecard[i].cardNumber;
				}
				cout << " ";
				for (int i = 0; i < dealer_gameturn; i++)
				{
					cout << dealer.pluscard[i].cardshape << " " << dealer.pluscard[i].cardNumber;
				}
				cout << endl << "����� �е���";
				for (int i = 0; i < 2; i++)
				{
					cout << my.visiblecard[i].cardshape << " " << my.visiblecard[i].cardNumber;
				}
				cout << " ";
				for (int i = 0; i < player_gameturn; i++)
				{
					cout << my.pluscard[i].cardshape << " " << my.pluscard[i].cardNumber;
				}
				cout << "������ 21�� �Ѱ����Ƿ�" << endl;
				cout << "�÷��̾��� �¸� �Դϴ�." << endl;
				my.money = (batting_money * 2) + my.money;
			}
			else if (my_cardmax > dealer_cardmax)
			{
				cout << "dealer�� ī�����";
				for (int i = 0; i < 2; i++)
				{
					cout << dealer.visiblecard[i].cardshape << " " << dealer.visiblecard[i].cardNumber;
				}
				cout << " ";
				for (int i = 0; i < dealer_gameturn; i++)
				{
					cout << dealer.pluscard[i].cardshape << " " << dealer.pluscard[i].cardNumber;
				}
				cout << endl << "����� �е���";
				for (int i = 0; i < 2; i++)
				{
					cout << my.visiblecard[i].cardshape << " " << my.visiblecard[i].cardNumber;
				}
				cout << " ";
				for (int i = 0; i < player_gameturn; i++)
				{
					cout << my.pluscard[i].cardshape << " " << my.pluscard[i].cardNumber;
				}
				cout << "������ ī���� " << dealer_cardmax << "�� �÷��̾��� ī�� ��" << my_cardmax << "���� �����Ƿ�";
				cout << "player�� �¸� �Դϴ�." << endl;
				my.money = (batting_money * 2) + my.money;
			}
			else if (my_cardmax < dealer_cardmax)
			{
				cout << "dealer�� ī�����";
				for (int i = 0; i < 2; i++)
				{
					cout << dealer.visiblecard[i].cardshape << " " << dealer.visiblecard[i].cardNumber;
				}
				cout << " ";
				for (int i = 0; i < dealer_gameturn; i++)
				{
					cout << dealer.pluscard[i].cardshape << " " << dealer.pluscard[i].cardNumber;
				}
				cout << endl << "����� �е���";
				for (int i = 0; i < 2; i++)
				{
					cout << my.visiblecard[i].cardshape << " " << my.visiblecard[i].cardNumber;
				}
				cout << " ";
				for (int i = 0; i < player_gameturn; i++)
				{
					cout << my.pluscard[i].cardshape << " " << my.pluscard[i].cardNumber;
				}
				cout << "������ ī���� " << dealer_cardmax << "�� �÷��̾��� ī�� ��" << my_cardmax << "���� �����Ƿ�";
				cout << "dealer�� �¸� �Դϴ�." << endl;
			}
			else
			{
				cout << "dealer�� ī�����";
				for (int i = 0; i < 2; i++)
				{
					cout << dealer.visiblecard[i].cardshape << " " << dealer.visiblecard[i].cardNumber;
				}
				cout << " ";
				for (int i = 0; i < dealer_gameturn; i++)
				{
					cout << dealer.pluscard[i].cardshape << " " << dealer.pluscard[i].cardNumber;
				}
				cout << endl << "����� �е���";
				for (int i = 0; i < 2; i++)
				{
					cout << my.visiblecard[i].cardshape << " " << my.visiblecard[i].cardNumber;
				}
				cout << " ";
				for (int i = 0; i < player_gameturn; i++)
				{
					cout << my.pluscard[i].cardshape << " " << my.pluscard[i].cardNumber;
				}
				cout << "���º� �Դϴ�." << endl;
				cout << "������ �ݾ��� �ٽ� �������ϴ�." << endl;
				my.money = batting_money + my.money;
			}
		}
	}

}