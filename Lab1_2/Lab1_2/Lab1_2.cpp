// Lab1_2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int a = 0, b = 0;

	cout << "Please enter two integer values: ";
	cin >> a >> b;
	cout << a << " + " << b << " = " << a + b << endl
		<< a << " - " << b << " = " << a - b << endl
		<< a << " * " << b << " = " << a * b << endl
		<< a << " / " << b << " = " << a / b << endl
		<< a << " % " << b << " = " << a % b << endl;

    return 0;
}

