// Lab1_5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>


int main()

{
	double F = 0;
	std::cout << "Please enter Fahreheit value: ";
	std::cin >> F;
	F = 5.0 / 9.0 * (F - 32);
	std::cout << "Celsius value is " << F << "\n";


    return 0;
}

