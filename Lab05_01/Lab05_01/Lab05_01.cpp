// Lab05_01.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void pow(int *n) {
	*n = (*n) * (*n);
}

int main()
{
	int num = 0;
	int *pnum;

	cout << "input>"; cin >> num;
	pnum = &num;
	pow(pnum);
	cout << num;
	
    return 0;
}

