// Lab10_02.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>


using namespace std;
using Iter = vector<int>::iterator;

int main()
{
	srand((unsigned)time(NULL));
	vector<int> v1(10,0);
	vector<int> v2(10,0);

	int v1_max = 0;
	int v1_min = 10;

	int v2_max = 0;
	int v2_min = 20;

	
	cout << "<vector 1>\n";
	for (Iter iter = v1.begin(); iter != v1.end(); iter++) {
		*iter = rand() % 11;
		cout << *iter << " ";
		if (v1_max < *iter) {
			v1_max = *iter;
		}
		if (v1_min > *iter) {
			v1_min = *iter;
		}
	}
	cout << "\n";
	cout << "<vector 2>\n";
	for (auto iter = v2.begin(); iter != v2.end(); iter++) {
		*iter = rand() % 21;
		cout << *iter << " ";
		if (v2_max < *iter) {
			v2_max = *iter;
		}
		if (v2_min > *iter) {
			v2_min = *iter;
		}
	}
	//cout << "\n("<<v1_max << ","<< v1_min << " ), "<< "(" <<v2_max << ", "<<v2_min << ")\n";
	cout << "\n\n최댓값 = " << v1_max * v2_max << endl;
	cout << "최솟값 = " << v1_min * v2_min << endl;

    return 0;
}

