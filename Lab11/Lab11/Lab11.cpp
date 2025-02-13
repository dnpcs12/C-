// Lab11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


//insert sort 
template<typename T>
void sort(vector<T> &v) {
	for (unsigned int i = 1; i < v.size(); i++) {
		for (int j = 0; j < i; j++) { 
			if (v[j] > v[i]) {
				//cout << "전: ";print(v);
				T temp = v[i];
				for (int k = i-1; k >= j; k--) {
					v[k+1] = v[k];
				}
				v[j] = temp;
				//cout << "후: ";print(v);
				//cout << "\n";
			}
		}
	}
	
}

template<typename T>
void print(T something) {
	for (auto iter = begin(something); iter != end(something); iter++) {
		cout << *iter << " ";
	}
	cout << "\n";
}


int main()
{
	vector<int> int_list(5);
	int_list = { 10,5,8,1,3 };
	
	vector<double> double_list(5);

	double_list = { 10.1,5.1,8.1,1.1,3.1 };
	vector<string>string_list(5);
	string_list = { "하나","둘","셋","넷","다섯" };

	
	sort(int_list);
	sort(double_list);
	sort(string_list);

	print(int_list);
	print(double_list);
	print(string_list);
	


    return 0;
}

