// Lab05_03.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <string>

using namespace std;

void reverseVec(vector<int>& v) {
	int temp = 0;
	for (int i = 0; i < 5; i++) {
		temp = v[i];
		v[i] = v[9 - i];
		v[9 - i] = temp;
	}
}

int main()
{
	vector<int> vec{1,2,3,4,5,6,7,8,9,10};
	cout << "기본 Vector 값 : " << "\n     ";
	for (int i = 0; i < 10; i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";
	reverseVec(vec);
	cout << "함수 실행 후 Vector 값 : " << "\n     ";
	for (int i = 0; i < 10; i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";
    return 0;
}

