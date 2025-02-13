// Lab09_02.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
/*애너그램을 만들기위해 삭제해야 할 최소 문자수를 출력
애너그램이란?
두 영단어의 순서를 바꿔서 같아질 수 있다면 두 단어는 애너그램 관계이다.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool in(const string &check, char word) {
	for (unsigned int i = 0; i < check.size(); i++) {
		if (check[i] == word) {
			return true;
		}
	}
	return false;
}

// 1.길이가 같아야하고, 2. 같은 원소를 갖고 있어야함. 
// -> 같은 원소를 제외하곤 지워야함. 
int makeAnagramNum(string w1,string w2) {
	int num1 = w1.size();
	int num2 = w2.size();
	int sameNum = 0;
	for (unsigned int i = 0; i < w1.size(); i++) {
		// w2안에 w1의 i번째 문자가 있는지 확인.
		if (w2.find(w1[i]) != w2.npos) { //있다면
			w2.erase(w2.find(w1[i]),1); // 그 문자를 w2에서 지운다. 
			sameNum++; // 동일 원소 갯수 ++
		}
	}
	
	return (num1 - sameNum) + (num2 - sameNum);
}
int main()
{
	string t1, t2;
	cout << "두 단어를 입력해주세요: "; cin >> t1 >> t2;
	cout << makeAnagramNum(t1, t2) << endl;
    return 0;
}

