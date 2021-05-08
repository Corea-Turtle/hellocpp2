//1.사용자로부터 총 10개의 정수를 입력받아서 그 합을 출력하는 프로그램을 작성해보자
#include"stdafx.h"
#include<iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	int a, b, c, d, e, f, g, h, i, j;

	std::cout << "10개의 정수를 입력하시오: " << std::endl;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;
	std::cin >> e;
	std::cin >> f;
	std::cin >> g;
	std::cin >> h;
	std::cin >> i;
	std::cin >> j;

	std::cout<< "10개 정수의 합은 "
	<<a + b + c + d + e + f + g + h + i + j <<"입니다."
	<< std::endl;
  
//2.사용자로부터 이름과 전화번호를 입력받아서 배열에 저장하고 그대로 출력하는 프로그램을 작성해보자

#include"stdafx.h"
#include<iostream>
#include<string>

int _tmain(int argc, _TCHAR* argv[])
{
	char tele[2][100];
	std::cout << "이름을 입력하세요." << std::endl;
	std::cin >> tele[0];
	std::cout << "전화번호를 입력하세요." << std::endl;
	std::cin >> tele[1];
	std::cout << '\n';
	std::cout<< tele[0]<<' '<< tele[1]<< std::endl;

	return 0;
}

//배열에 대한 공부가 다시 필요하다. 다 까먹은듯 

//3.숫자를 하나 입력받아서 그 수에 해당하는 구구단을 출력하시오.

#include"stdafx.h"
#include<iostream>

void gugudan(int num)
{
	for (int i = 1; i < 10; ++i)
		std::cout << num << 'x' << i << '=' << num * i << std::endl;

	return;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int numb;

	std::cout << "구구단의 단수를 입력하세요 :" << ' ';
	std::cin >> numb;
	gugudan(numb);

	return 0;	
}

//처음에 65번째 줄에 함수를 std::cout<<gugudan(numb)<<std::endl;로해서 이상하게 되었고
//51번째 줄에 함수 반환형도 int로 했기 때문에 return값에 꼭 수를 넣으라는 오류 메세지가 떠서 리턴값을 넣으면
//구구단 출력 후 마지막에 retrun 값이 출력되었다 5x9 다음 5혹은 return에 0을 썼으면 0이런식으로
//함수자체를 리턴하고 싶다면 반환형에 void를 써주자.


/*4.판매원들의 급여 계산 프로그램을 작성해보자.
이 회사는 모든 판매원에게 매달 50만원의 기본 급여와 물품 판매 가격의 12%에 달하는 돈을 지급한다.
예를 들어 민수라는 친구의 이번 달 물품 판매 금액이 100만원이라면, 50+100*0.12=62
따라서 62만원을 급여로 지급받는다. 다음 실행의 예를 참고하기 바란다.

실행의 예
--------------------------------------
판매 금액을 만원 단위로 입력(-1 to end): 100
이번 달 급여 : 62만원
판매 금액을 만원 단위로 입력(-1 to end): 200
이번 달 급여: 74만원
판매 금액을 만원 단위로 입력(-1 to end): -1
*/

#include"stdafx.h"
#include<iostream>

void Salary(int Mon) //Mon은 Month의 줄임이다.
{
	if (Mon!=-1 && Mon>=0)
		std::cout << "이번 달 급여 : " << 50 + Mon * 0.12 << "만원" << std::endl;
	return;
}


int main(int argc, _TCHAR* argv[])
{
	int Sales=0;

	while (Sales!=-1) {
		std::cout << "판매 금액을 만윈 단위로 입력(-1 to end):" << ' ';
		std::cin >> Sales;
		Salary(Sales);
	}
	return 0;
}

//1-2 다음 함수에서 필요로 하는 swap함수를 구하라
#include"stdafx.h"
#include<iostream>

void swap(int *a,  int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	
	return;
}

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;

	return;
}

void swap(double *a, double *b)
{
	double temp = *a;
	*a = *b;
	*b = temp;

	return;
}

int _tmain(int argc, _TCHAR*argv[])
{
	int num1 = 20, num2 = 30;
	swap(&num1, &num2);
	std::cout << num1 << ' ' << num2 << std::endl;

	char ch1 = 'a', ch2 = 'z';
	swap(&ch1, &ch2);
	std::cout << ch1 << ' ' << ch2 << std::endl;

	double dbl1 = 1.111, dbl2 = 2.222;
	swap(&dbl1, &dbl2);
	std::cout << dbl1 << ' ' << dbl2 << std::endl;

	return 0;
}

결과 : 스왑되면 됨

//
