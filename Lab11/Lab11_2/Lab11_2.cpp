// Lab11_2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//회문 판별 

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//예시 cout << [](string a, string b) -> bool{ return a > b; } (string_list[3], string_list[4]);

	string word = " " ;
	string reversed_word = " " ;
	cout << "문자열 하나를 입력해주세요 : "; cin >> word;
	for (int i = word.size() - 1; i >= 0; i--) {
		reversed_word += word[i];
	}
	cout << "입력하신 문자의 역순 : " << reversed_word <<endl; 
	
	if ([](string w, string rw)-> bool {
		if (w == rw) return true;
		return false;
	}(word,reversed_word)) {
		cout << "이 문자는 회문입니다.\n";
	}
	else cout << "이 문자는 회문이 아닙니다.\n";


    return 0;
}

