// Lab03_03.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	int n = 0;
	int sum = 0;
	
	std::cout << "number : "; std::cin >> n;
	for (int i = 0; i <= n; i++) {
		if (i % 2 != 0 && i % 3 != 0) {
			sum = sum + i;
		}
	}
	std::cout << "sum : "<< sum << "\n" ;
    return 0;
}

