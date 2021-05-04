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
	/*여기서 모든 변수를 초기화 해야 된다(돈을 제외하고)*/
	reset();//변수들을 리셋 해준다
	cout <<endl<<endl<< "\tplayer 의 돈은" << my.money << endl;
	cout << "\t패가 도착하였습니다." << endl;
	game.cardmade();//카드를 만듭니다.
	cout << "\t패를 섞고 있습니다." << endl;
	game.shufflecard();//카드를 섞습니다.
	cout << "\t당신의 패는 ";
	for (int i = 0; i < 3; i++)
	{
		my.firstcard[i] = game.cardcard[gamenumber];
		cout << " " << my.firstcard[i].cardshape << " " << my.firstcard[i].cardNumber;
		gamenumber++;
	}//첫번째 카드를 넘겨주는 코드
	for (int i = 0; i < 3; i++)//첫번째 카드를 넘겨주는 코드
	{
		enemy1.firstcard[i] = game.cardcard[gamenumber];
		gamenumber++;
	}//첫번째 카드를 넘겨주는 코드
	for (int i = 0; i < 3; i++)
	{
		enemy2.firstcard[i] = game.cardcard[gamenumber];
		gamenumber++;
	}//첫번째 카드를 넘겨주는 코드
	for (int i = 0; i < 3; i++)
	{
		enemy3.firstcard[i] = game.cardcard[gamenumber];
		gamenumber++;
	}//첫번째 카드를 넘겨주는 코드
	for (int i = 0; i < 3; i++)
	{
		enemy4.firstcard[i] = game.cardcard[gamenumber];
		gamenumber++;
	}//첫번째 카드를 넘겨주는 코드
	cout << endl;
	my.selectfirstcard();//보여줄 카드와 안보여줄 카드를 판별하는 함수 입니다.
	cout << "\tenemy1의 패는" << endl;
	enemy1.AIselectfirstcard();//보여줄 카드와 안보여줄 카드를 판별하는 함수 입니다.
	cout << "\tenemy2의 패는" << endl;
	enemy2.AIselectfirstcard();//보여줄 카드와 안보여줄 카드를 판별하는 함수 입니다.
	cout << "\tenemy3의 패는" << endl;
	enemy3.AIselectfirstcard();//보여줄 카드와 안보여줄 카드를 판별하는 함수 입니다.
	cout << "\tenemy4의 패는" << endl;
	enemy4.AIselectfirstcard();//보여줄 카드와 안보여줄 카드를 판별하는 함수 입니다.
	cout << "\t다음 턴으로 넘어 갑니다." << endl;
	Sleep(1500);
	distinction = distinction_card(gameturn);//카드를 나눠줄 우선 순위를 판별합니다.
	Dividing(distinction, gameturn);//첫번째로 나눠준다(4장째)
	gameturn++;//gameturn이 다음턴으로 넘어 갑니다.gameturn ==1
	system("cls");//콘솔창을 정리 합니다.
	cout << endl << endl << endl;
	gamebatting.battingMoney(my.money);//기본 배팅 금액을 알려 줍니다.
	cout << "\tplayer의 패:";
	my.print_card(gameturn);//카드를 보여 주는 함수 입니다. my라는 플레이어 자신의 카드를 보여 줍니다.
	cout << endl;
	cout << "\tenemy1의 패:";
	enemy1.AIprint_card(gameturn);//enemy1이라는 AI가 가진 카드를 보여줍니다. 
	cout << endl;
	cout << "\tenemy2의 패:";
	enemy2.AIprint_card(gameturn);//enemy2이라는 AI가 가진 카드를 보여줍니다. 
	cout << endl;
	cout << "\tenemy3의 패:";
	enemy3.AIprint_card(gameturn);//enemy3이라는 AI가 가진 카드를 보여줍니다. 
	cout << endl;
	cout << "\tenemy4의 패:";
	enemy4.AIprint_card(gameturn);//enemy4이라는 AI가 가진 카드를 보여줍니다. 
	cout << endl;
	distinction = distinction_card(gameturn);//우선순위를 판별합니다.
	Dividing(distinction, gameturn);//두번째로 나눠준다(5장째 이번 나눠주고 배팅 시작)
	gameturn++;//다음 턴으로 넘어 갑니다.gameturn==2
	cout << endl;
	Sleep(2000);
	system("cls");
	cout << endl << endl << endl;
	cout << "\tplayer의 패:";
	my.print_card(gameturn);//앞에 나왔던 print 함수랑 기능이 같습니다. 
	cout << endl;
	cout << "\tenemy1의 패:";
	enemy1.AIprint_card(gameturn);//앞에 나왔던 print 함수랑 기능이 같습니다.
	cout << endl;
	cout << "\tenemy2의 패:";
	enemy2.AIprint_card(gameturn);//앞에 나왔던 print 함수랑 기능이 같습니다.
	cout << endl;
	cout << "\tenemy3의 패:";
	enemy3.AIprint_card(gameturn);//앞에 나왔던 print 함수랑 기능이 같습니다.
	cout << endl;
	cout << "\tenemy4의 패:";
	enemy4.AIprint_card(gameturn);//앞에 나왔던 print 함수랑 기능이 같습니다.
	cout << endl;
	batting_first();
	while (gamebatting.callnumber + gamebatting.checknumber < 5)//첫번째 배팅을 진행하는 무한 루프입니다. callnumber와 checknumber를 설정해 주고 이 call과 check를 5번 하면 끝난다. 
	{
		batting_ing();
		Sleep(1500);
		system("cls");
		cout << "\tplayer의 패:";
		my.print_card(gameturn);//앞에 나왔던 print 함수랑 기능이 같습니다. 
		cout << endl;
		cout << "\tenemy1의 패:";
		enemy1.AIprint_card(gameturn);//앞에 나왔던 print 함수랑 기능이 같습니다.
		cout << endl;
		cout << "\tenemy2의 패:";
		enemy2.AIprint_card(gameturn);//앞에 나왔던 print 함수랑 기능이 같습니다.
		cout << endl;
		cout << "\tenemy3의 패:";
		enemy3.AIprint_card(gameturn);//앞에 나왔던 print 함수랑 기능이 같습니다.
		cout << endl;
		cout << "\tenemy4의 패:";
		enemy4.AIprint_card(gameturn);//앞에 나왔던 print 함수랑 기능이 같습니다.
		cout << endl;
	}
	distinction = distinction_card(gameturn);
	Dividing(distinction, gameturn);//세번째로 나눠준다(6장째)
	gameturn++;//game turn== 3
	cout << endl;
	cout << "\t다음 턴으로 넘어 갑니다." << endl;
	Sleep(1500);
	system("cls");
	if (my.dienumber != 1)
	{
		cout << "\tplayer의 패:";
		my.print_card(gameturn);
		cout << endl;
	}
	if (enemy1.dienumber != 1)
	{
		cout << "\tenemy1의 패:";
		enemy1.AIprint_card(gameturn);
		cout << endl;
	}
	if (enemy2.dienumber != 1)
	{
		cout << "\tenemy2의 패:";
		enemy2.AIprint_card(gameturn);
		cout << endl;
	}
	if (enemy3.dienumber != 1)
	{
		cout << "\tenemy3의 패:";
		enemy3.AIprint_card(gameturn);
		cout << endl;
	}
	if (enemy4.dienumber != 1)
	{
		cout << "\tenemy4의 패:";
		enemy4.AIprint_card(gameturn);
		cout << endl;
	}
	gamebatting.callnumber = 0; gamebatting.checknumber = 0;
	while (gamebatting.callnumber + gamebatting.checknumber < 5)//두번째 배팅 
	{
		batting_ing();
		Sleep(1500);
		system("cls");
		if (my.dienumber != 1)
		{
			cout << "\tplayer의 패:";
			my.print_card(gameturn);
			cout << endl;
		}
		if (enemy1.dienumber != 1)
		{
			cout << "\tenemy1의 패:";
			enemy1.AIprint_card(gameturn);
			cout << endl;
		}
		if (enemy2.dienumber != 1)
		{
			cout << "\tenemy2의 패:";
			enemy2.AIprint_card(gameturn);
			cout << endl;
		}
		if (enemy3.dienumber != 1)
		{
			cout << "\tenemy3의 패:";
			enemy3.AIprint_card(gameturn);
			cout << endl;
		}
		if (enemy4.dienumber != 1)
		{
			cout << "\tenemy4의 패:";
			enemy4.AIprint_card(gameturn);
			cout << endl;
		}
		cout << "\t현재 판돈:" << gamebatting.current_batting_money << " 지금 까지 걸린 돈:" << gamebatting.batting_money << endl;
	}
	distinction = distinction_card(gameturn);//마지막 히든카드
	if (distinction == 1)//마지막 히든카드를 받는 과정 
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
	cout << "\t다음 턴으로 넘어 갑니다." << endl;
	Sleep(3000);
	system("cls");
	cout << "\t마지막 배팅 시간입니다. 한번 해보시지요" << endl;
	gamebatting.callnumber = 0; gamebatting.checknumber = 0;
	if (my.dienumber != 1)
	{
		cout << "\tplayer의 패:";
		my.print_card(gameturn);
		cout << " " << my.unvisiblecard[2].cardshape << " " << my.unvisiblecard[2].cardNumber << endl;
	}
	if (enemy1.dienumber != 1)
	{
		cout << "\tenemy1의 패:";
		enemy1.AIprint_card(gameturn);
		cout << endl;
	}
	if (enemy2.dienumber != 1)
	{
		cout << "\tenemy2의 패:";
		enemy2.AIprint_card(gameturn);
		cout << endl;
	}
	if (enemy3.dienumber != 1)
	{
		cout << "\tenemy3의 패:";
		enemy3.AIprint_card(gameturn);
		cout << endl;
	}
	if (enemy4.dienumber != 1)
	{
		cout << "\tenemy4의 패:";
		enemy4.AIprint_card(gameturn);
		cout << endl;
	}
	gameturn++;//gameturn==4
	distinction_winner();
	while (gamebatting.callnumber + gamebatting.checknumber < 5)//마지막 배팅
	{
		batting_ing();
		Sleep(1500);
		system("cls");
		if (my.dienumber != 1)
		{
			cout << "\tplayer의 패:";
			my.print_card(gameturn - 1);
			cout << " " << my.unvisiblecard[2].cardshape << " " << my.unvisiblecard[2].cardNumber << endl;
		}
		if (enemy1.dienumber != 1)
		{
			cout << "\tenemy1의 패:";
			enemy1.AIprint_card(gameturn - 1);
			cout << endl;
		}
		if (enemy2.dienumber != 1)
		{
			cout << "\tenemy2의 패:";
			enemy2.AIprint_card(gameturn - 1);
			cout << endl;
		}
		if (enemy3.dienumber != 1)
		{
			cout << "\tenemy3의 패:";
			enemy3.AIprint_card(gameturn - 1);
			cout << endl;
		}
		if (enemy4.dienumber != 1)
		{
			cout << "\tenemy4의 패:";
			enemy4.AIprint_card(gameturn - 1);
			cout << endl;
		}
		cout << "\t현재 판돈:" << gamebatting.current_batting_money << " 지금 까지 걸린 돈:" << gamebatting.batting_money << endl;
	}
	cout << "\t결과는 다음창에 나옵니다." << endl;
	cout << "\t다음 턴으로 넘어 갑니다." << endl;
	Sleep(1500);
	system("cls");
	if (my.dienumber != 1)
	{
		cout <<endl<< "\tplayer의 패:";
		my.print_card(gameturn - 1);
		cout << " " << my.unvisiblecard[2].cardshape << " " << my.unvisiblecard[2].cardNumber << endl;

	}
	if (enemy1.dienumber != 1)
	{
		cout << "\tenemy1의 패:";
		enemy1.AIFinalcard();
		cout << endl;
	}
	if (enemy2.dienumber != 1)
	{
		cout << "\tenemy2의 패:";
		enemy2.AIFinalcard();
		cout << endl;
	}
	if (enemy3.dienumber != 1)
	{
		cout << "\tenemy3의 패:";
		enemy3.AIFinalcard();
		cout << endl;
	}
	if (enemy4.dienumber != 1)
	{
		cout << "\tenemy4의 패:";
		enemy4.AIFinalcard();
		cout << endl;
	}
	if (current_winner == 0)
	{
		cout << "\tplayer의 승리" << endl;
		my.money = my.money + gamebatting.batting_money + nagari;
		int temp = (winnervaluejokbo / 15);//이긴 족보 가르쳐 줄려고 쓴 변수 입니다.
		if ((winnervaluejokbo / 15) == 13)
		{
			cout << "\t로열 스트레이트 플러쉬로 우승하셨습니다." << endl;
		}
		else if (temp == 12)
		{
			cout << "\t백스트레이트 플러쉬로 우승하였습니다." << endl;
		}
		else if (temp == 11)
		{
			cout << "\t스트레이트 플러쉬로 우승하였습니다." << endl;
		}
		else if (temp == 10)
		{
			cout << "\t포카드로 우승하였습니다." << endl;
		}
		else if (temp == 9)
		{
			cout << "\t풀하우스로 우승하였습니다." << endl;
		}
		else if (temp == 8)
		{
			cout << "\t플러쉬로 우승하였습니다." << endl;
		}
		else if (temp == 7)
		{
			cout << "\t마운틴으로 우승하였습니다." << endl;
		}
		else if (temp == 6)
		{
			cout << "\t백스트레이트로 우승하였습니다." << endl;
		}
		else if (temp == 5)
		{
			cout << "\t스트레이트로 우승하였습니다." << endl;
		}
		else if (temp == 4)
		{
			cout << "\t트리플로 우승하였습니다." << endl;
		}
		else if (temp == 3)
		{
			cout << "\t투페어로 우승하였습니다." << endl;
		}
		else if (temp == 2)
		{
			cout << "\t원페어로 우승하였습니다." << endl;
		}
		else
		{
			cout << "\t운이 좋군요" << endl;
		}
		cout << "\t획득한 돈 :" << gamebatting.batting_money << "입니다." << endl;
		cout << "\t현재 돈은 :" << my.money << "입니다." << endl;
		cout << "\tenemy1의 돈은" << enemy1.money << "입니다." << endl;
		cout << "\tenemy2의 돈은" << enemy2.money << "입니다." << endl;
		cout << "\tenemy3의 돈은" << enemy3.money << "입니다." << endl;
		cout << "\tenemy4의 돈은" << enemy4.money << "입니다." << endl;
	}
	else if (current_winner == 1)
	{
		cout << "enemy1의 승리" << endl;
		enemy1.money = enemy1.money + gamebatting.batting_money + nagari;
		int temp = (winnervaluejokbo / 15);//이긴 족보 가르쳐 줄려고 쓴 변수 입니다.
		if ((winnervaluejokbo / 15) == 13)
		{
			cout << "\t로열 스트레이트 플러쉬로 우승하셨습니다." << endl;
		}
		else if (temp == 12)
		{
			cout << "\t백스트레이트 플러쉬로 우승하였습니다." << endl;
		}
		else if (temp == 11)
		{
			cout << "\t스트레이트 플러쉬로 우승하였습니다." << endl;
		}
		else if (temp == 10)
		{
			cout << "\t포카드로 우승하였습니다." << endl;
		}
		else if (temp == 9)
		{
			cout << "\t풀하우스로 우승하였습니다." << endl;
		}
		else if (temp == 8)
		{
			cout << "\t플러쉬로 우승하였습니다." << endl;
		}
		else if (temp == 7)
		{
			cout << "\t마운틴으로 우승하였습니다." << endl;
		}
		else if (temp == 6)
		{
			cout << "\t백스트레이트로 우승하였습니다." << endl;
		}
		else if (temp == 5)
		{
			cout << "\t스트레이트로 우승하였습니다." << endl;
		}
		else if (temp == 4)
		{
			cout << "\t트리플로 우승하였습니다." << endl;
		}
		else if (temp == 3)
		{
			cout << "\t투페어로 우승하였습니다." << endl;
		}
		else if (temp == 2)
		{
			cout << "\t원페어로 우승하였습니다." << endl;
		}
		else
		{
			cout << "\t운이 좋군요" << endl;
		}
		cout << "\t현재 돈은 :" << my.money << "입니다." << endl;
		cout << "\tenemy1의 돈은" << enemy1.money << "입니다." << endl;
		cout << "\tenemy2의 돈은" << enemy2.money << "입니다." << endl;
		cout << "\tenemy3의 돈은" << enemy3.money << "입니다." << endl;
		cout << "\tenemy4의 돈은" << enemy4.money << "입니다." << endl;
	}
	else if (current_winner == 2)
	{
		cout << "\tenemy2의 승리" << endl;
		enemy2.money = enemy2.money + gamebatting.batting_money + nagari;
		int temp = (winnervaluejokbo / 15);//이긴 족보 가르쳐 줄려고 쓴 변수 입니다.
		if ((winnervaluejokbo / 15) == 13)
		{
			cout << "\t로열 스트레이트 플러쉬로 우승하셨습니다." << endl;
		}
		else if (temp == 12)
		{
			cout << "\t백스트레이트 플러쉬로 우승하였습니다." << endl;
		}
		else if (temp == 11)
		{
			cout << "\t스트레이트 플러쉬로 우승하였습니다." << endl;
		}
		else if (temp == 10)
		{
			cout << "\t포카드로 우승하였습니다." << endl;
		}
		else if (temp == 9)
		{
			cout << "\t풀하우스로 우승하였습니다." << endl;
		}
		else if (temp == 8)
		{
			cout << "\t플러쉬로 우승하였습니다." << endl;
		}
		else if (temp == 7)
		{
			cout << "\t마운틴으로 우승하였습니다." << endl;
		}
		else if (temp == 6)
		{
			cout << "\t백스트레이트로 우승하였습니다." << endl;
		}
		else if (temp == 5)
		{
			cout << "\t스트레이트로 우승하였습니다." << endl;
		}
		else if (temp == 4)
		{
			cout << "\t트리플로 우승하였습니다." << endl;
		}
		else if (temp == 3)
		{
			cout << "\t투페어로 우승하였습니다." << endl;
		}
		else if (temp == 2)
		{
			cout << "\t원페어로 우승하였습니다." << endl;
		}
		else
		{
			cout << "\t운이 좋군요" << endl;
		}
		cout << "\t현재 돈은 :" << my.money << "입니다." << endl;
		cout << "\tenemy1의 돈은" << enemy1.money << "입니다." << endl;
		cout << "\tenemy2의 돈은" << enemy2.money << "입니다." << endl;
		cout << "\tenemy3의 돈은" << enemy3.money << "입니다." << endl;
		cout << "\tenemy4의 돈은" << enemy4.money << "입니다." << endl;
	}
	else if (current_winner == 3)
	{
		cout << "\tenemy3의 승리" << endl;
		enemy3.money = enemy3.money + gamebatting.batting_money + nagari;
		int temp = (winnervaluejokbo / 15);//이긴 족보 가르쳐 줄려고 쓴 변수 입니다.
		if ((winnervaluejokbo / 15) == 13)
		{
			cout << "\t로열 스트레이트 플러쉬로 우승하셨습니다." << endl;
		}
		else if (temp == 12)
		{
			cout << "\t백스트레이트 플러쉬로 우승하였습니다." << endl;
		}
		else if (temp == 11)
		{
			cout << "\t스트레이트 플러쉬로 우승하였습니다." << endl;
		}
		else if (temp == 10)
		{
			cout << "\t포카드로 우승하였습니다." << endl;
		}
		else if (temp == 9)
		{
			cout << "\t풀하우스로 우승하였습니다." << endl;
		}
		else if (temp == 8)
		{
			cout << "\t플러쉬로 우승하였습니다." << endl;
		}
		else if (temp == 7)
		{
			cout << "\t마운틴으로 우승하였습니다." << endl;
		}
		else if (temp == 6)
		{
			cout << "\t백스트레이트로 우승하였습니다." << endl;
		}
		else if (temp == 5)
		{
			cout << "\t스트레이트로 우승하였습니다." << endl;
		}
		else if (temp == 4)
		{
			cout << "\t트리플로 우승하였습니다." << endl;
		}
		else if (temp == 3)
		{
			cout << "\t투페어로 우승하였습니다." << endl;
		}
		else if (temp == 2)
		{
			cout << "\t원페어로 우승하였습니다." << endl;
		}
		else
		{
			cout << "\t운이 좋군요" << endl;
		}
		cout << "\t현재 돈은 :" << my.money << "입니다." << endl;
		cout << "\tenemy1의 돈은" << enemy1.money << "입니다." << endl;
		cout << "\tenemy2의 돈은" << enemy2.money << "입니다." << endl;
		cout << "\tenemy3의 돈은" << enemy3.money << "입니다." << endl;
		cout << "\tenemy4의 돈은" << enemy4.money << "입니다." << endl;
	}
	else if (current_winner == 4)
	{
		cout << "\tenemy4의 승리" << endl;
		enemy4.money = enemy4.money + gamebatting.batting_money + nagari;
		int temp = (winnervaluejokbo / 15);//이긴 족보 가르쳐 줄려고 쓴 변수 입니다.
		if ((winnervaluejokbo / 15) == 13)
		{
			cout << "\t로열 스트레이트 플러쉬로 우승하셨습니다." << endl;
		}
		else if (temp == 12)
		{
			cout << "\t백스트레이트 플러쉬로 우승하였습니다." << endl;
		}
		else if (temp == 11)
		{
			cout << "\t스트레이트 플러쉬로 우승하였습니다." << endl;
		}
		else if (temp == 10)
		{
			cout << "\t포카드로 우승하였습니다." << endl;
		}
		else if (temp == 9)
		{
			cout << "\t풀하우스로 우승하였습니다." << endl;
		}
		else if (temp == 8)
		{
			cout << "\t플러쉬로 우승하였습니다." << endl;
		}
		else if (temp == 7)
		{
			cout << "\t마운틴으로 우승하였습니다." << endl;
		}
		else if (temp == 6)
		{
			cout << "\t백스트레이트로 우승하였습니다." << endl;
		}
		else if (temp == 5)
		{
			cout << "\t스트레이트로 우승하였습니다." << endl;
		}
		else if (temp == 4)
		{
			cout << "\t트리플로 우승하였습니다." << endl;
		}
		else if (temp == 3)
		{
			cout << "\t투페어로 우승하였습니다." << endl;
		}
		else if (temp == 2)
		{
			cout << "\t원페어로 우승하였습니다." << endl;
		}
		else
		{
			cout << "\t운이 좋군요" << endl;
		}
		cout << "\t현재 돈은 :" << my.money << "입니다." << endl;
		cout << "\tenemy1의 돈은" << enemy1.money << "입니다." << endl;
		cout << "\tenemy2의 돈은" << enemy2.money << "입니다." << endl;
		cout << "\tenemy3의 돈은" << enemy3.money << "입니다." << endl;
		cout << "\tenemy4의 돈은" << enemy4.money << "입니다." << endl;
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
	float max_value_winner[5];//정렬 시킬려고하는 배열
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
							cout << "hey 이번판은 나가리이거든 ???" << endl << "다음판으로 돈이 갈거야 수고혀" << endl;
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
void pockergame::Dividing(int a, int b)//패나누기
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
}//내가 우선순위일때 받는것
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
}//enemy1이 우선순위일때 받는함수
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
}//enemy2이 우선순위일때 받는함수
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
}//enemy3이 우선순위일때 받는함수
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
}//enemy4이 우선순위일때 받는함수
int pockergame::distinction_card(int a)//우선순위판별프로그램 받는 것은 게임 턴;
									   /*나온결과 1이면 플레이어 순으로 카드를 갖게 된다.*/
{
	int pair[5] = { 0,0,0,0,0 };//페어 확인 변수
	int temp_card[4][5];//최댓값 확인 하기 위한 배열
	int temp1_card[4][5];//최댓값 확인 하기 위한 배열
	int distinctionpair[5] = { 0,0,0,0,0 };//우선 순위 계산을 위한 배열
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			temp_card[i][j] = 0;
			temp1_card[i][j] = 0;
		}
	}
	for (int i = 0; i <= a; i++)//배열에 집어 넣는다.
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
	for (int c = 0; c < 5; c++)/*페어 여부를 확인하고 페어 일시 card of number
							   에서*14를 한다*/
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
			for (int j = 0; j < 4 - i; j++)/*정렬확인*/
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
	enemy1.firstmoney = enemy1.money;//배팅하기전의 돈을 저장해 놓습니다.
	enemy2.firstmoney = enemy2.money;
	enemy3.firstmoney = enemy3.money;
	enemy4.firstmoney = enemy4.money;
	gamebatting.batting_money = 5 * gamebatting.current_batting_money;//처음 배팅할때 기본금액
	my.money = my.money - gamebatting.current_batting_money;
	enemy1.money = enemy1.money - gamebatting.current_batting_money;
	enemy2.money = enemy2.money - gamebatting.current_batting_money;
	enemy3.money = enemy3.money - gamebatting.current_batting_money;
	enemy4.money = enemy4.money - gamebatting.current_batting_money;
	gamebatting.callnumber = 0; gamebatting.checknumber = 0;
}
void pockergame::batting_ing()
{
	battingcount = 0;//명령어 를 집어 넣을 것이다.
	cout << "\t1. check(지켜봅니다)" << endl;
	cout << "\t2. call(판돈을 그대로 가죠)" << endl;
	cout << "\t3. double(판돈에 두배를 올리겠습니다.)" << endl;
	cout << "\t4. half(현재 올려진 돈에 반을 걸겠습니다.)" << endl;
	cout << "\t5. die(죽겠습니다.)" << endl;		
	cout << "\t올인을 했으면 check를 해주십시오" << endl;
	if (distinction == 1)
	{
		if (my.dienumber != 1)//die를 선언하면dienumber가이다 die를 선언했는지 선언 하지 않았는지 판단 한다. 
		{
			Sleep(1000);
			my.playerbatting(gamebatting, gameturn);
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)//call과 check를 판별한다.
		{
			return;
		}
		if (enemy1.dienumber != 1)//die를 선언하면dienumber가이다 die를 선언했는지 선언 하지 않았는지 판단 한다. 
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
		if (gamebatting.callnumber + gamebatting.checknumber == 5)//call과 check를 판별한다.
		{
			return;
		}
		if (enemy2.dienumber != 1)//die를 선언하면dienumber가이다 die를 선언했는지 선언 하지 않았는지 판단 한다. 
		{
			Sleep(500);
			Alpago.AI_distinction_card2(gameturn, my, enemy2, enemy1, enemy3, enemy4, gamebatting);
			cout << "enemy2 batting:" << endl;
			enemy2.AIbatting(gamebatting, gameturn);//call과 check를 판별한다
		}
		else
		{
			gamebatting.callnumber++;
		}
		if (gamebatting.callnumber + gamebatting.checknumber == 5)//call과 check를 판별한다
		{
			return;
		}
		if (enemy3.dienumber != 1)//die를 선언하면dienumber가이다 die를 선언했는지 선언 하지 않았는지 판단 한다. 
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
		if (gamebatting.callnumber + gamebatting.checknumber == 5)//call과 check를 판별한다
		{
			return;
		}
		if (enemy4.dienumber != 1)//die를 선언하면dienumber가이다 die를 선언했는지 선언 하지 않았는지 판단 한다. 
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
