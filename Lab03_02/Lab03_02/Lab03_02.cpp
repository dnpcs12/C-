// Lab03_02.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>


int main()
{
	int n = 0;
	int sum = 0;
	std::cout << "number : "; std::cin >> n;

	for (int i = 0; i <= n; i++) {
		sum = sum + i;
	}
	std::cout << sum << "\n";
    return 0;
}

