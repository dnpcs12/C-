// Lab03_05.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

int gcd(int a, int b) {
	int q = 0, r = 0;
	q = a / b;
	r = a % b;
	if (r == 0) {
		return b;
	}
	else {
		return gcd(b, r);
	}
}

int main()
{
	int x = 0, y = 0;
	std::cin >> x; std::cin >> y;
	std::cout << gcd(x, y) << "\n";

    return 0;
}

