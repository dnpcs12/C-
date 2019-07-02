// Lab2_2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
int sum(int x, int y) {
	return x + y;
}
int sub(int x, int y) {
	return x - y;
}
int mult(int x, int y) {
	return x * y;
}
double idiv(int x, int y) {

	return (float)x / (float)y;
}

int add_mult(int x, int y, int z) {
	return mult(sum(x, y), z);
}

double mult_div(int x, int y, int z) {

	return idiv(mult(x, y), z);
}
int add_mult_add(int x, int y, int z) {
	return mult(sum(x, y), sum(y, z));

}

double sub_div_sub(int x, int y, int z){
	return idiv(sub(x, y), sub(x ,z));
}
int main()
{
	int x = 0;
	int y = 0;
	int z = 0;
	std::cout << "x 입력 : "; std::cin >> x;
	std::cout << "y 입력 : ";  std::cin >> y;
	std::cout << "z 입력 : ";  std::cin >> z;
	std::cout << "(x + y) * z = " << add_mult(x, y, z) << "\n";
	std::cout << "(x * y) / z = " << mult_div(x, y, z) << "\n";
	std::cout << "(x + y) * (y + z) = " << add_mult_add(x, y, z) << "\n";
	std::cout << "(x - y) / (x - z) = " << sub_div_sub(x, y, z) << "\n";

    return 0;
}

