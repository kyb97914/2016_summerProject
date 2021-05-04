#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
struct caRD//카드의 모양 숫자등을 저장할 구조체
{
	string cardshape;//카드 모양 저장
	string cardNumber;//카드 숫자 저장
	int cardcardnumber;//카드의 고유 숫자를 저장한다.
	int numberofcard;//트럼프 카드를 보면 나오는 2 3 4 같은 숫자들을 저장할 변수 이다.
	int numberofshape;//만든 모양고 숫자의 숫자형 모음들이다.
	caRD& operator=(const caRD ref)//연산자 오버로딩 caRD의 구조체를 집어 넣을 때 한번에 모든 정보를 넣어버리는연산자이다.
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
	void cardmade();//카드에 고유번호를 지정해 주는 함수 이다.
	void shufflecard();//카드를 섞는 함수 이다.
	int shufflecardnumber[52];//카드를 섞은 것을 저장한다.
	void cardpattern(int a, int i);
	caRD cardcard[52];//카드의 모든 정보를 저장할 구조체 배열이다.
};

