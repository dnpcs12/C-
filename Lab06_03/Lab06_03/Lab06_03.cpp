// Lab06_03.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
int main()
{
	int n;
	int *p;
	
	cout << "n: ";
	cin >> n;

	p = new int[n];
	p[0] = 0;
	p[1] = 1;


	for (int i = 0; i < n; i++) {
		if (i >= 2) {
			p[i] = p[i - 1] + p[i - 2];

		}
		
		cout << p[i] << " ";
	}
	cout << '\n';
	delete[] p;

    return 0;
}

