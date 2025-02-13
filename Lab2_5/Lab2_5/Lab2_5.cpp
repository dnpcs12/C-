// Lab2_5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

void get_data(int &x, int &y){
	std::cout << "x 입력 : "; std::cin >> x;
	std::cout << "y 입력 : "; std::cin >> y;
	//return x, y;
}

void swap_call_by_value(int x, int y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}
void swap_call_by_reference(int &x, int &y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}

int main()
{
	int x = 0;
	int y = 0;

	get_data(x, y);
	
	std::cout << "\nswap_call_by_value 함수 사용 전\n" << "x = " << x << ", y = " << y << "\n";
	swap_call_by_value(x, y);
	std::cout << "swap_call_by_value 함수 사용 후\n" << "x = " << x << ", y = " << y << "\n";

	std::cout << "\nswap_call_by_reference 함수 사용 전\n" << "x = " << x << ", y = " << y << "\n";
	swap_call_by_reference(x, y);
	std::cout << "swap_call_by_reference 함수 사용 후\n" << "x = " << x << ", y = " << y << "\n";
	

    return 0;
}

