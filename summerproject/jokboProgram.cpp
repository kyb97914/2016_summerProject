#include "jokboProgram.h"



jokboProgram::jokboProgram()
{
}


jokboProgram::~jokboProgram()
{
}

void jokboProgram::plush_distinction(player &a)
{
	int Plush = 1;//�÷����� �Ǻ��ϱ� ���� ������ ������ ����
	for (int i = 0; i < 7; i++)
	{
		Plush = a.jokbocard[i].numberofshape*Plush;
	}
	int temp1 = Plush;
	int plushofshape = 0;
	int plush_rest;//������ ���� ����
	for (int i = 2; i < 5; i++)
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
	for (int i = 0; i < 7; i++)
	{
		if (a.jokbocard[i].numberofshape == 1)
		{
			plush1++;
		}
	}
	Plush = temp1;
	if (plush_rest == 0 || plush1 >= 5)
	{
		plush = 1;
		a.value_jokbo = 15 * 8 + plushofshape;
	}
	else
	{
		plush = 0;
	}
}
void jokboProgram::straight_distinction(player &a)
{
	int jokbotemp = 0;
	for (int j = 0; j < 6; j++)//;player�� ���������� ���� �е��� �ް� ����
	{
		for (int i = 0; i < 6 - j; i++)
		{
			if (a.jokbocard[i].numberofcard > a.jokbocard[i + 1].numberofcard)
			{
				jokbotemp = a.jokbocard[i].numberofcard;
				a.jokbocard[i].numberofcard = a.jokbocard[i + 1].numberofcard;
				a.jokbocard[i + 1].numberofcard = jokbotemp;
			}
		}
	}
	for (int i = 0; i < 7; i++)//��� �ϱ� ���Ͽ� jokbo�ȿ� �ִ� �迭�� �޽��ϴ�.
	{
		jokbo_arr[i] = a.jokbocard[i].numberofcard;
	}
	cout << endl;
	int subtract_arr[6];//1-0 2-1 3-2 4-3 5-4 6-5 �� �����ϴ� �迭 striaght�� �̰ɷ� �Ǻ��Ұ��Դϴ�..
	for (int i = 0; i < 6; i++)
	{
		subtract_arr[i] = jokbo_arr[i + 1] - jokbo_arr[i];
	}
	a.highcard = jokbo_arr[6];
	int temp;//sort �� �����Ű�� ���Ͽ� ������������ ����
	for (int i = 0; i < 6; i++)//0�� �ǵڷ� ���� �ſ���
	{
		if (subtract_arr[i] == 0)
		{
			for (int j = i; j < 5; j++)
			{
				temp = subtract_arr[j];
				subtract_arr[j] = subtract_arr[j + 1];
				subtract_arr[j + 1] = temp;
			}

		}
	}
	for (int i = 0; i < 6; i++)
	{
		if (subtract_arr[i] == 0)
		{
			subtract_arr[i] += 15;
		}
	}
	int distinction_straight = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			distinction_straight += subtract_arr[i + j];
		}
		if (distinction_straight <= 4)
		{
			int straightofnumber = 0;
			for (int i = 0; i<3; i++)
			{
				if (jokbo_arr[i] + 1 == jokbo_arr[i + 1] && jokbo_arr[i + 1] + 1 == jokbo_arr[i + 2])
				{
					straightofnumber = i;
					break;
				}
			}
			straight = 1;
			a.value_jokbo = 5 * 15 + straightofnumber;
		}
	}
	if (straight == 1)
	{
		int correct_arr[5] = { 10,11,12,13,14 };
		int backstraight_arr[5] = { 0,0,0,0,0 };
		for (int i = 0; i<7; i++)
		{
			for (int j = 0; j<5; j++)
			{
				if (jokbo_arr[i] == correct_arr[j])
				{
					backstraight_arr[j] = 1;
				}
			}
		}
		if (backstraight_arr[0] + backstraight_arr[1] + backstraight_arr[2] + backstraight_arr[3] + backstraight_arr[4] == 5)
		{
			mountain = 1;
		}
	}
	else
	{
		int correct_arr[5] = { 2,3,4,5,14 };
		int backstraight_arr[5] = { 0,0,0,0,0 };
		for (int i = 0; i<7; i++)
		{
			for (int j = 0; j<5; j++)
			{
				if (jokbo_arr[i] == correct_arr[j])
				{
					backstraight_arr[j] = 1;
				}
			}
		}
		if (backstraight_arr[0] + backstraight_arr[1] + backstraight_arr[2] + backstraight_arr[3] + backstraight_arr[4] == 5)
		{
			backstraight = 1;
		}
	}

}
void jokboProgram::pair_distinction(player &a)
{
	pair_count = 0;
	int pairofnumber = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 7; j++)
		{
			if (a.jokbocard[i].numberofcard == a.jokbocard[j].numberofcard)
			{
				pair_count++;
				pairofnumber = pairofnumber + a.jokbocard[i].numberofcard;
			}
		}
	}
	if (pair_count == 1)
	{
		Pair = 1;
		a.value_jokbo = (2 * 15) + pairofnumber;
	}
	else if (pair_count == 2)
	{
		twoPair = 1;
		a.value_jokbo = (3 * 15) + (float)(pairofnumber / 2);
	}
	else if (pair_count == 3)
	{
		int threepaircount[7] = { 0,0,0,0,0,0,0 };
		for (int i = 0; i < 6; i++)
		{
			for (int j = i + 1; j < 7; j++)
			{
				if (a.jokbocard[i].numberofcard == a.jokbocard[j].numberofcard)
				{
					threepaircount[i]++;
				}
			}
		}
		int three_pair = 0;
		for (int i = 0; i < 7; i++)
		{
			if (threepaircount[i] == 2)
			{
				three_pair = 1;
			}
		}
		if (three_pair == 0)
		{
			twoPair = 1;
			a.value_jokbo = (3 * 15) + (float)(pairofnumber / 3);
		}
		else
		{
			tripple = 1;
			a.value_jokbo = (4 * 15) + (float)(pairofnumber / 3);
		}
	}
	else if (pair_count == 4)
	{
		fullhouse = 1;
		a.value_jokbo = (9 * 15) + (float)(pairofnumber / 4);
	}
	else if (pair_count == 6)
	{
		int twotripplecount[7] = { 0,0,0,0,0,0,0 };
		for (int i = 0; i < 6; i++)
		{
			for (int j = i + 1; j < 7; j++)
			{
				if (a.jokbocard[i].numberofcard == a.jokbocard[j].numberofcard)
				{
					twotripplecount[i]++;
				}
			}
		}
		int two_tripple = 0;
		for (int i = 0; i < 7; i++)
		{
			if (twotripplecount[i] == 3)
			{
				two_tripple = 1;
			}
		}
		if (two_tripple == 0)
		{
			tripple = 1;
			a.value_jokbo = (4 * 15) + (float)(pairofnumber / 6);
		}
		else
		{
			fourcard = 1;
			a.value_jokbo = (10 * 15) + (float)(pairofnumber / 6);
		}
	}
}
void jokboProgram::distinction_jokbo(player &a)
{
	a.jokbocarding();
	plush_distinction(a);
	pair_distinction(a);
	straight_distinction(a);
	if (plush == 1 && mountain == 1)
	{
		a.value_jokbo = 13 * 15;//�ο� ��Ʈ����Ʈ �÷��� �ְ�
	}
	else if (plush == 1 && backstraight == 1)
	{
		a.value_jokbo = 12 * 15;//�� ��Ʈ����Ʈ �÷���
	}
	else if (plush == 1 && straight == 1)
	{
		a.value_jokbo = 11 * 15;//��Ʈ����Ʈ �÷���
	}
	else if (fourcard == 1)
	{
		;//��ī��
	}
	else if (fullhouse == 1)
	{
		;//Ǯ�Ͽ콺
	}
	else if (plush == 1)
	{
		;//�÷���
	}
	else if (mountain == 1)
	{
		a.value_jokbo = 7 * 15;//����ƾ �ΰ��� ����ƾ�� ����������ұ��
	}
	else if (backstraight == 1)
	{
		a.value_jokbo = 6 * 15;//�齺Ʈ����Ʈ�ΰ��� �齺Ʈ����Ʈ�� ����������ұ��
	}
	else if (straight == 1)
	{
		;//��Ʈ����Ʈ
	}
	else if (tripple == 1)
	{
		;//Ʈ����
	}
	else if (twoPair == 1)
	{
		;//�����
	}
	else if (Pair == 1)
	{
		;//���
	}
	else
	{
		;//����� ����ī��
	}
}
void jokboProgram::jokbo_reset()
{
	plush = 0;
	mountain = 0;
	straight = 0;
	Pair = 0;
	tripple = 0;
	fourcard = 0;
	twoPair = 0;
	backstraight = 0;
	fullhouse = 0;
}
void jokboProgram::AIplush_distinction(AIplayer &a)
{
	int Plush = 1;//�÷����� �Ǻ��ϱ� ���� ������ ������ ����
	for (int i = 0; i < 7; i++)
	{
		Plush = a.jokbocard[i].numberofshape*Plush;
	}
	int temp1 = Plush;
	int plushofshape = 0;
	int plush_rest;//������ ���� ����
	for (int i = 2; i < 5; i++)
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
	for (int i = 0; i < 7; i++)
	{
		if (a.jokbocard[i].numberofshape == 1)
		{
			plush1++;
		}
	}
	Plush = temp1;
	if (plush_rest == 0 || plush1 >= 5)
	{
		plush = 1;
		a.value_jokbo = 15 * 8 + plushofshape;
	}
	else
	{
		plush = 0;
	}
}
void jokboProgram::AIstraight_distinction(AIplayer &a)
{
	int jokbotemp = 0;
	for (int j = 0; j < 6; j++)//;player�� ���������� ���� �е��� �ް� ����
	{
		for (int i = 0; i < 6 - j; i++)
		{
			if (a.jokbocard[i].numberofcard > a.jokbocard[i + 1].numberofcard)
			{
				jokbotemp = a.jokbocard[i].numberofcard;
				a.jokbocard[i].numberofcard = a.jokbocard[i + 1].numberofcard;
				a.jokbocard[i + 1].numberofcard = jokbotemp;
			}
		}
	}
	for (int i = 0; i < 7; i++)//��� �ϱ� ���Ͽ� jokbo�ȿ� �ִ� �迭�� �޽��ϴ�.
	{
		jokbo_arr[i] = a.jokbocard[i].numberofcard;
	}
	cout << endl;
	int subtract_arr[6];//1-0 2-1 3-2 4-3 5-4 6-5 �� �����ϴ� �迭 striaght�� �̰ɷ� �Ǻ��Ұ��Դϴ�..
	for (int i = 0; i < 6; i++)
	{
		subtract_arr[i] = jokbo_arr[i + 1] - jokbo_arr[i];
	}
	a.highcard = jokbo_arr[6];
	int temp;//sort �� �����Ű�� ���Ͽ� ������������ ����
	for (int i = 0; i < 6; i++)//0�� �ǵڷ� ���� �ſ���
	{
		if (subtract_arr[i] == 0)
		{
			for (int j = i; j < 5; j++)
			{
				temp = subtract_arr[j];
				subtract_arr[j] = subtract_arr[j + 1];
				subtract_arr[j + 1] = temp;
			}

		}
	}
	for (int i = 0; i < 6; i++)
	{
		if (subtract_arr[i] == 0)
		{
			subtract_arr[i] += 15;
		}
	}
	int distinction_straight = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			distinction_straight += subtract_arr[i + j];
		}
		if (distinction_straight <= 4)
		{
			int straightofnumber = 0;
			for (int i = 0; i<3; i++)
			{
				if (jokbo_arr[i] + 1 == jokbo_arr[i + 1] && jokbo_arr[i + 1] + 1 == jokbo_arr[i + 2])
				{
					straightofnumber = i;
					break;
				}
			}
			straight = 1;
			a.value_jokbo = 5 * 15 + straightofnumber;
		}
	}
	if (straight == 1)
	{
		int correct_arr[5] = { 10,11,12,13,14 };
		int backstraight_arr[5] = { 0,0,0,0,0 };
		for (int i = 0; i<7; i++)
		{
			for (int j = 0; j<5; j++)
			{
				if (jokbo_arr[i] == correct_arr[j])
				{
					backstraight_arr[j] = 1;
				}
			}
		}
		if (backstraight_arr[0] + backstraight_arr[1] + backstraight_arr[2] + backstraight_arr[3] + backstraight_arr[4] == 5)
		{
			mountain = 1;
		}
	}
	else
	{
		int correct_arr[5] = { 2,3,4,5,14 };
		int backstraight_arr[5] = { 0,0,0,0,0 };
		for (int i = 0; i<7; i++)
		{
			for (int j = 0; j<5; j++)
			{
				if (jokbo_arr[i] == correct_arr[j])
				{
					backstraight_arr[j] = 1;
				}
			}
		}
		if (backstraight_arr[0] + backstraight_arr[1] + backstraight_arr[2] + backstraight_arr[3] + backstraight_arr[4] == 5)
		{
			backstraight = 1;
		}
	}

}
void jokboProgram::AIpair_distinction(AIplayer &a)
{
	pair_count = 0;
	int pairofnumber = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 7; j++)
		{
			if (a.jokbocard[i].numberofcard == a.jokbocard[j].numberofcard)
			{
				pair_count++;
				pairofnumber = pairofnumber + a.jokbocard[i].numberofcard;
			}
		}
	}
	if (pair_count == 1)
	{
		Pair = 1;
		a.value_jokbo = (2 * 15) + pairofnumber;
	}
	else if (pair_count == 2)
	{
		twoPair = 1;
		a.value_jokbo = (3 * 15) + (float)(pairofnumber / 2);
	}
	else if (pair_count == 3)/*���� ���� ���� ���� ���� ���� 3��� Ʈ���� ������ �Ǵ� �� �ֱ׷��� ???*/
	{
		int threepaircount[7] = { 0,0,0,0,0,0,0 };
		for (int i = 0; i < 6; i++)
		{
			for (int j = i + 1; j < 7; j++)
			{
				if (a.jokbocard[i].numberofcard == a.jokbocard[j].numberofcard)
				{
					threepaircount[i]++;
				}
			}
		}
		int three_pair = 0;
		for (int i = 0; i < 7; i++)
		{
			if (threepaircount[i] == 2)
			{
				three_pair = 1;
			}
		}
		if (three_pair == 0)
		{
			twoPair = 1;
			a.value_jokbo = (3 * 15) + (float)(pairofnumber / 3);
		}
		else
		{
			tripple = 1;
			a.value_jokbo = (4 * 15) + (float)(pairofnumber / 3);
		}
	}
	else if (pair_count == 4)
	{
		fullhouse = 1;
		a.value_jokbo = (9 * 15) + (float)(pairofnumber / 4);
	}
	else if (pair_count == 6)
	{

		/**/
		int twotripplecount[7] = { 0,0,0,0,0,0,0 };
		for (int i = 0; i < 6; i++)
		{
			for (int j = i + 1; j < 7; j++)
			{
				if (a.jokbocard[i].numberofcard == a.jokbocard[j].numberofcard)
				{
					twotripplecount[i]++;
				}
			}
		}
		int two_tripple = 0;
		for (int i = 0; i < 7; i++)
		{
			if (twotripplecount[i] == 3)
			{
				two_tripple = 1;
			}
		}
		if (two_tripple == 0)
		{
			tripple = 1;
			a.value_jokbo = (4 * 15) + (float)(pairofnumber / 6);
		}
		else
		{
			fourcard = 1;
			a.value_jokbo = (10 * 15) + (float)(pairofnumber / 6);
		}
	}
}
void jokboProgram::AIdistinction_jokbo(AIplayer &a)
{
	a.jokbocarding();
	AIplush_distinction(a);
	AIpair_distinction(a);
	AIstraight_distinction(a);
	if (plush == 1 && mountain == 1)
	{
		a.value_jokbo = 13 * 15;//�ο� ��Ʈ����Ʈ �÷��� �ְ�
	}
	else if (plush == 1 && backstraight == 1)
	{
		a.value_jokbo = 12 * 15;//�� ��Ʈ����Ʈ �÷���
	}
	else if (plush == 1 && straight == 1)
	{
		a.value_jokbo = 11 * 15;//��Ʈ����Ʈ �÷���
	}
	else if (fourcard == 1)
	{
		;//��ī��
	}
	else if (fullhouse == 1)
	{
		;//Ǯ�Ͽ콺
	}
	else if (plush == 1)
	{
		;//�÷���
	}
	else if (mountain == 1)
	{
		a.value_jokbo = 7 * 15;//����ƾ �ΰ��� ����ƾ�� ����������ұ��
	}
	else if (backstraight == 1)
	{
		a.value_jokbo = 6 * 15;//�齺Ʈ����Ʈ�ΰ��� �齺Ʈ����Ʈ�� ����������ұ��
	}
	else if (straight == 1)
	{
		;//��Ʈ����Ʈ
	}
	else if (tripple == 1)
	{
		;//Ʈ����
	}
	else if (twoPair == 1)
	{
		;//�����
	}
	else if (Pair == 1)
	{
		;//���
	}
	else
	{
		;//����� ����ī��
	}
}
