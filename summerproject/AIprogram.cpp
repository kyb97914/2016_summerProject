#include "AIprogram.h"



AIprogram::AIprogram()
{
}


AIprogram::~AIprogram()
{
}
/*
�÷��̾� �� �������� �� ����
���̳ѹ� �ʱ�ȭ �� �ؾ� �ڴ�
*/
/*ȣ����*/
void AIprogram::AI_distinction_card1(int a, AIplayer &myAI, batting bat)
{
	myAI.battingcount = 0;
	srand((unsigned int)time(NULL));
	/*ù���� ���� �Ǵ� ���α׷�
	����� ����� Ʈ���� �� ���
	��Ʈ����Ʈ 4�� ���� ����
	���� Ȯ���� ���
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
		if (AIpaircount == 1)//pair �̻��� �޴´ٸ� ������ go �ҰŴ� 		
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
			if (((myAI.firstmoney) / 10) * 7 > myAI.money)//������ �ִ� ���� 70%�� ���� ������ �ϸ鼭 �������� ������ call�̳� check�� �ϵ��� ��
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 60)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 50)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 40)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 15)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 10)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
		}
		int plush_ = 0;//�÷��� Ȯ�ο�
		if (batting_score == 0)
		{
			if (AI_batting_distinction[0].numberofshape == AI_batting_distinction[1].numberofshape&& AI_batting_distinction[0].numberofshape == AI_batting_distinction[2].numberofshape&&AI_batting_distinction[0].numberofshape == AI_batting_distinction[3].numberofshape)
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 90)
				{
					myAI.battingcount = 4;//����
				}
				else if (probablity > 60)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
				plush_ = 1;
			}
			else if (AI_batting_distinction[0].numberofshape == AI_batting_distinction[2].numberofshape&& AI_batting_distinction[0].numberofshape == AI_batting_distinction[3].numberofshape&&AI_batting_distinction[0].numberofshape == AI_batting_distinction[4].numberofshape)
			{

				int probablity = rand() % 100 + 1;
				if (probablity > 90)
				{
					myAI.battingcount = 4;//����
				}
				else if (probablity > 60)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
				plush_ = 1;
			}
			else if (AI_batting_distinction[1].numberofshape == AI_batting_distinction[2].numberofshape&& AI_batting_distinction[1].numberofshape == AI_batting_distinction[3].numberofshape&&AI_batting_distinction[1].numberofshape == AI_batting_distinction[4].numberofshape)
			{

				int probablity = rand() % 100 + 1;
				if (probablity > 90)
				{
					myAI.battingcount = 4;//����
				}
				else if (probablity > 60)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
				plush_ = 1;
			}
			int AItemp = 0;
			for (int j = 0; j < 4; j++)//;player�� ���������� ���� �е��� �ް� ����
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
			int straight_ = 0;//straight�� �Ǵ�
			int subtract_arr[4];//1-0 2-1 3-2 4-3 5-4 6-5 �� �����ϴ� �迭 striaght�� �̰ɷ� �Ǻ��Ұ��Դϴ�..
			for (int i = 0; i < 4; i++)
			{
				subtract_arr[i] = AI_batting_distinction[i + 1].numberofcard - AI_batting_distinction[i].numberofcard;
			}
			if (subtract_arr[0] + subtract_arr[1] + subtract_arr[2] == 3)
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 90)
				{
					myAI.battingcount = 4;//����
				}
				else if (probablity > 60)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
				straight_ = 1;
			}
			else if (subtract_arr[1] + subtract_arr[2] + subtract_arr[3] == 3)
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 90)
				{
					myAI.battingcount = 4;//����
				}
				else if (probablity > 60)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
				straight_ = 1;
			}
			if (plush_ == 0 && straight_ == 0)
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 95)
				{
					myAI.battingcount = 4;//����
				}
				else if (probablity > 90)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
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
		if (AIpaircount == 1)//pair �̻��� �޴´ٸ� ������ go �ҰŴ� 		
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
					myAI.battingcount = 4;//����
				}
				else if (probablity >70)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 75)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 50)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 15)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
		}
		if (batting_score == 5)
		{
			int probablity = rand() % 100 + 1;
			if (probablity > 40)
			{
				myAI.battingcount = 4;//����
			}
			else if (probablity > 10)
			{
				myAI.battingcount = 3;//double ��ħ
			}
			else
			{
				myAI.battingcount = 2;//call��ħ
			}
		}
		if (batting_score == 0)
		{
			int straight_ = 0;//��Ʈ����Ʈ Ȯ�ο�
			int plush_ = 0;//�÷��� Ȯ�ο�
			int temp = 0;
			for (int j = 0; j < 5; j++)//;player�� ���������� ���� �е��� �ް� ����
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
			int subtract_arr[5];//1-0 2-1 3-2 4-3 5-4 6-5 �� �����ϴ� �迭 striaght�� �̰ɷ� �Ǻ��Ұ��Դϴ�..
			for (int i = 0; i < 5; i++)
			{
				subtract_arr[i] = AI_batting_distinction[i + 1].numberofcard - AI_batting_distinction[i].numberofcard;
			}
			temp = 0;//sort �� �����Ű�� ���Ͽ� ������������ ����
			for (int i = 0; i < 5; i++)//0�� �ǵڷ� ���� �ſ���
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
			int Plush = 1;//�÷����� �Ǻ��ϱ� ���� ������ ������ ����
			for (int i = 0; i < 6; i++)
			{
				Plush = AI_batting_distinction[i].numberofshape*Plush;
			}
			int temp1 = Plush;
			int plushofshape = 0;
			int plush_rest;//������ ���� ����
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 35)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
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
				myAI.battingcount = 4;//����
			}
			else if (probablity > 95)
			{
				myAI.battingcount = 3;//double ��ħ
			}
			else
			{
				myAI.battingcount = 2;//call��ħ
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 80)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 60)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
		}
		else if (myAI.value_jokbo < 75)
		{
			int probablity = rand() % 100 + 1;
			if (probablity > 75)
			{
				myAI.battingcount = 4;//����
			}
			else if (probablity > 40)
			{
				myAI.battingcount = 3;//double ��ħ
			}
			else
			{
				myAI.battingcount = 2;//call��ħ
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 30)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}

			}
		}
		else
		{
			int probablity = rand() % 100 + 1;
			if (probablity > 40)
			{
				myAI.battingcount = 4;//����
			}
			else if (probablity > 10)
			{
				myAI.battingcount = 3;//double ��ħ
			}
			else
			{
				myAI.battingcount = 2;//call��ħ
			}
		}
	}

}
/*������*/
void AIprogram::AI_distinction_card2(int a, player A, AIplayer &myAI, AIplayer B, AIplayer C, AIplayer D, batting bat)//�̺���
{
	myAI.battingcount = 0;
	srand((unsigned int)time(NULL));
	if (a == 2)
	{
		caRD AI_batting_distinction[5];//5���� ī�带 �޽��ϴ�.
		AI_batting_distinction[0] = myAI.unvisiblecard[0];
		AI_batting_distinction[1] = myAI.unvisiblecard[1];
		AI_batting_distinction[2] = myAI.visiblecard[0];
		AI_batting_distinction[3] = myAI.visiblecard[1];
		AI_batting_distinction[4] = myAI.visiblecard[2];
		int AIpaircount = 0;
		for (int i = 0; i < 4; i++)//����� ������ Ȯ���մϴ�.
		{
			for (int j = i + 1; j < 5; j++)
			{
				if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[j].numberofcard)
				{
					AIpaircount++;
				}
			}
		}
		if (AIpaircount == 1)//pair �̻��� �޴´ٸ� ������ go �ҰŴ� 		
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
			if (((myAI.firstmoney) / 10) * 8 > myAI.money)//������ �ִ� ���� 70%�� ���� ������ �ϸ鼭 �������� ������ call�̳� check�� �ϵ��� ��
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 90)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 85)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 75)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 30)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 10)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
		}
		int plush_ = 0;//�÷��� Ȯ�ο�
		if (batting_score == 0)
		{
			if (AI_batting_distinction[0].numberofshape == AI_batting_distinction[1].numberofshape&& AI_batting_distinction[0].numberofshape == AI_batting_distinction[2].numberofshape&&AI_batting_distinction[0].numberofshape == AI_batting_distinction[3].numberofshape)
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 97)
				{
					myAI.battingcount = 4;//����
				}
				else if (probablity > 90)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
				plush_ = 1;
			}
			else if (AI_batting_distinction[0].numberofshape == AI_batting_distinction[2].numberofshape&& AI_batting_distinction[0].numberofshape == AI_batting_distinction[3].numberofshape&&AI_batting_distinction[0].numberofshape == AI_batting_distinction[4].numberofshape)
			{

				int probablity = rand() % 100 + 1;
				if (probablity > 97)
				{
					myAI.battingcount = 4;//����
				}
				else if (probablity > 90)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
				plush_ = 1;
			}
			else if (AI_batting_distinction[1].numberofshape == AI_batting_distinction[2].numberofshape&& AI_batting_distinction[1].numberofshape == AI_batting_distinction[3].numberofshape&&AI_batting_distinction[1].numberofshape == AI_batting_distinction[4].numberofshape)
			{

				int probablity = rand() % 100 + 1;
				if (probablity > 97)
				{
					myAI.battingcount = 4;//����
				}
				else if (probablity > 90)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
				plush_ = 1;
			}
			int AItemp = 0;
			for (int j = 0; j < 4; j++)//;player�� ���������� ���� �е��� �ް� ����
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
			int straight_ = 0;//straight�� �Ǵ�
			int subtract_arr[4];//1-0 2-1 3-2 4-3 5-4 6-5 �� �����ϴ� �迭 striaght�� �̰ɷ� �Ǻ��Ұ��Դϴ�..
			for (int i = 0; i < 4; i++)
			{
				subtract_arr[i] = AI_batting_distinction[i + 1].numberofcard - AI_batting_distinction[i].numberofcard;
			}
			if (subtract_arr[0] + subtract_arr[1] + subtract_arr[2] == 3)
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 97)
				{
					myAI.battingcount = 4;//����
				}
				else if (probablity > 90)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
				straight_ = 1;
			}
			else if (subtract_arr[1] + subtract_arr[2] + subtract_arr[3] == 3)
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 97)
				{
					myAI.battingcount = 4;//����
				}
				else if (probablity > 90)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
				straight_ = 1;
			}
			if (plush_ == 0 && straight_ == 0)
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 99)
				{
					myAI.battingcount = 4;//����
				}
				else if (probablity > 95)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else if (probablity > 70)
				{
					myAI.battingcount = 5;
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
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
		if (AIpaircount == 1)//pair �̻��� �޴´ٸ� ������ go �ҰŴ� 		
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
		if (batting_score == 1)//������϶�
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
				if (((myAI.firstmoney) / 10) * 8 > myAI.money)//������ �ִ� ���� 70%�� ���� ������ �ϸ鼭 �������� ������ call�̳� check�� �ϵ��� ��
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
						myAI.battingcount = 4;//����
					}
					else if (probablity > 90)
					{
						myAI.battingcount = 3;//double ��ħ
					}
					else
					{
						myAI.battingcount = 2;//call��ħ
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
						myAI.battingcount = 4;//����
					}
					else if (probablity > 90)
					{
						myAI.battingcount = 3;//double ��ħ
					}
					else
					{
						myAI.battingcount = 2;//call��ħ
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 80)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 40)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 20)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
		}
		int plush_ = 0;//�÷��� Ȯ�ο�
		if (batting_score == 0)
		{
			int straight_ = 0;//��Ʈ����Ʈ Ȯ�ο�
			int plush_ = 0;//�÷��� Ȯ�ο�
			int temp = 0;
			for (int j = 0; j < 5; j++)//;player�� ���������� ���� �е��� �ް� ����
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
			int subtract_arr[5];//1-0 2-1 3-2 4-3 5-4 6-5 �� �����ϴ� �迭 striaght�� �̰ɷ� �Ǻ��Ұ��Դϴ�..
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
			int Plush = 1;//�÷����� �Ǻ��ϱ� ���� ������ ������ ����
			for (int i = 0; i < 6; i++)
			{
				Plush = AI_batting_distinction[i].numberofshape*Plush;
			}
			int temp1 = Plush;
			int plushofshape = 0;
			int plush_rest;//������ ���� ����
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

			/*���� �̰Ŵ� ��Ʈ����Ʈ �Ǻ� �Ϸ� �� ��*/
			if (plush_ == 1 || straight_ == 1)
			{
				int probablity = rand() % 100 + 1;
				if (probablity > 90)
				{
					myAI.battingcount = 4;//����
				}
				else if (probablity > 80)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
			else
			{
				//6���� �� �� ��Ʈ����Ʈ�� �÷����� �ƴϴ� �׸��� 4���� ��Ʈ����Ʈ�� �÷����� �˸°� �ִ�
				int plushofshape = 0;
				int plush_plush = 0;
				int value = 0;
				int plush_rest;//������ ���� ����
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
						value = 1;//�÷��� value��
					}
					else
					{
						value = 0;
					}
				}
				int straight_value = 0;
				int AI_temp[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };//������ ���̴� ī�带 ������ �迭
				int my_hope_card[2];//���� ��Ʈ����Ʈ�� ���鶧 �ʿ��� ī����� ���ڸ� ������ ����
				int straight_straight = 0;//4���� ��Ʈ����Ʈ���� �Ǵ��� ����
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
		//���⿡ ������ ��� Ȯ�θ� ����
		//��Ʈ����Ʈ�� �÷����� ���� �ָ��ϴ�
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
		for (int a = 0; a < 4; a++)//���̴� �е��� ��� ����� Ʈ���� �Ǵ� ����
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
		if (myAI.value_jokbo <= 30)//�����  
		{
			int probablity = rand() % 100 + 1;
			if (value[0] > 0 || value[1] > 0 || value[2] > 0 || value[3] > 0 || value[4] >0)//���̴� �а� ����� �̻��̸� ������
			{
				myAI.battingcount = 5;
			}
			else if (probablity > 98)
			{
				myAI.battingcount = 4;//����
			}
			else if (probablity > 95)
			{
				myAI.battingcount = 3;//double ��ħ
			}
			else
			{
				myAI.battingcount = 2;//call��ħ
			}
		}
		else if (myAI.value_jokbo < 45)//����� 
		{
			int enemy_justice = 0;//����� �϶� ���Ұ����� ���� �������� ������ Ʈ������ ������ �̱� ���ɼ��� ���ٴ� �Ǵ�  ������ ����� 40�ۼ�Ʈ ����� 20�ۼ�Ʈ ������ Ȯ������ �̸� �����ϸ� 70%�� �Ѵ� �·��̱� ����
			if (value[0] > 1 || value[1] > 1 || value[2] > 1 || value[3] > 1 || value[4] > 1)//���̴� �а� ����� �̻��̸� ������
			{

				int other_money[4];
				other_money[0] = A.playerfirstmoney - A.money;
				other_money[1] = B.firstmoney - B.money;
				other_money[2] = C.firstmoney - C.money;
				other_money[3] = D.firstmoney - D.money;
				if (other_money[0] > (A.playerfirstmoney / 10) * 7)//���� ī�尡 ����� �̻��̶�� ���� �˰� ���� ���� 70%�� ��������� ����
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
						myAI.battingcount = 4;//����
					}
					else if (probablity > 90)
					{
						myAI.battingcount = 3;//double ��ħ
					}
					else
					{
						myAI.battingcount = 2;//call��ħ
					}
				}
			}
		}
		else if (myAI.value_jokbo < 60)//Ʈ����
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 70)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
		}
		else if (myAI.value_jokbo < 75)//��Ʈ����Ʈ
		{
			int probablity = rand() % 100 + 1;
			if (probablity > 75)
			{
				myAI.battingcount = 4;//����
			}
			else if (probablity > 40)
			{
				myAI.battingcount = 3;//double ��ħ
			}
			else
			{
				myAI.battingcount = 2;//call��ħ
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 30)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}

			}
		}
		else
		{
			int probablity = rand() % 100 + 1;
			if (probablity > 40)
			{
				myAI.battingcount = 4;//����
			}
			else if (probablity > 10)
			{
				myAI.battingcount = 3;//double ��ħ
			}
			else
			{
				myAI.battingcount = 2;//call��ħ
			}
		}
	}
}
/*�̺���*/
void AIprogram::AI_distinction_card3(int a, player A, AIplayer &myAI, AIplayer B, AIplayer C, AIplayer D, batting bat)
{
	myAI.battingcount = 0;
	srand((unsigned int)time(NULL));
	if (a == 2)
	{
		check_temp = 0;
		caRD AI_batting_distinction[5];//5���� ī�带 �޽��ϴ�.
		AI_batting_distinction[0] = myAI.unvisiblecard[0];
		AI_batting_distinction[1] = myAI.unvisiblecard[1];
		AI_batting_distinction[2] = myAI.visiblecard[0];
		AI_batting_distinction[3] = myAI.visiblecard[1];
		AI_batting_distinction[4] = myAI.visiblecard[2];
		int AIpaircount = 0;
		for (int i = 0; i < 4; i++)//����� ������ Ȯ���մϴ�.
		{
			for (int j = i + 1; j < 5; j++)
			{
				if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[j].numberofcard)
				{
					AIpaircount++;
				}
			}
		}
		if (AIpaircount == 1)//pair �̻��� �޴´ٸ� ������ go �ҰŴ� 		
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
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 2)//������ �ִ� ���� 30%�� ���� �ؾ��� ���̸� call�̳� check die�� �ϵ��� ��
			{
				if (probablity > 60)//70�ۼ�Ʈ�� Ȯ���� �״´�
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
				else//���� �������� 93%�� Ȯ���� ���� ��ģ��.-
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
		}
		if (batting_score == 2)//����� �϶� ���� 5�� �� ��Ȳ���� ������ ���� ���������� Ǯ�Ͽ콺�� ���� ���ɼ��� �ְ� �̱� ���ɼ��� 50%�̴�. 
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 3)//���� �ǵ��� �� ����30%�� check or call�� ��ģ��.
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
				if (probablity > 90)//10%Ȯ���� ���� �� �̿ܿ��� ���� ��ģ��.
				{
					myAI.battingcount = 3;//����
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
		}
		if (batting_score == 3)
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 4)//40%�� ���� �� �ݾ��̶�� callȤ�� check�� ��ģ��.
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
				if (probablity > 95)//5%Ȯ���� ���� 15%Ȯ���� ���� �� �̿ܿ��� ���� ��ģ��.
				{
					myAI.battingcount = 4;//����
				}
				else if (probablity > 80)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
		}
		if (batting_score == 4)
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 5)//call�ݾ��� 50%�϶� call or check�� �Ѵ�.
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 30)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
		}
		if (batting_score == 5)
		{
			int probablity = rand() % 100 + 1;//5���� �� 4ī��� �׳� �̱� �޷�����
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 10)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
		}
		int plush_ = 0;//�÷��� Ȯ�ο�
		if (batting_score == 0)
		{
			if (AI_batting_distinction[0].numberofshape == AI_batting_distinction[1].numberofshape&& AI_batting_distinction[0].numberofshape == AI_batting_distinction[2].numberofshape&&AI_batting_distinction[0].numberofshape == AI_batting_distinction[3].numberofshape)
			{//�÷����� 4�� ������
				int probablity = rand() % 100 + 1;
				if (bat.current_batting_money > (myAI.firstmoney / 10) * 2)//������ �ִ� ���� 30%�� ���� �ؾ��� ���̸� call�̳� check die�� �ϵ��� ��
				{
					if (probablity > 70)//40�ۼ�Ʈ�� Ȯ���� ���� �Ѵ�
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
						myAI.battingcount = 4;//����
					}
					else if (probablity > 90)
					{
						myAI.battingcount = 3;//double ��ħ
					}
					else
					{
						myAI.battingcount = 2;//call��ħ
					}
					plush_ = 1;
				}
			}
			else if (AI_batting_distinction[0].numberofshape == AI_batting_distinction[2].numberofshape&& AI_batting_distinction[0].numberofshape == AI_batting_distinction[3].numberofshape&&AI_batting_distinction[0].numberofshape == AI_batting_distinction[4].numberofshape)
			{
				int probablity = rand() % 100 + 1;
				if (bat.current_batting_money > (myAI.firstmoney / 10) * 2)//������ �ִ� ���� 30%�� ���� �ؾ��� ���̸� call�̳� check die�� �ϵ��� ��
				{
					if (probablity > 70)//40�ۼ�Ʈ�� Ȯ���� ���� �Ѵ�
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
						myAI.battingcount = 4;//����
					}
					else if (probablity > 90)
					{
						myAI.battingcount = 3;//double ��ħ
					}
					else
					{
						myAI.battingcount = 2;//call��ħ
					}
					plush_ = 1;
				}
			}
			else if (AI_batting_distinction[1].numberofshape == AI_batting_distinction[2].numberofshape&& AI_batting_distinction[1].numberofshape == AI_batting_distinction[3].numberofshape&&AI_batting_distinction[1].numberofshape == AI_batting_distinction[4].numberofshape)
			{
				int probablity = rand() % 100 + 1;
				if (bat.current_batting_money > (myAI.firstmoney / 10) * 2)//������ �ִ� ���� 30%�� ���� �ؾ��� ���̸� call�̳� check die�� �ϵ��� ��
				{
					if (probablity > 70)//40�ۼ�Ʈ�� Ȯ���� ���� �Ѵ�
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
						myAI.battingcount = 4;//����
					}
					else if (probablity > 90)
					{
						myAI.battingcount = 3;//double ��ħ
					}
					else
					{
						myAI.battingcount = 2;//call��ħ
					}
					plush_ = 1;
				}
			}
			int straight_ = 0;//straight�� �Ǵ�
			int subtract_arr[4];//1-0 2-1 3-2 4-3 5-4 6-5 �� �����ϴ� �迭 striaght�� �̰ɷ� �Ǻ��Ұ��Դϴ�..
			for (int i = 0; i < 4; i++)
			{
				subtract_arr[i] = AI_batting_distinction[i + 1].numberofcard - AI_batting_distinction[i].numberofcard;
			}
			if (subtract_arr[0] + subtract_arr[1] + subtract_arr[2] == 3)
			{
				int probablity = rand() % 100 + 1;
				if (bat.current_batting_money >(myAI.firstmoney / 10) * 2)//������ �ִ� ���� 30%�� ���� �ؾ��� ���̸� call�̳� check die�� �ϵ��� ��
				{
					if (probablity > 70)//40�ۼ�Ʈ�� Ȯ���� ���� �Ѵ�
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
						myAI.battingcount = 4;//����
					}
					else if (probablity > 90)
					{
						myAI.battingcount = 3;//double ��ħ
					}
					else
					{
						myAI.battingcount = 2;//call��ħ
					}
					straight_ = 1;
				}
			}
			else if (subtract_arr[1] + subtract_arr[2] + subtract_arr[3] == 3)
			{
				int probablity = rand() % 100 + 1;
				if (bat.current_batting_money > (myAI.firstmoney / 10) * 2)//������ �ִ� ���� 30%�� ���� �ؾ��� ���̸� call�̳� check die�� �ϵ��� ��
				{
					if (probablity > 70)//40�ۼ�Ʈ�� Ȯ���� ���� �Ѵ�
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
						myAI.battingcount = 4;//����
					}
					if (probablity > 90)
					{
						myAI.battingcount = 3;//double ��ħ
					}
					else
					{
						myAI.battingcount = 2;//call��ħ
					}
					straight_ = 1;
				}
			}
			if (plush_ == 0 && straight_ == 0)
			{
				int probablity = rand() % 100 + 1;
				if (bat.current_batting_money > (myAI.firstmoney / 10) * 2)//������ �ִ� ���� 30%�� ���� �ؾ��� ���̸� call�̳� check die�� �ϵ��� ��
				{
					if (probablity > 20)//80�ۼ�Ʈ�� Ȯ���� �״´ٰ��� 10%�� Ȯ���� call or check
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
					if (probablity > 50)//50�ۼ�Ʈ�� Ȯ���� �״´ٰ��� 10%�� Ȯ���� call or check
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
	else if (a == 3)//�̺��� 4���� �־ ���縮 ������ ���մϴ�.
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
		if (AIpaircount == 1)//pair �̻��� �޴´ٸ� ������ go �ҰŴ� 		
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
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 2)//������ �ִ� ���� 20%�� ���� �ؾ��� ���̸� call�̳� check die�� �ϵ��� ��
			{
				if (probablity > 30)//70�ۼ�Ʈ�� Ȯ���� �״´� ������̸� �� Ȯ���� ������ ����
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
				else//���� �������� 93%�� Ȯ���� ���� ��ģ��.-
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
		}
		if (batting_score == 2)
			//6��°���� ����� �϶����� �̱� Ȯ���� 50%�̴�. ���⼭ ������ ������ ���ͼ� Ǯ�Ͽ콺�� �ɼ��� �ְ����� �̷��� ���ɼ��� 4.8�� �������� ����ϴ�.
		{//�׷��Ƿ� ���� ���� ���� ������ ���̸� ����Ѵ�.
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 3)//������ �ִ� ���� 20%�� ���� �ؾ��� ���̸� call�̳� check die�� �ϵ��� ��
			{
				if (probablity > 50)//50�ۼ�Ʈ�� Ȯ���� �״´� ������ �̱� Ȯ���� �ټ��㰳 ������ ��A��,
				{
					myAI.battingcount = 5;
				}
				else if (check_temp == 1)//üũ�� ���̾ ����  ���Ѵ�.
				{
					myAI.battingcount = 2;
					check_temp = 0;
				}
				else if (probablity > 40)//10%�� Ȯ���� üũ�� �Ѵ�.
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
				if (probablity > 90)//10%Ȯ���� ���� �� �̿ܿ��� ���� ��ģ��.
				{
					myAI.battingcount = 3;//����
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
		}
		if (batting_score == 3)//Ʈ���÷� �̱� Ȯ���� �� ũ�� ���� 40%������ ���� ���� �� ������ ���� call�� �Ұ��̴�.
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 4)//���̴� ���� �ʴ´�.
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
			else//�׷��� Ȯ���ϰ� �̱�ٴ� ������ ������ �޸��� �ʴ´�.
			{
				if (probablity > 90)//���� Ʈ���÷� �º��ϱ⿡�� ��¯�� �����ϴ�
				{
					myAI.battingcount = 4;//10%Ȯ���� ������ ��ģ��.
				}
				else if (probablity > 70)//20%�� Ȯ���� ������ ��ģ��.
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
		}
		if (batting_score == 4)//Ǯ�Ͽ콺�� �̰� ���� �̰��.
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 15)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
		}
		if (batting_score == 5)//��ī�� ���°� �ű��� ���̴� ������ ������� �ص� �Ǵ°��� �̰��� �̱� Ȯ���� 1%�̸��̴� ����
		{
			int probablity = rand() % 100 + 1;
			if (probablity > 40)
			{
				myAI.battingcount = 4;//����
			}
			else if (probablity > 10)
			{
				myAI.battingcount = 3;//double ��ħ
			}
			else
			{
				myAI.battingcount = 2;//call��ħ
			}
		}
		if (batting_score == 0)//�̺����� ��Ʈ����Ʈ, �÷����� Ȯ���Ҷ��� ������ ����ī�忡�� �»��� ���ٰ� �����Ѵ�.
		{
			int straight_ = 0;//��Ʈ����Ʈ Ȯ�ο�
			int plush_ = 0;//�÷��� Ȯ�ο�
			int temp = 0;
			for (int j = 0; j < 5; j++)//;player�� ���������� ���� �е��� �ް� ����
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
			int subtract_arr[5];//1-0 2-1 3-2 4-3 5-4 6-5 �� �����ϴ� �迭 striaght�� �̰ɷ� �Ǻ��Ұ��Դϴ�..
			for (int i = 0; i < 5; i++)
			{
				subtract_arr[i] = AI_batting_distinction[i + 1].numberofcard - AI_batting_distinction[i].numberofcard;
			}
			temp = 0;//sort �� �����Ű�� ���Ͽ� ������������ ����
			for (int i = 0; i < 5; i++)//0�� �ǵڷ� ���� �ſ���
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
			int Plush = 1;//�÷����� �Ǻ��ϱ� ���� ������ ������ ����
			for (int i = 0; i < 6; i++)
			{
				Plush = AI_batting_distinction[i].numberofshape*Plush;
			}
			int temp1 = Plush;
			int plushofshape = 0;
			int plush_rest;//������ ���� ����
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 35)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
			else
			{
				myAI.battingcount = 5;//�ƹ� �е� ���� ������ ������ �״´� �� Ȯ���� 50%�� �ξ� �Ѿ�� �����̴�.
			}
		}
	}
	else if (a == 4)
	{
		if (myAI.value_jokbo <= 45)//�� Ȯ�� 50%�̻� ���� ���ݸ� ���� �ɷ� �־ �״´�.
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 2)//������ �ִ� ���� 30%�� ���� �ؾ��� ���̸� call�̳� check die�� �ϵ��� ��
			{
				if (probablity > 20)//80�ۼ�Ʈ�� Ȯ���� �״´�
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
				if (probablity > 50)//50�ۼ�Ʈ�� Ȯ���� �״´�
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
		else if (myAI.value_jokbo < 60)//��Ȯ���� 30%���� ��������� �̱�� �ִ� ī���̴�.
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money >(myAI.firstmoney / 10) * 4)//���� �ǵ��� �� ����30%�� check or call�� ��ģ��.
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
				if (probablity > 90)//10%Ȯ���� ���� �� �̿ܿ��� ���� ��ģ��.
				{
					myAI.battingcount = 3;//����
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
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
				else if (call_temp == 2)//10%�� Ȯ���� �״� �� Ʈ���ÿ�����
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 60)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
		}
		else if (myAI.value_jokbo < 120)//��Ʈ����Ʈ �÷��� ��
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 30)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 30)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
		}
	}

}
/*���İ���*/
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
		int alpago_pairdistinction[5] = { 0,0,0,0,0 };//���� ī��� ������ ���̴� ī����� ��� ���� Ȯ��
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
		int other_pair_count[13];//��� Ȯ�� �ϱ� ���ؼ�
		int other_plush_count[4];//�÷��� Ȯ��Run-Time Check Failure #2 - Stack around the variable ''was corrupted.
		for (int i = 0; i<13; i++)
		{
			other_pair_count[i] = 4;
		}
		for (int i = 0; i < 4; i++)
		{
			other_plush_count[i] = 13;
		}
		//���� ���⼭���� �Ǵ� �� ���� ���̴�.
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
		//������� ������ �ִ� ī����� ������ ���ڵ��� �����.
		//�迭���� ���� ���� �ִ� ����ŭ ���� ���� ���ϴ� ī����� �����̴�.
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
		if (alpago_pairdistinction[0] == 1)//pair �̻��� �޴´ٸ� ������ go �ҰŴ� 		
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
		if (batting_score == 1)//����� �϶�
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
			int double_double = 0;//�ߺ��� ����� ���� ���ؼ�
			int hope_value = 0;//��� �Ǵ� ���� Ʈ���� �� �ϴ� �� �ʿ��� ī�尡 �Ⱥ��̴� ���� *10 �� �Ǵ� �� �ʿ��� ī�尡 �Ⱥ��̴� ���� *1�� �Ǿ��ִ�.
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
							//�ϴ� ���� ����.
						}
						else//����� �� ��� �ɶ����� 
						{
							hope_value = hope_value + other_pair_count[j - 2];
						}
					}
				}
			}//���� ���� �ɷ��� ���� �ƴ� ��� ���߿��� ���ɼ��� ���� �ٸ��� ���� �� ���´�.
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 2)
			{
				if (hope_value > 25)
				{
					if (probablity > 97)
					{
						myAI.battingcount = 3;//double
					}
					else//���� �������� 97%�� Ȯ���� ���� ��ģ��.-
					{
						myAI.battingcount = 2;//call��ħ
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
						myAI.battingcount = 2;//call��ħ
					}
				}
				else if (hope_value > 15)
				{
					if (probablity > 98)
					{
						myAI.battingcount = 3;//double
					}
					else//���� �������� 98%�� Ȯ���� ���� ��ģ��.-
					{
						myAI.battingcount = 2;//call��ħ
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
						myAI.battingcount = 2;//call��ħ
					}
				}
				else if (hope_value>5)
				{
					if (probablity > 98)
					{
						myAI.battingcount = 3;//double
					}
					else//���� �������� 98%�� Ȯ���� ���� ��ģ��.-
					{
						myAI.battingcount = 2;//call��ħ
					}
				}
				else
				{
					myAI.battingcount = 5;
				}
			}
			else
			{
				if (hope_value > 25)//������ ����� �̻��� ���� Ȯ�� ��ũ�� 
				{
					if (probablity > 90)
					{
						myAI.battingcount = 3;//double
					}
					else//���� �������� 90%�� Ȯ���� ���� ��ģ��.-
					{
						myAI.battingcount = 2;//call��ħ
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
						myAI.battingcount = 2;//call��ħ
					}
				}
				else if (hope_value > 15)
				{
					if (probablity > 95)
					{
						myAI.battingcount = 3;//double
					}
					else//���� �������� 95%�� Ȯ���� ���� ��ģ��.-
					{
						myAI.battingcount = 2;//call��ħ
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
						myAI.battingcount = 2;//call��ħ
					}
				}
				else if (hope_value>5)
				{
					if (probablity > 98)
					{
						myAI.battingcount = 3;//double
					}
					else//���� �������� 98%�� Ȯ���� ���� ��ģ��.-
					{
						myAI.battingcount = 2;//call��ħ
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
						hope_fullhouse[0] = AI_batting_distinction[i].numberofcard;//ù��° �� ������ ��
					}
					else if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[j].numberofcard)
					{
						hope_fullhouse[1] = AI_batting_distinction[i].numberofcard;
						break;
					}
				}
			}
			int hope_value = 0;
			hope_value = other_pair_count[hope_fullhouse[0] - 2] + other_pair_count[hope_fullhouse[1] - 2];//Ʈ���� ���� ���� ī�带 ���մϴ�.
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 3)
			{
				if (hope_value > 2)//Ǯ�Ͽ콺�� ���� ���ɼ��� ����
				{
					if (probablity > 70)
					{
						myAI.battingcount = 3;//double
					}
					else//���� �������� 70%�� Ȯ���� ���� ��ģ��.-
					{
						myAI.battingcount = 2;//call��ħ
					}
				}
				else if (hope_value > 1)
				{
					if (probablity > 90)
					{
						myAI.battingcount = 3;//double
					}
					else//���� �������� 90%�� Ȯ���� ���� ��ģ��.-
					{
						myAI.battingcount = 2;//call��ħ
					}
				}
				else
				{
					if (probablity > 95)
					{
						myAI.battingcount = 3;//double
					}
					else//���� �������� 95%�� Ȯ���� ���� ��ģ��.-
					{
						myAI.battingcount = 2;//call��ħ
					}
				}
			}
			else
			{
				if (hope_value > 2)//������ ����� �̻��� ���� Ȯ�� ��ũ�� 
				{
					if (probablity > 80)
					{
						myAI.battingcount = 3;//double
					}
					else//���� �������� 90%�� Ȯ���� ���� ��ģ��.-
					{
						myAI.battingcount = 2;//call��ħ
					}
				}
				else if (hope_value > 1)
				{
					if (probablity > 90)
					{
						myAI.battingcount = 3;//double
					}
					else//���� �������� 95%�� Ȯ���� ���� ��ģ��.-
					{
						myAI.battingcount = 2;//call��ħ
					}
				}
				else
				{
					if (probablity > 97)
					{
						myAI.battingcount = 3;//double
					}
					else//���� �������� 97%�� Ȯ���� ���� ��ģ��.-
					{
						myAI.battingcount = 2;//call��ħ
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
				if (hope_value > 4)//Ǯ�Ͽ콺�� ���� ���ɼ��� ����
				{
					if (probablity > 70)
					{
						myAI.battingcount = 3;//double
					}
					else//���� �������� 70%�� Ȯ���� ���� ��ģ��.-
					{
						myAI.battingcount = 2;//call��ħ
					}
				}
				else if (hope_value > 2)
				{
					if (probablity > 80)
					{
						myAI.battingcount = 3;//double
					}
					else//���� �������� 80%�� Ȯ���� ���� ��ģ��.-
					{
						myAI.battingcount = 2;//call��ħ
					}
				}
				else
				{
					if (probablity > 90)
					{
						myAI.battingcount = 3;//double
					}
					else//���� �������� 90%�� Ȯ���� ���� ��ģ��.-
					{
						myAI.battingcount = 2;//call��ħ
					}
				}
			}
			else
			{
				if (hope_value > 4)//������ Ʈ���� �̻��� ���� Ȯ�� ��ũ�� 
				{
					if (probablity > 60)
					{
						myAI.battingcount = 3;//double
					}
					else//���� �������� 60%�� Ȯ���� ���� ��ģ��.-
					{
						myAI.battingcount = 2;//call��ħ
					}
				}
				else if (hope_value > 2)
				{
					if (probablity > 80)
					{
						myAI.battingcount = 3;//double
					}
					else//���� �������� 80%�� Ȯ���� ���� ��ģ��.-
					{
						myAI.battingcount = 2;//call��ħ
					}
				}
				else
				{
					if (probablity > 90)
					{
						myAI.battingcount = 3;//double
					}
					else//���� �������� 90%�� Ȯ���� ���� ��ģ��.-
					{
						myAI.battingcount = 2;//call��ħ
					}
				}
			}
		}
		if (batting_score == 4)
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 5)//call�ݾ��� 50%�϶� call or check�� �Ѵ�.
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 30)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
		}
		if (batting_score == 5)
		{
			int probablity = rand() % 100 + 1;//5���� �� 4ī��� �׳� �̱� �޷�����
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 10)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
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
			int straight_ = 0;//straight�� �Ǵ�
			int straight_number = 0;
			int subtract_arr[4];//1-0 2-1 3-2 4-3 5-4 6-5 �� �����ϴ� �迭 striaght�� �̰ɷ� �Ǻ��Ұ��Դϴ�..
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
			else//������ ���� �޾� ���� ������ �����ϰ� �״´�.
			{
				myAI.battingcount = 5;
			}
		}//���� �ƴѰ� �켱 hope_plush�� 1�� 4���� ī�尡 �𿴰� plushofcard�� ���ִ�.
	}// 5�� �޾��� ���� ������ ����
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
		int alpago_pairdistinction[5] = { 0,0,0,0,0 };//���� ī��� ������ ���̴� ī����� ��� ���� Ȯ��
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
		int other_pair_count[13];//��� Ȯ�� �ϱ� ���ؼ�
		int other_plush_count[4];//�÷��� Ȯ��
		for (int i = 0; i<13; i++)
		{
			other_pair_count[i] = 4;
		}
		for (int i = 0; i < 4; i++)
		{
			other_plush_count[i] = 13;
		}
		//���� ���⼭���� �Ǵ� �� ���� ���̴�.
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
		//������� ������ �ִ� ī����� ������ ���ڵ��� �����.
		//�迭���� ���� ���� �ִ� ����ŭ ���� ���� ���ϴ� ī����� �����̴�.
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
		if (alpago_pairdistinction[0] == 1)//pair �̻��� �޴´ٸ� ������ go �ҰŴ� 		
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
			int alpago_surrender[4] = { 0,0,0,0 };//Ȥ�ó� ���� ������ �״´� 
			int double_double = 0;//�ߺ��� ����� ���� ���ؼ�
			int hope_value = 0;//��� �Ǵ� ���� Ʈ���� �� �ϴ� �� �ʿ��� ī�尡 �Ⱥ��̴� ���� *10 �� �Ǵ� �� �ʿ��� ī�尡 �Ⱥ��̴� ���� *1�� �Ǿ��ִ�.
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
							//�ϴ� ���� ����.
						}
						else//����� �� ��� �ɶ����� 
						{
							hope_value = hope_value + other_pair_count[j - 2];
						}
					}
				}
			}//���� ���� �ɷ��� ���� �ƴ� ��� ���߿��� ���ɼ��� ���� �ٸ��� ���� �� ���´�.
			if (alpago_pairdistinction[1] != 0)
			{
				if (alpago_pairdistinction[1] == 1)
				{
					int double_double = 0;//�ߺ��� ����� ���� ���ؼ�
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
									//�ϴ� ���� ����.
								}
								else//����� �� ��� �ɶ����� 
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
					int double_double = 0;//�ߺ��� ����� ���� ���ؼ�
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
									//�ϴ� ���� ����.
								}
								else//����� �� ��� �ɶ����� 
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
					int double_double = 0;//�ߺ��� ����� ���� ���ؼ�
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
									//�ϴ� ���� ����.
								}
								else//����� �� ��� �ɶ����� 
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
					int double_double = 0;//�ߺ��� ����� ���� ���ؼ�
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
									//�ϴ� ���� ����.
								}
								else//����� �� ��� �ɶ����� 
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
							myAI.battingcount = 2;//call��ħ
						}
					}
					else if (hope_value > 15)
					{
						myAI.battingcount = 2;//call��ħ
					}
					else if (hope_value > 10)
					{
						if (bat.current_batting_money > (myAI.firstmoney / 10) * 4)
						{
							myAI.battingcount = 5;
						}
						else
						{
							myAI.battingcount = 2;//call��ħ
						}
					}
					else if (hope_value > 5)
					{
						myAI.battingcount = 2;//call��ħ
					}
					else
					{
						myAI.battingcount = 5;
					}
				}
				else
				{
					if (hope_value > 25)//������ ����� �̻��� ���� Ȯ�� ��ũ�� 
					{
						myAI.battingcount = 2;//call��ħ
					}
					else if (hope_value > 20)
					{
						if (bat.current_batting_money > (myAI.firstmoney / 10) * 4)
						{
							myAI.battingcount = 5;
						}
						else
						{
							myAI.battingcount = 2;//call��ħ
						}
					}
					else if (hope_value > 15)
					{
						myAI.battingcount = 2;//call��ħ
					}
					else if (hope_value > 10)
					{
						if (bat.current_batting_money > (myAI.firstmoney / 10) * 4)
						{
							myAI.battingcount = 5;
						}
						else
						{
							myAI.battingcount = 2;//call��ħ
						}
					}
					else if (hope_value > 5)
					{
						myAI.battingcount = 2;//call��ħ
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
						hope_fullhouse[0] = AI_batting_distinction[i].numberofcard;//ù��° �� ������ ��
					}
					else if (AI_batting_distinction[i].numberofcard == AI_batting_distinction[j].numberofcard)
					{
						hope_fullhouse[1] = AI_batting_distinction[i].numberofcard;
						break;
					}
				}
			}
			int hope_value = 0;
			hope_value = other_pair_count[hope_fullhouse[0] - 2] + other_pair_count[hope_fullhouse[1] - 2];//Ʈ���� ���� ���� ī�带 ���մϴ�.
																										   //���� ����� �̻��� ��츦 ������ 
			int axiety = 0;//������ �ƴ��� ����
			if (alpago_pairdistinction[1] > 2 || alpago_pairdistinction[2] > 2 || alpago_pairdistinction[3] > 2 || alpago_pairdistinction[4] > 2)//���� ����� �̻��϶�
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
						int double_double = 0;//�ߺ��� ����� ���� ���ؼ�
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
										//�ϴ� ���� ����.
									}
									else//����� �� ��� �ɶ����� 
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
						int double_double = 0;//�ߺ��� ����� ���� ���ؼ�
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
										//�ϴ� ���� ����.
									}
									else//����� �� ��� �ɶ����� 
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
						int double_double = 0;//�ߺ��� ����� ���� ���ؼ�
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
										//�ϴ� ���� ����.
									}
									else//����� �� ��� �ɶ����� 
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
						int double_double = 0;//�ߺ��� ����� ���� ���ؼ�
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
										//�ϴ� ���� ����.
									}
									else//����� �� ��� �ɶ����� 
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
					if (hope_value > 2)//Ǯ�Ͽ콺�� ���� ���ɼ��� ����
					{
						if (probablity > 90)
						{
							myAI.battingcount = 3;//double
						}
						else//90%�� Ȯ���� ���� ��ģ��.-
						{
							myAI.battingcount = 2;//call��ħ
						}
					}
					else if (hope_value > 1)
					{
						if (probablity > 95)
						{
							myAI.battingcount = 3;//double
						}
						else//���� �������� 95%�� Ȯ���� ���� ��ģ��.-
						{
							myAI.battingcount = 2;//call��ħ
						}
					}
					else
					{
						myAI.battingcount = 2;//call��ħ
					}
				}
				else
				{
					if (hope_value > 2)//������ ����� �̻��� ���� Ȯ�� ��ũ�� 
					{
						if (probablity > 80)
						{
							myAI.battingcount = 3;//double
						}
						else//���� �������� 90%�� Ȯ���� ���� ��ģ��.-
						{
							myAI.battingcount = 2;//call��ħ
						}
					}
					else if (hope_value > 1)
					{
						if (probablity > 90)
						{
							myAI.battingcount = 3;//double
						}
						else//���� �������� 95%�� Ȯ���� ���� ��ģ��.-
						{
							myAI.battingcount = 2;//call��ħ
						}
					}
					else
					{
						if (probablity > 97)
						{
							myAI.battingcount = 3;//double
						}
						else//���� �������� 97%�� Ȯ���� ���� ��ģ��.-
						{
							myAI.battingcount = 2;//call��ħ
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
				if (hope_value > 4)//Ǯ�Ͽ콺�� ���� ���ɼ��� ����
				{
					if (probablity > 90)
					{
						myAI.battingcount = 3;//double
					}
					else//���� �������� 70%�� Ȯ���� ���� ��ģ��.-
					{
						myAI.battingcount = 2;//call��ħ
					}
				}
				else
				{
					myAI.battingcount = 2;//call��ħ

				}
			}
			else
			{
				if (hope_value > 4)//������ Ʈ���� �̻��� ���� Ȯ�� ��ũ�� 
				{
					if (probablity > 90)
					{
						myAI.battingcount = 3;//double
					}
					else//���� �������� 90%�� Ȯ���� ���� ��ģ��.-
					{
						myAI.battingcount = 2;//call��ħ
					}
				}
				else if (hope_value > 2)
				{
					if (probablity > 95)
					{
						myAI.battingcount = 3;//double
					}
					else//���� �������� 95%�� Ȯ���� ���� ��ģ��.-
					{
						myAI.battingcount = 2;//call��ħ
					}
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
		}
		if (batting_score == 4)
		{
			int probablity = rand() % 100 + 1;
			if (bat.current_batting_money > (myAI.firstmoney / 10) * 5)//call�ݾ��� 50%�϶� call or check�� �Ѵ�.
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 50)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
		}
		if (batting_score == 5)
		{
			int probablity = rand() % 100 + 1;//5���� �� 4ī��� �׳� �̱� �޷�����
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 40)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
		}
		if (batting_score == 0)//���İ����� ��Ʈ����Ʈ, �÷����� ��Ȯ�� ������������ ���ϰ� ����ī�忡�� ���� ���ɼ��� ���ٰ� ����..
		{
			int straight_ = 0;//��Ʈ����Ʈ Ȯ�ο�
			int plush_ = 0;//�÷��� Ȯ�ο�
			int temp = 0;
			for (int j = 0; j < 5; j++)//;player�� ���������� ���� �е��� �ް� ����
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
			int subtract_arr[5];//1-0 2-1 3-2 4-3 5-4 6-5 �� �����ϴ� �迭 striaght�� �̰ɷ� �Ǻ��Ұ��Դϴ�..
			for (int i = 0; i < 5; i++)
			{
				subtract_arr[i] = AI_batting_distinction[i + 1].numberofcard - AI_batting_distinction[i].numberofcard;
			}
			temp = 0;//sort �� �����Ű�� ���Ͽ� ������������ ����
			for (int i = 0; i < 5; i++)//0�� �ǵڷ� ���� �ſ���
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
			int Plush = 1;//�÷����� �Ǻ��ϱ� ���� ������ ������ ����
			for (int i = 0; i < 6; i++)
			{
				Plush = AI_batting_distinction[i].numberofshape*Plush;
			}
			int temp1 = Plush;
			int plushofshape = 0;
			int plush_rest;//������ ���� ����
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
					myAI.battingcount = 4;//����
				}
				else if (probablity > 35)
				{
					myAI.battingcount = 3;//double ��ħ
				}
				else
				{
					myAI.battingcount = 2;//call��ħ
				}
			}
			else
			{
				myAI.battingcount = 5;//�ƹ� �е� ���� ������ ������ �״´� �� Ȯ���� 50%�� �ξ� �Ѿ�� �����̴�.
			}
		}
		//������ �ƹ��͵� ������ ���İ� ���� ��Ʈ����Ʈ�� �÷����� �븮�� �ʴ´�
	}//6��° ���κ�
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
		int alpago_pairdistinction[5] = { 0,0,0,0,0 };//���� ī��� ������ ���̴� ī����� ��� ���� Ȯ��
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
		int other_pair_count[13];//��� Ȯ�� �ϱ� ���ؼ�
		int other_plush_count[4];//�÷��� Ȯ��
		for (int i = 0; i<13; i++)
		{
			other_pair_count[i] = 4;
		}
		for (int i = 0; i < 4; i++)
		{
			other_plush_count[i] = 13;
		}
		//���� ���⼭���� �Ǵ� �� ���� ���̴�.
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
		//������� ������ �ִ� ī����� ������ ���ڵ��� �����.
		//�迭���� ���� ���� �ִ� ����ŭ ���� ���� ���ϴ� ī����� �����̴�.
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
		// ���̴°��� �տ� gameturn 3�϶��� ����.
		int enemy_hope_value = 0;
		if (alpago_pairdistinction[1] == 3 || alpago_pairdistinction[2] == 3 || alpago_pairdistinction[3] == 3 || alpago_pairdistinction[4] == 3)
		{//4���� �� �÷��̾� �߿� ���̴� ���� Ʈ������ ������ ������
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
				int temp_card = 0;//Ʈ������ ī���� ���ڸ� ������ ����
				for (int i = 0; i < 3; i++)
				{
					if (player_visiblecard[i].numberofcard == player_visiblecard[i + 1].numberofcard)
					{
						temp_card = player_visiblecard[i].numberofcard;
						break;
					}
				}
				int one_card;//Ʈ������ �ƴ� ī�� ����
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
					if ((A.playerfirstmoney - A.money) > (A.playerfirstmoney / 10) * 6)//�̹� ���ڿ� �� ���� ��ü ���� 60%�̻��̿����� 
					{
						enemy_hope_value = 9;//Ǯ�Ͽ콺 ����
					}
				}
				else if (hope_Value > 1)
				{
					if ((A.playerfirstmoney - A.money) > (A.playerfirstmoney / 10) * 6)//�̹� ���ڿ� �� ���� ��ü ���� 60%�̻��̿����� 
					{
						enemy_hope_value = 9;//Ǯ�Ͽ콺 ����
					}
				}
				else
				{
					enemy_hope_value = 4;
				}
			}
			else if (key_player == 2)
			{
				int temp_card = 0;//Ʈ������ ī���� ���ڸ� ������ ����
				for (int i = 0; i < 3; i++)
				{
					if (enemy1_visiblecard[i].numberofcard == enemy1_visiblecard[i + 1].numberofcard)
					{
						temp_card = enemy1_visiblecard[i].numberofcard;
						break;
					}
				}
				int one_card;//Ʈ������ �ƴ� ī�� ����
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
					if ((B.firstmoney - B.money) > (B.firstmoney / 10) * 6)//�̹� ���ڿ� �� ���� ��ü ���� 60%�̻��̿����� 
					{
						enemy_hope_value = 9;//Ǯ�Ͽ콺 ����
					}
				}
				else if (hope_Value > 1)
				{
					if ((B.firstmoney - B.money) > (B.firstmoney / 10) * 6)//�̹� ���ڿ� �� ���� ��ü ���� 60%�̻��̿����� 
					{
						enemy_hope_value = 9;//Ǯ�Ͽ콺 ����
					}
				}
				else
				{
					enemy_hope_value = 4;
				}
			}
			else if (key_player == 3)
			{
				int temp_card = 0;//Ʈ������ ī���� ���ڸ� ������ ����
				for (int i = 0; i < 3; i++)
				{
					if (enemy2_visiblecard[i].numberofcard == enemy2_visiblecard[i + 1].numberofcard)
					{
						temp_card = enemy2_visiblecard[i].numberofcard;
						break;
					}
				}
				int one_card;//Ʈ������ �ƴ� ī�� ����
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
					if ((C.firstmoney - C.money)>(C.firstmoney / 10) * 6)//�̹� ���ڿ� �� ���� ��ü ���� 60%�̻��̿����� 
						enemy_hope_value = 9;//Ǯ�Ͽ콺 ����
				}
				else if (hope_Value > 1)
				{
					if ((C.firstmoney - C.money)>(C.firstmoney / 10) * 6)//�̹� ���ڿ� �� ���� ��ü ���� 60%�̻��̿����� 
						enemy_hope_value = 9;//Ǯ�Ͽ콺 ����
				}
				else
				{
					enemy_hope_value = 4;
				}
			}
			else if (key_player == 4)
			{
				int temp_card = 0;//Ʈ������ ī���� ���ڸ� ������ ����
				for (int i = 0; i < 3; i++)
				{
					if (enemy3_visiblecard[i].numberofcard == enemy3_visiblecard[i + 1].numberofcard)
					{
						temp_card = enemy3_visiblecard[i].numberofcard;
						break;
					}
				}
				int one_card;//Ʈ������ �ƴ� ī�� ����
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
					if ((D.firstmoney - D.money) > (D.firstmoney / 10) * 6)//�̹� ���ڿ� �� ���� ��ü ���� 60%�̻��̿����� 
					{
						enemy_hope_value = 9;//Ǯ�Ͽ콺 ����
					}
				}
				else if (hope_Value > 1)
				{
					if ((D.firstmoney - D.money) > (D.firstmoney / 10) * 6)//�̹� ���ڿ� �� ���� ��ü ���� 60%�̻��̿����� 
					{
						enemy_hope_value = 9;//Ǯ�Ͽ콺 ����
					}
				}
				else
				{
					enemy_hope_value = 4;
				}
			}
		}
		else if (alpago_pairdistinction[1] == 2 || alpago_pairdistinction[2] == 2 || alpago_pairdistinction[3] == 2 || alpago_pairdistinction[4] == 2)
		{//�ִ밡 ������̴�
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
					if ((A.playerfirstmoney - A.money) > (A.playerfirstmoney / 10) * 7)//�̹� ���ڿ� �� ���� ��ü ���� 60%�̻��̿����� 
					{
						enemy_hope_value = 9;//Ǯ�Ͽ콺 ����
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
					if ((B.firstmoney - B.money) > (B.firstmoney / 10) * 7)//�̹� ���ڿ� �� ���� ��ü ���� 60%�̻��̿����� 
					{
						enemy_hope_value = 9;//Ǯ�Ͽ콺 ����
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
					if ((C.firstmoney - C.money) > (C.firstmoney / 10) * 7)//�̹� ���ڿ� �� ���� ��ü ���� 60%�̻��̿����� 
					{
						enemy_hope_value = 9;//Ǯ�Ͽ콺 ����
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
					if ((D.firstmoney - D.money) > (D.firstmoney / 10) * 7)//�̹� ���ڿ� �� ���� ��ü ���� 60%�̻��̿����� 
					{
						enemy_hope_value = 9;//Ǯ�Ͽ콺 ����
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
			//������ �� �����ϱ� 
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
				int double_double = 0;//�ߺ��� ����� ���� ���ؼ�
				int hope_value = 0;//��� �Ǵ� ���� Ʈ���� �� �ϴ� �� �ʿ��� ī�尡 �Ⱥ��̴� ���� *10 �� �Ǵ� �� �ʿ��� ī�尡 �Ⱥ��̴� ���� *1�� �Ǿ��ִ�.
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
								//�ϴ� ���� ����.
							}
							else//����� �� ��� �ɶ����� 
							{
								hope_value = hope_value + other_pair_count[j - 2];
							}
						}
					}
				}
				if (hope_value > 25)//Ǯ�Ͽ콺�� ���ɼ���
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
				else if (hope_value > 20)//Ʈ����
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
				int double_double = 0;//�ߺ��� ����� ���� ���ؼ�
				int hope_value = 0;//��� �Ǵ� ���� Ʈ���� �� �ϴ� �� �ʿ��� ī�尡 �Ⱥ��̴� ���� *10 �� �Ǵ� �� �ʿ��� ī�尡 �Ⱥ��̴� ���� *1�� �Ǿ��ִ�.
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
								//�ϴ� ���� ����.
							}
							else//����� �� ��� �ɶ����� 
							{
								hope_value = hope_value + other_pair_count[j - 2];
							}
						}
					}
				}
				if (hope_value > 25)//Ǯ�Ͽ콺�� ���ɼ���
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
				else if (hope_value > 20)//Ʈ����
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
				int double_double = 0;//�ߺ��� ����� ���� ���ؼ�
				int hope_value = 0;//��� �Ǵ� ���� Ʈ���� �� �ϴ� �� �ʿ��� ī�尡 �Ⱥ��̴� ���� *10 �� �Ǵ� �� �ʿ��� ī�尡 �Ⱥ��̴� ���� *1�� �Ǿ��ִ�.
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
								//�ϴ� ���� ����.
							}
							else//����� �� ��� �ɶ����� 
							{
								hope_value = hope_value + other_pair_count[j - 2];
							}
						}
					}
				}
				if (hope_value > 25)//Ǯ�Ͽ콺�� ���ɼ���
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
				else if (hope_value > 20)//Ʈ����
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
				int double_double = 0;//�ߺ��� ����� ���� ���ؼ�
				int hope_value = 0;//��� �Ǵ� ���� Ʈ���� �� �ϴ� �� �ʿ��� ī�尡 �Ⱥ��̴� ���� *10 �� �Ǵ� �� �ʿ��� ī�尡 �Ⱥ��̴� ���� *1�� �Ǿ��ִ�.
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
								//�ϴ� ���� ����.
							}
							else//����� �� ��� �ɶ����� 
							{
								hope_value = hope_value + other_pair_count[j - 2];
							}
						}
					}
				}
				if (hope_value > 25)//Ǯ�Ͽ콺�� ���ɼ���
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
				else if (hope_value > 20)//Ʈ����
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

			int temp;//�ӽ� ���� �迭���� ���� ������ ���Ͽ� ���� ���� ���ڸ� ����
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

			//���� ������ ���� ���� �ǰŷ� ���� �ؼ� value����
			//�̷��� �� �� �� ���� ����¸� �ϸ� ��
		}
		else
		{
			int other_batting_money[4];//���ݱ��� ���� ��ƾ�� �ݾ� ����
			other_batting_money[0] = A.playerfirstmoney - A.money;
			other_batting_money[1] = B.firstmoney - B.money;
			other_batting_money[2] = C.firstmoney - C.money;
			other_batting_money[3] = D.firstmoney - D.money;
			int over_money[4] = { 0,0,0,0 };//������� �ݾ��̻��̸� ����ϱ� ���ؼ� ����
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