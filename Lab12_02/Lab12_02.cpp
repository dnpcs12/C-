// Lab12_02.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;
int main()
{
	vector<int> list;
	srand((unsigned int)time(NULL));
	int r = rand() % 100 + 1;
	//cout << r;
	for (int i = 0; i < r; i++) {
		list.push_back(i);
	}
	int cnt = -1;
	
	while (1) {
	cnt++;
	try {
	list.at(cnt);
	}
	catch(exception& e){
		cout << "현재 list는 " << cnt <<"의 크기를 가지고 있다.\n";
		break;
	}
	}
	

    return 0;
}

