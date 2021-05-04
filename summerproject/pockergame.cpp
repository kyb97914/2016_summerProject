#include "pockergame.h"



pockergame::pockergame()
{
}


pockergame::~pockergame()
{
}
void pockergame::reset()
{
	my.dienumber = 0;
	enemy1.dienumber = 0;
	enemy2.dienumber = 0;
	enemy3.dienumber = 0;
	enemy4.dienumber = 0;
	gameturn = 0;
	gamenumber = 0;
}
void pockergame::pockergamestart()
{
	/*���⼭ ��� ������ �ʱ�ȭ �ؾ� �ȴ�(���� �����ϰ�)*/
	reset();//�������� ���� ���ش�
	cout <<endl<<endl<< "\tplayer �� ����" << my.money << endl;
	cout << "\t�а� �����Ͽ����ϴ�." << endl;
	game.cardmade();//ī�带 ����ϴ�.
	cout << "\t�и� ���� �ֽ��ϴ�." << endl;
	game.shufflecard();//ī�带 �����ϴ�.
	cout << "\t����� �д� ";
	for (int i = 0; i < 3; i++)
	{
		my.firstcard[i] = game.cardcard[gamenumber];
		cout << " " << my.firstcard[i].cardshape << " " << my.firstcard[i].cardNumber;
		gamenumber++;
	}//ù��° ī�带 �Ѱ��ִ� �ڵ�
	for (int i = 0; i < 3; i++)//ù��° ī�带 �Ѱ��ִ� �ڵ�
	{
		enemy1.firstcard[i] = game.cardcard[gamenumber];
		gamenumber++;
	}//ù��° ī�带 �Ѱ��ִ� �ڵ�
	for (int i = 0; i < 3; i++)
	{
		enemy2.firstcard[i] = game.cardcard[gamenumber];
		gamenumber++;
	}//ù��° ī�带 �Ѱ��ִ� �ڵ�
	for (int i = 0; i < 3; i++)
	{
		enemy3.firstcard[i] = game.cardcard[gamenumber];
		gamenumber++;
	}//ù��° ī�带 �Ѱ��ִ� �ڵ�
	for (int i = 0; i < 3; i++)
	{
		enemy4.firstcard[i] = game.cardcard[gamenumber];
		gamenumber++;
	}//ù��° ī�带 �Ѱ��ִ� �ڵ�
	cout << endl;
	my.selectfirstcard();//������ ī��� �Ⱥ����� ī�带 �Ǻ��ϴ� �Լ� �Դϴ�.
	cout << "\tenemy1�� �д�" << endl;
	enemy1.AIselectfirstcard();//������ ī��� �Ⱥ����� ī�带 �Ǻ��ϴ� �Լ� �Դϴ�.
	cout << "\tenemy2�� �д�" << endl;
	enemy2.AIselectfirstcard();//������ ī��� �Ⱥ����� ī�带 �Ǻ��ϴ� �Լ� �Դϴ�.
	cout << "\tenemy3�� �д�" << endl;
	enemy3.AIselectfirstcard();//������ ī��� �Ⱥ����� ī�带 �Ǻ��ϴ� �Լ� �Դϴ�.
	cout << "\tenemy4�� �д�" << endl;
	enemy4.AIselectfirstcard();//������ ī��� �Ⱥ����� ī�带 �Ǻ��ϴ� �Լ� �Դϴ�.
	cout << "\t���� ������ �Ѿ� ���ϴ�." << endl;
	Sleep(1500);
	distinction = distinction_card(gameturn);//ī�带 ������ �켱 ������ �Ǻ��մϴ�.
	Dividing(distinction, gameturn);//ù��°�� �����ش�(4��°)
	gameturn++;//gameturn�� ���������� �Ѿ� ���ϴ�.gameturn ==1
	system("cls");//�ܼ�â�� ���� �մϴ�.
	cout << endl << endl << endl;
	gamebatting.battingMoney(my.money);//�⺻ ���� �ݾ��� �˷� �ݴϴ�.
	cout << "\tplayer�� ��:";
	my.print_card(gameturn);//ī�带 ���� �ִ� �Լ� �Դϴ�. my��� �÷��̾� �ڽ��� ī�带 ���� �ݴϴ�.
	cout << endl;
	cout << "\tenemy1�� ��:";
	enemy1.AIprint_card(gameturn);//enemy1�̶�� AI�� ���� ī�带 �����ݴϴ�. 
	cout << endl;
	cout << "\tenemy2�� ��:";
	enemy2.AIprint_card(gameturn);//enemy2�̶�� AI�� ���� ī�带 �����ݴϴ�. 
	cout << endl;
	cout << "\tenemy3�� ��:";
	enemy3.AIprint_card(gameturn);//enemy3�̶�� AI�� ���� ī�带 �����ݴϴ�. 
	cout << endl;
	cout << "\tenemy4�� ��:";
	enemy4.AIprint_card(gameturn);//enemy4�̶�� AI�� ���� ī�带 �����ݴϴ�. 
	cout << endl;
	distinction = distinction_card(gameturn);//�켱������ �Ǻ��մϴ�.
	Dividing(distinction, gameturn);//�ι�°�� �����ش�(5��° �̹� �����ְ� ���� ����)
	gameturn++;//���� ������ �Ѿ� ���ϴ�.gameturn==2
	cout << endl;
	Sleep(2000);
	system("cls");
	cout << endl << endl << endl;
	cout << "\tplayer�� ��:";
	my.print_card(gameturn);//�տ� ���Դ� print �Լ��� ����� �����ϴ�. 
	cout << endl;
	cout << "\tenemy1�� ��:";
	enemy1.AIprint_card(gameturn);//�տ� ���Դ� print �Լ��� ����� �����ϴ�.
	cout << endl;
	cout << "\tenemy2�� ��:";
	enemy2.AIprint_card(gameturn);//�տ� ���Դ� print �Լ��� ����� �����ϴ�.
	cout << endl;
	cout << "\tenemy3�� ��:";
	enemy3.AIprint_card(gameturn);//�տ� ���Դ� print �Լ��� ����� �����ϴ�.
	cout << endl;
	cout << "\tenemy4�� ��:";
	enemy4.AIprint_card(gameturn);//�տ� ���Դ� print �Լ��� ����� �����ϴ�.
	cout << endl;
	batting_first();
	while (gamebatting.callnumber + gamebatting.checknumber < 5)//ù��° ������ �����ϴ� ���� �����Դϴ�. callnumber�� checknumber�� ������ �ְ� �� call�� check�� 5�� �ϸ� ������. 
	{
		batting_ing();
		Sleep(1500);
		system("cls");
		cout << "\tplayer�� ��:";
		my.print_card(gameturn);//�տ� ���Դ� print �Լ��� ����� �����ϴ�. 
		cout << endl;
		cout << "\tenemy1�� ��:";
		enemy1.AIprint_card(gameturn);//�տ� ���Դ� print �Լ��� ����� �����ϴ�.
		cout << endl;
		cout << "\tenemy2�� ��:";
		enemy2.AIprint_card(gameturn);//�տ� ���Դ� print �Լ��� ����� �����ϴ�.
		cout << endl;
		cout << "\tenemy3�� ��:";
		enemy3.AIprint_card(gameturn);//�տ� ���Դ� print �Լ��� ����� �����ϴ�.
		cout << endl;
		cout << "\tenemy4�� ��:";
		enemy4.AIprint_card(gameturn);//�տ� ���Դ� print �Լ��� ����� �����ϴ�.
		cout << endl;
	}
	distinction = distinction_card(gameturn);
	Dividing(distinction, gameturn);//����°�� �����ش�(6��°)
	gameturn++;//game turn== 3
	cout << endl;
	cout << "\t���� ������ �Ѿ� ���ϴ�." << endl;
	Sleep(1500);
	system("cls");
	if (my.dienumber != 1)
	{
		cout << "\tplayer�� ��:";
		my.print_card(gameturn);
		cout << endl;
	}
	if (enemy1.dienumber != 1)
	{
		cout << "\tenemy1�� ��:";
		enemy1.AIprint_card(gameturn);
		cout << endl;
	}
	if (enemy2.dienumber != 1)
	{
		cout << "\tenemy2�� ��:";
		enemy2.AIprint_card(gameturn);
		cout << endl;
	}
	if (enemy3.dienumber != 1)
	{
		cout << "\tenemy3�� ��:";
		enemy3.AIprint_card(gameturn);
		cout << endl;
	}
	if (enemy4.dienumber != 1)
	{
		cout << "\tenemy4�� ��:";
		enemy4.AIprint_card(gameturn);
		cout << endl;
	}
	gamebatting.callnumber = 0; gamebatting.checknumber = 0;
	while (gamebatting.callnumber + gamebatting.checknumber < 5)//�ι�° ���� 
	{
		batting_ing();
		Sleep(1500);
		system("cls");
		if (my.dienumber != 1)
		{
			cout << "\tplayer�� ��:";
			my.print_card(gameturn);
			cout << endl;
		}
		if (enemy1.dienumber != 1)
		{
			cout << "\tenemy1�� ��:";
			enemy1.AIprint_card(gameturn);
			cout << endl;
		}
		if (enemy2.dienumber != 1)
		{
			cout << "\tenemy2�� ��:";
			enemy2.AIprint_card(gameturn);
			cout << endl;
		}
		if (enemy3.dienumber != 1)
		{
			cout << "\tenemy3�� ��:";
			enemy3.AIprint_card(gameturn);
			cout << endl;
		}
		if (enemy4.dienumber != 1)
		{
			cout << "\tenemy4�� ��:";
			enemy4.AIprint_card(gameturn);
			cout << endl;
		}
		cout << "\t���� �ǵ�:" << gamebatting.current_batting_money << " ���� ���� �ɸ� ��:" << gamebatting.batting_money << endl;
	}
	distinction = distinction_card(gameturn);//������ ����ī��
	if (distinction == 1)//������ ����ī�带 �޴� ���� 
	{
		if (my.dienumber != 1)
		{
			my.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
		if (enemy1.dienumber != 1)
		{
			enemy1.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
		if (enemy2.dienumber != 1)
		{
			enemy2.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
		if (enemy3.dienumber != 1)
		{
			enemy3.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
		if (enemy4.dienumber != 1)
		{
			enemy4.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
	}
	else if (distinction == 2)
	{
		if (enemy1.dienumber != 1)
		{
			enemy1.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
		if (enemy2.dienumber != 1)
		{
			enemy2.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
		if (enemy3.dienumber != 1)
		{
			enemy3.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
		if (enemy4.dienumber != 1)
		{
			enemy4.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
		if (my.dienumber != 1)
		{
			my.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
	}
	else if (distinction == 3)
	{
		if (enemy2.dienumber != 1)
		{
			enemy2.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
		if (enemy3.dienumber != 1)
		{
			enemy3.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
		if (enemy4.dienumber != 1)
		{
			enemy4.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
		if (my.dienumber != 1)
		{
			my.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
		if (enemy1.dienumber != 1)
		{
			enemy1.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
	}
	else if (distinction == 4)
	{
		if (enemy3.dienumber != 1)
		{
			enemy3.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
		if (enemy4.dienumber != 1)
		{
			enemy4.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
		if (my.dienumber != 1)
		{
			my.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
		if (enemy1.dienumber != 1)
		{
			enemy1.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
		if (enemy2.dienumber != 1)
		{
			enemy2.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
	}
	else if (distinction == 5)
	{
		if (enemy4.dienumber != 1)
		{
			enemy4.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
		if (my.dienumber != 1)
		{
			my.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
		if (enemy1.dienumber != 1)
		{
			enemy1.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
		if (enemy2.dienumber != 1)
		{
			enemy2.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
		if (enemy3.dienumber != 1)
		{
			enemy3.unvisiblecard[2] = game.cardcard[gamenumber];
			gamenumber++;
		}
	}
	cout << "\t���� ������ �Ѿ� ���ϴ�." << endl;
	Sleep(3000);
	system("cls");
	cout << "\t������ ���� �ð��Դϴ�. �ѹ� �غ�������" << endl;
	gamebatting.callnumber = 0; gamebatting.checknumber = 0;
	if (my.dienumber != 1)
	{
		cout << "\tplayer�� ��:";
		my.print_card(gameturn);
		cout << " " << my.unvisiblecard[2].cardshape << " " << my.unvisiblecard[2].cardNumber << endl;
	}
	if (enemy1.dienumber != 1)
	{
		cout << "\tenemy1�� ��:";
		enemy1.AIprint_card(gameturn);
		cout << endl;
	}
	if (enemy2.dienumber != 1)
	{
		cout << "\tenemy2�� ��:";
		enemy2.AIprint_card(gameturn);
		cout << endl;
	}
	if (enemy3.dienumber != 1)
	{
		cout << "\tenemy3�� ��:";
		enemy3.AIprint_card(gameturn);
		cout << endl;
	}
	if (enemy4.dienumber != 1)
	{
		cout << "\tenemy4�� ��:";
		enemy4.AIprint_card(gameturn);
		cout << endl;
	}
	gameturn++;//gameturn==4
	distinction_winner();
	while (gamebatting.callnumber + gamebatting.checknumber < 5)//������ ����
	{
		batting_ing();
		Sleep(1500);
		system("cls");
		if (my.dienumber != 1)
		{
			cout << "\tplayer�� ��:";
			my.print_card(gameturn - 1);
			cout << " " << my.unvisiblecard[2].cardshape << " " << my.unvisiblecard[2].cardNumber << endl;
		}
		if (enemy1.dienumber != 1)
		{
			cout << "\tenemy1�� ��:";
			enemy1.AIprint_card(gameturn - 1);
			cout << endl;
		}
		if (enemy2.dienumber != 1)
		{
			cout << "\tenemy2�� ��:";
			enemy2.AIprint_card(gameturn - 1);
			cout << endl;
		}
		if (enemy3.dienumber != 1)
		{
			cout << "\tenemy3�� ��:";
			enemy3.AIprint_card(gameturn - 1);
			cout << endl;
		}
		if (enemy4.dienumber != 1)
		{
			cout << "\tenemy4�� ��:";
			enemy4.AIprint_card(gameturn - 1);
			cout << endl;
		}
		cout << "\t���� �ǵ�:" << gamebatting.current_batting_money << " ���� ���� �ɸ� ��:" << gamebatting.batting_money << endl;
	}
	cout << "\t����� ����â�� ���ɴϴ�." << endl;
	cout << "\t���� ������ �Ѿ� ���ϴ�." << endl;
	Sleep(1500);
	system("cls");
	if (my.dienumber != 1)
	{
		cout <<endl<< "\tplayer�� ��:";
		my.print_card(gameturn - 1);
		cout << " " << my.unvisiblecard[2].cardshape << " " << my.unvisiblecard[2].cardNumber << endl;

	}
	if (enemy1.dienumber != 1)
	{
		cout << "\tenemy1�� ��:";
		enemy1.AIFinalcard();
		cout << endl;
	}
	if (enemy2.dienumber != 1)
	{
		cout << "\tenemy2�� ��:";
		enemy2.AIFinalcard();
		cout << endl;
	}
	if (enemy3.dienumber != 1)
	{
		cout << "\tenemy3�� ��:";
		enemy3.AIFinalcard();
		cout << endl;
	}
	if (enemy4.dienumber != 1)
	{
		cout << "\tenemy4�� ��:";
		enemy4.AIFinalcard();
		cout << endl;
	}
	if (current_winner == 0)
	{
		cout << "\tplayer�� �¸�" << endl;
		my.money = my.money + gamebatting.batting_money + nagari;
		int temp = (winnervaluejokbo / 15);//�̱� ���� ������ �ٷ��� �� ���� �Դϴ�.
		if ((winnervaluejokbo / 15) == 13)
		{
			cout << "\t�ο� ��Ʈ����Ʈ �÷����� ����ϼ̽��ϴ�." << endl;
		}
		else if (temp == 12)
		{
			cout << "\t�齺Ʈ����Ʈ �÷����� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 11)
		{
			cout << "\t��Ʈ����Ʈ �÷����� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 10)
		{
			cout << "\t��ī��� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 9)
		{
			cout << "\tǮ�Ͽ콺�� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 8)
		{
			cout << "\t�÷����� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 7)
		{
			cout << "\t����ƾ���� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 6)
		{
			cout << "\t�齺Ʈ����Ʈ�� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 5)
		{
			cout << "\t��Ʈ����Ʈ�� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 4)
		{
			cout << "\tƮ���÷� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 3)
		{
			cout << "\t������ ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 2)
		{
			cout << "\t������ ����Ͽ����ϴ�." << endl;
		}
		else
		{
			cout << "\t���� ������" << endl;
		}
		cout << "\tȹ���� �� :" << gamebatting.batting_money << "�Դϴ�." << endl;
		cout << "\t���� ���� :" << my.money << "�Դϴ�." << endl;
		cout << "\tenemy1�� ����" << enemy1.money << "�Դϴ�." << endl;
		cout << "\tenemy2�� ����" << enemy2.money << "�Դϴ�." << endl;
		cout << "\tenemy3�� ����" << enemy3.money << "�Դϴ�." << endl;
		cout << "\tenemy4�� ����" << enemy4.money << "�Դϴ�." << endl;
	}
	else if (current_winner == 1)
	{
		cout << "enemy1�� �¸�" << endl;
		enemy1.money = enemy1.money + gamebatting.batting_money + nagari;
		int temp = (winnervaluejokbo / 15);//�̱� ���� ������ �ٷ��� �� ���� �Դϴ�.
		if ((winnervaluejokbo / 15) == 13)
		{
			cout << "\t�ο� ��Ʈ����Ʈ �÷����� ����ϼ̽��ϴ�." << endl;
		}
		else if (temp == 12)
		{
			cout << "\t�齺Ʈ����Ʈ �÷����� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 11)
		{
			cout << "\t��Ʈ����Ʈ �÷����� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 10)
		{
			cout << "\t��ī��� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 9)
		{
			cout << "\tǮ�Ͽ콺�� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 8)
		{
			cout << "\t�÷����� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 7)
		{
			cout << "\t����ƾ���� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 6)
		{
			cout << "\t�齺Ʈ����Ʈ�� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 5)
		{
			cout << "\t��Ʈ����Ʈ�� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 4)
		{
			cout << "\tƮ���÷� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 3)
		{
			cout << "\t������ ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 2)
		{
			cout << "\t������ ����Ͽ����ϴ�." << endl;
		}
		else
		{
			cout << "\t���� ������" << endl;
		}
		cout << "\t���� ���� :" << my.money << "�Դϴ�." << endl;
		cout << "\tenemy1�� ����" << enemy1.money << "�Դϴ�." << endl;
		cout << "\tenemy2�� ����" << enemy2.money << "�Դϴ�." << endl;
		cout << "\tenemy3�� ����" << enemy3.money << "�Դϴ�." << endl;
		cout << "\tenemy4�� ����" << enemy4.money << "�Դϴ�." << endl;
	}
	else if (current_winner == 2)
	{
		cout << "\tenemy2�� �¸�" << endl;
		enemy2.money = enemy2.money + gamebatting.batting_money + nagari;
		int temp = (winnervaluejokbo / 15);//�̱� ���� ������ �ٷ��� �� ���� �Դϴ�.
		if ((winnervaluejokbo / 15) == 13)
		{
			cout << "\t�ο� ��Ʈ����Ʈ �÷����� ����ϼ̽��ϴ�." << endl;
		}
		else if (temp == 12)
		{
			cout << "\t�齺Ʈ����Ʈ �÷����� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 11)
		{
			cout << "\t��Ʈ����Ʈ �÷����� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 10)
		{
			cout << "\t��ī��� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 9)
		{
			cout << "\tǮ�Ͽ콺�� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 8)
		{
			cout << "\t�÷����� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 7)
		{
			cout << "\t����ƾ���� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 6)
		{
			cout << "\t�齺Ʈ����Ʈ�� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 5)
		{
			cout << "\t��Ʈ����Ʈ�� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 4)
		{
			cout << "\tƮ���÷� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 3)
		{
			cout << "\t������ ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 2)
		{
			cout << "\t������ ����Ͽ����ϴ�." << endl;
		}
		else
		{
			cout << "\t���� ������" << endl;
		}
		cout << "\t���� ���� :" << my.money << "�Դϴ�." << endl;
		cout << "\tenemy1�� ����" << enemy1.money << "�Դϴ�." << endl;
		cout << "\tenemy2�� ����" << enemy2.money << "�Դϴ�." << endl;
		cout << "\tenemy3�� ����" << enemy3.money << "�Դϴ�." << endl;
		cout << "\tenemy4�� ����" << enemy4.money << "�Դϴ�." << endl;
	}
	else if (current_winner == 3)
	{
		cout << "\tenemy3�� �¸�" << endl;
		enemy3.money = enemy3.money + gamebatting.batting_money + nagari;
		int temp = (winnervaluejokbo / 15);//�̱� ���� ������ �ٷ��� �� ���� �Դϴ�.
		if ((winnervaluejokbo / 15) == 13)
		{
			cout << "\t�ο� ��Ʈ����Ʈ �÷����� ����ϼ̽��ϴ�." << endl;
		}
		else if (temp == 12)
		{
			cout << "\t�齺Ʈ����Ʈ �÷����� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 11)
		{
			cout << "\t��Ʈ����Ʈ �÷����� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 10)
		{
			cout << "\t��ī��� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 9)
		{
			cout << "\tǮ�Ͽ콺�� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 8)
		{
			cout << "\t�÷����� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 7)
		{
			cout << "\t����ƾ���� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 6)
		{
			cout << "\t�齺Ʈ����Ʈ�� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 5)
		{
			cout << "\t��Ʈ����Ʈ�� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 4)
		{
			cout << "\tƮ���÷� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 3)
		{
			cout << "\t������ ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 2)
		{
			cout << "\t������ ����Ͽ����ϴ�." << endl;
		}
		else
		{
			cout << "\t���� ������" << endl;
		}
		cout << "\t���� ���� :" << my.money << "�Դϴ�." << endl;
		cout << "\tenemy1�� ����" << enemy1.money << "�Դϴ�." << endl;
		cout << "\tenemy2�� ����" << enemy2.money << "�Դϴ�." << endl;
		cout << "\tenemy3�� ����" << enemy3.money << "�Դϴ�." << endl;
		cout << "\tenemy4�� ����" << enemy4.money << "�Դϴ�." << endl;
	}
	else if (current_winner == 4)
	{
		cout << "\tenemy4�� �¸�" << endl;
		enemy4.money = enemy4.money + gamebatting.batting_money + nagari;
		int temp = (winnervaluejokbo / 15);//�̱� ���� ������ �ٷ��� �� ���� �Դϴ�.
		if ((winnervaluejokbo / 15) == 13)
		{
			cout << "\t�ο� ��Ʈ����Ʈ �÷����� ����ϼ̽��ϴ�." << endl;
		}
		else if (temp == 12)
		{
			cout << "\t�齺Ʈ����Ʈ �÷����� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 11)
		{
			cout << "\t��Ʈ����Ʈ �÷����� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 10)
		{
			cout << "\t��ī��� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 9)
		{
			cout << "\tǮ�Ͽ콺�� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 8)
		{
			cout << "\t�÷����� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 7)
		{
			cout << "\t����ƾ���� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 6)
		{
			cout << "\t�齺Ʈ����Ʈ�� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 5)
		{
			cout << "\t��Ʈ����Ʈ�� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 4)
		{
			cout << "\tƮ���÷� ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 3)
		{
			cout << "\t������ ����Ͽ����ϴ�." << endl;
		}
		else if (temp == 2)
		{
			cout << "\t������ ����Ͽ����ϴ�." << endl;
		}
		else
		{
			cout << "\t���� ������" << endl;
		}
		cout << "\t���� ���� :" << my.money << "�Դϴ�." << endl;
		cout << "\tenemy1�� ����" << enemy1.money << "�Դϴ�." << endl;
		cout << "\tenemy2�� ����" << enemy2.money << "�Դϴ�." << endl;
		cout << "\tenemy3�� ����" << enemy3.money << "�Դϴ�." << endl;
		cout << "\tenemy4�� ����" << enemy4.money << "�Դϴ�." << endl;
	}
	else if (current_winner == 5)
	{
		if (nagari_number == 1)
		{
			nagari_number++;
		}
		else
		{
			nagari = 0;
		}
	}
	if (enemy1.money == 0)
	{
		enemy1.money = (my.money) + (my.money)*((rand() % 21 - 10) / 100);

	}
	if (enemy2.money == 0)
	{
		enemy2.money = (my.money) + (my.money)*((rand() % 21 - 10) / 100);

	}
	if (enemy3.money == 0)
	{
		enemy3.money = (my.money) + (my.money)*((rand() % 21 - 10) / 100);

	}
	if (enemy4.money == 0)
	{
		enemy4.money = (my.money) + (my.money)*((rand() % 21 - 10) / 100);

	}

	system("pause");
}
void pockergame::distinction_winner()
{
	if (my.dienumber != 1)
	{
		jokbo.distinction_jokbo(my);
		jokbo.jokbo_reset();
		winner_value[0] = my.value_jokbo;
	}
	else
	{
		winner_value[0] = 0;

	}
	if (enemy1.dienumber != 1)
	{
		jokbo.AIdistinction_jokbo(enemy1);
		jokbo.jokbo_reset();
		winner_value[1] = enemy1.value_jokbo;
	}
	else
	{
		winner_value[1] = 0;
	}
	if (enemy2.dienumber != 1)
	{
		jokbo.AIdistinction_jokbo(enemy2);
		jokbo.jokbo_reset();
		winner_value[2] = enemy2.value_jokbo;
	}
	else
	{
		winner_value[2] = 0;
	}
	if (enemy3.dienumber != 1)
	{
		jokbo.AIdistinction_jokbo(enemy3);
		jokbo.jokbo_reset();
		winner_value[3] = enemy3.value_jokbo;
	}
	else
	{
		winner_value[3] = 0;

	}
	if (enemy4.dienumber != 1)
	{
		jokbo.AIdistinction_jokbo(enemy4);
		jokbo.jokbo_reset();
		winner_value[4] = enemy4.value_jokbo;
	}
	else
	{
		winner_value[4] = 0;
	}
	float max_value_winner[5];//���� ��ų�����ϴ� �迭
	for (int i = 0; i < 5; i++)
	{
		max_value_winner[i] = winner_value[i];
	}
	float winnertemp = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			if (max_value_winner[i] > max_value_winner[i + 1])
			{
				winnertemp = max_value_winner[i];
				max_value_winner[i] = max_value_winner[i + 1];
				max_value_winner[i + 1] = winnertemp;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (max_value_winner[4] == winner_value[i])
		{
			if (max_value_winner[4] != max_value_winner[3])
			{
				current_winner = i;
				winnervaluejokbo = winner_value[i];
				break;
			}
			else
			{
				int a, b = 0;
				for (int j = i + 1; j < 5; j++)
				{
					if (max_value_winner[3] == winner_value[j])
					{
						if (i == 0)
						{
							a = my.highcard;
						}
						else if (i == 1)
						{
							a = enemy1.highcard;
						}
						else if (i == 2)
						{
							a = enemy2.highcard;
						}
						else if (i == 3)
						{
							a = enemy3.highcard;
						}
						else
						{
							a = enemy4.highcard;
						}
						if (j == 0)
						{
							b = my.highcard;
						}
						else if (j == 1)
						{
							b = enemy1.highcard;
						}
						else if (j == 2)
						{
							b = enemy2.highcard;
						}
						else if (j == 3)
						{
							b = enemy3.highcard;
						}
						else
						{
							b = enemy4.highcard;
						}
						if (a > b)
						{
							current_winner = i;
						}
						else if (a == b)
						{
							cout << "hey �̹����� �������̰ŵ� ???" << endl << "���������� ���� ���ž� ������" << endl;
							nagari = gamebatting.batting_money;
							nagari_number = 1;
							current_winner = 5;
						}
						else
						{
							current_winner = j;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		max_value_winner[i] = 0;
		winner_value[i] = 0;
	}
}
void pockergame::Dividing(int a, int b)//�г�����
{
	if (a == 1)
	{
		my_cardDividing(b);
	}
	else if (a == 2)
	{
		enemy1_cardDividing(b);
	}
	else if (a == 3)
	{
		enemy2_cardDividing(b);
	}
	else if (a == 4)
	{
		enemy3_cardDividing(b);
	}
	else if (a == 5)
	{
		enemy4_cardDividing(b);
	}
}
void pockergame::my_cardDividing(int a)
{
	if (my.dienumber != 1)
	{
		my.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
	if (enemy1.dienumber != 1)
	{
		enemy1.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
	if (enemy2.dienumber != 1)
	{
		enemy2.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
	if (enemy3.dienumber != 1)
	{
		enemy3.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
	if (enemy4.dienumber != 1)
	{
		enemy4.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
}//���� �켱�����϶� �޴°�
void pockergame::enemy1_cardDividing(int a)
{
	if (enemy1.dienumber != 1)
	{
		enemy1.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
	if (enemy2.dienumber != 1)
	{
		enemy2.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
	if (enemy3.dienumber != 1)
	{
		enemy3.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
	if (enemy4.dienumber != 1)
	{
		enemy4.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
	if (my.dienumber != 1)
	{
		my.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
}//enemy1�� �켱�����϶� �޴��Լ�
void pockergame::enemy2_cardDividing(int a)
{
	if (enemy2.dienumber != 1)
	{
		enemy2.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
	if (enemy3.dienumber != 1)
	{
		enemy3.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
	if (enemy4.dienumber != 1)
	{
		enemy4.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
	if (my.dienumber != 1)
	{
		my.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}

	if (enemy1.dienumber != 1)
	{
		enemy1.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
}//enemy2�� �켱�����϶� �޴��Լ�
void pockergame::enemy3_cardDividing(int a)
{
	if (enemy3.dienumber != 1)
	{
		enemy3.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
	if (enemy4.dienumber != 1)
	{
		enemy4.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
	if (my.dienumber != 1)
	{
		my.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}

	if (enemy1.dienumber != 1)
	{
		enemy1.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
	if (enemy2.dienumber != 1)
	{
		enemy2.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
}//enemy3�� �켱�����϶� �޴��Լ�
void pockergame::enemy4_cardDividing(int a)
{
	if (enemy4.dienumber != 1)
	{
		enemy4.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
	if (my.dienumber != 1)
	{
		my.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}

	if (enemy1.dienumber != 1)
	{
		enemy1.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
	if (enemy2.dienumber != 1)
	{
		enemy2.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
	if (enemy3.dienumber != 1)
	{
		enemy3.visiblecard[a + 1] = game.cardcard[gamenumber];
		gamenumber++;
	}
}//enemy4�� �켱�����϶� �޴��Լ�
int pockergame::distinction_card(int a)//�켱�����Ǻ����α׷� �޴� ���� ���� ��;
									   /*���°�� 1�̸� �÷��̾� ������ ī�带 ���� �ȴ�.*/
{
	int pair[5] = { 0,0,0,0,0 };//��� Ȯ�� ����
	int temp_card[4][5];//�ִ� Ȯ�� �ϱ� ���� �迭
	int temp1_card[4][5];//�ִ� Ȯ�� �ϱ� ���� �迭
	int distinctionpair[5] = { 0,0,0,0,0 };//�켱 ���� ����� ���� �迭
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			temp_card[i][j] = 0;
			temp1_card[i][j] = 0;
		}
	}
	for (int i = 0; i <= a; i++)//�迭�� ���� �ִ´�.
	{
		temp_card[i][0] = my.visiblecard[i].numberofcard;
		temp1_card[i][0] = my.visiblecard[i].numberofcard;
	}
	for (int i = 0; i <= a; i++)
	{
		temp_card[i][1] = enemy1.visiblecard[i].numberofcard;
		temp1_card[i][1] = enemy1.visiblecard[i].numberofcard;
	}
	for (int i = 0; i <= a; i++)
	{
		temp_card[i][2] = enemy2.visiblecard[i].numberofcard;
		temp1_card[i][2] = enemy2.visiblecard[i].numberofcard;
	}
	for (int i = 0; i <= a; i++)
	{
		temp_card[i][3] = enemy3.visiblecard[i].numberofcard;
		temp1_card[i][3] = enemy3.visiblecard[i].numberofcard;
	}
	for (int i = 0; i <= a; i++)
	{
		temp_card[i][4] = enemy4.visiblecard[i].numberofcard;
		temp1_card[i][4] = enemy4.visiblecard[i].numberofcard;
	}
	int Temp = 0;
	int max[4] = { 0,0,0,0 };
	for (int c = 0; c < 5; c++)/*��� ���θ� Ȯ���ϰ� ��� �Ͻ� card of number
							   ����*14�� �Ѵ�*/
	{
		for (int i = 0; i <= a; i++)
		{
			for (int j = i + 1; j < 4; j++)
			{
				if (temp_card[i][c] == temp_card[j][c])
				{
					pair[c]++;
					distinctionpair[c] = temp_card[i][c] * 14;
				}
			}
		}
	}
	if (pair[0] == 0 && pair[1] == 0 && pair[2] == 0 && pair[3] == 0 && pair[4] == 0)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4 - i; j++)/*����Ȯ��*/
			{
				Temp = temp_card[a][j];
				temp_card[a][j] = temp_card[a + 1][j + 1];
				temp_card[a][j + 1] = Temp;
			}
		}
		max[a] = temp_card[a][4];
		if (max[a] == temp1_card[a][0])
		{
			return 1;
		}
		else if (max[a] == temp1_card[a][1])
		{
			return 2;
		}
		else if (max[a] == temp1_card[a][2])
		{
			return 3;
		}
		else if (max[a] == temp1_card[a][3])
		{
			return 4;
		}
		else if (max[a] == temp1_card[a][4])
		{
			return 5;
		}
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			distinctionpair[i] = distinctionpair[i] + temp1_card[a][i];
		}
		if (distinctionpair[0] > distinctionpair[1] && distinctionpair[0] > distinctionpair[2] && distinctionpair[0] > distinctionpair[3] && distinctionpair[0] > distinctionpair[4])
		{
			return 1;
		}
		else if (distinctionpair[0] < distinctionpair[1] && distinctionpair[1] > distinctionpair[2] && distinctionpair[1] > distinctionpair[3] && distinctionpair[1] > distinctionpair[4])
		{
			return 2;
		}
		else if (distinctionpair[2] > distinctionpair[0] && distinctionpair[2] > distinctionpair[1] && distinctionpair[2] > distinctionpair[3] && distinctionpair[2] > distinctionpair[4])
		{
			return 3;
		}
		else if (distinctionpair[3] > distinctionpair[0] && distinctionpair[3] > distinctionpair[1] && distinctionpair[3] > distinctionpair[2] && distinctionpair[3] > distinctionpair[4])
		{
			return 4;
		}
		else if (distinctionpair[4] > distinctionpair[0] && distinctionpair[4] > distinctionpair[1] && distinctionpair[4] > distinctionpair[2] && distinctionpair[4] > distinctionpair[3])
		{
			return 5;
		}

	}
}
void pockergame::batting_first()
{
	my.playerfirstmoney = my.money;
	enemy1.firstmoney = enemy1.money;//�����ϱ����� ���� ������ �����ϴ�.
	enemy2.firstmoney = enemy2.money;
	enemy3.firstmoney = enemy3.money;
	enemy4.firstmoney = enemy4.money;
	gamebatting.batting_money = 5 * gamebatting.current_batting_money;//ó�� �����Ҷ� �⺻�ݾ�
	my.money = my.money - gamebatting.current_batting_money;
	enemy1.money = enemy1.money - gamebatting.current_batting_money;
	enemy2.money = enemy2.money - gamebatting.current_batting_money;
	enemy3.money = enemy3.money - gamebatting.current_batting_money;
	enemy4.money = enemy4.money - gamebatting.current_batting_money;
	gamebatting.callnumber = 0; gamebatting.checknumber = 0;
}
void pockergame::batting_ing()
{
	battingcount = 0;//��ɾ� �� ���� ���� ���̴�.
	cout << "\t1. check(���Ѻ��ϴ�)" << endl;
	cout << "\t2. call(�ǵ��� �״�� ����)" << endl;
	cout << "\t3. double(�ǵ��� �ι踦 �ø��ڽ��ϴ�.)" << endl;
	cout << "\t4. half(���� �÷��� ���� ���� �ɰڽ��ϴ�.)" << endl;
	cout << "\t5. die(�װڽ��ϴ�.)" << endl;		
	cout << "\t������ ������ check�� ���ֽʽÿ�" << endl;
	if (distinction == 1)
	{
		if (my.dienumber != 1)//die�� �����ϸ�dienumber���̴� die�� �����ߴ��� ���� ���� �ʾҴ��� �Ǵ� �Ѵ�. 
		{
			Sleep(1000);
			my.playerbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)//call�� check�� �Ǻ��Ѵ�.
		{
			return;
		}
		if (enemy1.dienumber != 1)//die�� �����ϸ�dienumber���̴� die�� �����ߴ��� ���� ���� �ʾҴ��� �Ǵ� �Ѵ�. 
		{
			Sleep(500);
			Alpago.AI_distinction_card1(gameturn, enemy1, gamebatting);
			cout << "enemy1 batting:" << endl;
			enemy1.AIbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)//call�� check�� �Ǻ��Ѵ�.
		{
			return;
		}
		if (enemy2.dienumber != 1)//die�� �����ϸ�dienumber���̴� die�� �����ߴ��� ���� ���� �ʾҴ��� �Ǵ� �Ѵ�. 
		{
			Sleep(500);
			Alpago.AI_distinction_card2(gameturn, my, enemy2, enemy1, enemy3, enemy4, gamebatting);
			cout << "enemy2 batting:" << endl;
			enemy2.AIbatting(gamebatting, gameturn);//call�� check�� �Ǻ��Ѵ�
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)//call�� check�� �Ǻ��Ѵ�
		{
			return;
		}
		if (enemy3.dienumber != 1)//die�� �����ϸ�dienumber���̴� die�� �����ߴ��� ���� ���� �ʾҴ��� �Ǵ� �Ѵ�. 
		{
			Sleep(500);
			Alpago.AI_distinction_card3(gameturn, my, enemy3, enemy1, enemy2, enemy4, gamebatting);
			cout << "enemy3 batting:" << endl;
			enemy3.AIbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)//call�� check�� �Ǻ��Ѵ�
		{
			return;
		}
		if (enemy4.dienumber != 1)//die�� �����ϸ�dienumber���̴� die�� �����ߴ��� ���� ���� �ʾҴ��� �Ǵ� �Ѵ�. 
		{
			Sleep(500);
			Alpago.AI_distinction_card4(gameturn, my, enemy4, enemy1, enemy2, enemy3, gamebatting);
			cout << "enemy4 batting:" << endl;
			enemy4.AIbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
	}
	else if (distinction == 2)
	{
		if (enemy1.dienumber != 1)
		{
			Sleep(500);
			Alpago.AI_distinction_card1(gameturn, enemy1, gamebatting);
			cout << "enemy1 batting:";
			enemy1.AIbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)
		{
			return;
		}
		if (enemy2.dienumber != 1)
		{
			Sleep(500);
			Alpago.AI_distinction_card2(gameturn, my, enemy2, enemy1, enemy3, enemy4, gamebatting);
			cout << "enemy2 batting:";
			enemy2.AIbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)
		{
			return;
		}
		if (enemy3.dienumber != 1)
		{
			Sleep(500);
			Alpago.AI_distinction_card3(gameturn, my, enemy3, enemy1, enemy2, enemy4, gamebatting);
			cout << "enemy3 batting:";
			enemy3.AIbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)
		{
			return;
		}
		if (enemy4.dienumber != 1)
		{
			Sleep(500);
			Alpago.AI_distinction_card4(gameturn, my, enemy4, enemy1, enemy2, enemy3, gamebatting);
			cout << "enemy4 batting:";
			enemy4.AIbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)
		{
			return;
		}
		if (my.dienumber != 1)
		{
			my.playerbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
	}
	else if (distinction == 3)
	{
		if (enemy2.dienumber != 1)
		{
			Sleep(500);
			Alpago.AI_distinction_card2(gameturn, my, enemy2, enemy1, enemy3, enemy4, gamebatting);
			cout << "enemy2 batting:";
			enemy2.AIbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)
		{
			return;
		}
		if (enemy3.dienumber != 1)
		{
			Sleep(500);
			Alpago.AI_distinction_card3(gameturn, my, enemy3, enemy1, enemy2, enemy4, gamebatting);
			cout << "enemy3 batting:";
			enemy3.AIbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)
		{
			return;
		}
		if (enemy4.dienumber != 1)
		{
			Sleep(500);
			Alpago.AI_distinction_card3(gameturn, my, enemy4, enemy1, enemy2, enemy4, gamebatting);
			cout << "enemy4 batting:";
			enemy4.AIbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)
		{
			return;
		}
		if (my.dienumber != 1)
		{
			my.playerbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)
		{
			return;
		}
		if (enemy1.dienumber != 1)
		{
			Sleep(500);
			Alpago.AI_distinction_card1(gameturn, enemy1, gamebatting);
			cout << "enemy1 batting:";
			enemy1.AIbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
	}
	else if (distinction == 4)
	{
		if (enemy3.dienumber != 1)
		{
			Sleep(500);
			Alpago.AI_distinction_card3(gameturn, my, enemy3, enemy1, enemy2, enemy4, gamebatting);
			cout << "enemy3 batting:";
			enemy3.AIbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)
		{
			return;
		}
		if (enemy4.dienumber != 1)
		{
			Sleep(500);
			Alpago.AI_distinction_card4(gameturn, my, enemy4, enemy1, enemy2, enemy3, gamebatting);
			cout << "enemy4 batting:";
			enemy4.AIbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)
		{
			return;
		}
		if (my.dienumber != 1)
		{
			my.playerbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)
		{
			return;
		}
		if (enemy1.dienumber != 1)
		{
			Sleep(500);
			Alpago.AI_distinction_card1(gameturn, enemy1, gamebatting);
			cout << "enemy1 batting:";
			enemy1.AIbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)
		{
			return;
		}
		if (enemy2.dienumber != 1)
		{
			Sleep(500); Alpago.AI_distinction_card2(gameturn, my, enemy2, enemy1, enemy3, enemy4, gamebatting);
			cout << "enemy2 batting:";
			enemy2.AIbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
	}
	else if (distinction == 5)
	{
		if (enemy4.dienumber != 1)
		{
			Sleep(500);
			Alpago.AI_distinction_card3(gameturn, my, enemy4, enemy1, enemy2, enemy4, gamebatting);
			cout << "enemy4 batting:";
			enemy4.AIbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)
		{
			return;
		}
		if (my.dienumber != 1)
		{
			my.playerbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)
		{
			return;
		}
		if (enemy1.dienumber != 1)
		{
			Sleep(500);
			Alpago.AI_distinction_card1(gameturn, enemy1, gamebatting);
			cout << "enemy1 batting:";
			enemy1.AIbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)
		{
			return;
		}
		if (enemy2.dienumber != 1)
		{
			Alpago.AI_distinction_card2(gameturn, my, enemy2, enemy1, enemy3, enemy4, gamebatting);
			cout << "enemy2 batting:";
			enemy2.AIbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)
		{
			return;
		}
		if (enemy3.dienumber != 1)
		{
			Sleep(500);
			Alpago.AI_distinction_card3(gameturn, my, enemy3, enemy1, enemy2, enemy4, gamebatting);
			cout << "enemy3 batting:";
			enemy3.AIbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
	}


}
