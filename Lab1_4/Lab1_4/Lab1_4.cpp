// Lab1_4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	int a, b, temp = 0;
	std::cout << "Please enter two integer values: \n";
	std::cout << "A : ";
	std::cin >> a;
	std::cout << "B : ";
    std:: cin >> b;
	temp = a;
	a = b;
	b = temp;
	std::cout << "Value of A is : "<< a << "\nValue of B is : " << b << "\n";

    return 0;
}

