// Lab1_3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	int i1 = 2, i2 = 5, i3 = -3;
	double d1 = 2.0, d2 = 5.0, d3 = -0.5;

	std::cout << i1 + i2 * i3 << "\n";
	std::cout << i1 * (i2 + i3) << "\n";
	std::cout << i1 / (i2 + i3) << "\n";
	std::cout << i1 / i2 + i3 << "\n";
	std::cout << 3 + 4 + 5 / 3 << "\n";
	std::cout << (3 + 4 + 5) / 3 << "\n";
	std::cout << d1 + (d2 * d3) << "\n";
	std::cout << d1 + d2 * d3 << "\n";
	std::cout << d1 / d2 - d3 << "\n";
	std::cout << d1 / (d2 - d3) << "\n";
	std::cout << d1 + d2 + d3 / 3 << "\n";
	std::cout << (d1 + d2 + d3) / 3 << "\n";
	
	return 0;
    
}

