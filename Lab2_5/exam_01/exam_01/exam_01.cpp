// exam_01.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

bool isPrime(int n) {
	int i = 2;
	while (i < n) {
		if (n % i == 0) {
			return false;
		}
		i++;
	}
	return true;

}
void Input(int& num1, int& num2) {
	cout << "두 수, x값과 y값을 입력하세요 : ";
	cin >> num1 >> num2;
}
int Calculate(int num1, int num2) {
	int sum = 0;
	int i = num1;
	while (i <= num2) {
		if (isPrime(i)) {
			sum = sum + i;
		}
		i++;
	}
	return sum;
}
void Output(int sum, int lcm) {
	cout << "x와 y사이의 소수들의 합 : " << sum << '\n';
	cout << "x와 y의 최소공배수 : " << lcm << '\n';

}


int gcd(int num1, int num2) {
	int q = 0, r = 0;
	q = num1 / num2;
	r = num1 % num2;
	if (r == 0) {
		return num2;
	}
	else {
		return gcd(num2, r);
	}
}
int lcm(int num1, int num2) {
	int num = num1 * num2;
	int gcd_num = gcd(num1, num2);
	int lcm_num = num / gcd_num;
	return lcm_num;
}

int main()
{
	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	int lcm_number = 0;
	Input(num1, num2);
	sum = Calculate(num1, num2);
	lcm_number = lcm(num1, num2);
	Output(sum, lcm_number);

    return 0;
}

