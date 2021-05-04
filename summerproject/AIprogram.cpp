#include "AIprogram.h"



AIprogram::AIprogram()
{
}


AIprogram::~AIprogram()
{
}
/*
플레이어 가 다이했을 때 오류
다이넘버 초기화 를 해야 겠다
*/
/*호구형*/
void AIprogram::AI_distinction_card1(int a, AIplayer &myAI, batting bat)
{
	myAI.battingcount = 0;
	srand((unsigned int)time(NULL));
	/*첫번쩨 배팅 판단 프로그램
	원페어 투페어 트리플 인 경우
	스트레이트 4장 모였을 때의
	배팅 확률을 계산
	*/
	if (a == 2)
	{
		caRD AI_batting_distinction[5];
		AI_batting_distinction[0] = myAI.unvisiblecard[0];
		AI_batting_distinction[1] = myAI.unvisiblecard[1];
		AI_batting_distinction[2] = myAI.visiblecard[0];
		AI_batting_distinction[3] = myAI.visiblecard[1];
		AI_batting_distinction[4] = myAI.visiblecard[2];
		int AIpaircount = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = i + 1; j < 5; j++)
			{
				if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[j].numberofcard)
				{
					AIpaircount++;
				}
			}
		}
		if (AIpaircount == 1)//pair 이상을 받는다면 무조건 go 할거다 		
		{
			batting_score = 1;
		}
		else if (AIpaircount == 2)
		{
			batting_score = 2;
		}
		else if (AIpaircount == 3)
		{
			batting_score = 3;
		}
		else if (AIpaircount == 4)
		{
			batting_score = 4;
		}
		else if (AIpaircount == 6)
		{
			batting_score = 5;
		}
		else
		{
			batting_score = 0;
		}
		if (batting_score == 1)
		{
			int probablity = rand() % 100 + 1;
			if (((myAI.firstmoney) / 10) * 7 > myAI.money)//가지고 있던 돈의 70%가 내가 배팅을 하면서 낸돈보다 많으면 call이나 check를 하도록 함
			{

				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}

			}
			else
			{
				if (probablity > 90)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 60)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 2)
		{
			int probablity = rand() % 100 + 1;
			if (((myAI.firstmoney) / 10) * 6> myAI.money)
			{

				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}

			}
			else
			{
				if (probablity > 80)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 50)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 3)
		{
			int probablity = rand() % 100 + 1;
			if (((myAI.firstmoney) / 10) * 5> myAI.money)
			{

				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}

			}
			else
			{
				if (probablity > 75)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 40)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 4)
		{
			int probablity = rand() % 100 + 1;
			if (((myAI.firstmoney) / 10) * 5 > myAI.money)
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}

			}
			else
			{

				if (probablity > 55)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 15)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 5)
		{
			int probablity = rand() % 100 + 1;
			if (((myAI.firstmoney) / 10) * 4 > myAI.money)
			{
				int check_temp = 0;
				int call_temp = 0;
				call_temp = rand() % 10 + 1;
				if (call_temp > 1 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}

			}
			else
			{

				if (probablity > 40)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 10)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		int plush_ = 0;//플러쉬 확인용
		if (batting_score == 0)
		{
			if (AI_batting_distinction[0].numberofshape == AI_batting_distinction[1].numberofshape&& AI_batting_distinction[0].numberofshape == AI_batting_distinction[2].numberofshape&&AI_batting_distinction[0].numberofshape == AI_batting_distinction[3].numberofshape)
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 90)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 60)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
				plush_ = 1;
			}
			else if (AI_batting_distinction[0].numberofshape == AI_batting_distinction[2].numberofshape&& AI_batting_distinction[0].numberofshape == AI_batting_distinction[3].numberofshape&&AI_batting_distinction[0].numberofshape == AI_batting_distinction[4].numberofshape)
			{

				int probablity = rand() % 100 + 1;
				if (probablity > 90)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 60)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
				plush_ = 1;
			}
			else if (AI_batting_distinction[1].numberofshape == AI_batting_distinction[2].numberofshape&& AI_batting_distinction[1].numberofshape == AI_batting_distinction[3].numberofshape&&AI_batting_distinction[1].numberofshape == AI_batting_distinction[4].numberofshape)
			{

				int probablity = rand() % 100 + 1;
				if (probablity > 90)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 60)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
				plush_ = 1;
			}
			int AItemp = 0;
			for (int j = 0; j < 4; j++)//;player가 최종적으로 얻은 패들을 받고 정렬
			{
				for (int i = 0; i < 4 - j; i++)
				{
					if (AI_batting_distinction[i].numberofcard > AI_batting_distinction[i + 1].numberofcard)
					{
						AItemp = AI_batting_distinction[i].numberofcard;
						AI_batting_distinction[i].numberofcard = AI_batting_distinction[i + 1].numberofcard;
						AI_batting_distinction[i + 1].numberofcard = AItemp;
					}
				}
			}
			int straight_ = 0;//straight을 판단
			int subtract_arr[4];//1-0 2-1 3-2 4-3 5-4 6-5 를 저장하는 배열 striaght를 이걸로 판별할것입니다..
			for (int i = 0; i < 4; i++)
			{
				subtract_arr[i] = AI_batting_distinction[i + 1].numberofcard - AI_batting_distinction[i].numberofcard;
			}
			if (subtract_arr[0] + subtract_arr[1] + subtract_arr[2] == 3)
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 90)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 60)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
				straight_ = 1;
			}
			else if (subtract_arr[1] + subtract_arr[2] + subtract_arr[3] == 3)
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 90)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 60)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
				straight_ = 1;
			}
			if (plush_ == 0 && straight_ == 0)
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 95)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 90)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
	}
	else if (a == 3)
	{
		caRD AI_batting_distinction[6];
		AI_batting_distinction[0] = myAI.unvisiblecard[0];
		AI_batting_distinction[1] = myAI.unvisiblecard[1];
		AI_batting_distinction[2] = myAI.visiblecard[0];
		AI_batting_distinction[3] = myAI.visiblecard[1];
		AI_batting_distinction[4] = myAI.visiblecard[2];
		AI_batting_distinction[5] = myAI.visiblecard[3];
		int AIpaircount = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = i + 1; j < 6; j++)
			{
				if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[j].numberofcard)
				{
					AIpaircount++;
				}
			}
		}
		if (AIpaircount == 1)//pair 이상을 받는다면 무조건 go 할거다 		
		{
			batting_score = 1;
		}
		else if (AIpaircount == 2)
		{
			batting_score = 2;
		}
		else if (AIpaircount == 3)
		{
			batting_score = 3;
		}
		else if (AIpaircount == 4)
		{
			batting_score = 4;
		}
		else if (AIpaircount == 6)
		{
			batting_score = 5;
		}
		else
		{
			batting_score = 0;
		}
		if (batting_score == 1)
		{
			int probablity = rand() % 100 + 1;
			if (((myAI.firstmoney) / 10) * 7 > myAI.money)
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
			}
			else
			{
				if (probablity > 90)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity >70)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 2)
		{
			int probablity = rand() % 100 + 1;
			if (((myAI.firstmoney) / 10) * 5 > myAI.money)
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
			}
			else
			{
				if (probablity > 85)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 75)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 3)
		{
			int probablity = rand() % 100 + 1;
			if (((myAI.firstmoney) / 10) * 5 > myAI.money)
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
			}
			else
			{

				if (probablity > 75)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 50)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 4)
		{
			int probablity = rand() % 100 + 1;
			if (((myAI.firstmoney) / 10) * 5 > myAI.money)
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
			}
			else
			{
				if (probablity > 55)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 15)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 5)
		{
			int probablity = rand() % 100 + 1;
			if (probablity > 40)
			{
				myAI.battingcount = 4;//하프
			}
			else if (probablity > 10)
			{
				myAI.battingcount = 3;//double 외침
			}
			else
			{
				myAI.battingcount = 2;//call외침
			}
		}
		if (batting_score == 0)
		{
			int straight_ = 0;//스트레이트 확인용
			int plush_ = 0;//플러쉬 확인용
			int temp = 0;
			for (int j = 0; j < 5; j++)//;player가 최종적으로 얻은 패들을 받고 정렬
			{
				for (int i = 0; i < 5 - j; i++)
				{
					if (AI_batting_distinction[i].numberofcard > AI_batting_distinction[i + 1].numberofcard)
					{
						temp = AI_batting_distinction[i].numberofcard;
						AI_batting_distinction[i].numberofcard = AI_batting_distinction[i + 1].numberofcard;
						AI_batting_distinction[i + 1].numberofcard = temp;
					}
				}
			}
			int subtract_arr[5];//1-0 2-1 3-2 4-3 5-4 6-5 를 저장하는 배열 striaght를 이걸로 판별할것입니다..
			for (int i = 0; i < 5; i++)
			{
				subtract_arr[i] = AI_batting_distinction[i + 1].numberofcard - AI_batting_distinction[i].numberofcard;
			}
			temp = 0;//sort 를 실행시키기 위하여 설정한임의의 변수
			for (int i = 0; i < 5; i++)//0을 맨뒤로 보낼 거예요
			{
				if (subtract_arr[i] == 0)
				{
					for (int j = i; j < 4; j++)
					{
						temp = subtract_arr[j];
						subtract_arr[j] = subtract_arr[j + 1];
						subtract_arr[j + 1] = temp;
					}

				}
			}
			for (int i = 0; i < 5; i++)
			{
				if (subtract_arr[i] == 0)
				{
					subtract_arr[i] += 15;
				}
			}
			int distinction_straight = 0;
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					distinction_straight += subtract_arr[i + j];
				}
				if (distinction_straight <= 4)
				{
					int straightofnumber = 0;
					for (int i = 0; i < 3; i++)
					{
						if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[i + 1].numberofcard && AI_batting_distinction[i + 1].numberofcard + 1 == AI_batting_distinction[i + 2].numberofcard)
						{
							break;
						}
					}
					straight_ = 1;
				}
			}
			int Plush = 1;//플러쉬를 판별하기 위해 선언한 임의의 변수
			for (int i = 0; i < 6; i++)
			{
				Plush = AI_batting_distinction[i].numberofshape*Plush;
			}
			int temp1 = Plush;
			int plushofshape = 0;
			int plush_rest;//나머지 저장 변수
			for (int i = 2; i < 4; i++)
			{
				Plush = temp1;
				for (int j = 0; j < 5; j++)
				{
					if (i == 4)
					{
						i = i + 1;
					}
					plush_rest = Plush%i;
					Plush = Plush / i;
					if (plush_rest != 0)
					{
						break;
					}
				}
				if (plush_rest == 0)
				{
					plushofshape = i;
					break;
				}
			}
			int plush1 = 0;
			for (int i = 0; i < 6; i++)
			{
				if (AI_batting_distinction[i].numberofshape == 1)
				{
					plush1++;
				}
			}
			Plush = temp1;
			if (plush_rest == 0 || plush1 >= 5)
			{
				plush_ = 1;
			}
			else
			{
				plush_ = 0;
			}
			if (plush_ == 1 || straight_ == 1)
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 70)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 35)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
			else
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
			}
		}
	}
	else if (a == 4)
	{
		if (myAI.value_jokbo <= 30)
		{
			int probablity = rand() % 100 + 1;
			if (probablity > 98)
			{
				myAI.battingcount = 4;//하프
			}
			else if (probablity > 95)
			{
				myAI.battingcount = 3;//double 외침
			}
			else
			{
				myAI.battingcount = 2;//call외침
			}
		}
		else if (myAI.value_jokbo < 45)
		{
			if (((myAI.firstmoney) / 10) * 5 > myAI.money)
			{

				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
			}
			else
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 95)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 80)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		else if (myAI.value_jokbo < 60)
		{
			int probablity = rand() % 100 + 1;
			if (((myAI.firstmoney) / 10) * 5 > myAI.money)
			{

				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
			}
			else
			{
				if (probablity > 85)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 60)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		else if (myAI.value_jokbo < 75)
		{
			int probablity = rand() % 100 + 1;
			if (probablity > 75)
			{
				myAI.battingcount = 4;//하프
			}
			else if (probablity > 40)
			{
				myAI.battingcount = 3;//double 외침
			}
			else
			{
				myAI.battingcount = 2;//call외침
			}
		}
		else if (myAI.value_jokbo<120)
		{
			int probablity = rand() % 100 + 1;
			if (((myAI.firstmoney) / 10) * 4 > myAI.money)
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
			}
			else
			{

				if (probablity > 70)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 30)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}

			}
		}
		else
		{
			int probablity = rand() % 100 + 1;
			if (probablity > 40)
			{
				myAI.battingcount = 4;//하프
			}
			else if (probablity > 10)
			{
				myAI.battingcount = 3;//double 외침
			}
			else
			{
				myAI.battingcount = 2;//call외침
			}
		}
	}

}
/*신중형*/
void AIprogram::AI_distinction_card2(int a, player A, AIplayer &myAI, AIplayer B, AIplayer C, AIplayer D, batting bat)//쫄보형
{
	myAI.battingcount = 0;
	srand((unsigned int)time(NULL));
	if (a == 2)
	{
		caRD AI_batting_distinction[5];//5장의 카드를 받습니다.
		AI_batting_distinction[0] = myAI.unvisiblecard[0];
		AI_batting_distinction[1] = myAI.unvisiblecard[1];
		AI_batting_distinction[2] = myAI.visiblecard[0];
		AI_batting_distinction[3] = myAI.visiblecard[1];
		AI_batting_distinction[4] = myAI.visiblecard[2];
		int AIpaircount = 0;
		for (int i = 0; i < 4; i++)//페어의 유무를 확인합니다.
		{
			for (int j = i + 1; j < 5; j++)
			{
				if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[j].numberofcard)
				{
					AIpaircount++;
				}
			}
		}
		if (AIpaircount == 1)//pair 이상을 받는다면 무조건 go 할거다 		
		{
			batting_score = 1;
		}
		else if (AIpaircount == 2)
		{
			batting_score = 2;
		}
		else if (AIpaircount == 3)
		{
			batting_score = 3;
		}
		else if (AIpaircount == 4)
		{
			batting_score = 4;
		}
		else if (AIpaircount == 6)
		{
			batting_score = 5;
		}
		else
		{
			batting_score = 0;
		}
		if (batting_score == 1)
		{
			int probablity = rand() % 100 + 1;
			if (((myAI.firstmoney) / 10) * 8 > myAI.money)//가지고 있던 돈의 70%가 내가 배팅을 하면서 낸돈보다 많으면 call이나 check를 하도록 함
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 2 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}

			}
			else
			{
				if (probablity > 97)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 90)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 2)
		{
			int probablity = rand() % 100 + 1;
			if (((myAI.firstmoney) / 10) * 7 > myAI.money)
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}

			}
			else
			{
				if (probablity > 95)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 85)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 3)
		{
			int probablity = rand() % 100 + 1;
			if (((myAI.firstmoney) / 10) * 6 > myAI.money)
			{

				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
			}
			else
			{
				if (probablity > 90)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 75)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 4)
		{
			int probablity = rand() % 100 + 1;
			if (((myAI.firstmoney) / 10) * 4 > myAI.money)
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}

			}
			else
			{

				if (probablity > 60)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 30)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 5)
		{
			int probablity = rand() % 100 + 1;
			if (((myAI.firstmoney) / 10) * 4 > myAI.money)
			{
				int check_temp = 0;
				int call_temp = 0;
				call_temp = rand() % 10 + 1;
				if (call_temp > 1 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}

			}
			else
			{

				if (probablity > 50)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 10)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		int plush_ = 0;//플러쉬 확인용
		if (batting_score == 0)
		{
			if (AI_batting_distinction[0].numberofshape == AI_batting_distinction[1].numberofshape&& AI_batting_distinction[0].numberofshape == AI_batting_distinction[2].numberofshape&&AI_batting_distinction[0].numberofshape == AI_batting_distinction[3].numberofshape)
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 97)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 90)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
				plush_ = 1;
			}
			else if (AI_batting_distinction[0].numberofshape == AI_batting_distinction[2].numberofshape&& AI_batting_distinction[0].numberofshape == AI_batting_distinction[3].numberofshape&&AI_batting_distinction[0].numberofshape == AI_batting_distinction[4].numberofshape)
			{

				int probablity = rand() % 100 + 1;
				if (probablity > 97)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 90)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
				plush_ = 1;
			}
			else if (AI_batting_distinction[1].numberofshape == AI_batting_distinction[2].numberofshape&& AI_batting_distinction[1].numberofshape == AI_batting_distinction[3].numberofshape&&AI_batting_distinction[1].numberofshape == AI_batting_distinction[4].numberofshape)
			{

				int probablity = rand() % 100 + 1;
				if (probablity > 97)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 90)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
				plush_ = 1;
			}
			int AItemp = 0;
			for (int j = 0; j < 4; j++)//;player가 최종적으로 얻은 패들을 받고 정렬
			{
				for (int i = 0; i < 4 - j; i++)
				{
					if (AI_batting_distinction[i].numberofcard > AI_batting_distinction[i + 1].numberofcard)
					{
						AItemp = AI_batting_distinction[i].numberofcard;
						AI_batting_distinction[i].numberofcard = AI_batting_distinction[i + 1].numberofcard;
						AI_batting_distinction[i + 1].numberofcard = AItemp;
					}
				}
			}
			int straight_ = 0;//straight을 판단
			int subtract_arr[4];//1-0 2-1 3-2 4-3 5-4 6-5 를 저장하는 배열 striaght를 이걸로 판별할것입니다..
			for (int i = 0; i < 4; i++)
			{
				subtract_arr[i] = AI_batting_distinction[i + 1].numberofcard - AI_batting_distinction[i].numberofcard;
			}
			if (subtract_arr[0] + subtract_arr[1] + subtract_arr[2] == 3)
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 97)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 90)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
				straight_ = 1;
			}
			else if (subtract_arr[1] + subtract_arr[2] + subtract_arr[3] == 3)
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 97)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 90)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
				straight_ = 1;
			}
			if (plush_ == 0 && straight_ == 0)
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 99)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 95)
				{
					myAI.battingcount = 3;//double 외침
				}
				else if (probablity > 70)
				{
					myAI.battingcount = 5;
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
	}
	else if (a == 3)
	{
		caRD AI_batting_distinction[6];
		AI_batting_distinction[0] = myAI.unvisiblecard[0];
		AI_batting_distinction[1] = myAI.unvisiblecard[1];
		AI_batting_distinction[2] = myAI.visiblecard[0];
		AI_batting_distinction[3] = myAI.visiblecard[1];
		AI_batting_distinction[4] = myAI.visiblecard[2];
		AI_batting_distinction[5] = myAI.visiblecard[3];
		int AIpaircount = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = i + 1; j < 6; j++)
			{
				if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[j].numberofcard)
				{
					AIpaircount++;
				}
			}
		}
		if (AIpaircount == 1)//pair 이상을 받는다면 무조건 go 할거다 		
		{
			batting_score = 1;
		}
		else if (AIpaircount == 2)
		{
			batting_score = 2;
		}
		else if (AIpaircount == 3)
		{
			batting_score = 3;
		}
		else if (AIpaircount == 4)
		{
			batting_score = 4;
		}
		else if (AIpaircount == 6)
		{
			batting_score = 5;
		}
		else
		{
			batting_score = 0;
		}
		if (batting_score == 1)//원페어일때
		{
			int other_money[4];
			other_money[0] = A.playerfirstmoney - A.money;
			other_money[1] = B.firstmoney - B.money;
			other_money[2] = C.firstmoney - C.money;
			other_money[3] = D.firstmoney - D.money;
			int hope_die = 0;
			for (int i = 0; i < 4; i++)
			{
				if (other_money[i] >(myAI.firstmoney / 10) * 6)
				{
					hope_die = 1;
					break;
				}
			}
			int probablity = rand() % 100 + 1;
			if (hope_die == 1)
			{
				if (probablity > 50)
				{
					myAI.battingcount = 5;
				}
				else if (probablity > 20 && check_temp == 0)
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
				else
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
			}
			else
			{
				if (((myAI.firstmoney) / 10) * 8 > myAI.money)//가지고 있던 돈의 70%가 내가 배팅을 하면서 낸돈보다 많으면 call이나 check를 하도록 함
				{
					call_temp = rand() % 10 + 1;
					if (call_temp > 2 && check_temp == 0)
					{
						myAI.battingcount = 2;
					}
					else if (check_temp == 1)
					{
						myAI.battingcount = 2;
						check_temp = 0;
					}
					else
					{
						myAI.battingcount = 1;
						check_temp = 1;
					}

				}
				else
				{
					if (probablity > 97)
					{
						myAI.battingcount = 4;//하프
					}
					else if (probablity > 90)
					{
						myAI.battingcount = 3;//double 외침
					}
					else
					{
						myAI.battingcount = 2;//call외침
					}
				}
			}
		}
		if (batting_score == 2)
		{
			int other_money[4];
			other_money[0] = A.playerfirstmoney - A.money;
			other_money[1] = B.firstmoney - B.money;
			other_money[2] = C.firstmoney - C.money;
			other_money[3] = D.firstmoney - D.money;
			int hope_die = 0;
			for (int i = 0; i < 4; i++)
			{
				if (other_money[i] >(myAI.firstmoney / 10) * 7)
				{
					hope_die = 1;
				}
			}
			int probablity = rand() % 100 + 1;
			if (hope_die == 1)
			{
				if (probablity > 60)
				{
					myAI.battingcount = 5;
				}
				else if (probablity > 20 && check_temp == 0)
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
				else
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
			}
			else
			{
				if (((myAI.firstmoney) / 10) * 6 > myAI.money)
				{
					call_temp = rand() % 10 + 1;
					if (call_temp > 3 && check_temp == 0)
					{
						myAI.battingcount = 2;
					}
					else if (check_temp == 1)
					{
						myAI.battingcount = 2;
						check_temp = 0;
					}
					else
					{
						myAI.battingcount = 1;
						check_temp = 1;
					}

				}
				else
				{
					if (probablity > 95)
					{
						myAI.battingcount = 4;//하프
					}
					else if (probablity > 90)
					{
						myAI.battingcount = 3;//double 외침
					}
					else
					{
						myAI.battingcount = 2;//call외침
					}
				}
			}
		}
		if (batting_score == 3)
		{
			int probablity = rand() % 100 + 1;
			if (((myAI.firstmoney) / 10) * 5 > myAI.money)
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
			}
			else
			{
				if (probablity > 90)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 80)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 4)
		{
			int probablity = rand() % 100 + 1;
			if (((myAI.firstmoney) / 10) * 4 > myAI.money)
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}

			}
			else
			{

				if (probablity > 60)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 40)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 5)
		{
			int probablity = rand() % 100 + 1;
			if (((myAI.firstmoney) / 10) * 4 > myAI.money)
			{
				int check_temp = 0;
				int call_temp = 0;
				call_temp = rand() % 10 + 1;
				if (call_temp > 1 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}

			}
			else
			{

				if (probablity > 60)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 20)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		int plush_ = 0;//플러쉬 확인용
		if (batting_score == 0)
		{
			int straight_ = 0;//스트레이트 확인용
			int plush_ = 0;//플러쉬 확인용
			int temp = 0;
			for (int j = 0; j < 5; j++)//;player가 최종적으로 얻은 패들을 받고 정렬
			{
				for (int i = 0; i < 5 - j; i++)
				{
					if (AI_batting_distinction[i].numberofcard > AI_batting_distinction[i + 1].numberofcard)
					{
						temp = AI_batting_distinction[i].numberofcard;
						AI_batting_distinction[i].numberofcard = AI_batting_distinction[i + 1].numberofcard;
						AI_batting_distinction[i + 1].numberofcard = temp;
					}
				}
			}
			int subtract_arr[5];//1-0 2-1 3-2 4-3 5-4 6-5 를 저장하는 배열 striaght를 이걸로 판별할것입니다..
			for (int i = 0; i < 5; i++)
			{
				subtract_arr[i] = AI_batting_distinction[i + 1].numberofcard - AI_batting_distinction[i].numberofcard;
			}
			for (int i = 0; i < 5; i++)
			{
				if (subtract_arr[i] == 0)
				{
					subtract_arr[i] += 15;
				}
			}
			int distinction_straight = 0;
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					distinction_straight += subtract_arr[i + j];
				}
				if (distinction_straight <= 4)
				{
					int straightofnumber = 0;
					for (int i = 0; i < 3; i++)
					{
						if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[i + 1].numberofcard && AI_batting_distinction[i + 1].numberofcard + 1 == AI_batting_distinction[i + 2].numberofcard)
						{
							break;
						}
					}
					straight_ = 1;
				}
			}
			int Plush = 1;//플러쉬를 판별하기 위해 선언한 임의의 변수
			for (int i = 0; i < 6; i++)
			{
				Plush = AI_batting_distinction[i].numberofshape*Plush;
			}
			int temp1 = Plush;
			int plushofshape = 0;
			int plush_rest;//나머지 저장 변수
			for (int i = 2; i < 4; i++)
			{
				Plush = temp1;
				for (int j = 0; j < 5; j++)
				{
					if (i == 4)
					{
						i = i + 1;
					}
					plush_rest = Plush%i;
					Plush = Plush / i;
					if (plush_rest != 0)
					{
						break;
					}
				}
				if (plush_rest == 0)
				{
					plushofshape = i;
					break;
				}
			}
			int plush1 = 0;
			for (int i = 0; i < 6; i++)
			{
				if (AI_batting_distinction[i].numberofshape == 1)
				{
					plush1++;
				}
			}
			Plush = temp1;
			if (plush_rest == 0 || plush1 >= 5)
			{
				plush_ = 1;
			}
			else
			{
				plush_ = 0;
			}

			/*지금 이거는 스트레이트 판별 완료 후 임*/
			if (plush_ == 1 || straight_ == 1)
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 90)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 80)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
			else
			{
				//6장일 때 페어도 스트레이트도 플러쉬도 아니다 그리고 4장이 스트레이트나 플러쉬에 알맞게 있다
				int plushofshape = 0;
				int plush_plush = 0;
				int value = 0;
				int plush_rest;//나머지 저장 변수
				for (int i = 2; i < 4; i++)
				{
					Plush = temp1;
					for (int j = 0; j < 4; j++)
					{
						if (i == 4)
						{
							i = i + 1;
						}
						plush_rest = Plush%i;
						Plush = Plush / i;
						if (plush_rest != 0)
						{
							break;
						}
					}
					if (plush_rest == 0)
					{
						plush_plush = 1;
						plushofshape = i;
						break;
					}
				}
				if (plush_plush == 1)
				{
					int AI_temp[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
					for (int i = 0; i < 3; i++)
					{
						AI_temp[i] = A.visiblecard[i].numberofshape;
					}
					for (int i = 0, b = 3; i < 3; i++, b++)
					{
						AI_temp[b] = B.visiblecard[i].numberofshape;
					}
					for (int i = 0, b = 6; i < 3; i++, b++)
					{
						AI_temp[b] = C.visiblecard[i].numberofshape;
					}
					for (int i = 0, b = 9; i < 3; i++, b++)
					{
						AI_temp[b] = D.visiblecard[i].numberofshape;
					}
					int AI_distinction_go = 0;
					for (int i = 0; i < 12; i++)
					{
						if (plushofshape == AI_temp[i])
						{
							AI_distinction_go++;
						}
					}
					if (AI_distinction_go < 4)
					{
						value = 1;//플러쉬 value값
					}
					else
					{
						value = 0;
					}
				}
				int straight_value = 0;
				int AI_temp[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };//적들이 보이는 카드를 저장할 배열
				int my_hope_card[2];//내가 스트레이트를 만들때 필요한 카드들의 숫자를 저장할 변수
				int straight_straight = 0;//4장이 스트레이트인지 판단할 변수
				for (int i = 0; i < 4; i++)
				{
					if (subtract_arr[i] + subtract_arr[i + 1] + subtract_arr[i + 2] == 3)
					{
						straight_straight = 1;
						my_hope_card[0] = AI_batting_distinction[i].numberofcard - 1;
						my_hope_card[1] = AI_batting_distinction[i].numberofcard + 3;
						break;
					}
				}
				if (straight_straight == 1)
				{
					int straight_go[2] = { 0,0 };
					for (int i = 0; i < 3; i++)
					{
						AI_temp[i] = A.visiblecard[i].numberofcard;
					}
					for (int i = 0, b = 3; i < 3; i++, b++)
					{
						AI_temp[b] = B.visiblecard[i].numberofcard;
					}
					for (int i = 0, b = 6; i < 3; i++, b++)
					{
						AI_temp[b] = C.visiblecard[i].numberofcard;
					}
					for (int i = 0, b = 9; i < 3; i++, b++)
					{
						AI_temp[b] = D.visiblecard[i].numberofcard;
					}
					for (int i = 0; i < 12; i++)
					{
						if (my_hope_card[0] == AI_temp[i])
						{
							straight_go[0]++;
						}
						if (my_hope_card[1] == AI_temp[i])
						{
							straight_go[1]++;
						}
					}
					if (straight_go[0] < 2 || straight_go[1] < 2)
					{
						straight_value = 1;
					}
					else
					{
						straight_value = 0;
					}
				}
				else
				{
					straight_value = 0;
				}
				if (straight_value + value >= 1)
				{
					int other_money[4];
					other_money[0] = A.playerfirstmoney - A.money;
					other_money[1] = B.firstmoney - B.money;
					other_money[2] = C.firstmoney - C.money;
					other_money[3] = D.firstmoney - D.money;
					int hope_die = 0;
					for (int i = 0; i < 4; i++)
					{
						if (other_money[i] >(myAI.firstmoney / 10) * 6)
						{
							hope_die = 1;
						}
					}
					int probablity = rand() % 100 + 1;
					if (hope_die == 1)
					{
						if (probablity > 50)
						{
							myAI.battingcount = 5;
						}
						else if (probablity > 20 && check_temp == 0)
						{
							myAI.battingcount = 1;
							check_temp = 1;
						}
						else
						{
							myAI.battingcount = 2;
							check_temp = 0;
						}
					}
					else
					{
						if (probablity > 50)
						{
							myAI.battingcount = 5;
						}
						else if (probablity > 20 && check_temp == 0)
						{
							myAI.battingcount = 1;
							check_temp = 1;
						}
						else
						{
							myAI.battingcount = 2;
							check_temp = 0;
						}
					}
				}
				else
				{
					int probablity = rand() % 100 + 1;
					if (probablity > 50)
					{
						myAI.battingcount = 5;
					}
					else if (probablity > 20 && check_temp == 0)
					{
						myAI.battingcount = 1;
						check_temp = 1;
					}
					else
					{
						myAI.battingcount = 2;
						check_temp = 0;
					}
				}
			}
		}
	}
	else if (a == 4)
	{
		//여기에 적들의 페어 확인만 하자
		//스트레이트나 플러쉬는 뭔가 애매하다
		int card_enemy[4][4];
		for (int i = 0; i < 4; i++)
		{
			card_enemy[0][i] = A.visiblecard[i].numberofcard;
		}
		for (int i = 0; i < 4; i++)
		{
			card_enemy[1][i] = A.visiblecard[i].numberofcard;
		}
		for (int i = 0; i < 4; i++)
		{
			card_enemy[2][i] = A.visiblecard[i].numberofcard;
		}
		for (int i = 0; i < 4; i++)
		{
			card_enemy[3][i] = A.visiblecard[i].numberofcard;
		}
		int enemy_jokbo_value[4] = { 0,0,0,0 };
		for (int a = 0; a < 4; a++)//보이는 패들이 페어 투페어 트리플 판단 여부
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = i + 1; j < 4; j++)
				{
					if (card_enemy[a][i] == card_enemy[a][j] && card_enemy[a][i] != 0)
					{
						enemy_jokbo_value[a]++;
					}
				}
			}
		}
		int value[4] = { 0 ,0,0,0 };
		for (int i = 0; i < 4; i++)
		{
			if (enemy_jokbo_value[i] > 1)
			{
				value[i] = 2;
			}
			else if (enemy_jokbo_value[i] == 1)
			{
				value[i] = 1;
			}
			else
			{
				value[i] = 0;
			}
		}
		if (myAI.value_jokbo <= 30)//원페어  
		{
			int probablity = rand() % 100 + 1;
			if (value[0] > 0 || value[1] > 0 || value[2] > 0 || value[3] > 0 || value[4] >0)//보이는 패가 투페어 이상이면 위험함
			{
				myAI.battingcount = 5;
			}
			else if (probablity > 98)
			{
				myAI.battingcount = 4;//하프
			}
			else if (probablity > 95)
			{
				myAI.battingcount = 3;//double 외침
			}
			else
			{
				myAI.battingcount = 2;//call외침
			}
		}
		else if (myAI.value_jokbo < 45)//투페어 
		{
			int enemy_justice = 0;//투페어 일때 고할것인지 생각 신중형은 가정이 트리플을 가지면 이길 가능성이 높다는 판단  이유는 원페어 40퍼센트 투페어 20퍼센트 정도의 확률에서 이를 제외하면 70%가 넘는 승률이기 때문
			if (value[0] > 1 || value[1] > 1 || value[2] > 1 || value[3] > 1 || value[4] > 1)//보이는 패가 투페어 이상이면 위험함
			{

				int other_money[4];
				other_money[0] = A.playerfirstmoney - A.money;
				other_money[1] = B.firstmoney - B.money;
				other_money[2] = C.firstmoney - C.money;
				other_money[3] = D.firstmoney - D.money;
				if (other_money[0] > (A.playerfirstmoney / 10) * 7)//적의 카드가 투페어 이상이라는 것을 알고 적의 돈이 70%를 사용햇을때 다이
				{
					myAI.battingcount = 5;
					enemy_justice = 2;
				}
				else if (other_money[1] > (B.firstmoney / 10) * 7)
				{
					myAI.battingcount = 5;
					enemy_justice = 2;
				}
				else if (other_money[2] > (C.firstmoney / 10) * 7)
				{
					myAI.battingcount = 5;
					enemy_justice = 2;
				}
				else if (other_money[3] > (D.firstmoney / 10) * 7)
				{
					myAI.battingcount = 5;
					enemy_justice = 2;
				}
				else
				{
					enemy_justice = 1;
				}
			}
			if (enemy_justice == 2)
			{
			}
			else
			{
				if (((myAI.firstmoney) / 10) * 6 > myAI.money)
				{
					call_temp = rand() % 10 + 1;
					if (call_temp > 3 && check_temp == 0)
					{
						myAI.battingcount = 2;
					}
					else if (check_temp == 1)
					{
						myAI.battingcount = 2;
						check_temp = 0;
					}
					else
					{
						myAI.battingcount = 1;
						check_temp = 1;
					}
				}
				else
				{
					int probablity = rand() % 100 + 1;
					if (probablity > 97)
					{
						myAI.battingcount = 4;//하프
					}
					else if (probablity > 90)
					{
						myAI.battingcount = 3;//double 외침
					}
					else
					{
						myAI.battingcount = 2;//call외침
					}
				}
			}
		}
		else if (myAI.value_jokbo < 60)//트리플
		{
			int probablity = rand() % 100 + 1;
			if (((myAI.firstmoney) / 10) * 5 > myAI.money)
			{

				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
			}
			else
			{
				if (probablity > 90)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 70)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		else if (myAI.value_jokbo < 75)//스트레이트
		{
			int probablity = rand() % 100 + 1;
			if (probablity > 75)
			{
				myAI.battingcount = 4;//하프
			}
			else if (probablity > 40)
			{
				myAI.battingcount = 3;//double 외침
			}
			else
			{
				myAI.battingcount = 2;//call외침
			}
		}
		else if (myAI.value_jokbo<120)
		{
			int probablity = rand() % 100 + 1;
			if (((myAI.firstmoney) / 10) * 4 > myAI.money)
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
			}
			else
			{

				if (probablity > 70)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 30)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}

			}
		}
		else
		{
			int probablity = rand() % 100 + 1;
			if (probablity > 40)
			{
				myAI.battingcount = 4;//하프
			}
			else if (probablity > 10)
			{
				myAI.battingcount = 3;//double 외침
			}
			else
			{
				myAI.battingcount = 2;//call외침
			}
		}
	}
}
/*쫄보형*/
void AIprogram::AI_distinction_card3(int a, player A, AIplayer &myAI, AIplayer B, AIplayer C, AIplayer D, batting bat)
{
	myAI.battingcount = 0;
	srand((unsigned int)time(NULL));
	if (a == 2)
	{
		check_temp = 0;
		caRD AI_batting_distinction[5];//5장의 카드를 받습니다.
		AI_batting_distinction[0] = myAI.unvisiblecard[0];
		AI_batting_distinction[1] = myAI.unvisiblecard[1];
		AI_batting_distinction[2] = myAI.visiblecard[0];
		AI_batting_distinction[3] = myAI.visiblecard[1];
		AI_batting_distinction[4] = myAI.visiblecard[2];
		int AIpaircount = 0;
		for (int i = 0; i < 4; i++)//페어의 유무를 확인합니다.
		{
			for (int j = i + 1; j < 5; j++)
			{
				if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[j].numberofcard)
				{
					AIpaircount++;
				}
			}
		}
		if (AIpaircount == 1)//pair 이상을 받는다면 무조건 go 할거다 		
		{
			batting_score = 1;
		}
		else if (AIpaircount == 2)
		{
			batting_score = 2;
		}
		else if (AIpaircount == 3)
		{
			batting_score = 3;
		}
		else if (AIpaircount == 4)
		{
			batting_score = 4;
		}
		else if (AIpaircount == 6)
		{
			batting_score = 5;
		}
		else
		{
			batting_score = 0;
		}
		if (batting_score == 1)
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 2)//가지고 있던 돈의 30%가 콜을 해야할 돈이면 call이나 check die를 하도록 함
			{
				if (probablity > 60)//70퍼센트의 확률로 죽는다
				{
					myAI.battingcount = 5;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else if (probablity > 10)
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
				else
				{
					myAI.battingcount = 2;
				}
			}
			else
			{
				if (probablity > 97)
				{
					myAI.battingcount = 3;//double
				}
				else//원페어를 가졌을때 93%의 확률로 콜을 외친다.-
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 2)//투페어 일때 지금 5장 인 상황에서 투페어는 것은 최종적으로 풀하우스가 나올 가능성이 있고 이길 가능성도 50%이다. 
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 3)//현재 판돈이 내 돈의30%면 check or call을 외친다.
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}

			}
			else
			{
				if (probablity > 90)//10%확률로 더블 그 이외에는 콜을 외친다.
				{
					myAI.battingcount = 3;//하프
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 3)
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 4)//40%가 배팅 할 금액이라면 call혹은 check를 외친다.
			{

				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
			}
			else
			{
				if (probablity > 95)//5%확률로 하프 15%확률로 더블 그 이외에는 콜을 외친다.
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 80)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 4)
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 5)//call금액이 50%일때 call or check를 한다.
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}

			}
			else
			{

				if (probablity > 60)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 30)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 5)
		{
			int probablity = rand() % 100 + 1;//5장일 때 4카드면 그냥 이김 달려야지
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 5)
			{
				int check_temp = 0;
				int call_temp = 0;
				call_temp = rand() % 10 + 1;
				if (call_temp > 1 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}

			}
			else
			{
				if (probablity > 50)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 10)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		int plush_ = 0;//플러쉬 확인용
		if (batting_score == 0)
		{
			if (AI_batting_distinction[0].numberofshape == AI_batting_distinction[1].numberofshape&& AI_batting_distinction[0].numberofshape == AI_batting_distinction[2].numberofshape&&AI_batting_distinction[0].numberofshape == AI_batting_distinction[3].numberofshape)
			{//플러쉬가 4장 모였을때
				int probablity = rand() % 100 + 1;
				if (bat.current_batting_money > (myAI.firstmoney / 10) * 2)//가지고 있던 돈의 30%가 콜을 해야할 돈이면 call이나 check die를 하도록 함
				{
					if (probablity > 70)//40퍼센트의 확률로 콜을 한다
					{
						myAI.battingcount = 2;
					}
					else if (check_temp == 1)
					{
						myAI.battingcount = 2;
						check_temp = 0;
					}
					else if (probablity > 10)
					{
						myAI.battingcount = 1;
						check_temp = 1;
					}
					else
					{
						myAI.battingcount = 2;
					}
					plush_ = 1;
				}
				else
				{
					if (probablity > 97)
					{
						myAI.battingcount = 4;//하프
					}
					else if (probablity > 90)
					{
						myAI.battingcount = 3;//double 외침
					}
					else
					{
						myAI.battingcount = 2;//call외침
					}
					plush_ = 1;
				}
			}
			else if (AI_batting_distinction[0].numberofshape == AI_batting_distinction[2].numberofshape&& AI_batting_distinction[0].numberofshape == AI_batting_distinction[3].numberofshape&&AI_batting_distinction[0].numberofshape == AI_batting_distinction[4].numberofshape)
			{
				int probablity = rand() % 100 + 1;
				if (bat.current_batting_money > (myAI.firstmoney / 10) * 2)//가지고 있던 돈의 30%가 콜을 해야할 돈이면 call이나 check die를 하도록 함
				{
					if (probablity > 70)//40퍼센트의 확률로 콜을 한다
					{
						myAI.battingcount = 2;
					}
					else if (check_temp == 1)
					{
						myAI.battingcount = 2;
						check_temp = 0;
					}
					else if (probablity > 10)
					{
						myAI.battingcount = 1;
						check_temp = 1;
					}
					else
					{
						myAI.battingcount = 2;
					}
					plush_ = 1;
				}
				else
				{
					if (probablity > 97)
					{
						myAI.battingcount = 4;//하프
					}
					else if (probablity > 90)
					{
						myAI.battingcount = 3;//double 외침
					}
					else
					{
						myAI.battingcount = 2;//call외침
					}
					plush_ = 1;
				}
			}
			else if (AI_batting_distinction[1].numberofshape == AI_batting_distinction[2].numberofshape&& AI_batting_distinction[1].numberofshape == AI_batting_distinction[3].numberofshape&&AI_batting_distinction[1].numberofshape == AI_batting_distinction[4].numberofshape)
			{
				int probablity = rand() % 100 + 1;
				if (bat.current_batting_money > (myAI.firstmoney / 10) * 2)//가지고 있던 돈의 30%가 콜을 해야할 돈이면 call이나 check die를 하도록 함
				{
					if (probablity > 70)//40퍼센트의 확률로 콜을 한다
					{
						myAI.battingcount = 2;
					}
					else if (check_temp == 1)
					{
						myAI.battingcount = 2;
						check_temp = 0;
					}
					else if (probablity > 10)
					{
						myAI.battingcount = 1;
						check_temp = 1;
					}
					else
					{
						myAI.battingcount = 2;
					}
					plush_ = 1;
				}
				else
				{
					if (probablity > 97)
					{
						myAI.battingcount = 4;//하프
					}
					else if (probablity > 90)
					{
						myAI.battingcount = 3;//double 외침
					}
					else
					{
						myAI.battingcount = 2;//call외침
					}
					plush_ = 1;
				}
			}
			int straight_ = 0;//straight을 판단
			int subtract_arr[4];//1-0 2-1 3-2 4-3 5-4 6-5 를 저장하는 배열 striaght를 이걸로 판별할것입니다..
			for (int i = 0; i < 4; i++)
			{
				subtract_arr[i] = AI_batting_distinction[i + 1].numberofcard - AI_batting_distinction[i].numberofcard;
			}
			if (subtract_arr[0] + subtract_arr[1] + subtract_arr[2] == 3)
			{
				int probablity = rand() % 100 + 1;
				if (bat.current_batting_money >(myAI.firstmoney / 10) * 2)//가지고 있던 돈의 30%가 콜을 해야할 돈이면 call이나 check die를 하도록 함
				{
					if (probablity > 70)//40퍼센트의 확률로 콜을 한다
					{
						myAI.battingcount = 2;
					}
					else if (check_temp == 1)
					{
						myAI.battingcount = 2;
						check_temp = 0;
					}
					else if (probablity > 10)
					{
						myAI.battingcount = 1;
						check_temp = 1;
					}
					else
					{
						myAI.battingcount = 2;
					}
					straight_ = 1;
				}
				else
				{
					if (probablity > 97)
					{
						myAI.battingcount = 4;//하프
					}
					else if (probablity > 90)
					{
						myAI.battingcount = 3;//double 외침
					}
					else
					{
						myAI.battingcount = 2;//call외침
					}
					straight_ = 1;
				}
			}
			else if (subtract_arr[1] + subtract_arr[2] + subtract_arr[3] == 3)
			{
				int probablity = rand() % 100 + 1;
				if (bat.current_batting_money > (myAI.firstmoney / 10) * 2)//가지고 있던 돈의 30%가 콜을 해야할 돈이면 call이나 check die를 하도록 함
				{
					if (probablity > 70)//40퍼센트의 확률로 콜을 한다
					{
						myAI.battingcount = 2;
					}
					else if (check_temp == 1)
					{
						myAI.battingcount = 2;
						check_temp = 0;
					}
					else if (probablity > 10)
					{
						myAI.battingcount = 1;
						check_temp = 1;
					}
					else
					{
						myAI.battingcount = 2;
					}
					straight_ = 1;
				}
				else
				{
					if (probablity > 97)
					{
						myAI.battingcount = 4;//하프
					}
					if (probablity > 90)
					{
						myAI.battingcount = 3;//double 외침
					}
					else
					{
						myAI.battingcount = 2;//call외침
					}
					straight_ = 1;
				}
			}
			if (plush_ == 0 && straight_ == 0)
			{
				int probablity = rand() % 100 + 1;
				if (bat.current_batting_money > (myAI.firstmoney / 10) * 2)//가지고 있던 돈의 30%가 콜을 해야할 돈이면 call이나 check die를 하도록 함
				{
					if (probablity > 20)//80퍼센트의 확률로 죽는다각각 10%의 확률로 call or check
					{
						myAI.battingcount = 5;
					}
					else if (check_temp == 1)
					{
						myAI.battingcount = 2;
						check_temp = 0;
					}
					else if (probablity > 10)
					{
						myAI.battingcount = 1;
						check_temp = 1;
					}
					else
					{
						myAI.battingcount = 2;
					}
				}
				else
				{
					if (probablity > 50)//50퍼센트의 확률로 죽는다각각 10%의 확률로 call or check
					{
						myAI.battingcount = 5;
					}
					else if (check_temp == 1)
					{
						myAI.battingcount = 2;
						check_temp = 0;
					}
					else if (probablity > 10)
					{
						myAI.battingcount = 1;
						check_temp = 1;
					}
					else
					{
						myAI.battingcount = 2;
					}
				}
			}
		}
	}
	else if (a == 3)//쫄보는 4장이 있어도 쉽사리 도전을 못합니다.
	{

		caRD AI_batting_distinction[6];
		AI_batting_distinction[0] = myAI.unvisiblecard[0];
		AI_batting_distinction[1] = myAI.unvisiblecard[1];
		AI_batting_distinction[2] = myAI.visiblecard[0];
		AI_batting_distinction[3] = myAI.visiblecard[1];
		AI_batting_distinction[4] = myAI.visiblecard[2];
		AI_batting_distinction[5] = myAI.visiblecard[3];
		int AIpaircount = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = i + 1; j < 6; j++)
			{
				if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[j].numberofcard)
				{
					AIpaircount++;
				}
			}
		}
		if (AIpaircount == 1)//pair 이상을 받는다면 무조건 go 할거다 		
		{
			batting_score = 1;
		}
		else if (AIpaircount == 2)
		{
			batting_score = 2;
		}
		else if (AIpaircount == 3)
		{
			batting_score = 3;
		}
		else if (AIpaircount == 4)
		{
			batting_score = 4;
		}
		else if (AIpaircount == 6)
		{
			batting_score = 5;
		}
		else
		{
			batting_score = 0;
		}
		if (batting_score == 1)
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 2)//가지고 있던 돈의 20%가 콜을 해야할 돈이면 call이나 check die를 하도록 함
			{
				if (probablity > 30)//70퍼센트의 확률로 죽는다 원페어이면 질 확률이 굉장히 높음
				{
					myAI.battingcount = 5;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else if (probablity > 10)
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
				else
				{
					myAI.battingcount = 2;
				}
			}
			else
			{
				if (probablity > 97)
				{
					myAI.battingcount = 3;//double
				}
				else//원페어를 가졌을때 93%의 확률로 콜을 외친다.-
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 2)
			//6장째에서 투페어 일때에는 이길 확률이 50%이다. 여기서 한장이 운좋게 나와서 풀하우스가 될수도 있겠지만 이렇나 가능성은 4.8로 갈정도로 희박하다.
		{//그러므로 적이 돈을 많이 지르면 다이를 결심한다.
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 3)//가지고 있던 돈의 20%가 콜을 해야할 돈이면 call이나 check die를 하도록 함
			{
				if (probablity > 50)//50퍼센트의 확률로 죽는다 투페어로 이길 확률과 바숫허개 솔종울 허욨더,
				{
					myAI.battingcount = 5;
				}
				else if (check_temp == 1)//체크는 뒤이어서 하지  못한다.
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else if (probablity > 40)//10%의 확률로 체크를 한다.
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
				else
				{
					myAI.battingcount = 2;
				}
			}
			else
			{
				if (probablity > 90)//10%확률로 더블 그 이외에는 콜을 외친다.
				{
					myAI.battingcount = 3;//하프
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 3)//트리플로 이길 확률은 꽤 크다 따라서 40%돈으로 오버 하지 만 않으면 거의 call을 할것이다.
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 4)//다이는 하지 않는다.
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
			}
			else//그래도 확실하게 이긴다는 보장이 없으면 달리지 않는다.
			{
				if (probablity > 90)//아직 트리플로 승부하기에는 배짱이 부족하다
				{
					myAI.battingcount = 4;//10%확률로 하프를 외친다.
				}
				else if (probablity > 70)//20%의 확률로 더블을 외친다.
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 4)//풀하우스다 이건 거의 이겼다.
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 6)
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
			}
			else
			{
				if (probablity > 55)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 15)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 5)//포카드 지는게 신기할 때이다 올인을 마음대로 해도 되는것이 이것을 이길 확률은 1%미만이다 허허
		{
			int probablity = rand() % 100 + 1;
			if (probablity > 40)
			{
				myAI.battingcount = 4;//하프
			}
			else if (probablity > 10)
			{
				myAI.battingcount = 3;//double 외침
			}
			else
			{
				myAI.battingcount = 2;//call외침
			}
		}
		if (batting_score == 0)//쫄보형은 스트레이트, 플러쉬가 확실할때만 지른다 히든카드에서 승산이 없다고 생각한다.
		{
			int straight_ = 0;//스트레이트 확인용
			int plush_ = 0;//플러쉬 확인용
			int temp = 0;
			for (int j = 0; j < 5; j++)//;player가 최종적으로 얻은 패들을 받고 정렬
			{
				for (int i = 0; i < 5 - j; i++)
				{
					if (AI_batting_distinction[i].numberofcard > AI_batting_distinction[i + 1].numberofcard)
					{
						temp = AI_batting_distinction[i].numberofcard;
						AI_batting_distinction[i].numberofcard = AI_batting_distinction[i + 1].numberofcard;
						AI_batting_distinction[i + 1].numberofcard = temp;
					}
				}
			}
			int subtract_arr[5];//1-0 2-1 3-2 4-3 5-4 6-5 를 저장하는 배열 striaght를 이걸로 판별할것입니다..
			for (int i = 0; i < 5; i++)
			{
				subtract_arr[i] = AI_batting_distinction[i + 1].numberofcard - AI_batting_distinction[i].numberofcard;
			}
			temp = 0;//sort 를 실행시키기 위하여 설정한임의의 변수
			for (int i = 0; i < 5; i++)//0을 맨뒤로 보낼 거예요
			{
				if (subtract_arr[i] == 0)
				{
					for (int j = i; j < 4; j++)
					{
						temp = subtract_arr[j];
						subtract_arr[j] = subtract_arr[j + 1];
						subtract_arr[j + 1] = temp;
					}
				}
			}
			for (int i = 0; i < 5; i++)
			{
				if (subtract_arr[i] == 0)
				{
					subtract_arr[i] += 15;
				}
			}
			int distinction_straight = 0;
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					distinction_straight += subtract_arr[i + j];
				}
				if (distinction_straight <= 4)
				{
					int straightofnumber = 0;
					for (int i = 0; i < 3; i++)
					{
						if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[i + 1].numberofcard && AI_batting_distinction[i + 1].numberofcard + 1 == AI_batting_distinction[i + 2].numberofcard)
						{
							break;
						}
					}
					straight_ = 1;
				}
			}
			int Plush = 1;//플러쉬를 판별하기 위해 선언한 임의의 변수
			for (int i = 0; i < 6; i++)
			{
				Plush = AI_batting_distinction[i].numberofshape*Plush;
			}
			int temp1 = Plush;
			int plushofshape = 0;
			int plush_rest;//나머지 저장 변수
			for (int i = 2; i < 4; i++)
			{
				Plush = temp1;
				for (int j = 0; j < 5; j++)
				{
					if (i == 4)
					{
						i = i + 1;
					}
					plush_rest = Plush%i;
					Plush = Plush / i;
					if (plush_rest != 0)
					{
						break;
					}
				}
				if (plush_rest == 0)
				{
					plushofshape = i;
					break;
				}
			}
			int plush1 = 0;
			for (int i = 0; i < 6; i++)
			{
				if (AI_batting_distinction[i].numberofshape == 1)
				{
					plush1++;
				}
			}
			Plush = temp1;
			if (plush_rest == 0 || plush1 >= 5)
			{
				plush_ = 1;
			}
			else
			{
				plush_ = 0;
			}
			if (plush_ == 1 || straight_ == 1)
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 70)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 35)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
			else
			{
				myAI.battingcount = 5;//아무 패도 없을 때에는 과감히 죽는다 질 확률이 50%가 훨씬 넘어가기 때문이다.
			}
		}
	}
	else if (a == 4)
	{
		if (myAI.value_jokbo <= 45)//질 확률 50%이상 돈이 조금만 많이 걸려 있어도 죽는다.
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 2)//가지고 있던 돈의 30%가 콜을 해야할 돈이면 call이나 check die를 하도록 함
			{
				if (probablity > 20)//80퍼센트의 확률로 죽는다
				{
					myAI.battingcount = 5;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else if (probablity > 10)
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
				else
				{
					myAI.battingcount = 2;
				}
			}
			else
			{
				if (probablity > 50)//50퍼센트의 확률로 죽는다
				{
					myAI.battingcount = 5;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else if (probablity > 10)
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
				else
				{
					myAI.battingcount = 2;
				}
			}
		}
		else if (myAI.value_jokbo < 60)//질확률이 30%정도 어느정도는 이길수 있는 카드이다.
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money >(myAI.firstmoney / 10) * 4)//현재 판돈이 내 돈의30%면 check or call을 외친다.
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
			}
			else
			{
				if (probablity > 90)//10%확률로 더블 그 이외에는 콜을 외친다.
				{
					myAI.battingcount = 3;//더블
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		else if (myAI.value_jokbo < 75)
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money>(myAI.firstmoney / 10) * 5)
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 5 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (call_temp == 2)//10%의 확률로 죽는 다 트리플에서는
				{
					myAI.battingcount = 5;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
			}
			else
			{
				if (probablity > 85)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 60)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		else if (myAI.value_jokbo < 120)//스트레이트 플러쉬 등
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money>(myAI.firstmoney / 10) * 6)
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
			}
			else
			{
				if (probablity > 70)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 30)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		else
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money>(myAI.firstmoney / 10) * 6)
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
			}
			else
			{
				if (probablity > 70)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 30)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
	}

}
/*알파고형*/
void AIprogram::AI_distinction_card4(int a, player A, AIplayer &myAI, AIplayer B, AIplayer C, AIplayer D, batting bat)
{
	myAI.battingcount = 0;
	srand((unsigned int)time(NULL));
	if (a == 2)
	{
		caRD AI_batting_distinction[5];
		AI_batting_distinction[0] = myAI.unvisiblecard[0];
		AI_batting_distinction[1] = myAI.unvisiblecard[1];
		AI_batting_distinction[2] = myAI.visiblecard[0];
		AI_batting_distinction[3] = myAI.visiblecard[1];
		AI_batting_distinction[4] = myAI.visiblecard[2];
		caRD player_visiblecard[3];
		for (int i = 0; i < 3; i++)
		{
			player_visiblecard[i] = A.visiblecard[i];
		}
		caRD enemy1_visiblecard[3];
		for (int i = 0; i < 3; i++)
		{
			enemy1_visiblecard[i] = B.visiblecard[i];
		}
		caRD enemy2_visiblecard[3];
		for (int i = 0; i < 3; i++)
		{
			enemy2_visiblecard[i] = C.visiblecard[i];
		}
		caRD enemy3_visiblecard[3];
		for (int i = 0; i < 3; i++)
		{
			enemy3_visiblecard[i] = D.visiblecard[i];
		}
		int alpago_pairdistinction[5] = { 0,0,0,0,0 };//나의 카드와 적들의 보이는 카드들의 페어 여부 확인
		for (int i = 0; i < 4; i++)
		{
			for (int j = i + 1; j < 5; j++)
			{
				if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[j].numberofcard)
				{
					alpago_pairdistinction[0] ++;
				}
			}
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = i + 1; j < 3; j++)
			{
				if (player_visiblecard[i].numberofcard == player_visiblecard[j].numberofcard)
				{
					alpago_pairdistinction[1]++;
				}
			}
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = i + 1; j < 3; j++)
			{
				if (enemy1_visiblecard[i].numberofcard == enemy1_visiblecard[j].numberofcard)
				{
					alpago_pairdistinction[2]++;
				}
			}
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = i + 1; j < 3; j++)
			{
				if (enemy2_visiblecard[i].numberofcard == enemy2_visiblecard[j].numberofcard)
				{
					alpago_pairdistinction[3]++;
				}
			}
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = i + 1; j < 3; j++)
			{
				if (enemy3_visiblecard[i].numberofcard == enemy3_visiblecard[j].numberofcard)
				{
					alpago_pairdistinction[4]++;
				}
			}
		}
		int other_pair_count[13];//페어 확인 하기 위해서
		int other_plush_count[4];//플러쉬 확인Run-Time Check Failure #2 - Stack around the variable ''was corrupted.
		for (int i = 0; i<13; i++)
		{
			other_pair_count[i] = 4;
		}
		for (int i = 0; i < 4; i++)
		{
			other_plush_count[i] = 13;
		}
		//이제 여기서부터 판단 해 나갈 것이다.
		for (int c = 0; c < 3; c++)
		{
			for (int i = 2, b = 0; i < 15; i++, b++)
			{
				if (player_visiblecard[c].numberofcard == i)
				{
					other_pair_count[b]--;
				}
				if (enemy1_visiblecard[c].numberofcard == i)
				{
					other_pair_count[b]--;
				}
				if (enemy2_visiblecard[c].numberofcard == i)
				{
					other_pair_count[b]--;
				}
				if (enemy3_visiblecard[c].numberofcard == i)
				{
					other_pair_count[b]--;
				}
			}
		}
		for (int c = 0; c < 3; c++)
		{
			for (int i = 1, b = 0; b < 4; b++, i++)
			{
				if (i == 4)
				{
					i = 5;
				}
				if (player_visiblecard[c].numberofshape == i)
				{
					other_plush_count[b]--;
				}
				if (enemy1_visiblecard[c].numberofshape == i)
				{
					other_plush_count[b]--;
				}
				if (enemy2_visiblecard[c].numberofshape == i)
				{
					other_plush_count[b]--;
				}
				if (enemy3_visiblecard[c].numberofshape == i)
				{
					other_plush_count[b]--;
				}
			}
		}
		//여기까지 적한테 있는 카드들을 삭제한 숫자들을 얻었다.
		//배열에서 각각 남아 있느 수만큼 내가 보지 못하는 카드들의 숫자이다.
		for (int i = 0; i < 5; i++)
		{
			for (int b = 2, c = 0; b < 15; b++, c++)
			{
				if (AI_batting_distinction[i].numberofcard == b)
				{
					other_pair_count[c]--;
				}
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (int b = 1, c = 0; c < 4; b++, c++)
			{
				if (b == 4)
				{
					b = 5;
				}
				if (AI_batting_distinction[i].numberofshape == b)
				{
					other_plush_count[c]--;
				}
			}
		}
		if (alpago_pairdistinction[0] == 1)//pair 이상을 받는다면 무조건 go 할거다 		
		{
			batting_score = 1;
		}
		else if (alpago_pairdistinction[0] == 2)
		{
			batting_score = 2;
		}
		else if (alpago_pairdistinction[0] == 3)
		{
			batting_score = 3;
		}
		else if (alpago_pairdistinction[0] == 4)
		{
			batting_score = 4;
		}
		else if (alpago_pairdistinction[0] == 6)
		{
			batting_score = 5;
		}
		else
		{
			batting_score = 0;
		}
		if (batting_score == 1)//원페어 일때
		{
			int my_pair_temp = 0;
			for (int i = 0; i < 4; i++)
			{
				for (int j = i + 1; j < 5; j++)
				{
					if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[j].numberofcard)
					{
						my_pair_temp = AI_batting_distinction[i].numberofcard;
					}
				}
			}
			int double_double = 0;//중복된 계산을 막기 위해서
			int hope_value = 0;//기대 되는 값들 트리플 이 하는 데 필요한 카드가 안보이는 갯수 *10 페어가 되는 데 필요한 카드가 안보이는 갯수 *1로 되어있다.
			for (int i = 0; i < 5; i++)
			{
				for (int j = 2; j < 15; j++)
				{
					if (AI_batting_distinction[i].numberofcard == j)
					{
						if (AI_batting_distinction[i].numberofcard == my_pair_temp&&double_double == 0)
						{
							hope_value = hope_value + other_pair_count[j - 2] * 10;
							double_double = 1;
						}
						else if (AI_batting_distinction[i].numberofcard == my_pair_temp&&double_double == 1)
						{
							//하는 일이 없다.
						}
						else//원페어 가 기대 될때에는 
						{
							hope_value = hope_value + other_pair_count[j - 2];
						}
					}
				}
			}//돈이 많이 걸렸을 경우와 아닌 경우 둘중에서 가능성에 따라서 다르게 설정 해 놓는다.
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 2)
			{
				if (hope_value > 25)
				{
					if (probablity > 97)
					{
						myAI.battingcount = 3;//double
					}
					else//원페어를 가졌을때 97%의 확률로 콜을 외친다.-
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else if (hope_value > 20)
				{
					if (bat.current_batting_money > (myAI.firstmoney / 10) * 4)
					{
						myAI.battingcount = 5;
					}
					else
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else if (hope_value > 15)
				{
					if (probablity > 98)
					{
						myAI.battingcount = 3;//double
					}
					else//원페어를 가졌을때 98%의 확률로 콜을 외친다.-
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else if (hope_value > 10)
				{
					if (bat.current_batting_money > (myAI.firstmoney / 10) * 4)
					{
						myAI.battingcount = 5;
					}
					else
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else if (hope_value>5)
				{
					if (probablity > 98)
					{
						myAI.battingcount = 3;//double
					}
					else//원페어를 가졌을때 98%의 확률로 콜을 외친다.-
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else
				{
					myAI.battingcount = 5;
				}
			}
			else
			{
				if (hope_value > 25)//족보가 원페어 이상이 나올 확률 이크다 
				{
					if (probablity > 90)
					{
						myAI.battingcount = 3;//double
					}
					else//원페어를 가졌을때 90%의 확률로 콜을 외친다.-
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else if (hope_value > 20)
				{
					if (bat.current_batting_money > (myAI.firstmoney / 10) * 4)
					{
						myAI.battingcount = 5;
					}
					else
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else if (hope_value > 15)
				{
					if (probablity > 95)
					{
						myAI.battingcount = 3;//double
					}
					else//원페어를 가졌을때 95%의 확률로 콜을 외친다.-
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else if (hope_value > 10)
				{
					if (bat.current_batting_money > (myAI.firstmoney / 10) * 4)
					{
						myAI.battingcount = 5;
					}
					else
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else if (hope_value>5)
				{
					if (probablity > 98)
					{
						myAI.battingcount = 3;//double
					}
					else//원페어를 가졌을때 98%의 확률로 콜을 외친다.-
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else
				{
					myAI.battingcount = 5;
				}
			}

		}
		if (batting_score == 2)
		{
			int hope_fullhouse[2] = { 0,0 };
			for (int i = 0; i < 4; i++)
			{
				for (int j = i + 1; j < 5; j++)
				{
					if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[j].numberofcard&&hope_fullhouse[0] == 0)
					{
						hope_fullhouse[0] = AI_batting_distinction[i].numberofcard;//첫번째 페어를 저장할 곳
					}
					else if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[j].numberofcard)
					{
						hope_fullhouse[1] = AI_batting_distinction[i].numberofcard;
						break;
					}
				}
			}
			int hope_value = 0;
			hope_value = other_pair_count[hope_fullhouse[0] - 2] + other_pair_count[hope_fullhouse[1] - 2];//트리플 까지 남은 카드를 더합니다.
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 3)
			{
				if (hope_value > 2)//풀하우스가 나올 가능성이 높다
				{
					if (probablity > 70)
					{
						myAI.battingcount = 3;//double
					}
					else//원페어를 가졌을때 70%의 확률로 콜을 외친다.-
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else if (hope_value > 1)
				{
					if (probablity > 90)
					{
						myAI.battingcount = 3;//double
					}
					else//원페어를 가졌을때 90%의 확률로 콜을 외친다.-
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else
				{
					if (probablity > 95)
					{
						myAI.battingcount = 3;//double
					}
					else//원페어를 가졌을때 95%의 확률로 콜을 외친다.-
					{
						myAI.battingcount = 2;//call외침
					}
				}
			}
			else
			{
				if (hope_value > 2)//족보가 투페어 이상이 나올 확률 이크다 
				{
					if (probablity > 80)
					{
						myAI.battingcount = 3;//double
					}
					else//원페어를 가졌을때 90%의 확률로 콜을 외친다.-
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else if (hope_value > 1)
				{
					if (probablity > 90)
					{
						myAI.battingcount = 3;//double
					}
					else//원페어를 가졌을때 95%의 확률로 콜을 외친다.-
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else
				{
					if (probablity > 97)
					{
						myAI.battingcount = 3;//double
					}
					else//원페어를 가졌을때 97%의 확률로 콜을 외친다.-
					{
						myAI.battingcount = 2;//call외침
					}
				}
			}
		}
		if (batting_score == 3)
		{
			int my_pair_temp = 0;
			for (int i = 0; i < 4; i++)
			{
				for (int j = i + 1; j < 5; j++)
				{
					if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[j].numberofcard)
					{
						my_pair_temp = AI_batting_distinction[i].numberofcard;
						break;
					}
				}
			}
			int hope_value = 0;
			int probablity = rand() % 100 + 1;
			for (int i = 0; i < 5; i++)
			{
				if (AI_batting_distinction[i].numberofcard != my_pair_temp)
				{
					hope_value = hope_value + other_pair_count[AI_batting_distinction[i].numberofcard - 2];
				}
			}
			if (bat.current_batting_money >(myAI.firstmoney / 10) * 3)
			{
				if (hope_value > 4)//풀하우스가 나올 가능성이 높다
				{
					if (probablity > 70)
					{
						myAI.battingcount = 3;//double
					}
					else//원페어를 가졌을때 70%의 확률로 콜을 외친다.-
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else if (hope_value > 2)
				{
					if (probablity > 80)
					{
						myAI.battingcount = 3;//double
					}
					else//원페어를 가졌을때 80%의 확률로 콜을 외친다.-
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else
				{
					if (probablity > 90)
					{
						myAI.battingcount = 3;//double
					}
					else//원페어를 가졌을때 90%의 확률로 콜을 외친다.-
					{
						myAI.battingcount = 2;//call외침
					}
				}
			}
			else
			{
				if (hope_value > 4)//족보가 트리플 이상이 나올 확률 이크다 
				{
					if (probablity > 60)
					{
						myAI.battingcount = 3;//double
					}
					else//원페어를 가졌을때 60%의 확률로 콜을 외친다.-
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else if (hope_value > 2)
				{
					if (probablity > 80)
					{
						myAI.battingcount = 3;//double
					}
					else//원페어를 가졌을때 80%의 확률로 콜을 외친다.-
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else
				{
					if (probablity > 90)
					{
						myAI.battingcount = 3;//double
					}
					else//원페어를 가졌을때 90%의 확률로 콜을 외친다.-
					{
						myAI.battingcount = 2;//call외침
					}
				}
			}
		}
		if (batting_score == 4)
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 5)//call금액이 50%일때 call or check를 한다.
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}

			}
			else
			{

				if (probablity > 60)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 30)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 5)
		{
			int probablity = rand() % 100 + 1;//5장일 때 4카드면 그냥 이김 달려야지
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 5)
			{
				int check_temp = 0;
				int call_temp = 0;
				call_temp = rand() % 10 + 1;
				if (call_temp > 1 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}

			}
			else
			{
				if (probablity > 50)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 10)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		int plush_ = 1;

		if (batting_score == 0)
		{
			int hope_plush = 0;
			int plush_rest = 0;
			int temp1;
			int plushofshape = 0;
			for (int i = 0; i < 5; i++)
			{
				plush_ = plush_*AI_batting_distinction[i].numberofshape;
			}
			temp1 = plush_;
			for (int i = 2; i < 5; i++)
			{
				plush_ = temp1;
				for (int j = 0; j < 4; j++)
				{
					if (i == 4)
					{
						i = i + 1;
					}
					plush_rest = plush_%i;
					plush_ = plush_ / i;
					if (plush_rest != 0)
					{
						break;
					}
				}
				if (plush_rest == 0)
				{
					plushofshape = i;
					hope_plush = 1;
					break;
				}
			}
			int straight_ = 0;//straight을 판단
			int straight_number = 0;
			int subtract_arr[4];//1-0 2-1 3-2 4-3 5-4 6-5 를 저장하는 배열 striaght를 이걸로 판별할것입니다..
			for (int i = 0; i < 4; i++)
			{
				subtract_arr[i] = AI_batting_distinction[i + 1].numberofcard - AI_batting_distinction[i].numberofcard;
			}
			if (subtract_arr[0] + subtract_arr[1] + subtract_arr[2] == 3)
			{
				straight_ = 1;
				straight_number = AI_batting_distinction[0].numberofcard - 1;
			}
			else if (subtract_arr[1] + subtract_arr[2] + subtract_arr[3] == 3)
			{
				straight_ = 1;
				straight_number = AI_batting_distinction[1].numberofcard - 1;
			}
			if (straight_ == 1)
			{
				int stragiht_probabilty = other_pair_count[straight_number - 2] + other_pair_count[straight_number + 3];
				if (stragiht_probabilty > 4)
				{
					int probablity = rand() % 100 + 1;
					if (probablity > 80)
					{
						myAI.battingcount = 3;
					}
					else
					{
						myAI.battingcount = 2;
					}
				}
				else if (stragiht_probabilty > 2)
				{
					int probablity = rand() % 100 + 1;
					if (probablity > 90)
					{
						myAI.battingcount = 3;
					}
					else
					{
						myAI.battingcount = 2;
					}

				}
				else
				{
					int probablity = rand() % 100 + 1;
					if (probablity > 95)
					{
						myAI.battingcount = 3;
					}
					else
					{
						myAI.battingcount = 2;
					}
				}
			}
			else if (hope_plush == 1)
			{
				if (plushofshape == 5)
				{
					plushofshape = 4;
				}
				int plush_probablity = other_plush_count[plushofshape - 1];
				if (plush_probablity > 7)
				{
					int probablity = rand() % 100 + 1;
					if (probablity > 80)
					{
						myAI.battingcount = 3;
					}
					else
					{
						myAI.battingcount = 2;
					}

				}
				else if (plush_probablity > 5)
				{
					int probablity = rand() % 100 + 1;
					if (probablity > 90)
					{
						myAI.battingcount = 3;
					}
					else
					{
						myAI.battingcount = 2;
					}
				}
				else
				{
					int probablity = rand() % 100 + 1;
					if (probablity > 95)
					{
						myAI.battingcount = 3;
					}
					else
					{
						myAI.battingcount = 2;
					}
				}
			}
			else//어차피 많이 받아 봤자 원페어다 과감하게 죽는다.
			{
				myAI.battingcount = 5;
			}
		}//원페어도 아닌거 우선 hope_plush는 1이 4장의 카드가 모였고 plushofcard에 모여있다.
	}// 5장 받았을 때가 끝나는 지점
	else if (a == 3)
	{
		caRD AI_batting_distinction[6];
		AI_batting_distinction[0] = myAI.unvisiblecard[0];
		AI_batting_distinction[1] = myAI.unvisiblecard[1];
		AI_batting_distinction[2] = myAI.visiblecard[0];
		AI_batting_distinction[3] = myAI.visiblecard[1];
		AI_batting_distinction[4] = myAI.visiblecard[2];
		AI_batting_distinction[5] = myAI.visiblecard[3];
		caRD player_visiblecard[4];
		for (int i = 0; i < 4; i++)
		{
			player_visiblecard[i] = A.visiblecard[i];
		}
		caRD enemy1_visiblecard[4];
		for (int i = 0; i < 4; i++)
		{
			enemy1_visiblecard[i] = B.visiblecard[i];
		}
		caRD enemy2_visiblecard[4];
		for (int i = 0; i < 4; i++)
		{
			enemy2_visiblecard[i] = C.visiblecard[i];
		}
		caRD enemy3_visiblecard[4];
		for (int i = 0; i < 4; i++)
		{
			enemy3_visiblecard[i] = D.visiblecard[i];
		}
		int alpago_pairdistinction[5] = { 0,0,0,0,0 };//나의 카드와 적들의 보이는 카드들의 페어 여부 확인
		for (int i = 0; i < 5; i++)
		{
			for (int j = i + 1; j < 6; j++)
			{
				if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[j].numberofcard)
				{
					alpago_pairdistinction[0] ++;
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = i + 1; j < 4; j++)
			{
				if (player_visiblecard[i].numberofcard == player_visiblecard[j].numberofcard)
				{
					alpago_pairdistinction[1]++;
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = i + 1; j < 4; j++)
			{
				if (enemy1_visiblecard[i].numberofcard == enemy1_visiblecard[j].numberofcard)
				{
					alpago_pairdistinction[2]++;
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = i + 1; j < 4; j++)
			{
				if (enemy2_visiblecard[i].numberofcard == enemy2_visiblecard[j].numberofcard)
				{
					alpago_pairdistinction[3]++;
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = i + 1; j < 4; j++)
			{
				if (enemy3_visiblecard[i].numberofcard == enemy3_visiblecard[j].numberofcard)
				{
					alpago_pairdistinction[4]++;
				}
			}
		}
		int other_pair_count[13];//페어 확인 하기 위해서
		int other_plush_count[4];//플러쉬 확인
		for (int i = 0; i<13; i++)
		{
			other_pair_count[i] = 4;
		}
		for (int i = 0; i < 4; i++)
		{
			other_plush_count[i] = 13;
		}
		//이제 여기서부터 판단 해 나갈 것이다.
		for (int c = 0; c < 4; c++)
		{
			for (int i = 2, b = 0; i < 15; i++, b++)
			{
				if (player_visiblecard[c].numberofcard == i)
				{
					other_pair_count[b]--;
				}
				if (enemy1_visiblecard[c].numberofcard == i)
				{
					other_pair_count[b]--;
				}
				if (enemy2_visiblecard[c].numberofcard == i)
				{
					other_pair_count[b]--;
				}
				if (enemy3_visiblecard[c].numberofcard == i)
				{
					other_pair_count[b]--;
				}
			}
		}
		for (int c = 0; c < 4; c++)
		{
			for (int i = 1, b = 0; b < 4; b++, i++)
			{
				if (i == 4)
				{
					i = 5;
				}
				if (player_visiblecard[c].numberofshape == i)
				{
					other_plush_count[b]--;
				}
				if (enemy1_visiblecard[c].numberofshape == i)
				{
					other_plush_count[b]--;
				}
				if (enemy2_visiblecard[c].numberofshape == i)
				{
					other_plush_count[b]--;
				}
				if (enemy3_visiblecard[c].numberofshape == i)
				{
					other_plush_count[b]--;
				}
			}
		}
		//여기까지 적한테 있는 카드들을 삭제한 숫자들을 얻었다.
		//배열에서 각각 남아 있느 수만큼 내가 보지 못하는 카드들의 숫자이다.
		for (int i = 0; i < 6; i++)
		{
			for (int b = 2, c = 0; b < 15; b++, c++)
			{
				if (AI_batting_distinction[i].numberofcard == b)
				{
					other_pair_count[c]--;
				}
			}
		}
		for (int i = 0; i < 6; i++)
		{
			for (int b = 1, c = 0; c < 4; b++, c++)
			{
				if (b == 4)
				{
					b = 5;
				}
				if (AI_batting_distinction[i].numberofshape == b)
				{
					if (b == 5)
					{
						other_plush_count[c]--;
					}
					else
					{
						other_plush_count[c]--;
					}
				}
			}
		}
		if (alpago_pairdistinction[0] == 1)//pair 이상을 받는다면 무조건 go 할거다 		
		{
			batting_score = 1;
		}
		else if (alpago_pairdistinction[0] == 2)
		{
			batting_score = 2;
		}
		else if (alpago_pairdistinction[0] == 3)
		{
			batting_score = 3;
		}
		else if (alpago_pairdistinction[0] == 4)
		{
			batting_score = 4;
		}
		else if (alpago_pairdistinction[0] == 6)
		{
			batting_score = 5;
		}
		else
		{
			batting_score = 0;
		}
		if (batting_score == 1)
		{
			int my_pair_temp = 0;
			for (int i = 0; i < 5; i++)
			{
				for (int j = i + 1; j < 6; j++)
				{
					if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[j].numberofcard)
					{
						my_pair_temp = AI_batting_distinction[i].numberofcard;
						break;
					}
				}
			}
			int alpago_surrender[4] = { 0,0,0,0 };//혹시나 센거 나오면 죽는다 
			int double_double = 0;//중복된 계산을 막기 위해서
			int hope_value = 0;//기대 되는 값들 트리플 이 하는 데 필요한 카드가 안보이는 갯수 *10 페어가 되는 데 필요한 카드가 안보이는 갯수 *1로 되어있다.
			for (int i = 0; i < 6; i++)
			{
				for (int j = 2; j < 15; j++)
				{
					if (AI_batting_distinction[i].numberofcard == j)
					{
						if (AI_batting_distinction[i].numberofcard == my_pair_temp&&double_double == 0)
						{
							hope_value = hope_value + other_pair_count[j - 2] * 10;
							double_double = 1;
						}
						else if (AI_batting_distinction[i].numberofcard == my_pair_temp&&double_double == 1)
						{
							//하는 일이 없다.
						}
						else//원페어 가 기대 될때에는 
						{
							hope_value = hope_value + other_pair_count[j - 2];
						}
					}
				}
			}//돈이 많이 걸렸을 경우와 아닌 경우 둘중에서 가능성에 따라서 다르게 설정 해 놓는다.
			if (alpago_pairdistinction[1] != 0)
			{
				if (alpago_pairdistinction[1] == 1)
				{
					int double_double = 0;//중복된 계산을 막기 위해서
					int enemy_pair_temp = 0;
					for (int i = 0; i < 5; i++)
					{
						for (int j = i + 1; j < 6; j++)
						{
							if (player_visiblecard[i].numberofcard == player_visiblecard[j].numberofcard)
							{
								enemy_pair_temp = player_visiblecard[i].numberofcard;
								break;
							}
						}
					}
					int enemey_value = 0;
					for (int i = 0; i < 4; i++)
					{
						for (int j = 2; j < 15; j++)
						{
							if (player_visiblecard[i].numberofcard == j)
							{
								if (player_visiblecard[i].numberofcard == enemy_pair_temp&&double_double == 0)
								{
									enemey_value = enemey_value + other_pair_count[j - 2] * 10;
									double_double = 1;
								}
								else if (player_visiblecard[i].numberofcard == enemy_pair_temp&&double_double == 1)
								{
									//하는 일이 없다.
								}
								else//원페어 가 기대 될때에는 
								{
									enemey_value = enemey_value + other_pair_count[j - 2];
								}
							}
						}
					}
					if ((enemey_value % 10) > 5 || enemey_value > 20)
					{
						alpago_surrender[0] = 1;
					}
				}
				else if (alpago_pairdistinction[1] == 2)
				{
					int enemy_value = 0;
					for (int i = 0; i < 4; i++)
					{
						enemy_value = enemy_value + other_pair_count[player_visiblecard[i].numberofcard - 2];
					}
					enemy_value = enemy_value / 2;
					if (enemy_value > 2)
					{
						alpago_surrender[0] = 1;
					}
					else
					{

					}
				}
				else
				{
					alpago_surrender[0] = 1;
				}
			}
			if (alpago_pairdistinction[2] != 0)
			{
				if (alpago_pairdistinction[2] == 1)
				{
					int double_double = 0;//중복된 계산을 막기 위해서
					int enemy_pair_temp = 0;
					for (int i = 0; i < 5; i++)
					{
						for (int j = i + 1; j < 6; j++)
						{
							if (enemy1_visiblecard[i].numberofcard == enemy1_visiblecard[j].numberofcard)
							{
								enemy_pair_temp = enemy1_visiblecard[i].numberofcard;
								break;
							}
						}
					}
					int enemey_value = 0;
					for (int i = 0; i < 4; i++)
					{
						for (int j = 2; j < 15; j++)
						{
							if (enemy1_visiblecard[i].numberofcard == j)
							{
								if (enemy1_visiblecard[i].numberofcard == enemy_pair_temp&&double_double == 0)
								{
									enemey_value = enemey_value + other_pair_count[j - 2] * 10;
									double_double = 1;
								}
								else if (enemy1_visiblecard[i].numberofcard == enemy_pair_temp&&double_double == 1)
								{
									//하는 일이 없다.
								}
								else//원페어 가 기대 될때에는 
								{
									enemey_value = enemey_value + other_pair_count[j - 2];
								}
							}
						}
					}
					if ((enemey_value % 10) > 5 || enemey_value > 20)
					{
						alpago_surrender[1] = 1;
					}
				}
				else if (alpago_pairdistinction[2] == 2)
				{
					int enemy_value = 0;
					for (int i = 0; i < 4; i++)
					{
						enemy_value = enemy_value + other_pair_count[enemy1_visiblecard[i].numberofcard - 2];
					}
					enemy_value = enemy_value / 2;
					if (enemy_value > 2)
					{
						alpago_surrender[1] = 1;
					}
					else
					{

					}
				}
				else
				{
					alpago_surrender[1] = 1;
				}
			}
			if (alpago_pairdistinction[3] != 0)
			{
				if (alpago_pairdistinction[3] == 1)
				{
					int double_double = 0;//중복된 계산을 막기 위해서
					int enemy_pair_temp = 0;
					for (int i = 0; i < 5; i++)
					{
						for (int j = i + 1; j < 6; j++)
						{
							if (enemy2_visiblecard[i].numberofcard == enemy2_visiblecard[j].numberofcard)
							{
								enemy_pair_temp = enemy2_visiblecard[i].numberofcard;
								break;
							}
						}
					}
					int enemey_value = 0;
					for (int i = 0; i < 4; i++)
					{
						for (int j = 2; j < 15; j++)
						{
							if (enemy2_visiblecard[i].numberofcard == j)
							{
								if (enemy2_visiblecard[i].numberofcard == enemy_pair_temp&&double_double == 0)
								{
									enemey_value = enemey_value + other_pair_count[j - 2] * 10;
									double_double = 1;
								}
								else if (enemy2_visiblecard[i].numberofcard == enemy_pair_temp&&double_double == 1)
								{
									//하는 일이 없다.
								}
								else//원페어 가 기대 될때에는 
								{
									enemey_value = enemey_value + other_pair_count[j - 2];
								}
							}
						}
					}
					if ((enemey_value % 10) > 5 || enemey_value > 20)
					{
						alpago_surrender[2] = 1;
					}
				}
				else if (alpago_pairdistinction[3] == 2)
				{
					int enemy_value = 0;
					for (int i = 0; i < 4; i++)
					{
						enemy_value = enemy_value + other_pair_count[enemy2_visiblecard[i].numberofcard - 2];
					}
					enemy_value = enemy_value / 2;
					if (enemy_value > 2)
					{
						alpago_surrender[2] = 1;
					}
					else
					{

					}
				}
				else
				{
					alpago_surrender[2] = 1;
				}
			}
			if (alpago_pairdistinction[4] != 0)
			{
				if (alpago_pairdistinction[4] == 1)
				{
					int double_double = 0;//중복된 계산을 막기 위해서
					int enemy_pair_temp = 0;
					for (int i = 0; i < 5; i++)
					{
						for (int j = i + 1; j < 6; j++)
						{
							if (enemy3_visiblecard[i].numberofcard == enemy3_visiblecard[j].numberofcard)
							{
								enemy_pair_temp = enemy3_visiblecard[i].numberofcard;
								break;
							}
						}
					}
					int enemey_value = 0;
					for (int i = 0; i < 4; i++)
					{
						for (int j = 2; j < 15; j++)
						{
							if (enemy3_visiblecard[i].numberofcard == j)
							{
								if (enemy3_visiblecard[i].numberofcard == enemy_pair_temp&&double_double == 0)
								{
									enemey_value = enemey_value + other_pair_count[j - 2] * 10;
									double_double = 1;
								}
								else if (enemy3_visiblecard[i].numberofcard == enemy_pair_temp&&double_double == 1)
								{
									//하는 일이 없다.
								}
								else//원페어 가 기대 될때에는 
								{
									enemey_value = enemey_value + other_pair_count[j - 2];
								}
							}
						}
					}
					if ((enemey_value % 10) > 5 || enemey_value > 20)
					{
						alpago_surrender[3] = 1;
					}
				}
				else if (alpago_pairdistinction[4] == 2)
				{
					int enemy_value = 0;
					for (int i = 0; i < 4; i++)
					{
						enemy_value = enemy_value + other_pair_count[enemy3_visiblecard[i].numberofcard - 2];
					}
					enemy_value = enemy_value / 2;
					if (enemy_value > 2)
					{
						alpago_surrender[3] = 1;
					}
					else
					{

					}
				}
				else
				{
					alpago_surrender[3] = 1;
				}
			}
			int probablity = rand() % 100 + 1;
			if (alpago_surrender[0] + alpago_surrender[1] + alpago_surrender[2] + alpago_surrender[3] != 0)
			{
				myAI.battingcount = 5;
			}
			else
			{
				if (bat.current_batting_money > (myAI.firstmoney / 10) * 2)
				{
					if (hope_value > 25)
					{
						myAI.battingcount = 3;//double
					}
					else if (hope_value > 20)
					{
						if (bat.current_batting_money > (myAI.firstmoney / 10) * 4)
						{
							myAI.battingcount = 5;
						}
						else
						{
							myAI.battingcount = 2;//call외침
						}
					}
					else if (hope_value > 15)
					{
						myAI.battingcount = 2;//call외침
					}
					else if (hope_value > 10)
					{
						if (bat.current_batting_money > (myAI.firstmoney / 10) * 4)
						{
							myAI.battingcount = 5;
						}
						else
						{
							myAI.battingcount = 2;//call외침
						}
					}
					else if (hope_value > 5)
					{
						myAI.battingcount = 2;//call외침
					}
					else
					{
						myAI.battingcount = 5;
					}
				}
				else
				{
					if (hope_value > 25)//족보가 원페어 이상이 나올 확률 이크다 
					{
						myAI.battingcount = 2;//call외침
					}
					else if (hope_value > 20)
					{
						if (bat.current_batting_money > (myAI.firstmoney / 10) * 4)
						{
							myAI.battingcount = 5;
						}
						else
						{
							myAI.battingcount = 2;//call외침
						}
					}
					else if (hope_value > 15)
					{
						myAI.battingcount = 2;//call외침
					}
					else if (hope_value > 10)
					{
						if (bat.current_batting_money > (myAI.firstmoney / 10) * 4)
						{
							myAI.battingcount = 5;
						}
						else
						{
							myAI.battingcount = 2;//call외침
						}
					}
					else if (hope_value > 5)
					{
						myAI.battingcount = 2;//call외침
					}
					else
					{
						myAI.battingcount = 5;
					}
				}
			}
		}
		if (batting_score == 2)
		{
			int hope_fullhouse[2] = { 0,0 };
			for (int i = 0; i < 5; i++)
			{
				for (int j = i + 1; j < 6; j++)
				{
					if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[j].numberofcard&&hope_fullhouse[0] == 0)
					{
						hope_fullhouse[0] = AI_batting_distinction[i].numberofcard;//첫번째 페어를 저장할 곳
					}
					else if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[j].numberofcard)
					{
						hope_fullhouse[1] = AI_batting_distinction[i].numberofcard;
						break;
					}
				}
			}
			int hope_value = 0;
			hope_value = other_pair_count[hope_fullhouse[0] - 2] + other_pair_count[hope_fullhouse[1] - 2];//트리플 까지 남은 카드를 더합니다.
																										   //적이 투페어 이상일 경우를 구하자 
			int axiety = 0;//고할지 아닐지 결정
			if (alpago_pairdistinction[1] > 2 || alpago_pairdistinction[2] > 2 || alpago_pairdistinction[3] > 2 || alpago_pairdistinction[4] > 2)//적이 투페어 이상일때
			{
				axiety = 1;
			}
			else
			{
				int alpago_surrender[4] = { 0,0,0,0 };
				if (alpago_pairdistinction[1] != 0)
				{
					if (alpago_pairdistinction[1] == 1)
					{
						int double_double = 0;//중복된 계산을 막기 위해서
						int enemy_pair_temp = 0;
						for (int i = 0; i < 5; i++)
						{
							for (int j = i + 1; j < 6; j++)
							{
								if (player_visiblecard[i].numberofcard == player_visiblecard[j].numberofcard)
								{
									enemy_pair_temp = player_visiblecard[i].numberofcard;
									break;
								}
							}
						}
						int enemey_value = 0;
						for (int i = 0; i < 4; i++)
						{
							for (int j = 2; j < 15; j++)
							{
								if (player_visiblecard[i].numberofcard == j)
								{
									if (player_visiblecard[i].numberofcard == enemy_pair_temp&&double_double == 0)
									{
										enemey_value = enemey_value + other_pair_count[j - 2] * 10;
										double_double = 1;
									}
									else if (player_visiblecard[i].numberofcard == enemy_pair_temp&&double_double == 1)
									{
										//하는 일이 없다.
									}
									else//원페어 가 기대 될때에는 
									{
										enemey_value = enemey_value + other_pair_count[j - 2];
									}
								}
							}
						}
						if ((enemey_value % 10) > 5 || enemey_value > 20)
						{
							alpago_surrender[0] = 1;
						}
					}
					else if (alpago_pairdistinction[1] == 2)
					{
						int enemy_value = 0;
						for (int i = 0; i < 4; i++)
						{
							enemy_value = enemy_value + other_pair_count[player_visiblecard[i].numberofcard - 2];
						}
						enemy_value = enemy_value / 2;
						if (enemy_value > 2)
						{
							alpago_surrender[0] = 1;
						}
						else
						{

						}
					}
					else
					{
						alpago_surrender[0] = 1;
					}
				}
				if (alpago_pairdistinction[2] != 0)
				{
					if (alpago_pairdistinction[2] == 1)
					{
						int double_double = 0;//중복된 계산을 막기 위해서
						int enemy_pair_temp = 0;
						for (int i = 0; i < 5; i++)
						{
							for (int j = i + 1; j < 6; j++)
							{
								if (enemy1_visiblecard[i].numberofcard == enemy1_visiblecard[j].numberofcard)
								{
									enemy_pair_temp = enemy1_visiblecard[i].numberofcard;
									break;
								}
							}
						}
						int enemey_value = 0;
						for (int i = 0; i < 4; i++)
						{
							for (int j = 2; j < 15; j++)
							{
								if (enemy1_visiblecard[i].numberofcard == j)
								{
									if (enemy1_visiblecard[i].numberofcard == enemy_pair_temp&&double_double == 0)
									{
										enemey_value = enemey_value + other_pair_count[j - 2] * 10;
										double_double = 1;
									}
									else if (enemy1_visiblecard[i].numberofcard == enemy_pair_temp&&double_double == 1)
									{
										//하는 일이 없다.
									}
									else//원페어 가 기대 될때에는 
									{
										enemey_value = enemey_value + other_pair_count[j - 2];
									}
								}
							}
						}
						if ((enemey_value % 10) > 5 || enemey_value > 20)
						{
							alpago_surrender[1] = 1;
						}
					}
					else if (alpago_pairdistinction[2] == 2)
					{
						int enemy_value = 0;
						for (int i = 0; i < 4; i++)
						{
							enemy_value = enemy_value + other_pair_count[enemy1_visiblecard[i].numberofcard - 2];
						}
						enemy_value = enemy_value / 2;
						if (enemy_value > 2)
						{
							alpago_surrender[1] = 1;
						}
						else
						{

						}
					}
					else
					{
						alpago_surrender[1] = 1;
					}
				}
				if (alpago_pairdistinction[3] != 0)
				{
					if (alpago_pairdistinction[3] == 1)
					{
						int double_double = 0;//중복된 계산을 막기 위해서
						int enemy_pair_temp = 0;
						for (int i = 0; i < 5; i++)
						{
							for (int j = i + 1; j < 6; j++)
							{
								if (enemy2_visiblecard[i].numberofcard == enemy2_visiblecard[j].numberofcard)
								{
									enemy_pair_temp = enemy2_visiblecard[i].numberofcard;
									break;
								}
							}
						}
						int enemey_value = 0;
						for (int i = 0; i < 4; i++)
						{
							for (int j = 2; j < 15; j++)
							{
								if (enemy2_visiblecard[i].numberofcard == j)
								{
									if (enemy2_visiblecard[i].numberofcard == enemy_pair_temp&&double_double == 0)
									{
										enemey_value = enemey_value + other_pair_count[j - 2] * 10;
										double_double = 1;
									}
									else if (enemy2_visiblecard[i].numberofcard == enemy_pair_temp&&double_double == 1)
									{
										//하는 일이 없다.
									}
									else//원페어 가 기대 될때에는 
									{
										enemey_value = enemey_value + other_pair_count[j - 2];
									}
								}
							}
						}
						if ((enemey_value % 10) > 5 || enemey_value > 20)
						{
							alpago_surrender[2] = 1;
						}
					}
					else if (alpago_pairdistinction[3] == 2)
					{
						int enemy_value = 0;
						for (int i = 0; i < 4; i++)
						{
							enemy_value = enemy_value + other_pair_count[enemy2_visiblecard[i].numberofcard - 2];
						}
						enemy_value = enemy_value / 2;
						if (enemy_value > 2)
						{
							alpago_surrender[2] = 1;
						}
						else
						{

						}
					}
					else
					{
						alpago_surrender[2] = 1;
					}
				}
				if (alpago_pairdistinction[4] != 0)
				{
					if (alpago_pairdistinction[4] == 1)
					{
						int double_double = 0;//중복된 계산을 막기 위해서
						int enemy_pair_temp = 0;
						for (int i = 0; i < 5; i++)
						{
							for (int j = i + 1; j < 6; j++)
							{
								if (enemy3_visiblecard[i].numberofcard == enemy3_visiblecard[j].numberofcard)
								{
									enemy_pair_temp = enemy3_visiblecard[i].numberofcard;
									break;
								}
							}
						}
						int enemey_value = 0;
						for (int i = 0; i < 4; i++)
						{
							for (int j = 2; j < 15; j++)
							{
								if (enemy3_visiblecard[i].numberofcard == j)
								{
									if (enemy3_visiblecard[i].numberofcard == enemy_pair_temp&&double_double == 0)
									{
										enemey_value = enemey_value + other_pair_count[j - 2] * 10;
										double_double = 1;
									}
									else if (enemy3_visiblecard[i].numberofcard == enemy_pair_temp&&double_double == 1)
									{
										//하는 일이 없다.
									}
									else//원페어 가 기대 될때에는 
									{
										enemey_value = enemey_value + other_pair_count[j - 2];
									}
								}
							}
						}
						if ((enemey_value % 10) > 5 || enemey_value > 20)
						{
							alpago_surrender[3] = 1;
						}
					}
					else if (alpago_pairdistinction[4] == 2)
					{
						int enemy_value = 0;
						for (int i = 0; i < 4; i++)
						{
							enemy_value = enemy_value + other_pair_count[enemy3_visiblecard[i].numberofcard - 2];
						}
						enemy_value = enemy_value / 2;
						if (enemy_value > 2)
						{
							alpago_surrender[3] = 1;
						}
						else
						{

						}
					}
					else
					{
						alpago_surrender[3] = 1;
					}
				}
				if (alpago_surrender[0] + alpago_surrender[1] + alpago_surrender[2] + alpago_surrender[3])
				{
					axiety = 1;
				}
			}
			int probablity = rand() % 100 + 1;
			if (axiety == 1)
			{
				if (probablity > 10)
				{
					myAI.battingcount = 5;
				}
				else
				{
					if (bat.current_batting_money > (myAI.firstmoney / 10) * 3)
					{
						myAI.battingcount = 5;
					}
					else
					{
						myAI.battingcount = 2;
					}
				}
			}
			else
			{
				if (bat.current_batting_money > (myAI.firstmoney / 10) * 3)
				{
					if (hope_value > 2)//풀하우스가 나올 가능성이 높다
					{
						if (probablity > 90)
						{
							myAI.battingcount = 3;//double
						}
						else//90%의 확률로 콜을 외친다.-
						{
							myAI.battingcount = 2;//call외침
						}
					}
					else if (hope_value > 1)
					{
						if (probablity > 95)
						{
							myAI.battingcount = 3;//double
						}
						else//원페어를 가졌을때 95%의 확률로 콜을 외친다.-
						{
							myAI.battingcount = 2;//call외침
						}
					}
					else
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else
				{
					if (hope_value > 2)//족보가 투페어 이상이 나올 확률 이크다 
					{
						if (probablity > 80)
						{
							myAI.battingcount = 3;//double
						}
						else//원페어를 가졌을때 90%의 확률로 콜을 외친다.-
						{
							myAI.battingcount = 2;//call외침
						}
					}
					else if (hope_value > 1)
					{
						if (probablity > 90)
						{
							myAI.battingcount = 3;//double
						}
						else//원페어를 가졌을때 95%의 확률로 콜을 외친다.-
						{
							myAI.battingcount = 2;//call외침
						}
					}
					else
					{
						if (probablity > 97)
						{
							myAI.battingcount = 3;//double
						}
						else//원페어를 가졌을때 97%의 확률로 콜을 외친다.-
						{
							myAI.battingcount = 2;//call외침
						}
					}
				}
			}
		}
		if (batting_score == 3)
		{
			int my_pair_temp = 0;
			for (int i = 0; i < 5; i++)
			{
				for (int j = i + 1; j < 6; j++)
				{
					if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[j].numberofcard)
					{
						my_pair_temp = AI_batting_distinction[i].numberofcard;
						break;
					}
				}
			}
			int hope_value = 0;
			int probablity = rand() % 100 + 1;
			for (int i = 0; i < 5; i++)
			{
				if (AI_batting_distinction[i].numberofcard != my_pair_temp)
				{
					hope_value = hope_value + other_pair_count[AI_batting_distinction[i].numberofcard - 2];
				}
			}
			if (bat.current_batting_money >(myAI.firstmoney / 10) * 3)
			{
				if (hope_value > 4)//풀하우스가 나올 가능성이 높다
				{
					if (probablity > 90)
					{
						myAI.battingcount = 3;//double
					}
					else//원페어를 가졌을때 70%의 확률로 콜을 외친다.-
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else
				{
					myAI.battingcount = 2;//call외침

				}
			}
			else
			{
				if (hope_value > 4)//족보가 트리플 이상이 나올 확률 이크다 
				{
					if (probablity > 90)
					{
						myAI.battingcount = 3;//double
					}
					else//원페어를 가졌을때 90%의 확률로 콜을 외친다.-
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else if (hope_value > 2)
				{
					if (probablity > 95)
					{
						myAI.battingcount = 3;//double
					}
					else//원페어를 가졌을때 95%의 확률로 콜을 외친다.-
					{
						myAI.battingcount = 2;//call외침
					}
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 4)
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 5)//call금액이 50%일때 call or check를 한다.
			{
				call_temp = rand() % 10 + 1;
				if (call_temp > 3 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}
			}
			else
			{

				if (probablity > 80)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 50)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 5)
		{
			int probablity = rand() % 100 + 1;//5장일 때 4카드면 그냥 이김 달려야지
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 5)
			{
				int check_temp = 0;
				int call_temp = 0;
				call_temp = rand() % 10 + 1;
				if (call_temp > 1 && check_temp == 0)
				{
					myAI.battingcount = 2;
				}
				else if (check_temp == 1)
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else
				{
					myAI.battingcount = 1;
					check_temp = 1;
				}

			}
			else
			{
				if (probablity > 70)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 40)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
		}
		if (batting_score == 0)//알파고형은 스트레이트, 플러쉬가 정확히 나왔을때에만 고하고 히든카드에서 나올 가능성이 없다고 본다..
		{
			int straight_ = 0;//스트레이트 확인용
			int plush_ = 0;//플러쉬 확인용
			int temp = 0;
			for (int j = 0; j < 5; j++)//;player가 최종적으로 얻은 패들을 받고 정렬
			{
				for (int i = 0; i < 5 - j; i++)
				{
					if (AI_batting_distinction[i].numberofcard > AI_batting_distinction[i + 1].numberofcard)
					{
						temp = AI_batting_distinction[i].numberofcard;
						AI_batting_distinction[i].numberofcard = AI_batting_distinction[i + 1].numberofcard;
						AI_batting_distinction[i + 1].numberofcard = temp;
					}
				}
			}
			int subtract_arr[5];//1-0 2-1 3-2 4-3 5-4 6-5 를 저장하는 배열 striaght를 이걸로 판별할것입니다..
			for (int i = 0; i < 5; i++)
			{
				subtract_arr[i] = AI_batting_distinction[i + 1].numberofcard - AI_batting_distinction[i].numberofcard;
			}
			temp = 0;//sort 를 실행시키기 위하여 설정한임의의 변수
			for (int i = 0; i < 5; i++)//0을 맨뒤로 보낼 거예요
			{
				if (subtract_arr[i] == 0)
				{
					for (int j = i; j < 4; j++)
					{
						temp = subtract_arr[j];
						subtract_arr[j] = subtract_arr[j + 1];
						subtract_arr[j + 1] = temp;
					}
				}
			}
			for (int i = 0; i < 5; i++)
			{
				if (subtract_arr[i] == 0)
				{
					subtract_arr[i] += 15;
				}
			}
			int distinction_straight = 0;
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					distinction_straight += subtract_arr[i + j];
				}
				if (distinction_straight <= 4)
				{
					int straightofnumber = 0;
					for (int i = 0; i < 3; i++)
					{
						if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[i + 1].numberofcard && AI_batting_distinction[i + 1].numberofcard + 1 == AI_batting_distinction[i + 2].numberofcard)
						{
							break;
						}
					}
					straight_ = 1;
				}
			}
			int Plush = 1;//플러쉬를 판별하기 위해 선언한 임의의 변수
			for (int i = 0; i < 6; i++)
			{
				Plush = AI_batting_distinction[i].numberofshape*Plush;
			}
			int temp1 = Plush;
			int plushofshape = 0;
			int plush_rest;//나머지 저장 변수
			for (int i = 2; i < 4; i++)
			{
				Plush = temp1;
				for (int j = 0; j < 5; j++)
				{
					if (i == 4)
					{
						i = i + 1;
					}
					plush_rest = Plush%i;
					Plush = Plush / i;
					if (plush_rest != 0)
					{
						break;
					}
				}
				if (plush_rest == 0)
				{
					plushofshape = i;
					break;
				}
			}
			int plush1 = 0;
			for (int i = 0; i < 6; i++)
			{
				if (AI_batting_distinction[i].numberofshape == 1)
				{
					plush1++;
				}
			}
			Plush = temp1;
			if (plush_rest == 0 || plush1 >= 5)
			{
				plush_ = 1;
			}
			else
			{
				plush_ = 0;
			}
			if (plush_ == 1 || straight_ == 1)
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 70)
				{
					myAI.battingcount = 4;//하프
				}
				else if (probablity > 35)
				{
					myAI.battingcount = 3;//double 외침
				}
				else
				{
					myAI.battingcount = 2;//call외침
				}
			}
			else
			{
				myAI.battingcount = 5;//아무 패도 없을 때에는 과감히 죽는다 질 확률이 50%가 훨씬 넘어가기 때문이다.
			}
		}
		//마지막 아무것도 없을때 알파고 형은 스트레이트나 플러쉬를 노리지 않는다
	}//6장째 끝부분
	else if (a == 4)
	{
		caRD AI_batting_distinction[7];
		AI_batting_distinction[0] = myAI.unvisiblecard[0];
		AI_batting_distinction[1] = myAI.unvisiblecard[1];
		AI_batting_distinction[6] = myAI.unvisiblecard[2];
		AI_batting_distinction[2] = myAI.visiblecard[0];
		AI_batting_distinction[3] = myAI.visiblecard[1];
		AI_batting_distinction[4] = myAI.visiblecard[2];
		AI_batting_distinction[5] = myAI.visiblecard[3];
		caRD player_visiblecard[4];
		for (int i = 0; i < 4; i++)
		{
			player_visiblecard[i] = A.visiblecard[i];
		}
		caRD enemy1_visiblecard[4];
		for (int i = 0; i < 4; i++)
		{
			enemy1_visiblecard[i] = B.visiblecard[i];
		}
		caRD enemy2_visiblecard[4];
		for (int i = 0; i < 4; i++)
		{
			enemy2_visiblecard[i] = C.visiblecard[i];
		}
		caRD enemy3_visiblecard[4];
		for (int i = 0; i < 4; i++)
		{
			enemy3_visiblecard[i] = D.visiblecard[i];
		}
		int alpago_pairdistinction[5] = { 0,0,0,0,0 };//나의 카드와 적들의 보이는 카드들의 페어 여부 확인
		for (int i = 0; i < 3; i++)
		{
			for (int j = i + 1; j < 4; j++)
			{
				if (player_visiblecard[i].numberofcard == player_visiblecard[j].numberofcard)
				{
					if (player_visiblecard[i].numberofcard == 0)
					{
					}
					else
					{
						alpago_pairdistinction[1]++;
					}
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = i + 1; j < 4; j++)
			{
				if (enemy1_visiblecard[i].numberofcard == enemy1_visiblecard[j].numberofcard)
				{
					if (enemy1_visiblecard[i].numberofcard == 0)
					{
					}
					else
					{
						alpago_pairdistinction[2]++;
					}
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = i + 1; j < 4; j++)
			{
				if (enemy2_visiblecard[i].numberofcard == enemy2_visiblecard[j].numberofcard)
				{
					if (enemy2_visiblecard[i].numberofcard == 0)
					{
					}
					else
					{
						alpago_pairdistinction[3]++;
					}
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = i + 1; j < 4; j++)
			{
				if (enemy3_visiblecard[i].numberofcard == enemy3_visiblecard[j].numberofcard)
				{
					if (enemy3_visiblecard[i].numberofcard == 0)
					{
					}
					else
					{
						alpago_pairdistinction[4]++;
					}
				}
			}
		}
		int other_pair_count[13];//페어 확인 하기 위해서
		int other_plush_count[4];//플러쉬 확인
		for (int i = 0; i<13; i++)
		{
			other_pair_count[i] = 4;
		}
		for (int i = 0; i < 4; i++)
		{
			other_plush_count[i] = 13;
		}
		//이제 여기서부터 판단 해 나갈 것이다.
		for (int c = 0; c < 4; c++)
		{
			for (int i = 2, b = 0; i < 15; i++, b++)
			{
				if (player_visiblecard[c].numberofcard == i)
				{
					other_pair_count[b]--;
				}
				if (enemy1_visiblecard[c].numberofcard == i)
				{
					other_pair_count[b]--;
				}
				if (enemy2_visiblecard[c].numberofcard == i)
				{
					other_pair_count[b]--;
				}
				if (enemy3_visiblecard[c].numberofcard == i)
				{
					other_pair_count[b]--;
				}
			}
		}
		for (int c = 0; c < 4; c++)
		{
			for (int i = 1, b = 0; b < 4; b++, i++)
			{
				if (i == 4)
				{
					i = 5;
				}
				if (player_visiblecard[c].numberofshape == i)
				{
					other_plush_count[b]--;
				}
				if (enemy1_visiblecard[c].numberofshape == i)
				{
					other_plush_count[b]--;
				}
				if (enemy2_visiblecard[c].numberofshape == i)
				{
					other_plush_count[b]--;
				}
				if (enemy3_visiblecard[c].numberofshape == i)
				{
					other_plush_count[b]--;
				}
			}
		}
		//여기까지 적한테 있는 카드들을 삭제한 숫자들을 얻었다.
		//배열에서 각각 남아 있느 수만큼 내가 보지 못하는 카드들의 숫자이다.
		for (int i = 0; i < 6; i++)
		{
			for (int b = 2, c = 0; b < 15; b++, c++)
			{
				if (AI_batting_distinction[i].numberofcard == b)
				{
					other_pair_count[c]--;
				}
			}
		}
		for (int i = 0; i < 6; i++)
		{
			for (int b = 1, c = 0; c < 4; b++, c++)
			{
				if (b == 4)
				{
					b = 5;
				}
				if (AI_batting_distinction[i].numberofshape == b)
				{
					if (b == 5)
					{
						other_plush_count[c]--;
					}
					else
					{
						other_plush_count[c]--;
					}
				}
			}
		}
		// 보이는것은 앞에 gameturn 3일때랑 같다.
		int enemy_hope_value = 0;
		if (alpago_pairdistinction[1] == 3 || alpago_pairdistinction[2] == 3 || alpago_pairdistinction[3] == 3 || alpago_pairdistinction[4] == 3)
		{//4명의 적 플레이어 중에 보이는 것중 트리플이 무조건 있으면
			int key_player = 0;
			for (int i = 1; i < 5; i++)
			{
				if (alpago_pairdistinction[i] == 3)
				{
					key_player = i;
					break;
				}
			}
			if (key_player == 1)
			{
				int temp_card = 0;//트리플일 카드의 숫자를 저장할 변수
				for (int i = 0; i < 3; i++)
				{
					if (player_visiblecard[i].numberofcard == player_visiblecard[i + 1].numberofcard)
					{
						temp_card = player_visiblecard[i].numberofcard;
						break;
					}
				}
				int one_card;//트리플이 아닌 카드 한장
				for (int i = 0; i < 4; i++)
				{
					if (player_visiblecard[i].numberofcard != temp_card)
					{
						one_card = player_visiblecard[i].numberofcard;
					}
				}
				int hope_Value = other_pair_count[one_card - 2];
				if (hope_Value > 2)
				{
					if ((A.playerfirstmoney - A.money) > (A.playerfirstmoney / 10) * 6)//이번 도박에 건 돈이 전체 돈의 60%이상이였으면 
					{
						enemy_hope_value = 9;//풀하우스 예상
					}
				}
				else if (hope_Value > 1)
				{
					if ((A.playerfirstmoney - A.money) > (A.playerfirstmoney / 10) * 6)//이번 도박에 건 돈이 전체 돈의 60%이상이였으면 
					{
						enemy_hope_value = 9;//풀하우스 예상
					}
				}
				else
				{
					enemy_hope_value = 4;
				}
			}
			else if (key_player == 2)
			{
				int temp_card = 0;//트리플일 카드의 숫자를 저장할 변수
				for (int i = 0; i < 3; i++)
				{
					if (enemy1_visiblecard[i].numberofcard == enemy1_visiblecard[i + 1].numberofcard)
					{
						temp_card = enemy1_visiblecard[i].numberofcard;
						break;
					}
				}
				int one_card;//트리플이 아닌 카드 한장
				for (int i = 0; i < 4; i++)
				{
					if (enemy1_visiblecard[i].numberofcard != temp_card)
					{
						one_card = enemy1_visiblecard[i].numberofcard;
					}
				}
				int hope_Value = other_pair_count[one_card - 2];
				if (hope_Value > 2)
				{
					if ((B.firstmoney - B.money) > (B.firstmoney / 10) * 6)//이번 도박에 건 돈이 전체 돈의 60%이상이였으면 
					{
						enemy_hope_value = 9;//풀하우스 예상
					}
				}
				else if (hope_Value > 1)
				{
					if ((B.firstmoney - B.money) > (B.firstmoney / 10) * 6)//이번 도박에 건 돈이 전체 돈의 60%이상이였으면 
					{
						enemy_hope_value = 9;//풀하우스 예상
					}
				}
				else
				{
					enemy_hope_value = 4;
				}
			}
			else if (key_player == 3)
			{
				int temp_card = 0;//트리플일 카드의 숫자를 저장할 변수
				for (int i = 0; i < 3; i++)
				{
					if (enemy2_visiblecard[i].numberofcard == enemy2_visiblecard[i + 1].numberofcard)
					{
						temp_card = enemy2_visiblecard[i].numberofcard;
						break;
					}
				}
				int one_card;//트리플이 아닌 카드 한장
				for (int i = 0; i < 4; i++)
				{
					if (enemy2_visiblecard[i].numberofcard != temp_card)
					{
						one_card = enemy2_visiblecard[i].numberofcard;
					}
				}
				int hope_Value = other_pair_count[one_card - 2];
				if (hope_Value > 2)
				{
					if ((C.firstmoney - C.money)>(C.firstmoney / 10) * 6)//이번 도박에 건 돈이 전체 돈의 60%이상이였으면 
						enemy_hope_value = 9;//풀하우스 예상
				}
				else if (hope_Value > 1)
				{
					if ((C.firstmoney - C.money)>(C.firstmoney / 10) * 6)//이번 도박에 건 돈이 전체 돈의 60%이상이였으면 
						enemy_hope_value = 9;//풀하우스 예상
				}
				else
				{
					enemy_hope_value = 4;
				}
			}
			else if (key_player == 4)
			{
				int temp_card = 0;//트리플일 카드의 숫자를 저장할 변수
				for (int i = 0; i < 3; i++)
				{
					if (enemy3_visiblecard[i].numberofcard == enemy3_visiblecard[i + 1].numberofcard)
					{
						temp_card = enemy3_visiblecard[i].numberofcard;
						break;
					}
				}
				int one_card;//트리플이 아닌 카드 한장
				for (int i = 0; i < 4; i++)
				{
					if (enemy3_visiblecard[i].numberofcard != temp_card)
					{
						one_card = enemy3_visiblecard[i].numberofcard;
					}
				}
				int hope_Value = other_pair_count[one_card - 2];
				if (hope_Value > 2)
				{
					if ((D.firstmoney - D.money) > (D.firstmoney / 10) * 6)//이번 도박에 건 돈이 전체 돈의 60%이상이였으면 
					{
						enemy_hope_value = 9;//풀하우스 예상
					}
				}
				else if (hope_Value > 1)
				{
					if ((D.firstmoney - D.money) > (D.firstmoney / 10) * 6)//이번 도박에 건 돈이 전체 돈의 60%이상이였으면 
					{
						enemy_hope_value = 9;//풀하우스 예상
					}
				}
				else
				{
					enemy_hope_value = 4;
				}
			}
		}
		else if (alpago_pairdistinction[1] == 2 || alpago_pairdistinction[2] == 2 || alpago_pairdistinction[3] == 2 || alpago_pairdistinction[4] == 2)
		{//최대가 투페어이다
			int key_player = 0;
			for (int i = 1; i < 5; i++)
			{
				if (alpago_pairdistinction[i] == 2)
				{
					key_player = i;
					break;
				}
			}
			if (key_player == 1)
			{
				int temp_card[2];
				for (int i = 1; i < 4; i++)
				{
					if (player_visiblecard[0].numberofcard == player_visiblecard[i].numberofcard)
					{
						temp_card[0] = player_visiblecard[0].numberofcard;
					}
				}
				for (int i = 0; i < 4; i++)
				{
					if (player_visiblecard[i].numberofcard != temp_card[0])
					{
						temp_card[1] = player_visiblecard[i].numberofcard;
					}
				}
				int hope_value = other_pair_count[temp_card[0] - 2] + other_pair_count[temp_card[1] - 2];
				if (hope_value > 2)
				{
					if ((A.playerfirstmoney - A.money) > (A.playerfirstmoney / 10) * 7)//이번 도박에 건 돈이 전체 돈의 60%이상이였으면 
					{
						enemy_hope_value = 9;//풀하우스 예상
					}
				}
				else
				{
					enemy_hope_value = 3;
				}
			}
			else if (key_player == 2)
			{
				int temp_card[2];
				for (int i = 1; i < 4; i++)
				{
					if (enemy1_visiblecard[0].numberofcard == enemy1_visiblecard[i].numberofcard)
					{
						temp_card[0] = enemy1_visiblecard[0].numberofcard;
					}
				}
				for (int i = 0; i < 4; i++)
				{
					if (enemy1_visiblecard[i].numberofcard != temp_card[0])
					{
						temp_card[1] = enemy1_visiblecard[i].numberofcard;
					}
				}
				int hope_value = other_pair_count[temp_card[0] - 2] + other_pair_count[temp_card[1] - 2];
				if (hope_value > 2)
				{
					if ((B.firstmoney - B.money) > (B.firstmoney / 10) * 7)//이번 도박에 건 돈이 전체 돈의 60%이상이였으면 
					{
						enemy_hope_value = 9;//풀하우스 예상
					}
				}
				else
				{
					enemy_hope_value = 3;
				}
			}
			else if (key_player == 3)
			{
				int temp_card[2];
				for (int i = 1; i < 4; i++)
				{
					if (enemy2_visiblecard[0].numberofcard == enemy2_visiblecard[i].numberofcard)
					{
						temp_card[0] = enemy2_visiblecard[0].numberofcard;
					}
				}
				for (int i = 0; i < 4; i++)
				{
					if (enemy2_visiblecard[i].numberofcard != temp_card[0])
					{
						temp_card[1] = enemy2_visiblecard[i].numberofcard;
					}
				}
				int hope_value = other_pair_count[temp_card[0] - 2] + other_pair_count[temp_card[1] - 2];
				if (hope_value > 2)
				{
					if ((C.firstmoney - C.money) > (C.firstmoney / 10) * 7)//이번 도박에 건 돈이 전체 돈의 60%이상이였으면 
					{
						enemy_hope_value = 9;//풀하우스 예상
					}
				}
				else
				{
					enemy_hope_value = 3;
				}
			}
			else
			{
				int temp_card[2];
				for (int i = 1; i < 4; i++)
				{
					if (enemy3_visiblecard[0].numberofcard == enemy3_visiblecard[i].numberofcard)
					{
						temp_card[0] = enemy3_visiblecard[0].numberofcard;
					}
				}
				for (int i = 0; i < 4; i++)
				{
					if (enemy3_visiblecard[i].numberofcard != temp_card[0])
					{
						temp_card[1] = enemy3_visiblecard[i].numberofcard;
					}
				}
				int hope_value = other_pair_count[temp_card[0] - 2] + other_pair_count[temp_card[1] - 2];
				if (hope_value > 2)
				{
					if ((D.firstmoney - D.money) > (D.firstmoney / 10) * 7)//이번 도박에 건 돈이 전체 돈의 60%이상이였으면 
					{
						enemy_hope_value = 9;//풀하우스 예상
					}
				}
				else
				{
					enemy_hope_value = 3;
				}
			}
		}
		else if (alpago_pairdistinction[1] == 1 || alpago_pairdistinction[2] == 1 || alpago_pairdistinction[3] == 1 || alpago_pairdistinction[4] == 1)
		{
			int temp_value[4] = { 0,0,0,0 };
			//원페어는 좀 많으니까 
			if (alpago_pairdistinction[1] == 1)
			{
				int my_pair_temp = 0;
				for (int i = 0; i < 3; i++)
				{
					for (int j = i + 1; j < 4; j++)
					{
						if (A.visiblecard[i].numberofcard == A.visiblecard[j].numberofcard)
						{
							my_pair_temp = A.visiblecard[i].numberofcard;
						}
					}
				}
				int double_double = 0;//중복된 계산을 막기 위해서
				int hope_value = 0;//기대 되는 값들 트리플 이 하는 데 필요한 카드가 안보이는 갯수 *10 페어가 되는 데 필요한 카드가 안보이는 갯수 *1로 되어있다.
				for (int i = 0; i < 4; i++)
				{
					for (int j = 2; j < 15; j++)
					{
						if (A.visiblecard[i].numberofcard == j)
						{
							if (A.visiblecard[i].numberofcard == my_pair_temp&&double_double == 0)
							{
								hope_value = hope_value + other_pair_count[j - 2] * 10;
								double_double = 1;
							}
							else if (A.visiblecard[i].numberofcard == my_pair_temp&&double_double == 1)
							{
								//하는 일이 없다.
							}
							else//원페어 가 기대 될때에는 
							{
								hope_value = hope_value + other_pair_count[j - 2];
							}
						}
					}
				}
				if (hope_value > 25)//풀하우스의 가능성이
				{
					if ((A.playerfirstmoney - A.money) > (A.playerfirstmoney / 10) * 7)
					{
						temp_value[0] = 9;
					}
					else
					{
						temp_value[0] = 3;
					}
				}
				else if (hope_value > 20)//트피플
				{
					temp_value[0] = 4;
				}
				else if (hope_value>10)
				{
					if ((A.playerfirstmoney - A.money) > (A.playerfirstmoney / 10) * 7)
					{
						temp_value[0] = 4;
					}
					else
					{
						temp_value[0] = 3;
					}
				}
				else if (hope_value>5)
				{
					temp_value[0] = 3;
				}
				else
				{
					temp_value[0] = 2;
				}
			}
			else
			{
				temp_value[0] = 0;
			}
			if (alpago_pairdistinction[2] == 1)
			{
				int my_pair_temp = 0;
				for (int i = 0; i < 3; i++)
				{
					for (int j = i + 1; j < 4; j++)
					{
						if (B.visiblecard[i].numberofcard == B.visiblecard[j].numberofcard)
						{
							my_pair_temp = B.visiblecard[i].numberofcard;
						}
					}
				}
				int double_double = 0;//중복된 계산을 막기 위해서
				int hope_value = 0;//기대 되는 값들 트리플 이 하는 데 필요한 카드가 안보이는 갯수 *10 페어가 되는 데 필요한 카드가 안보이는 갯수 *1로 되어있다.
				for (int i = 0; i < 4; i++)
				{
					for (int j = 2; j < 15; j++)
					{
						if (B.visiblecard[i].numberofcard == j)
						{
							if (B.visiblecard[i].numberofcard == my_pair_temp&&double_double == 0)
							{
								hope_value = hope_value + other_pair_count[j - 2] * 10;
								double_double = 1;
							}
							else if (B.visiblecard[i].numberofcard == my_pair_temp&&double_double == 1)
							{
								//하는 일이 없다.
							}
							else//원페어 가 기대 될때에는 
							{
								hope_value = hope_value + other_pair_count[j - 2];
							}
						}
					}
				}
				if (hope_value > 25)//풀하우스의 가능성이
				{
					if ((B.firstmoney - B.money) > (B.firstmoney / 10) * 7)
					{
						temp_value[1] = 9;
					}
					else
					{
						temp_value[1] = 3;
					}
				}
				else if (hope_value > 20)//트피플
				{
					temp_value[1] = 4;
				}
				else if (hope_value>10)
				{
					if ((B.firstmoney - B.money) > (B.firstmoney / 10) * 7)
					{
						temp_value[1] = 4;
					}
					else
					{
						temp_value[1] = 3;
					}
				}
				else if (hope_value>5)
				{
					temp_value[1] = 3;
				}
				else
				{
					temp_value[1] = 2;
				}
			}
			else
			{
				temp_value[1] = 0;
			}
			if (alpago_pairdistinction[3] == 1)
			{
				int my_pair_temp = 0;
				for (int i = 0; i < 3; i++)
				{
					for (int j = i + 1; j < 4; j++)
					{
						if (C.visiblecard[i].numberofcard == C.visiblecard[j].numberofcard)
						{
							my_pair_temp = C.visiblecard[i].numberofcard;
						}
					}
				}
				int double_double = 0;//중복된 계산을 막기 위해서
				int hope_value = 0;//기대 되는 값들 트리플 이 하는 데 필요한 카드가 안보이는 갯수 *10 페어가 되는 데 필요한 카드가 안보이는 갯수 *1로 되어있다.
				for (int i = 0; i < 4; i++)
				{
					for (int j = 2; j < 15; j++)
					{
						if (C.visiblecard[i].numberofcard == j)
						{
							if (C.visiblecard[i].numberofcard == my_pair_temp&&double_double == 0)
							{
								hope_value = hope_value + other_pair_count[j - 2] * 10;
								double_double = 1;
							}
							else if (C.visiblecard[i].numberofcard == my_pair_temp&&double_double == 1)
							{
								//하는 일이 없다.
							}
							else//원페어 가 기대 될때에는 
							{
								hope_value = hope_value + other_pair_count[j - 2];
							}
						}
					}
				}
				if (hope_value > 25)//풀하우스의 가능성이
				{
					if ((C.firstmoney - C.money) > (C.firstmoney / 10) * 7)
					{
						temp_value[2] = 9;
					}
					else
					{
						temp_value[2] = 3;
					}
				}
				else if (hope_value > 20)//트피플
				{
					temp_value[2] = 4;
				}
				else if (hope_value>10)
				{
					if ((C.firstmoney - C.money) > (C.firstmoney / 10) * 7)
					{
						temp_value[2] = 4;
					}
					else
					{
						temp_value[2] = 3;
					}
				}
				else if (hope_value>5)
				{
					temp_value[2] = 3;
				}
				else
				{
					temp_value[2] = 2;
				}
			}
			else
			{
				temp_value[2] = 0;
			}
			if (alpago_pairdistinction[4] == 1)
			{
				int my_pair_temp = 0;
				for (int i = 0; i < 3; i++)
				{
					for (int j = i + 1; j < 4; j++)
					{
						if (D.visiblecard[i].numberofcard == D.visiblecard[j].numberofcard)
						{
							my_pair_temp = D.visiblecard[i].numberofcard;
						}
					}
				}
				int double_double = 0;//중복된 계산을 막기 위해서
				int hope_value = 0;//기대 되는 값들 트리플 이 하는 데 필요한 카드가 안보이는 갯수 *10 페어가 되는 데 필요한 카드가 안보이는 갯수 *1로 되어있다.
				for (int i = 0; i < 4; i++)
				{
					for (int j = 2; j < 15; j++)
					{
						if (D.visiblecard[i].numberofcard == j)
						{
							if (D.visiblecard[i].numberofcard == my_pair_temp&&double_double == 0)
							{
								hope_value = hope_value + other_pair_count[j - 2] * 10;
								double_double = 1;
							}
							else if (D.visiblecard[i].numberofcard == my_pair_temp&&double_double == 1)
							{
								//하는 일이 없다.
							}
							else//원페어 가 기대 될때에는 
							{
								hope_value = hope_value + other_pair_count[j - 2];
							}
						}
					}
				}
				if (hope_value > 25)//풀하우스의 가능성이
				{
					if ((D.firstmoney - D.money) > (D.firstmoney / 10) * 7)
					{
						temp_value[3] = 9;
					}
					else
					{
						temp_value[3] = 3;
					}
				}
				else if (hope_value > 20)//트피플
				{
					temp_value[3] = 4;
				}
				else if (hope_value>10)
				{
					if ((D.firstmoney - D.money) > (D.firstmoney / 10) * 7)
					{
						temp_value[3] = 4;
					}
					else
					{
						temp_value[3] = 3;
					}
				}
				else if (hope_value>5)
				{
					temp_value[3] = 3;
				}
				else
				{
					temp_value[3] = 2;
				}
			}
			else
			{
				temp_value[3] = 0;
			}

			int temp;//임시 저장 배열ㅇ르 만들어서 정렬을 통하여 가장 높은 숫자를 결정
			for (int i = 0; i <3; i++)
			{
				for (int j = 0; j < 3 - i; j++)
				{
					if (temp_value[j] > temp_value[j + 1])
					{
						temp = temp_value[j];
						temp_value[j] = temp_value[j + 1];
						temp_value[j + 1] = temp;
					}
				}
			}
			enemy_hope_value = temp_value[3];

			//그후 노페어는 돈을 많이 건거로 결정 해서 value결정
			//이러면 끝 그 뒤 파일 입출력만 하면 됨
		}
		else
		{
			int other_batting_money[4];//지금까지 적이 배틴한 금액 저장
			other_batting_money[0] = A.playerfirstmoney - A.money;
			other_batting_money[1] = B.firstmoney - B.money;
			other_batting_money[2] = C.firstmoney - C.money;
			other_batting_money[3] = D.firstmoney - D.money;
			int over_money[4] = { 0,0,0,0 };//어느정도 금액이상이면 고민하기 위해서 만듬
			if (other_batting_money[0] > (A.playerfirstmoney / 10) * 6)
			{
				over_money[0] = 1;
			}
			if (other_batting_money[1] > (B.firstmoney / 10) * 6)
			{
				over_money[1] = 1;
			}
			if (other_batting_money[2] > (C.firstmoney / 10) * 6)
			{
				over_money[2] = 1;
			}
			if (other_batting_money[3] > (D.firstmoney / 10) * 6)
			{
				over_money[3] = 1;
			}
			if (over_money[0] + over_money[1] + over_money[2] + over_money[3] == 0)
			{
				enemy_hope_value = 2;
			}
			else
			{
				enemy_hope_value = 4;
			}
		}

		if ((myAI.value_jokbo / 15) > enemy_hope_value)
		{
			int probablity = rand() % 100 + 1;
			if (probablity > 90)
			{
				myAI.battingcount = 3;
			}
			else
			{
				myAI.battingcount = 2;
			}
		}
		else if ((myAI.value_jokbo / 15) == enemy_hope_value)
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 6)
			{
				if (probablity > 50)
				{
					myAI.battingcount = 5;
				}
				else
				{
					myAI.battingcount = 2;
				}
			}
			else
			{
				if (probablity > 95)
				{
					myAI.battingcount = 3;
				}
				else
				{
					myAI.battingcount = 2;
				}
			}
		}
		else
		{
			int probablity = rand() % 100 + 1;
			if (probablity > 30)
			{
				myAI.battingcount = 5;
			}
			else
			{
				myAI.battingcount = 2;
			}
		}
	}
}