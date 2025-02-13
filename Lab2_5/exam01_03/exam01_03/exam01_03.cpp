// exam01_03.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void print_current_code(char code, int count) {
	switch (code)
	{
	case('W'):cout << count << code ;
		break;
	case('B'):
		if (count == 1) {
			cout << code;
		}
		else {
			cout << count << code;
		}
		break;
	default:
		break;
	}

}


void run_length_encoding(string& screen) {
	int count = 0;
	char ch = screen[0];
	for (int i = 0; i <= screen.length(); i++) {
		
		if (ch != screen[i]) {
			print_current_code(ch, count);
			ch = screen[i];
			count = 1;
		}
		else {
			count++;
		}
	}
}

int main()
{
	string screen = "WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWBWWWWWWWWWWWWWW";
	cout << "Run-length encoding(RLE) Test" << endl;
	cout << "Input data : " << screen << endl << endl;
	cout << "Encording result : ";
	run_length_encoding(screen);
	cout << endl;

	
    return 0;
}

