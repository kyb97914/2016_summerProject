#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
struct caRD//ī���� ��� ���ڵ��� ������ ����ü
{
	string cardshape;//ī�� ��� ����
	string cardNumber;//ī�� ���� ����
	int cardcardnumber;//ī���� ���� ���ڸ� �����Ѵ�.
	int numberofcard;//Ʈ���� ī�带 ���� ������ 2 3 4 ���� ���ڵ��� ������ ���� �̴�.
	int numberofshape;//���� ���� ������ ������ �������̴�.
	caRD& operator=(const caRD ref)//������ �����ε� caRD�� ����ü�� ���� ���� �� �ѹ��� ��� ������ �־�����¿������̴�.
	{
		cardshape = ref.cardshape;
		cardNumber = ref.cardNumber;
		cardcardnumber = ref.cardcardnumber;
		numberofcard = ref.numberofcard;
		numberofshape = ref.numberofshape;
		return *this;
	}
};
class card
{
private:
	int cardnumber[52];
public:
	card();
	~card();
	void cardmade();//ī�忡 ������ȣ�� ������ �ִ� �Լ� �̴�.
	void shufflecard();//ī�带 ���� �Լ� �̴�.
	int shufflecardnumber[52];//ī�带 ���� ���� �����Ѵ�.
	void cardpattern(int a, int i);
	caRD cardcard[52];//ī���� ��� ������ ������ ����ü �迭�̴�.
};

