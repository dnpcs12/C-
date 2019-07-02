// Lab12.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> list{ 10,20,30,40,50 };
	int num;

	while (1) {
		cout << "출력 할 숫자의 수 : "; cin >> num;
		
		try {
			for (int i = 0; i < num; i++) {
				cout << list.at(i) << " ";
			}
			cout << "\n";
		}
		catch (std::exception& e) {
			cout << "\nindex is out of range. Please try again\n";
		}
		
	}
    return 0;
}

